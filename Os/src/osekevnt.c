/* Kernbauer Version: 2.16 Konfiguration: RH850 Erzeugungsgangnummer: 222 Zweig: 4 */

/*****************************************************************************
| Project Name: MICROSAR OS
|    File Name: osekevnt.c
|
|  General code: @Version: 9.01.04@
|  Module version: $vv$=1.57
|
|  Description: osek API-functions for handling events
|               - SetEvent
|               - ClearEvent
|               - GetEvent
|               - WaitEvent
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

/* CovComment 0:  file: osekevnt.c */

/* KB begin osekStartOfCModule (overwritten) */
#pragma ghs section bss=".os_bss"
#pragma ghs section data=".os_data"
#pragma ghs section sbss=".os_sbss"
#pragma ghs section sdata=".os_sdata"
#pragma ghs section text=".os_text"
#pragma ghs section rodata=".os_rodata"
#pragma ghs section rosdata=".os_rosdata"
/* KB end osekStartOfCModule */

#if ((CC == ECC1) || (CC == ECC2)) && (osdNumberOfExtendedTasks > 0)

/*
 *  MICROSAR OS timing hooks call macro, used by event API below
 */
/* CovComment 4:  Macro: OS_VTH_CALL_SETEVENT_HOOK */
#if osdCallTimingHooks
#define OS_VTH_CALL_SETEVENT_HOOK(TaskId, EventMask, StateChange)              \
   COVER(0x0211)                                                                     \
   OS_VTH_SETEVENT((TaskId), (EventMask), (StateChange), 0, 0)
#else
#define OS_VTH_CALL_SETEVENT_HOOK(TaskId, EventMask, StateChange) \
   COVER(0x0212)
#endif




/*-+--------------------------------------------------------------------------
 / SetEvent
 / ========          
 /
 / Syntax:          StatusType SetEvent ( TaskType <TaskID>
 /                                        EventMaskType <Mask> )
 / Parameter (In):  - TaskID Reference to the task for which one or 
 /                    several events are to be set.
 /                  - Mask Mask of the events to be set
 / Parameter (Out): none
 / Description:     The service might be called from an interrupt service 
 /                  routine and from the task level, but not from hook 
 /                  routines.
 /                  The events of task <TaskID> are set according to the 
 /                  event mask <Mask>. Calling SetEvent causes the task 
 /                  <TaskID> to be transferred to the ready state, if it
 /                  has been waiting for at least one of the events 
 /                  specified in <Mask>.
 / Particularities: Any events not set in the event mask remain unchanged.
 / Status:
 /  -Standard:      - No error, E_OK
 /  -Extended:      - Task <TaskID> is invalid, E_OS_ID
 /                  - Referenced task is no extended task, E_OS_ACCESS
 /                  - Events can not be set as the referenced task is in the
 /                    suspended state, E_OS_STATE
 /                  - Call with disabled interrupts, E_OS_DISABLEDINT
 / Conformance:     ECC1, ECC2
 / Context:         Task, Cat2-ISR, interrupts not disabled by the application
 /--------------------------------------------------------------------------*/

/* MISRA RULE 14.1 VIOLATION: The function osSetEvent is referenced
 * by the corresponding Psys-Wrapper, which is typically assembler code. MISRA
 * cannot see this.
 */
