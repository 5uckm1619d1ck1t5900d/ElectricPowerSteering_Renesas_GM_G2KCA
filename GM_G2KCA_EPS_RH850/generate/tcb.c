/* file: C:/_synergy/G2KCAT3_CZ8L9T/GM_G2KCA_EPS_RH850/generate/tcb.c */
/* automatically generated by genRH850.exe, Version: 1.06 */
/* Configuration file: C:/Users/cz8l9t/AppData/Local/Temp/Cfg_Gen-1484853116431-5/AutosarFiles_ValGen-1484860851174-0/Os_ECUC_4.0.3_2798538737394265774.arxml */
/* Generation time: Thu Jan 19 16:20:53 2017 */
/* Unlimited license CBD1400351 for Nexteer Automotive, Project License, EPS */
/* Implementation: RH850_P1M */
/* Version of general code: 9.01.04 */
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

#define osdVrmGenMajRelNum 1
#define osdVrmGenMinRelNum 6
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

#if defined USE_QUOTE_INCLUDES
 #include "Os.h"
#else
 #include <Os.h>
#endif

#if defined USE_QUOTE_INCLUDES
 #include "osekext.h"
#else
 #include <osekext.h>
#endif

#pragma ghs section bss=".os_bss"
#pragma ghs section data=".os_data"
#pragma ghs section sbss=".os_sbss"
#pragma ghs section sdata=".os_sdata"
#pragma ghs section text=".os_text"
#pragma ghs section rodata=".os_rodata"
#pragma ghs section rosdata=".os_rosdata"



/*--------------------------------------------------------------------------*/
/*    alarms                                                                */
/*--------------------------------------------------------------------------*/
      osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osAlarmTime[osdNumberOfAlarms+osdNumberOfScheduleTables];
      osqTcbRAM1 volatile osqTcbRAM2 osuint8 osqTcbRAM3 osAlarmActivated[osdNumberOfAlarms];

   /* Minimum Heap for Counter osSystemSWCounter */
   /* MISRA RULE 8.10 VIOLATION: This array is only referenced directly in this
    * unit but via a reference table also external. To avoid warnings from
    * some compilers it can't be static
    */
   osqTcbRAM1 osqTcbRAM2 osHeapElementType osqTcbRAM3 ososSystemSWCounterHeap[2];   /* PRQA S 1504 */
   /* Minimum Heap for Counter OsCounter */
   /* MISRA RULE 8.10 VIOLATION: This array is only referenced directly in this
    * unit but via a reference table also external. To avoid warnings from
    * some compilers it can't be static
    */
   osqTcbRAM1 osqTcbRAM2 osHeapElementType osqTcbRAM3 osOsCounterHeap[10];   /* PRQA S 1504 */

   osqROM0 osqROM1 const osqROM2 osAlarmIndexType osqROM3 oskAlarmHeapSize[2] = {
   2, /* osSystemSWCounter */
   10, /* OsCounter */
   };

   osqROM0 osqROM1 const osqROM2 osHeapType osqROM3 oskAlarmHeaps[2] = {
      {
         ososSystemSWCounterHeap,
         &osAlarmHeapCount[osSystemSWCounter]
      },
      {
         osOsCounterHeap,
         &osAlarmHeapCount[OsCounter]
      },
   };

      osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osAlarmCycleTime[osdNumberOfAlarms];

/* Schedule Tables */ 
osqROM0 osqROM1 const osqROM2 CounterType osqROM3 oskCounterOfST[osdNumberOfScheduleTables]={
   osSystemSWCounter, /* osSystemSchT */
};

osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskSTMaxAllowed[osdNumberOfScheduleTables]={
   1,   /* osdSTSyncNONE osSystemSchT */
};

osqROM0 osqROM1 const osqROM2 osSTOffsetType osqROM3 oskScheduleTableInitialOffset[osdNumberOfScheduleTables] = {
   1, /* osSystemSchT */
};

osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskAutostartScheduleTableOffset[osdNumberOfScheduleTables]={
   0,   /* osSystemSchT */
};

osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskPrecision[osdNumberOfScheduleTables]={
   0,
};

