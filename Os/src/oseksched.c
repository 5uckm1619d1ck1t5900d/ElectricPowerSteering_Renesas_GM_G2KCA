/* Kernbauer Version: 2.16 Konfiguration: RH850 Erzeugungsgangnummer: 222 Zweig: 4 */

/*****************************************************************************
| Project Name: MICROSAR OS
|    File Name: osekSched.c
|
|  General code: @Version: 9.01.04@
|  Module version: $vv$=1.04
|
|  Description: OSEK Scheduler
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000-2015 Vector Informatik GmbH          All rights reserved.
|****************************************************************************/


#if defined USE_QUOTE_INCLUDES
 #include "osek.h"
 #include "osekext.h"
#else
 #include <osek.h>
 #include <osekext.h>
#endif

/* Vector release management */
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif
/* KB begin vrmReleaseNumber (overwritten) */
/* Source release number */
#define osdVrmMajRelNum 1
#define osdVrmMinRelNum 6
/* KB end vrmReleaseNumber */
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

/* CovComment 0:  file: osekSched.c */

/* KB begin osekStartOfCModule (overwritten) */
#pragma ghs section bss=".os_bss"
#pragma ghs section data=".os_data"
#pragma ghs section sbss=".os_sbss"
#pragma ghs section sdata=".os_sdata"
#pragma ghs section text=".os_text"
#pragma ghs section rodata=".os_rodata"
#pragma ghs section rosdata=".os_rosdata"
/* KB end osekStartOfCModule */

/* KB begin osekHWosGetHighPrioBit (overwritten) */
/* osGetHighPrioBit is provided via assembler macro in osekasm.h */
/* KB end osekHWosGetHighPrioBit */

/*-+--------------------------------------------------------------------------
 / osSchedInsertTask
 / Function:
 /   - inserts the task into its home priority queue
 /   - sets the corresponding ready mask bit to TRUE
 /   - if the new task has a higher priority than the current HighReadyTask,
 /     - HighReadyTask and HighReadyPrio are set to the new task
 /     - StartDispatcher is set to TRUE.
 /
 /   Note: This function must be called with interrupts disabled and the new
 /         task's core's lock occupied!
 /
 / Parameter:     taskID : task to be inserted
 / Return value:  void
 /--------------------------------------------------------------------------*/

osqFunc1 void osqFunc2 osSchedInsertTask(TaskType taskIndex)
{
   /* CovComment 4:  Function: osSchedInsertTask */

   /* get priority of task to insert */
   osPrioType taskPriority = oskTcbHomePrio[taskIndex];

   /* validate the priority */
   osSysErrAssert(taskPriority < osrNumberOfPriorities, osdErrQIWrongTaskPrio)

   COVER(0x0163)
   /* Add task to the ready queue */
   oskQActivationQueues[taskPriority][ptrToCcb->ossQReadyTaskTail[taskPriority]] = taskIndex;
   /* increment tail and handle overflow */
   ptrToCcb->ossQReadyTaskTail[taskPriority]++;
   if (ptrToCcb->ossQReadyTaskTail[taskPriority] > oskQMaxActivations[taskPriority])
   {
      COVER(0x0164)
      ptrToCcb->ossQReadyTaskTail[taskPriority] = 0;
   }
   ELSEWITHCOVER(0x0165)

   /* at least one task is now ready on this priority */
   COVER(0x0166)
   ptrToCcb->ossQReadyPrios[oskTcbReadyPrioOffset[taskIndex]] |= oskTcbReadyPrioMask[taskIndex];

   /* start dispatcher only if new task has greater prio */
   if (taskPriority < ptrToCcb->ossHighReadyTaskPrio)
   {
      COVER(0x0167)
      ptrToCcb->ossHighReadyTaskPrio  = taskPriority;
      ptrToCcb->ossHighReadyTaskIndex = taskIndex;
      ptrToCcb->ossStartDispatcher    = osdTRUE;
   }
}