osqFunc1 StatusType osqFunc2 osSetEvent(TaskType taskIndex, EventMaskType setMask)   /* PRQA S 1503 */
{
   /* CovComment 4:  Function: osSetEvent */
/* KB begin setEventBody (default) */

   OS_SE_ENTRY()
   COVER(0x0213)

   /* check call context */
   if ((osdValidCtx_SetEvent & osOwnCcb->LockIsNotNeeded.ossCurrentContext) == 0)
   {
      COVER(0x0214)
      osAPIError(E_OS_CALLEVEL, osdErrSECallContext);
      OS_SE_EXIT()
      return E_OS_CALLEVEL;
   }
   ELSEWITHCOVER(0x0215)

   if (taskIndex >= osrNumberOfAllTasks)
   {
      COVER(0x0216)
      osAPIError(E_OS_ID, osdErrSEWrongTaskID);
      OS_SE_EXIT()
      return E_OS_ID;
   }
   ELSEWITHCOVER(0x0217)
   /* check access rights for this object */
   if (((oskApplTaskAccess[taskIndex] & (1UL << osOwnCcb->LockIsNotNeeded.ossActiveApplicationID)) == 0))
   {
      COVER(0x0218)
      osAPIError(E_OS_ACCESS, osdErrSENoAccess);
      OS_SE_EXIT()
      return E_OS_ACCESS;
   }
   ELSEWITHCOVER(0x0219)

#if osdNumberOfExtendedTasks != osdNumberOfAllTasks
   if (taskIndex >= osrNumberOfExtendedTasks)
   {
      COVER(0x021A)
      osAPIError(E_OS_ACCESS, osdErrSENotExtendedTask);
      OS_SE_EXIT()
      return E_OS_ACCESS;
   }
   ELSEWITHCOVER(0x021B)
#endif

   if (osOwnCcb->LockIsNotNeeded.ossIntAPIStatus != 0)
   {
      COVER(0x021C)
      osAPIError(E_OS_DISABLEDINT, osdErrSEIntAPIDisabled);
      OS_SE_EXIT()
      return E_OS_DISABLEDINT;
   }
   ELSEWITHCOVER(0x021D)



   COVER(0x021E)
   /* KB begin osekHWosSaveDisableLevel (overwritten) */
   osSaveDisableLevel() /* save level and disable up to system level, no nesting */
   /* KB end osekHWosSaveDisableLevel */
   OS_SE_START_CRITICAL()



   if (osTcbTaskState[taskIndex] == SUSPENDED)
   {
      COVER(0x021F)
      osSaveSetEvent_TaskID(taskIndex)
      osSaveSetEvent_Mask(setMask)
      osAPIError(E_OS_STATE, osdErrSETaskSuspended);
      COVER(0x0220)
      OS_SE_END_CRITICAL()
      /* KB begin osekHWosRestoreEnableLevel (overwritten) */
      osRestoreEnableLevel() /* restore level saved by osSaveDisableLevel */
      /* KB end osekHWosRestoreEnableLevel */
      OS_SE_EXIT()
      return E_OS_STATE;
   }
   ELSEWITHCOVER(0x0221)

   COVER(0x0222)
   /* KB begin osekHWosDisableTimProtInterrupt (overwritten) */
   /* KB end osekHWosDisableTimProtInterrupt */

   COVER(0x0223)
   osTcbSetEventMask[taskIndex]|= setMask; /* set event flag(s)    */

   if (osTcbTaskState[taskIndex] == WAITING)
   {
      /* task is waiting */
      if ((osTcbSetEventMask[taskIndex] & osTcbWaitEventMask[taskIndex]) != 0)
      {
         COVER(0x0224)

         OS_VTH_CALL_SETEVENT_HOOK(((TaskType) taskIndex)   ,
                                   ((EventMaskType) setMask),
                                   ((osbool) osdTRUE)       )

         /*  satisfied, change from waiting to ready */
         osTcbTaskState[taskIndex] = READY;
         
         osSchedInsertTask(taskIndex);

         if (osdTRUE == ptrToCcb->ossStartDispatcher)
         {
            COVER(0x0225)
               if (osOwnCcb->LockIsNotNeeded.ossLockDispatcher == 0)
               {
                  /* trigger the dispatcher on the current core */
                  COVER(0x0226)
                  COVER(0x0227)
                  /* KB begin osekHWosEnableTimProtInterrupt (overwritten) */
                  /* KB end osekHWosEnableTimProtInterrupt */

                  OS_SE_END_CRITICAL()
                  /* KB begin osekHWosRestoreEnableLevel (overwritten) */
                  osRestoreEnableLevel() /* restore level saved by osSaveDisableLevel */
                  /* KB end osekHWosRestoreEnableLevel */
                  OS_SE_EXIT()
                  OS_START_DISPATCH()
                  /* KB begin osekHWosLocalDispatcher (overwritten) */
                  ptrToCcb2->ossCallDispatcher = 1;
                  /* KB end osekHWosLocalDispatcher */
                  return E_OK;
               }
               ELSEWITHCOVER(0x0228)
         }
         ELSEWITHCOVER(0x0229)
      }/*if ((EventsRequireStateChange == osdTRUE) && (StateChangeAllowed == osdTRUE))*/
      else
      {
         COVER(0x022A)
         /* no change of task state as the task was not waiting for this event or timing protection prevented the state change */
         OS_VTH_CALL_SETEVENT_HOOK(((TaskType) taskIndex)   ,
                                   ((EventMaskType) setMask),
                                   ((osbool) osdFALSE)       )
      }
   }/* if (osTcbTaskState[taskIndex] == WAITING) */
   else
   {
      COVER(0x022B)
      /* no change of task state as the task was not waiting at all */
      OS_VTH_CALL_SETEVENT_HOOK(((TaskType) taskIndex)   ,
                                ((EventMaskType) setMask),
                                ((osbool) osdFALSE)       )
   }


   COVER(0x022C)
   /* KB begin osekHWosEnableTimProtInterrupt (overwritten) */
   /* KB end osekHWosEnableTimProtInterrupt */

   OS_SE_END_CRITICAL()
   /* KB begin osekHWosRestoreEnableLevel (overwritten) */
   osRestoreEnableLevel() /* restore level saved by osSaveDisableLevel */
   /* KB end osekHWosRestoreEnableLevel */
   OS_SE_EXIT()
   return E_OK; /* TR:SPMF82:0002 */

/* KB end setEventBody */
} /* END OF osSetEvent */