osqROM0 osqROM1 const osqROM2 osSTIndexType osqROM3 oskSTStartIndex[osdNumberOfScheduleTables]={
   0,
};

osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskScheduleTableAutoStart[osdNumberOfScheduleTables] =
{
    0x00, /* osSystemSchT*/
};
 osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskScheduleTableAutoStartType[osdNumberOfScheduleTables] =
 {
    osdScheduleTableAutostartNO, /* osSystemSchT*/
 };
osqRAM0 osqRAM1 volatile osqRAM2 osSTIndexType           osqRAM3 osSTCurrentIndex[osdNumberOfScheduleTables];
osqRAM0 osqRAM1 volatile osqRAM2 ScheduleTableStatusType osqRAM3 osSTState[osdNumberOfScheduleTables];
osqRAM0 osqRAM1 volatile osqRAM2 ScheduleTableType       osqRAM3 osSTNextTable[osdNumberOfScheduleTables];

osqFunc1 osSTReactionType osqFunc2 osSTWorkActions(GlobalTimeTickType* diff, osSTIndexType CurrentEP)
{
   switch (CurrentEP)
   {
      case 0: /* osSystemSchT */
         *diff= 1; /* no sync for this schedule table / this expiry point */
         return osdSTReact_InitialDelay;
      case 1: /* osSystemSchT */
         (void)osSysActivateTask(osSystemBasicTask);
         *diff= 1; /* no sync for this schedule table / this expiry point */
         return osdSTReact_Continue;
      case 2: /* osSystemSchT */
         (void)osSysSetEvent(osSystemExtendedTask,osSystemEvent);
         *diff=0;
         return osdSTReact_Stop;
      /* MISRA RULE 14.1 VIOLATION: return is not
       * reachable but this is the only way for prevent a compiler warning (3201) */
      default:
         osSysErrAssertFailed(osdErrWSUnknownAction)
         return osdSTReact_Stop;  /* PRQA S 3201 */
   }
}
/* Counters */

/* Holds all counter values. Use this array only for write access.
For read access use osGetCurrentTime(). Size = #Counter */
osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osCounter[2];

/* Holds the maximum allowed value of all counters. Size = #Counter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskCounterMaxAllowedValue[2]={
(TickType)10, /* osSystemSWCounter */
(TickType)2147483647, /* OsCounter */
};

/* Size = #Counter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskCounterInternalMaximumValue[2]={
(TickType)21, /* osSystemSWCounter */
(TickType)4294967295, /* OsCounter */
};

/* Size = #Counter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskCounterHalfrange[2]={
(TickType)10, /* osSystemSWCounter */
(TickType)2147483647, /* OsCounter */
};

/* Size = #Counter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskCounterTicksPerBase[2]={
(TickType)1, /* osSystemSWCounter */
(TickType)160000, /* OsCounter */
};

/* Defines the minimum time between two counter actions. Size = #Counter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskCounterMinCycle[2]={
(TickType)0, /* osSystemSWCounter */
(TickType)1, /* OsCounter */
};

/* The counters' reload values. Size = #Counter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskCounterReloadValue[2]={
(TickType)0, /* osSystemSWCounter */
(TickType)0, /* OsCounter */
};

/* The id of the core, this counter is assigned too. Size = #Counter */
osqROM0 osqROM1 const osqROM2 CoreIdType osqROM3 oskCounterCoreId[2]={
(CoreIdType)0, /* osSystemSWCounter */
(CoreIdType)0, /* OsCounter */
};

/* The half allowed maximum value of high resolution counter. Size = #HiResCounter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskCounterHiResMaxHardwareValueHalf[1]={ 0 };

/* Timer mask; n LSbs set, where n = timer bit width. Size = #HiResCounter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskHiResTimerBitMask[1]={ 0 };

/* The half allowed maximum value of high resolution timer. Size = #HiResCounter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskHWTimerSemiCount[1]={ 0 };

/* The minimum time between two high resolution timer interrupts. Size = #HiResCounter */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskMinTimeBetweenTimerIrqs[1]={ 0 };

/* Holds the last time of a high resolution timer interrupt. Size = #HiResCounter */
osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osLastHighResTimerIrq[1];