/*-+--------------------------------------------------------------------------
 / osSchedRemoveRunningTask
 / Function:
 /   - removes the currently running task from the ready queue
 /   - if the queue is empty afterwards, the corresponding ready mask bit is
 /     cleared
 /   - a new HighReadyTask and HighReadyPrio are calculated
 /   - StartDispatcher is set to TRUE (the previously active task was preempted or
 /     terminated, so we need the dispatcher to continue in any case)
 /
 /   Note: This function must be called with interrupts disabled and local
 /         core's lock occupied! No cross-core support! Tasks can only deactivate
 /         themselves, so this function will be executed on the tasks's core
 /         exclusively.
 /
 / Parameter:     void
 / Return value:  void
 /--------------------------------------------------------------------------*/
 /* MISRA RULE 14.1 VIOLATION: osSchedRemoveRunningTask is a function which might be unused. In order to keep the code 
  * simple and error free, it is available in more configurations than necessary.*/
osqFunc1 void osqFunc2 osSchedRemoveRunningTask(void) /* PRQA S 1503 */
{
   /* CovComment 4:  Function: osSchedRemoveRunningTask */

   osPrioType hiPriorTask;
   osqPRAM1 volatile osqPRAM2 osPrioFlagType osqPRAM3 *ptr;
   osPrioFlagType uiTestPattern;
   TaskType activeTaskID;
   osPrioType activeTaskPrio;
   
   activeTaskID = osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex;
   activeTaskPrio = osOwnCcb->LockIsNotNeeded.ossActiveTaskPrio;

   osSysErrAssert(activeTaskID < osrNumberOfAllTasks, osdErrQRWrongTaskID)
   osSysErrAssert(activeTaskPrio < osrNumberOfPriorities, osdErrQRWrongTaskPrio)

   COVER(0x0168)
   osSysErrAssert((osCheckInterruptsDisabled() != 0), osdErrQRInterruptsEnabled) /* TR:SPMF12:0007 */


   /* delete task out of the prio queue */
   ptrToCcb->ossQReadyTaskHead[activeTaskPrio]++;
   if (ptrToCcb->ossQReadyTaskHead[activeTaskPrio] > oskQMaxActivations[activeTaskPrio])
   {
      COVER(0x0169)
      ptrToCcb->ossQReadyTaskHead[activeTaskPrio]= 0;
   }
   ELSEWITHCOVER(0x016A)

   if (ptrToCcb->ossQReadyTaskHead[activeTaskPrio] == ptrToCcb->ossQReadyTaskTail[activeTaskPrio])
   {  /* queue empty */
      COVER(0x016B)

      COVER(0x016C)
      ptrToCcb->ossQReadyPrios[oskTcbReadyPrioOffset[activeTaskID]]&= ~oskTcbReadyPrioMask[activeTaskID];

   }
   ELSEWITHCOVER(0x016D)

   /* calculate ready task with highest priority */
   COVER(0x016E)
   COVER(0x016F)
   ptr = ptrToCcb->ossQReadyPrios;
   uiTestPattern = *ptr;
   hiPriorTask = 0;
   IFCOVER(!uiTestPattern,0x018F,0x0190)
   while (!uiTestPattern)
   {
      ptr++;
      if (ptr > &ptrToCcb->ossQReadyPrios[osrRTSize-1])
      {  /* prepare for IDLE-Loop */
         COVER(0x0170)
         ptrToCcb->ossHighReadyTaskPrio  = osdNoActivePrio;
         ptrToCcb->ossHighReadyTaskIndex = osdNoActiveTask;
         ptrToCcb->ossStartDispatcher    = osdTRUE;
         return;
      }
      ELSEWITHCOVER(0x0171)
      uiTestPattern = *ptr;
      hiPriorTask += osdPrioBitsPerWord;
      IFCOVER(!uiTestPattern,0x0191,0x0192)
   }
   COVER(0x0172)
   hiPriorTask += osGetHighPrioBit(uiTestPattern);

   osSysErrAssert(hiPriorTask < osrNumberOfPriorities, osdErrQRWrongHighRdyPrio)

   COVER(0x0173)
   ptrToCcb->ossHighReadyTaskIndex = oskQActivationQueues[hiPriorTask][ptrToCcb->ossQReadyTaskHead[hiPriorTask]];

   ptrToCcb->ossHighReadyTaskPrio  = hiPriorTask;

   /* we have just removed the running task from the ready queue, so we need a dispatcher call in any case. */
   ptrToCcb->ossStartDispatcher    = osdTRUE;
   return;
}