#if ((osdNumberOfAlarmSetEvent > 0) || (osdNumberOfSTSetEvent > 0))
/*
 * MISRA RULE 14.1 VIOLATION: The function osSysSetEvent is unused in some configurations. In order to keep the code 
 * simple and error free, it is available in more configurations than necessary.
 */
osqFunc1 StatusType osqFunc2  osSysSetEvent(TaskType taskIndex, EventMaskType setMask) /* PRQA S 1503 */
{
   /* CovComment 4:  Function: osSysSetEvent */
/* KB begin sysSetEventBody (default) */

   OS_SE_ENTRY()
   COVER(0x022D)





   if (osTcbTaskState[taskIndex] == SUSPENDED)
   {
      COVER(0x022E)
      osSaveSetEvent_TaskID(taskIndex)
      osSaveSetEvent_Mask(setMask)
      osAPIError(E_OS_STATE, osdErrSETaskSuspended);
      OS_SE_EXIT()
      return E_OS_STATE;
   }
   ELSEWITHCOVER(0x022F)

   COVER(0x0230)
   osTcbSetEventMask[taskIndex]|= setMask; /* set event flag(s)    */

   if (osTcbTaskState[taskIndex] == WAITING)
   {
      /* task is waiting */
      
      COVER(0x0231)
      if ((osTcbSetEventMask[taskIndex] & osTcbWaitEventMask[taskIndex]) != 0)
      {
         COVER(0x0232)

         OS_VTH_CALL_SETEVENT_HOOK(((TaskType) taskIndex)   ,
                                   ((EventMaskType) setMask),
                                   ((osbool) osdTRUE)       )

         /*  satisfied, change from waiting to ready */
         osTcbTaskState[taskIndex] = READY;
         
         osSchedInsertTask(taskIndex);

      }/*if ((EventsRequireStateChange == osdTRUE) && (StateChangeAllowed == osdTRUE))*/
      else
      {
         COVER(0x0233)
         /* no change of task state as the task was not waiting for this event or timing protection prevented the state change */
         OS_VTH_CALL_SETEVENT_HOOK(((TaskType) taskIndex)   ,
                                   ((EventMaskType) setMask),
                                   ((osbool) osdFALSE)       )
      }
   }/* if (osTcbTaskState[taskIndex] == WAITING) */
   else
   {
      COVER(0x0234)
      /* no change of task state as the task was not waiting at all */
      OS_VTH_CALL_SETEVENT_HOOK(((TaskType) taskIndex)   ,
                                ((EventMaskType) setMask),
                                ((osbool) osdFALSE)       )
   }


   OS_SE_EXIT()
   return E_OK; /* TR:SPMF82:0002 */

/* KB end sysSetEventBody */
} /* END OF osSysSetEvent */
#endif


/*-+--------------------------------------------------------------------------
 / ClearEvent
 / =========
 /
 / Syntax:          StatusType ClearEvent ( EventMaskType <Mask> )
 / Parameter (In):  Mask Mask of the events to be cleared
 / Parameter (Out): none
 / Description:     The events of the extended task calling ClearEvent are 
 /                  cleared according to the event mask <Mask>.
 / Particularities: The system service ClearEvent is restricted to extended 
 /                  tasks which own the event.
 / Status:
 /  -Standard:      - No error, E_OK
 /  -Extended:      - Call not from extended task, E_OS_ACCESS
 /                  - Call at interrupt level, E_OS_CALLEVEL
 /                  - Call with disabled interrupts, E_OS_DISABLEDINT
 / Conformance:     ECC1, ECC2
 / Context:         Extended task, interrupts enabled
 /--------------------------------------------------------------------------*/