/* Holds the time of the next allowed high resolution interrupt. Size = #HiResCounter */
osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osNextAllowedTimerInt[1];

/* The id of a counter, the given alarm is assigned to. Size = #Alarms */
osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmCounterRef[10]={
(osuint8)OsCounter, /* Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
(osuint8)OsCounter, /* Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
(osuint8)OsCounter, /* Rte_Al_TE_Task_100ms_Appl10_0_100ms */
(osuint8)OsCounter, /* Rte_Al_TE_Task_100ms_Appl6_0_100ms */
(osuint8)OsCounter, /* Rte_Al_TE_Task_10ms_Appl10_0_10ms */
(osuint8)OsCounter, /* Rte_Al_TE_Task_10ms_Appl6_0_10ms */
(osuint8)OsCounter, /* Rte_Al_TE_Task_2ms_Appl10_0_2ms */
(osuint8)OsCounter, /* Rte_Al_TE_Task_2ms_Appl6_0_2ms */
(osuint8)OsCounter, /* Rte_Al_TE_Task_4ms_Appl10_0_4ms */
(osuint8)osSystemSWCounter, /* osSystemAlarm */
};
#pragma ghs section bss=".os_bss"
#pragma ghs section data=".os_data"
#pragma ghs section sbss=".os_sbss"
#pragma ghs section sdata=".os_sdata"
#pragma ghs section text=".os_text"
#pragma ghs section rodata=".os_rodata"
#pragma ghs section rosdata=".os_rosdata"