#if (osdNumberOfTaskResources > 0)
#if (!defined(osdGetResourceNotUsed))
/*-+--------------------------------------------------------------------------
 / osSchedGetResource
 / Function:
 /   - occupies the given resource's ceiling priority with the active task
 /   - active task prio and high ready task prio and index are adapted if
 /     adequate.
 /
 /   Note: This function must be called with interrupts disabled and local
 /         core's lock occupied! No cross-core support!
 /
 / Parameter:     ResId : resource to be occupied
 / Return value:  void
 /--------------------------------------------------------------------------*/

osqFunc1 void osqFunc2 osSchedGetResource(ResourceType ResId)
{
   /* CovComment 4:  Function: osSchedGetResource */


   /* validate that the resource's priority is free */
   COVER(0x0174)
   osSysErrAssert(((ptrToCcb->ossQReadyPrios[oskResCeilingPrioOffset[ResId]] & 
                    oskResCeilingPrioMask[ResId]) == 0U), osdErrGRPriorityOccupied)  /* NOCOV */

   COVER(0x0175)
   /* Add task to the ready queue */
   oskQActivationQueues[oskResCeilingPrio[ResId]][ptrToCcb->ossQReadyTaskTail[oskResCeilingPrio[ResId]]] = osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex;
   /* increment tail and handle overflow */
   ptrToCcb->ossQReadyTaskTail[oskResCeilingPrio[ResId]]++;
   if (ptrToCcb->ossQReadyTaskTail[oskResCeilingPrio[ResId]] > oskQMaxActivations[oskResCeilingPrio[ResId]])
   {
      COVER(0x0176)
      ptrToCcb->ossQReadyTaskTail[oskResCeilingPrio[ResId]] = 0;
   }
   ELSEWITHCOVER(0x0177)

   /* set the ready bitmask */
   COVER(0x0178)
   ptrToCcb->ossQReadyPrios[oskResCeilingPrioOffset[ResId]] |= oskResCeilingPrioMask[ResId];

   /* increase current task's priority to the ceiling prio */
   if (oskResCeilingPrio[ResId] < osOwnCcb->LockIsNotNeeded.ossActiveTaskPrio)
   {
      COVER(0x0179)
      osOwnCcb->LockIsNotNeeded.ossActiveTaskPrio = oskResCeilingPrio[ResId];
   }
   ELSEWITHCOVER(0x017A)

   /* update high ready task prio and index */
   /* no need to trigger dispatcher: high ready task is already running */
   if (oskResCeilingPrio[ResId] < ptrToCcb->ossHighReadyTaskPrio)
   {
      COVER(0x017B)
      ptrToCcb->ossHighReadyTaskPrio  = oskResCeilingPrio[ResId];
      ptrToCcb->ossHighReadyTaskIndex = osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex;
   }
   ELSEWITHCOVER(0x017C)
   return;
}
#endif


#if (!defined(osdReleaseResourceNotUsed))
/*-+--------------------------------------------------------------------------
 / osSchedReleaseResource
 / Function:
 /   - releases the given resource's ceiling priority
 /   - recalculates high ready task index and prio, and requests dispatcher
 /     activation, if adequate.
 /
 /   Note: This function must be called with interrupts disabled and local
 /         core's lock occupied! No cross-core support!
 /
 / Parameter:     ResId : resource to be released
 / Return value:  void
 /--------------------------------------------------------------------------*/