/* MISRA RULE 14.1 VIOLATION: The function osClearEvent is referenced
 * by the corresponding Psys-Wrapper, which is typically assembler code. MISRA
 * cannot see this.
 */
osqFunc1 StatusType osqFunc2 osClearEvent (EventMaskType Mask)   /* PRQA S 1503 */
{
   /* CovComment 4:  Function: osClearEvent */
   OS_CE_ENTRY()
   COVER(0x0235)

   COVER(0x0236)
   /* check call context */
   if ((osdValidCtx_ClearEvent & osOwnCcb->LockIsNotNeeded.ossCurrentContext) == 0)
   {
      COVER(0x0237)
      osAPIError(E_OS_CALLEVEL, osdErrCECallContext);
      OS_CE_EXIT()
      return E_OS_CALLEVEL;
   }
   ELSEWITHCOVER(0x0238)

   if (osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex >= osrNumberOfExtendedTasks)
   {
      COVER(0x0239)
      osAPIError(E_OS_ACCESS, osdErrCENotExtendedTask);
      OS_CE_EXIT()
      return E_OS_ACCESS;
   }
   ELSEWITHCOVER(0x023A)

   if (osOwnCcb->LockIsNotNeeded.ossIntAPIStatus != 0)
   {
      COVER(0x023B)
      osAPIError(E_OS_DISABLEDINT, osdErrCEIntAPIDisabled);
      OS_CE_EXIT()
      return E_OS_DISABLEDINT;
   }
   ELSEWITHCOVER(0x023C)

   /* KB begin osekHWosSaveDisableLevel (overwritten) */
   osSaveDisableLevel() /* save level and disable up to system level, no nesting */
   /* KB end osekHWosSaveDisableLevel */ /* disable interrupts as next command is not atomic */
   OS_CE_START_CRITICAL()
   osTcbSetEventMask[osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex]&=(EventMaskType)(~Mask);
   OS_CE_END_CRITICAL()
   /* KB begin osekHWosRestoreEnableLevel (overwritten) */
   osRestoreEnableLevel() /* restore level saved by osSaveDisableLevel */
   /* KB end osekHWosRestoreEnableLevel */

   COVER(0x023D)
   OS_CE_EXIT()
   return E_OK;
} /* END OF osClearEvent */
/*-+--------------------------------------------------------------------------
 / GetEvent
 / ========
 /
 / Syntax:          StatusType GetEvent ( TaskType <TaskID>, 
 /                                        EventMaskRefType <Event> )
 / Parameter (In):  TaskID Task whose event mask is to be returned.
 / Parameter (Out): Event Reference to the memory of the return data.
 / Description:     This service returns the current state of all event bits 
 /                  of the task <TaskID>, not the events that the task is 
 /                  waiting for.
 /                  The service might be called from interrupt service 
 /                  routines, task level and some hook routines.
 /                  The current status of the event mask of task <TaskID> is
 /                  copied to <Event>.
 / Particularities: The referenced task must be an extended task.
 / Status:
 /  -Standard:      - No error, E_OK
 /  -Extended:      - Task <TaskID> is invalid, E_OS_ID
 /                  - Referenced task <TaskID> is not an extended task, 
 /                    E_OS_ACCESS
 /                  - Referenced task <TaskID> is in the suspended state, 
 /                    E_OS_STATE
 /                  - Call with disabled interrupts, E_OS_DISABLEDINT
 / Conformance:     ECC1, ECC2
 / Context:         Task, Cat2-ISR, ErrorHook, PreTaskHook, PostTaskHook,
 /                  interrupts not disabled by the application
 /--------------------------------------------------------------------------*/

/* MISRA RULE 14.1 VIOLATION: The function osGetEvent is referenced
 * by the corresponding Psys-Wrapper, which is typically assembler code. MISRA
 * cannot see this.
 */