/* Start of invariant part */
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_0[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_1[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_2[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_3[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_4[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_5[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_6[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_7[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_8[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_9[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_10[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_11[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_12[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_13[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_14[4];
osqROM0 osqPTcbRAM1 volatile osqPTcbRAM2 TaskType osqPTcbRAM3 * osqROM1 const osqROM2 osqROM3 oskQActivationQueues[osdNumberOfPriorities] = 
{
      osQTaskActivation_0,
      osQTaskActivation_1,
      osQTaskActivation_2,
      osQTaskActivation_3,
      osQTaskActivation_4,
      osQTaskActivation_5,
      osQTaskActivation_6,
      osQTaskActivation_7,
      osQTaskActivation_8,
      osQTaskActivation_9,
      osQTaskActivation_10,
      osQTaskActivation_11,
      osQTaskActivation_12,
      osQTaskActivation_13,
      osQTaskActivation_14,
};
osqROM0 osqROM1 const osqROM2 osQEntryCountType osqROM3 oskQMaxActivations[osdNumberOfPriorities] =
   {
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      3,
   };
      osqTcbRAM1 volatile osqTcbRAM2 osActivationCountType osqTcbRAM3 osTcbActivationCount[osdNumberOfAllTasks];

osqTcbRAM1 osqTcbRAM2 osCtrlVarType osqTcbRAM3 osCtrlVarsCore0;
   osqTcbRAM1 volatile osqTcbRAM2 osTaskStateType osqTcbRAM3 osTcbTaskState[osdNumberOfAllTasks];
   osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osTcbActualPrio[osdNumberOfAllTasks];
   osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbORTIServiceId[osdNumberOfAllTasks];
     osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[osdNumberOfAllTasks];
   osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbInSystemFct[osdNumberOfAllTasks];


      osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osResSavedPrio[osdNumberOfAllResources];
      osqTcbRAM1 osqTcbRAM2 osResCounterType osqTcbRAM3 osResOccupationCounter[osdNumberOfAllResources];
      osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osResActualTask[osdNumberOfAllResources];


   osqTcbRAM1 volatile osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbWaitEventMask[osdNumberOfExtendedTasks];

   osqTcbRAM1 volatile osqTcbRAM2 ApplicationStateType osqTcbRAM3 osApplicationState [osdNumberOfApplications];

   osqTcbRAM1 volatile osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbSetEventMask[osdNumberOfExtendedTasks];

   osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osSemaphoreState[osdNumberOfSemaphores];
   osqTcbRAM1 volatile osqTcbRAM2 osSemaphoreType osqTcbRAM3 osTcbWaitForSemaphore[osdNumberOfExtendedTasks];
      osqTcbRAM1 volatile osqTcbRAM2 TaskType osqTcbRAM3 osSemaOwner[osdNumberOfSemaphores];

/* End of invariant part */
osqROM0 osqROM1 const osqROM2 osTaskFlagType osqROM3 oskTcbTaskFlags[osdNumberOfAllTasks] = {
 0,
 0,
 0,
 0,
 0,
 0,
 0,
 0,
 0,
 0,
 0,
 0,
 0,
 0,
};

osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskTcbReadyPrioMask[osdNumberOfAllTasks] = {
   0x00020000UL,
   0x80000000UL,
   0x40000000UL,
   0x20000000UL,
   0x10000000UL,
   0x08000000UL,
   0x04000000UL,
   0x02000000UL,
   0x01000000UL,
   0x00800000UL,
   0x00200000UL,
   0x00100000UL,
   0x00080000UL,
   0x00020000UL,
};

osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskTcbReadyPrioOffset[osdNumberOfAllTasks] = {
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
};
osqROM0 osqROM1 const osqROM2 osPrioType osqROM3 oskTcbHomePrio[osdNumberOfAllTasks] = {
   14,
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   10,
   11,
   12,
   14,
};

osqROM0 osqROM1 const osqROM2 osActivationCountType osqROM3 oskTcbAllowedActivations[osdNumberOfAllTasks] = {
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   2,
};

   osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osTcbLockedResource[osdNumberOfAllTasks];
 osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAutoStart[osdNumberOfAlarms] =
 {
    0x00, /* Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms*/
    0x00, /* Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms*/
    0x00, /* Rte_Al_TE_Task_100ms_Appl10_0_100ms*/
    0x00, /* Rte_Al_TE_Task_100ms_Appl6_0_100ms*/
    0x00, /* Rte_Al_TE_Task_10ms_Appl10_0_10ms*/
    0x00, /* Rte_Al_TE_Task_10ms_Appl6_0_10ms*/
    0x00, /* Rte_Al_TE_Task_2ms_Appl10_0_2ms*/
    0x00, /* Rte_Al_TE_Task_2ms_Appl6_0_2ms*/
    0x00, /* Rte_Al_TE_Task_4ms_Appl10_0_4ms*/
    0x00, /* osSystemAlarm*/
 };
 osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAutoStartType[osdNumberOfAlarms] =
 {
    osdAlarmAutostartNO, /* Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms*/
    osdAlarmAutostartNO, /* Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms*/
    osdAlarmAutostartNO, /* Rte_Al_TE_Task_100ms_Appl10_0_100ms*/
    osdAlarmAutostartNO, /* Rte_Al_TE_Task_100ms_Appl6_0_100ms*/
    osdAlarmAutostartNO, /* Rte_Al_TE_Task_10ms_Appl10_0_10ms*/
    osdAlarmAutostartNO, /* Rte_Al_TE_Task_10ms_Appl6_0_10ms*/
    osdAlarmAutostartNO, /* Rte_Al_TE_Task_2ms_Appl10_0_2ms*/
    osdAlarmAutostartNO, /* Rte_Al_TE_Task_2ms_Appl6_0_2ms*/
    osdAlarmAutostartNO, /* Rte_Al_TE_Task_4ms_Appl10_0_4ms*/
    osdAlarmAutostartNO, /* osSystemAlarm*/
 };
 osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskTcbAutoStart[osdNumberOfAllTasks] =
 {
    0x00, /* osSystemExtendedTask*/
    0x01, /* Task_InitBsw_Appl10*/
    0x00, /* Task_Init_Appl10*/
    0x00, /* Task_Init_Appl6*/
    0x00, /* Task_4msBsw_Appl10*/
    0x00, /* Task_2ms_Appl10*/
    0x00, /* Task_2ms_Appl6*/
    0x00, /* Task_4ms_Appl10*/
    0x00, /* Task_10ms_Appl10*/
    0x00, /* Task_10ms_Appl6*/
    0x00, /* Task_10msBsw_Appl10*/
    0x00, /* Task_100ms_Appl10*/
    0x00, /* Task_100ms_Appl6*/
    0x00, /* osSystemBasicTask*/
 };
/* static alarm time */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmTime[osdNumberOfAlarms] = {
   (TickType)0UL, /* Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
   (TickType)0UL, /* Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
   (TickType)0UL, /* Rte_Al_TE_Task_100ms_Appl10_0_100ms */
   (TickType)0UL, /* Rte_Al_TE_Task_100ms_Appl6_0_100ms */
   (TickType)0UL, /* Rte_Al_TE_Task_10ms_Appl10_0_10ms */
   (TickType)0UL, /* Rte_Al_TE_Task_10ms_Appl6_0_10ms */
   (TickType)0UL, /* Rte_Al_TE_Task_2ms_Appl10_0_2ms */
   (TickType)0UL, /* Rte_Al_TE_Task_2ms_Appl6_0_2ms */
   (TickType)0UL, /* Rte_Al_TE_Task_4ms_Appl10_0_4ms */
   (TickType)0UL, /* osSystemAlarm */
};
/* static cycle time */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmCycleTime[osdNumberOfAlarms] = {
   (TickType)0UL, /* Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
   (TickType)0UL, /* Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
   (TickType)0UL, /* Rte_Al_TE_Task_100ms_Appl10_0_100ms */
   (TickType)0UL, /* Rte_Al_TE_Task_100ms_Appl6_0_100ms */
   (TickType)0UL, /* Rte_Al_TE_Task_10ms_Appl10_0_10ms */
   (TickType)0UL, /* Rte_Al_TE_Task_10ms_Appl6_0_10ms */
   (TickType)0UL, /* Rte_Al_TE_Task_2ms_Appl10_0_2ms */
   (TickType)0UL, /* Rte_Al_TE_Task_2ms_Appl6_0_2ms */
   (TickType)0UL, /* Rte_Al_TE_Task_4ms_Appl10_0_4ms */
   (TickType)0UL, /* osSystemAlarm */
};
/* task to activate or to receive the event  */
osqROM0 osqROM1 const osqROM2 TaskType osqROM3 oskAlarmTask[osdNumberOfAlarms] = {
   Task_10msBsw_Appl10, /* Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
   Task_4msBsw_Appl10, /* Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
   Task_100ms_Appl10, /* Rte_Al_TE_Task_100ms_Appl10_0_100ms */
   Task_100ms_Appl6, /* Rte_Al_TE_Task_100ms_Appl6_0_100ms */
   Task_10ms_Appl10, /* Rte_Al_TE_Task_10ms_Appl10_0_10ms */
   Task_10ms_Appl6, /* Rte_Al_TE_Task_10ms_Appl6_0_10ms */
   Task_2ms_Appl10, /* Rte_Al_TE_Task_2ms_Appl10_0_2ms */
   Task_2ms_Appl6, /* Rte_Al_TE_Task_2ms_Appl6_0_2ms */
   Task_4ms_Appl10, /* Rte_Al_TE_Task_4ms_Appl10_0_4ms */
   INVALID_TASK, /* osSystemAlarm */
};
/* the event to set */
osqROM0 osqROM1 const osqROM2 EventMaskType osqROM3 oskAlarmEvent[osdNumberOfAlarms] = {
   0, /* alarmaction != SETEVENT */
   0, /* alarmaction != SETEVENT */
   0, /* alarmaction != SETEVENT */
   0, /* alarmaction != SETEVENT */
   0, /* alarmaction != SETEVENT */
   0, /* alarmaction != SETEVENT */
   0, /* alarmaction != SETEVENT */
   0, /* alarmaction != SETEVENT */
   0, /* alarmaction != SETEVENT */
   0, /* alarmaction != SETEVENT */
};
/* counter ID to increment */
osqROM0 osqROM1 const osqROM2 CounterType osqROM3 oskAlarmIncrementCounterID[osdNumberOfAlarms] = {
   0, /* alarmaction != INCREMENTCOUNTER */
   0, /* alarmaction != INCREMENTCOUNTER */
   0, /* alarmaction != INCREMENTCOUNTER */
   0, /* alarmaction != INCREMENTCOUNTER */
   0, /* alarmaction != INCREMENTCOUNTER */
   0, /* alarmaction != INCREMENTCOUNTER */
   0, /* alarmaction != INCREMENTCOUNTER */
   0, /* alarmaction != INCREMENTCOUNTER */
   0, /* alarmaction != INCREMENTCOUNTER */
   osSystemSWCounter, /* osSystemAlarm */
};
osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAction[osdNumberOfAlarms] = {
  osdAlarmActionActivateTask, /* Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
  osdAlarmActionActivateTask, /* Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
  osdAlarmActionActivateTask, /* Rte_Al_TE_Task_100ms_Appl10_0_100ms */
  osdAlarmActionActivateTask, /* Rte_Al_TE_Task_100ms_Appl6_0_100ms */
  osdAlarmActionActivateTask, /* Rte_Al_TE_Task_10ms_Appl10_0_10ms */
  osdAlarmActionActivateTask, /* Rte_Al_TE_Task_10ms_Appl6_0_10ms */
  osdAlarmActionActivateTask, /* Rte_Al_TE_Task_2ms_Appl10_0_2ms */
  osdAlarmActionActivateTask, /* Rte_Al_TE_Task_2ms_Appl6_0_2ms */
  osdAlarmActionActivateTask, /* Rte_Al_TE_Task_4ms_Appl10_0_4ms */
  osdAlarmActionIncrementCounter, /* osSystemAlarm */
};
/* Resources */

#if ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
osqROM0 osqROM1 const osqROM2 osResAccessMaskType osqROM3 oskResAccessMask[osdNumberOfAllResources][1]=
{
/* sequence of taskNumbers (!not priorities) */
   {    0x00200000UL,   } /* RES_SCHEDULER*/
  ,{    0x80000000UL,   } /* osSystemResource*/
};

osqROM0 osqROM1 const osqROM2 osPrioType osqROM3 oskResCeilingPrio[osdNumberOfAllResources]=
{
   (osPrioType)9, /* RES_SCHEDULER*/
   (osPrioType)13, /* osSystemResource*/
};

osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResCeilingPrioMask[osdNumberOfTaskResources]=
{
   0x00400000UL,
   0x00040000UL,
};

osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResCeilingPrioOffset[osdNumberOfTaskResources]=
{
   0x00,
   0x00,
};
#endif /* ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))) */

   osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osResNextLockedResource[osdNumberOfAllResources];
/* Alarms */

/* Restart task for each application */
osqROM0 osqROM1 const osqROM2 TaskType osqROM3 oskRestartTask[osdNumberOfApplications]=
{
   osdNoActiveTask,   /* Appl0 */
   osdNoActiveTask,   /* Appl10 */
   osdNoActiveTask,   /* Appl6 */
   osdNoActiveTask,   /* osSystemApplicationCore0 */
};

/* Owner application for each task */
/* applications (bit mask) with access rights to the tasks */
/* MISRA RULE 8.10 VIOLATION: This array is only referenced directly in this
 * unit but via a reference table also external. To avoid warnings from
 * some compilers it can't be static
 */
osqROM0 osqROM1 const osqROM2 ApplAccessMaskType osqROM3 oskApplTaskAccess[osdNumberOfAllTasks]=   /* PRQA S 1504 */
{
   0x00000008,   /* osSystemExtendedTask */
   0x0000000a,   /* Task_InitBsw_Appl10 */
   0x0000000e,   /* Task_Init_Appl10 */
   0x0000000e,   /* Task_Init_Appl6 */
   0x0000000e,   /* Task_4msBsw_Appl10 */
   0x0000000e,   /* Task_2ms_Appl10 */
   0x0000000e,   /* Task_2ms_Appl6 */
   0x0000000e,   /* Task_4ms_Appl10 */
   0x0000000e,   /* Task_10ms_Appl10 */
   0x0000000e,   /* Task_10ms_Appl6 */
   0x0000000e,   /* Task_10msBsw_Appl10 */
   0x0000000e,   /* Task_100ms_Appl10 */
   0x0000000e,   /* Task_100ms_Appl6 */
   0x00000008,   /* osSystemBasicTask */
};

/* Owner application for each ISR */
/* applications (bit mask) with access rights to the ISRs */
/* MISRA RULE 8.10 VIOLATION: This array is only referenced directly in this
 * unit but via a reference table also external. To avoid warnings from
 * some compilers it can't be static
 */
osqROM0 osqROM1 const osqROM2 ApplAccessMaskType osqROM3 oskApplISRAccess[osdNumberOfCat2ISRs]=  /* PRQA S 1504 */
{
   0x00000004,   /* CanIsrGlobalStatus */
   0x00000004,   /* CanIsrRxFifo */
   0x00000004,   /* CanIsrStatus_0 */
   0x00000004,   /* CanIsrStatus_1 */
   0x00000004,   /* CanIsrStatus_2 */
   0x00000004,   /* CanIsrTx_0 */
   0x00000004,   /* CanIsrTx_1 */
   0x00000004,   /* CanIsrTx_2 */
   0x00000002,   /* MCU_ECM_EIC_CAT2_ISR */
   0x00000001,   /* SPI_CSIG0_TIC_CAT2_ISR */
   0x00000001,   /* SPI_CSIG0_TIRE_CAT2_ISR */
   0x00000001,   /* SPI_CSIG0_TIR_CAT2_ISR */
   0x00000001,   /* SPI_CSIH0_TIC_CAT2_ISR */
   0x00000001,   /* SPI_CSIH0_TIRE_CAT2_ISR */
   0x00000001,   /* SPI_CSIH0_TIR_CAT2_ISR */
   0x00000001,   /* SPI_CSIH2_TIC_CAT2_ISR */
   0x00000001,   /* SPI_CSIH2_TIRE_CAT2_ISR */
   0x00000001,   /* SPI_CSIH2_TIR_CAT2_ISR */
   0x00000002,   /* SnsrMeasStrtIrq */
   0x00000008,   /* osOstmInterrupt_c0 */
   0x00000008,   /* osSystemCat2ISR */
};

/* Owner application for each resource */
/* applications (bit mask) with access rights to the resources */
/* MISRA RULE 8.10 VIOLATION: This array is only referenced directly in this
 * unit but via a reference table also external. To avoid warnings from
 * some compilers it can't be static
 */
osqROM0 osqROM1 const osqROM2 ApplAccessMaskType osqROM3 oskApplResourceAccess[osdNumberOfAllResources]=  /* PRQA S 1504 */
{
   0x0000000a,   /* RES_SCHEDULER */
   0x00000008,   /* osSystemResource */
};

/* Owner application for each alarm */
/* MISRA RULE 8.10 VIOLATION: In some configurations this array is only referenced in this
 * unit, adding code to make it static in those cases would increase code complexity too much.
 */
osqROM0 osqROM1 const osqROM2 ApplicationType osqROM3 oskAlarmToAppl[osdNumberOfAlarms] = /* PRQA S 1504 */
{
   Appl10,   /* Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
   Appl10,   /* Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
   Appl10,   /* Rte_Al_TE_Task_100ms_Appl10_0_100ms */
   Appl6,   /* Rte_Al_TE_Task_100ms_Appl6_0_100ms */
   Appl10,   /* Rte_Al_TE_Task_10ms_Appl10_0_10ms */
   Appl6,   /* Rte_Al_TE_Task_10ms_Appl6_0_10ms */
   Appl10,   /* Rte_Al_TE_Task_2ms_Appl10_0_2ms */
   Appl6,   /* Rte_Al_TE_Task_2ms_Appl6_0_2ms */
   Appl10,   /* Rte_Al_TE_Task_4ms_Appl10_0_4ms */
   osSystemApplicationCore0,   /* osSystemAlarm */
};

/* applications (bit mask) with access rights to the alarms */
/* MISRA RULE 8.10 VIOLATION: This array is only referenced directly in this
 * unit but via a reference table also external. To avoid warnings from
 * some compilers it can't be static
 */
osqROM0 osqROM1 const osqROM2 ApplAccessMaskType osqROM3 oskApplAlarmAccess[osdNumberOfAlarms]=  /* PRQA S 1504 */
{
   0x0000000a,   /* Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
   0x0000000a,   /* Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
   0x0000000a,   /* Rte_Al_TE_Task_100ms_Appl10_0_100ms */
   0x0000000e,   /* Rte_Al_TE_Task_100ms_Appl6_0_100ms */
   0x0000000a,   /* Rte_Al_TE_Task_10ms_Appl10_0_10ms */
   0x0000000e,   /* Rte_Al_TE_Task_10ms_Appl6_0_10ms */
   0x0000000a,   /* Rte_Al_TE_Task_2ms_Appl10_0_2ms */
   0x0000000e,   /* Rte_Al_TE_Task_2ms_Appl6_0_2ms */
   0x0000000a,   /* Rte_Al_TE_Task_4ms_Appl10_0_4ms */
   0x00000008,   /* osSystemAlarm */
};

/* Owner application for each counter */
/* MISRA RULE 8.10 VIOLATION: This array is only referenced directly in this
 * unit but via a reference table also external. To avoid warnings from
 * some compilers it can't be static
 */
osqROM0 osqROM1 const osqROM2 ApplicationType osqROM3 oskCounterToAppl[osdNumberOfCounters] = /* PRQA S 1504 */
{
   osSystemApplicationCore0,   /* osSystemSWCounter */
   Appl10,   /* OsCounter */
};

/* applications (bit mask) with access rights to the counters */
/* MISRA RULE 8.10 VIOLATION: This array is only referenced directly in this
 * unit but via a reference table also external. To avoid warnings from
 * some compilers it can't be static
 */
osqROM0 osqROM1 const osqROM2 ApplAccessMaskType osqROM3 oskApplCounterAccess[osdNumberOfCounters]=  /* PRQA S 1504 */
{
   0x00000008,   /* osSystemSWCounter */
   0x0000000a,   /* OsCounter */
};

/* Owner application for each schedule table */
/* MISRA RULE 8.10 VIOLATION: In some configurations this array is only referenced in this
 * unit, adding code to make it static in those cases would increase code complexity too much.
 */
osqROM0 osqROM1 const osqROM2 ApplicationType osqROM3 oskScheduleTableToAppl[osdNumberOfScheduleTables] =  /* PRQA S 1504 */
{
   osSystemApplicationCore0,   /* osSystemSchT */
};

/* applications (bit mask) with access rights to the schedule tables */
/* MISRA RULE 8.10 VIOLATION: This array is only referenced directly in this
 * unit but via a reference table also external. To avoid warnings from
 * some compilers it can't be static
 */
osqROM0 osqROM1 const osqROM2 ApplAccessMaskType osqROM3 oskApplScheduleTableAccess[osdNumberOfScheduleTables]={ /* PRQA S 1504 */
   0x00000008,   /* osSystemSchT */
};

osqROM0 ApplAccessMaskType osqROM1 const *osqROM2 const osqROM3 oskApplObjectAccess[osdNumberOfObjectTypes] =
{
   oskApplTaskAccess,
   oskApplISRAccess,
   oskApplAlarmAccess,
   oskApplResourceAccess,
   oskApplCounterAccess,
   oskApplScheduleTableAccess
};

osqROM0 osqROM1 const osqROM2 osuint16 osqROM3 oskObjectCount[osdNumberOfObjectTypes]=
{
   osdNumberOfAllTasks,
   osdNumberOfCat2ISRs,
   osdNumberOfAlarms,
   osdNumberOfAllResources,
   osdNumberOfCounters,
   osdNumberOfScheduleTables
};

osqROM0 ApplicationType osqROM1 const *osqROM2 const osqROM3 oskObjectToAppl[osdNumberOfObjectTypes] =
{
   osConfigBlock.acTaskToAppl,
   osConfigBlock.acIsrToAppl,
   oskAlarmToAppl,
   osdNULL,
   oskCounterToAppl,
   oskScheduleTableToAppl
};

   osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osIcbLockedResource[osdNumberOfCat2ISRs];

/* END OF C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\tcb.c */

#pragma ghs section bss=default
#pragma ghs section data=default
#pragma ghs section sbss=default
#pragma ghs section sdata=default
#pragma ghs section text=default
#pragma ghs section rodata=default
#pragma ghs section rosdata=default

#pragma ghs section bss=default
#pragma ghs section data=default
#pragma ghs section sbss=default
#pragma ghs section sdata=default
#pragma ghs section text=default
#pragma ghs section rodata=default
#pragma ghs section rosdata=default