osqFunc1 void osqFunc2 osSchedReleaseResource(ResourceType ResId)
{
   /* CovComment 4:  Function: osSchedReleaseResource */

   osPrioType hiPriorTask;
   osqPRAM1 volatile osqPRAM2 osPrioFlagType osqPRAM3 *ptr;
   osPrioFlagType uiTestPattern;

   /* next assertion checks if there is a bit set in the ready bits */
   COVER(0x017D)
   osSysErrAssert(((ptrToCcb->ossQReadyPrios[oskResCeilingPrioOffset[ResId]] &
      oskResCeilingPrioMask[ResId]) != 0U), osdErrRRCeilingPriorityNotSet) /* NOCOV */

   /* delete task out of the prio queue */
   ptrToCcb->ossQReadyTaskHead[oskResCeilingPrio[ResId]]++;
   if (ptrToCcb->ossQReadyTaskHead[oskResCeilingPrio[ResId]] > oskQMaxActivations[oskResCeilingPrio[ResId]])
   {
      COVER(0x017E)
      ptrToCcb->ossQReadyTaskHead[oskResCeilingPrio[ResId]]= 0;
   }
   ELSEWITHCOVER(0x017F)

   COVER(0x0180)
   ptrToCcb->ossQReadyPrios[oskResCeilingPrioOffset[ResId]] &= ~oskResCeilingPrioMask[ResId];

   /* calculate ready task with highest priority */
   COVER(0x0181)
   COVER(0x0182)
   ptr = ptrToCcb->ossQReadyPrios;
   uiTestPattern = *ptr;
   hiPriorTask = 0;
   IFCOVER(!uiTestPattern,0x0193,0x0194)
   while (!uiTestPattern)
   {
      ptr++;
      /* at least the task releasing its resource must still be ready on its home prio. */
      osSysErrAssert((ptr <= &ptrToCcb->ossQReadyPrios[osrRTSize-1]), osdErrRRNoReadyTaskFound)
      uiTestPattern = *ptr;
      hiPriorTask += osdPrioBitsPerWord;
      IFCOVER(!uiTestPattern,0x0195,0x0196)
   }
   COVER(0x0183)
   hiPriorTask += osGetHighPrioBit(uiTestPattern);

   osSysErrAssert(hiPriorTask < osrNumberOfPriorities, osdErrRRWrongHighRdyPrio)

   COVER(0x0184)
   ptrToCcb->ossHighReadyTaskIndex = oskQActivationQueues[hiPriorTask][ptrToCcb->ossQReadyTaskHead[hiPriorTask]];

   ptrToCcb->ossHighReadyTaskPrio  = hiPriorTask;

   /* KB begin osekHWosSchedulePrioReaction (default) */
      if (ptrToCcb->ossHighReadyTaskIndex != osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex)
      {
         COVER(0x0185)
         ptrToCcb->ossStartDispatcher    = osdTRUE;
      }
      ELSEWITHCOVER(0x0186)
   /* KB end osekHWosSchedulePrioReaction */
   return;
}
#endif
#endif


/*-+--------------------------------------------------------------------------
 / osSchedOccupyInternalResource
 / Function:
 /   - occupies the ceiling priority of the internal resource assigned to the
 /     active task
 /   - high ready task prio is adapted if adequate.
 /   - active task prio is set (even if no internal resource is assigned)
 /
 /   Note: This function must be called with interrupts disabled and local
 /         core's lock occupied! No cross-core support!
 /         osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex must be set to the task
 /         that is being dispatched before this function is called!
 /
 / Parameter:     void
 / Return value:  void
 /--------------------------------------------------------------------------*/