osqFunc1 StatusType osqFunc2 osGetEvent(TaskType taskIndex, EventMaskRefType Event)   /* PRQA S 1503 */
{
   /* CovComment 4:  Function: osGetEvent */
   /* KB begin osekHWGetEventLocalVars (overwritten) */
   /* KB end osekHWGetEventLocalVars */

   OS_GE_ENTRY()
   COVER(0x023E)

   COVER(0x023F)
   COVER(0x0240)
   /* check call context */
   if ((osdValidCtx_GetEvent & osOwnCcb->LockIsNotNeeded.ossCurrentContext) == 0)
   {
      COVER(0x0241)
      osAPIError(E_OS_CALLEVEL, osdErrGECallContext);
      OS_GE_EXIT()
      return E_OS_CALLEVEL;
   }
   ELSEWITHCOVER(0x0242)


   if (taskIndex >= osrNumberOfAllTasks)
   {
      COVER(0x0243)
      osAPIError(E_OS_ID, osdErrGEWrongTaskID);
      OS_GE_EXIT()
      return E_OS_ID;
   }
   ELSEWITHCOVER(0x0244)
   COVER(0x0245)
   /* check access rights for this object */
   if (((oskApplTaskAccess[taskIndex] & (1UL << osOwnCcb->LockIsNotNeeded.ossActiveApplicationID)) == 0))
   {
      COVER(0x0246)
      osAPIError(E_OS_ACCESS, osdErrGENoAccess);
      OS_GE_EXIT()
      return E_OS_ACCESS;
   }
   ELSEWITHCOVER(0x0247)

#if osdNumberOfExtendedTasks != osdNumberOfAllTasks
   COVER(0x0248)
   if (taskIndex >= osrNumberOfExtendedTasks)
   {
      COVER(0x0249)
      osAPIError(E_OS_ACCESS, osdErrGENotExtendedTask);
      OS_GE_EXIT()
      return E_OS_ACCESS;
   }
   ELSEWITHCOVER(0x024A)
#endif

   if (osTcbTaskState[taskIndex] == SUSPENDED)
   {
      COVER(0x024B)
      osAPIError(E_OS_STATE, osdErrGETaskSuspended);
      OS_GE_EXIT()
      return E_OS_STATE;
   }
   ELSEWITHCOVER(0x024C)

   if (osOwnCcb->LockIsNotNeeded.ossIntAPIStatus != 0)
   {
      COVER(0x024D)
      osAPIError(E_OS_DISABLEDINT, osdErrGEIntAPIDisabled);
      OS_GE_EXIT()
      return E_OS_DISABLEDINT;
   }
   ELSEWITHCOVER(0x024E)


   COVER(0x024F)
/* KB begin osekHWGetEventMaskAccess (overwritten) */
*Event= osTcbSetEventMask[taskIndex];
/* KB end osekHWGetEventMaskAccess */

   COVER(0x0250)
   OS_GE_EXIT()
   return E_OK;
   
} /* END OF osGetEvent */
/*-+--------------------------------------------------------------------------
 / WaitEvent
 / =========
 /
 / Syntax:          StatusType WaitEvent ( EventMaskType <Mask> )
 / Parameter (In):  Mask Mask of the events waited for.
 / Parameter (Out): none
 / Description:     The state of the calling task is set to waiting, unless 
 /                  at least one of the events specified in <Mask> has 
 /                  already been set.
 / Particularities: This call enforces rescheduling, if the wait condition 
 /                  occurs. If rescheduling takes place, the internal 
 /                  resource of the task is released while the task is in 
 /                  the waiting state.
 /                  This service must only be called from the extended task 
 /                  owning the event.
 / Status:
 /  -Standard:      - No error, E_OK
 /  -Extended:      - Calling task is not an extended task, E_OS_ACCESS
 /                  - Calling task occupies resources, E_OS_RESOURCE
 /                  - Call at interrupt level, E_OS_CALLEVEL
 /                  - Call with disabled interrupts, E_OS_DISABLEDINT
 / Conformance:     ECC1, ECC2
 / Context:         Extended task, interrupts enabled, no resources occupied
 /--------------------------------------------------------------------------*/

/* MISRA RULE 14.1 VIOLATION: The function osWaitEvent is referenced
 * by the corresponding Psys-Wrapper, which is typically assembler code. MISRA
 * cannot see this.
 */