/* MISRA RULE 14.1 not violated: osSchedOccupyInternalResource is a function which is called from 
 *                               assembly language in some implementations. This is not recognized 
 *                               by the MISRA checker. 
 */
osqFunc1 void osqFunc2 osSchedOccupyInternalResource(void) /* PRQA S 1503 */
{
   /* CovComment 4:  Function: osSchedOccupyInternalResource */

   TaskType activeTaskID;
   
   activeTaskID = osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex;
   osSysErrAssert(activeTaskID < osrNumberOfAllTasks, osdErrQOWrongTaskID)


      COVER(0x0187)
      osOwnCcb->LockIsNotNeeded.ossActiveTaskPrio  = ptrToCcb->ossHighReadyTaskPrio;

   osTcbActualPrio[activeTaskID] = osOwnCcb->LockIsNotNeeded.ossActiveTaskPrio;
}

/*-+--------------------------------------------------------------------------
 / osSchedOnHomePrio
 / Function:
 /   - releases the internal resource held by the running task (if applicable)
 /   - recalculates high ready task index and prio, and requests dispatcher
 /     activation, if adequate.
 /
 /   Note: This function must be called with interrupts disabled and local
 /         core's lock occupied! No cross-core support!
 /
 / Parameter:     void
 / Return value:  void
 /--------------------------------------------------------------------------*/

osqFunc1 void osqFunc2 osSchedOnHomePrio(void)
{
   /* CovComment 4:  Function: osSchedOnHomePrio */

   osPrioType hiPriorTask;
   osqPRAM1 volatile osqPRAM2 osPrioFlagType osqPRAM3 *ptr;
   osPrioFlagType uiTestPattern;

   COVER(0x0188)
   osSysErrAssert((osCheckInterruptsDisabled() != 0), osdErrQSInterruptsEnabled) /* TR:SPMF12:0007 */


   /* calculate ready task with highest priority */
   COVER(0x0189)
   COVER(0x018A)
   ptr = ptrToCcb->ossQReadyPrios;
   uiTestPattern = *ptr;
   hiPriorTask = 0;
   IFCOVER(!uiTestPattern,0x0197,0x0198)
   while (!uiTestPattern)
   {
      ptr++;
      /* at least the task releasing its internal resource must still be ready on its home prio. */
      osSysErrAssert((ptr <= &ptrToCcb->ossQReadyPrios[osrRTSize-1]), osdErrQSNoReadyTaskFound)
      uiTestPattern = *ptr;
      hiPriorTask += osdPrioBitsPerWord;
      IFCOVER(!uiTestPattern,0x0199,0x019A)
   }
   COVER(0x018B)
   hiPriorTask += osGetHighPrioBit(uiTestPattern);

   osSysErrAssert(hiPriorTask < osrNumberOfPriorities, osdErrQSWrongPriority)

   COVER(0x018C)
   ptrToCcb->ossHighReadyTaskIndex = oskQActivationQueues[hiPriorTask][ptrToCcb->ossQReadyTaskHead[hiPriorTask]];

   ptrToCcb->ossHighReadyTaskPrio  = hiPriorTask;

   /* KB begin osekHWosSchedulePrioReaction (default) */
      if (ptrToCcb->ossHighReadyTaskIndex != osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex)
      {
         COVER(0x018D)
         ptrToCcb->ossStartDispatcher    = osdTRUE;
      }
      ELSEWITHCOVER(0x018E)
   /* KB end osekHWosSchedulePrioReaction */
   return;
}



/* KB begin osekEndOfCModule (overwritten) */
#pragma ghs section bss=default
#pragma ghs section data=default
#pragma ghs section sbss=default
#pragma ghs section sdata=default
#pragma ghs section text=default
#pragma ghs section rodata=default
#pragma ghs section rosdata=default
/* KB end osekEndOfCModule */

/* END OF MODULE osekSched.c */