osqFunc1 StatusType osqFunc2 osWaitEvent(EventMaskType mask)   /* PRQA S 1503 */
{
   /* CovComment 4:  Function: osWaitEvent */
   TaskType taskIndex = osOwnCcb->LockIsNotNeeded.ossActiveTaskIndex;
   
   OS_WE_ENTRY()
   COVER(0x0251)

   COVER(0x0252)
   COVER(0x0253)
   /* check call context */
   if ((osdValidCtx_WaitEvent & osOwnCcb->LockIsNotNeeded.ossCurrentContext) == 0)
   {
      COVER(0x0254)
      osAPIError(E_OS_CALLEVEL, osdErrWECallContext);
      OS_WE_EXIT()
      return E_OS_CALLEVEL;
   }
   ELSEWITHCOVER(0x0255)

   if (taskIndex >= osrNumberOfExtendedTasks)
   {
      COVER(0x0256)
      osAPIError(E_OS_ACCESS, osdErrWENotExtendedTask);
      OS_WE_EXIT()
      return E_OS_ACCESS;
   }
   ELSEWITHCOVER(0x0257)
   

   COVER(0x0258)
   /* check for task resources only system */
   if (osOwnCcb->LockIsNotNeeded.ossActiveTaskPrio != oskTcbHomePrio[taskIndex])
   {
      COVER(0x0259)
      osAPIError(E_OS_RESOURCE, osdErrWEResourcesOccupied);
      OS_WE_EXIT()
      return E_OS_RESOURCE;
   }
   ELSEWITHCOVER(0x025A)

   if (osCheckInterruptsEnabled() == 0)
   {
      COVER(0x025B)
      osAPIError(E_OS_DISABLEDINT, osdErrWEInterruptsDisabled);
      OS_WE_EXIT()
      return E_OS_DISABLEDINT;
   }
   ELSEWITHCOVER(0x025C)

   COVER(0x025D)
   /* KB begin osekHWosDisableLevel (overwritten) */
   osDisableLevel(); /* disable interrupts up to system level */
   /* KB end osekHWosDisableLevel */ /* (WaitEvent is only called from task level) */
   OS_WE_START_CRITICAL()
   /* KB begin osekHWosDisableTimProtInterrupt (overwritten) */
   /* KB end osekHWosDisableTimProtInterrupt */

   osTcbWaitEventMask[taskIndex]= mask;

   if ((osTcbSetEventMask[taskIndex] & mask) == 0)
   {
      COVER(0x025E)
      /* no expected event set, set task into waiting state */

      /* call hook routine for the waiting task */
#if osdPostTaskHook
      COVER(0x025F)
      osPostTaskHook();
#endif


      COVER(0x0260)
      /* change task state from ready to waiting */
      osTcbTaskState[taskIndex] = WAITING;

      osSchedRemoveRunningTask();

      /* for WaitEvent, osSchedRemoveRunningTask() always sets
       * ossStartDispatcher to osdTRUE
       * (same task is never running when reaching this point of code) */
      /* KB begin osekHWosEnableTimProtInterrupt (overwritten) */
      /* KB end osekHWosEnableTimProtInterrupt */
      OS_WE_END_CRITICAL()
      OS_WE_EXIT()
      /* KB begin osekHWosEnableLevel (overwritten) */
      osEnableLevel(); /* enable task level interrupt */
      /* KB end osekHWosEnableLevel */

      /* start dispatcher */
      OS_START_DISPATCH()
      /* KB begin osekHWosLocalDispatcher (overwritten) */
      ptrToCcb2->ossCallDispatcher = 1;
      /* KB end osekHWosLocalDispatcher */

      return E_OK;
   }
   
   /* KB begin osekHWosEnableTimProtInterrupt (overwritten) */
   /* KB end osekHWosEnableTimProtInterrupt */
   OS_WE_END_CRITICAL()
   OS_WE_EXIT()
   /* KB begin osekHWosEnableLevel (overwritten) */
   osEnableLevel(); /* enable task level interrupt */
   /* KB end osekHWosEnableLevel */

   return E_OK;
} /* END OF osWaitEvent */

#else 
/* KB begin osekHWosOsekEvntDummy (default) */
/* KB end osekHWosOsekEvntDummy */
#endif /* End of ((CC == ECC1) || (CC == ECC2)) && (osdNumberOfExtendedTasks > 0) */
/* KB begin osekEndOfCModule (overwritten) */
#pragma ghs section bss=default
#pragma ghs section data=default
#pragma ghs section sbss=default
#pragma ghs section sdata=default
#pragma ghs section text=default
#pragma ghs section rodata=default
#pragma ghs section rosdata=default
/* KB end osekEndOfCModule */

/* END OF MODULE osekevnt.c */

