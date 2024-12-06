/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2012 - 2016 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Dem
 *           Program: GM Global A / FR (MSR_Gm_SLP2)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701311
 *    License Scope : The usage is restricted to CBD1400351_D03
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_Lcfg.c
 *   Generation Time: 2016-09-23 11:27:59
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1400351_D03
 *      Tool Version: DaVinci Configurator (beta) 5.10.26 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/



/* configuration, interrupt handling implementations differ from the
 * source identification define used here. The naming
 * schemes for those files can be taken from this list:
 *
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE */
#define DEM_LCFG_SOURCE


/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */                                      /* Maximum '#if...' nesting exceeds 8 levels - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */                                      /* Number of macro definitions exceeds 1024 - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0779 EOF */ /* MD_DEM_5.1 */                                          /* Identifier does not differ in 32 significant characters -- caused by Autosar algorithm for unique symbolic names. */
/* PRQA S 0612 EOF */ /* MD_DEM_1.1_612 */                                      /* The size of an object exceeds 32767 bytes - program is non-conforming -- caused by large user configration. */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "Dem.h"
#if (DEM_CFG_USE_NVM == STD_ON)
# include "NvM.h"                                                           /* get: symbolic names for NvM block IDs */
#endif
#if (DEM_CFG_SUPPORT_J1939 == STD_ON)
# include "J1939Nm.h"                                                       /* get: symbolic names for J1939Nm node IDs */
#endif
#if (DEM_CFG_USE_RTE == STD_ON)
/* DEM used with RTE */
# include "Rte_Dem.h"
#else
#endif


/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Dem_C_CallbackDtcStatusChanged
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_DtcStatusChangedFPtrType, DEM_CONST) Dem_C_CallbackDtcStatusChanged[1] = {
  /* Index    CallbackDtcStatusChanged                 */
  /*     0 */Rte_Call_CBStatusDTC_1_DTCStatusChanged 
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DataCollectionTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_DataCollectionTable
  \details
  Element                                Description
  IdNumber                           
  CollectionSize                     
  DataElementTableCol2ElmtIndEndIdx      the end index of the 0:n relation pointing to Dem_C_DataElementTableCol2ElmtInd
  DataElementTableCol2ElmtIndStartIdx    the start index of the 0:n relation pointing to Dem_C_DataElementTableCol2ElmtInd
  MaskedBits                             contains bitcoded the boolean data of Dem_C_DataElementTableCol2ElmtIndUsedOfDataCollectionTable, Dem_C_UpdateOfDataCollectionTable
  StorageKind                        
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DataCollectionTableType, DEM_CONST) Dem_C_DataCollectionTable[20] = {
    /* Index    IdNumber  CollectionSize  DataElementTableCol2ElmtIndEndIdx                                DataElementTableCol2ElmtIndStartIdx                                MaskedBits  StorageKind                     Referrable Keys */
  { /*     0 */  0x0000U,             0U, DEM_C_NO_DATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE, DEM_C_NO_DATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE,      0x00U, DEM_CFG_EREC_TYPE_GLOBAL },  /* [#NoDataCollectionConfigured] */
  { /*     1 */  0x4016U,             2U,                                                              1U,                                                                0U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid4016, Ffm:DemFreezeFrameClass] */
  { /*     2 */  0x401BU,             1U,                                                              2U,                                                                1U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid401B, Ffm:DemFreezeFrameClass] */
  { /*     3 */  0x4074U,             2U,                                                              3U,                                                                2U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid4074, Ffm:DemFreezeFrameClass] */
  { /*     4 */  0x40ACU,             2U,                                                              4U,                                                                3U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid40AC, Ffm:DemFreezeFrameClass] */
  { /*     5 */  0x40ADU,             1U,                                                              5U,                                                                4U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid40AD, Ffm:DemFreezeFrameClass] */
  { /*     6 */  0x40BCU,             2U,                                                              6U,                                                                5U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid40BC, Ffm:DemFreezeFrameClass] */
  { /*     7 */  0x40BDU,             1U,                                                              7U,                                                                6U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid40BD, Ffm:DemFreezeFrameClass] */
  { /*     8 */  0x41D3U,             2U,                                                              8U,                                                                7U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid41D3, Ffm:DemFreezeFrameClass] */
  { /*     9 */  0x41D4U,             2U,                                                              9U,                                                                8U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid41D4, Ffm:DemFreezeFrameClass] */
  { /*    10 */  0x41D5U,             1U,                                                             10U,                                                                9U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid41D5, Ffm:DemFreezeFrameClass] */
  { /*    11 */  0x41D6U,             1U,                                                             11U,                                                               10U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid41D6, Ffm:DemFreezeFrameClass] */
  { /*    12 */  0x41D7U,             2U,                                                             12U,                                                               11U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid41D7, Ffm:DemFreezeFrameClass] */
  { /*    13 */  0x41D9U,             2U,                                                             13U,                                                               12U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid41D9, Ffm:DemFreezeFrameClass] */
  { /*    14 */  0x43D0U,             1U,                                                             14U,                                                               13U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid43D0, Ffm:DemFreezeFrameClass] */
  { /*    15 */  0x446FU,             2U,                                                             15U,                                                               14U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid446F, Ffm:DemFreezeFrameClass] */
  { /*    16 */  0x8002U,             1U,                                                             16U,                                                               15U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid8002, Ffm:DemFreezeFrameClass] */
  { /*    17 */  0x8078U,             1U,                                                             17U,                                                               16U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPid8078, Ffm:DemFreezeFrameClass] */
  { /*    18 */  0xC000U,             4U,                                                             18U,                                                               17U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPidC000, Ffm:DemFreezeFrameClass] */
  { /*    19 */  0xC050U,             5U,                                                             19U,                                                               18U,      0x02U, DEM_CFG_EREC_TYPE_USER   }   /* [#DidPidC050, Ffm:DemFreezeFrameClass] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DataCollectionTableFfm2CollInd
**********************************************************************************************************************/
/** 
  \var    Dem_C_DataCollectionTableFfm2CollInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_C_DataCollectionTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DataCollectionTableFfm2CollIndType, DEM_CONST) Dem_C_DataCollectionTableFfm2CollInd[19] = {
  /* Index    DataCollectionTableFfm2CollInd      Referrable Keys */
  /*     0 */                            16U,  /* [Ffm:DemFreezeFrameClass] */
  /*     1 */                            14U,  /* [Ffm:DemFreezeFrameClass] */
  /*     2 */                            17U,  /* [Ffm:DemFreezeFrameClass] */
  /*     3 */                             6U,  /* [Ffm:DemFreezeFrameClass] */
  /*     4 */                             7U,  /* [Ffm:DemFreezeFrameClass] */
  /*     5 */                            18U,  /* [Ffm:DemFreezeFrameClass] */
  /*     6 */                             1U,  /* [Ffm:DemFreezeFrameClass] */
  /*     7 */                            19U,  /* [Ffm:DemFreezeFrameClass] */
  /*     8 */                             2U,  /* [Ffm:DemFreezeFrameClass] */
  /*     9 */                             5U,  /* [Ffm:DemFreezeFrameClass] */
  /*    10 */                             3U,  /* [Ffm:DemFreezeFrameClass] */
  /*    11 */                             4U,  /* [Ffm:DemFreezeFrameClass] */
  /*    12 */                            13U,  /* [Ffm:DemFreezeFrameClass] */
  /*    13 */                             8U,  /* [Ffm:DemFreezeFrameClass] */
  /*    14 */                             9U,  /* [Ffm:DemFreezeFrameClass] */
  /*    15 */                            12U,  /* [Ffm:DemFreezeFrameClass] */
  /*    16 */                            10U,  /* [Ffm:DemFreezeFrameClass] */
  /*    17 */                            15U,  /* [Ffm:DemFreezeFrameClass] */
  /*    18 */                            11U   /* [Ffm:DemFreezeFrameClass] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DataElementTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_DataElementTable
  \details
  Element         Description
  ElementKind     see #define DEM_CFG_DATA_FROM_... to interpret results
  ElementSize     Size of data element in Byte.
  ReadDataFunc    C-function for getting the data. Its signature depends on ElementKind: With value 28U or 30U use: Std_ReturnType (*)(uint8* Buffer); With value 29U or 31U use: Std_ReturnType (*)(uint8* Buffer, uint16 EventId);.
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DataElementTableType, DEM_CONST) Dem_C_DataElementTable[20] = {
    /* Index    ElementKind  ElementSize  ReadDataFunc                                                                                                        Referrable Keys */
  { /*     0 */         32U,          0U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                         },  /* [#NoDataElementConfigured] */
  { /*     1 */         28U,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_IgnCycCntr_ReadData          },  /* [#IgnCycCntr, DidPid4016] */
  { /*     2 */         28U,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EcuIntT_ReadData             },  /* [#EcuIntT, DidPid401B] */
  { /*     3 */         28U,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_SteerWhlAg_ReadData          },  /* [#SteerWhlAg, DidPid4074] */
  { /*     4 */         28U,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_SteerInpTq_ReadData          },  /* [#SteerInpTq, DidPid40AC] */
  { /*     5 */         28U,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EpdMotOvldProtnCntr_ReadData },  /* [#EpdMotOvldProtnCntr, DidPid40AD] */
  { /*     6 */         28U,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EngSpd_ReadData              },  /* [#EngSpd, DidPid40BC] */
  { /*     7 */         28U,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_VehSpd_ReadData              },  /* [#VehSpd, DidPid40BD] */
  { /*     8 */         28U,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EpsMotCurr_ReadData          },  /* [#EpsMotCurr, DidPid41D3] */
  { /*     9 */         28U,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EpsMotCurrFb_ReadData        },  /* [#EpsMotCurrFb, DidPid41D4] */
  { /*    10 */         28U,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EpsTqOvrlSts_ReadData        },  /* [#EpsTqOvrlSts, DidPid41D5] */
  { /*    11 */         28U,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EpsAgOvrlSts_ReadData        },  /* [#EpsAgOvrlSts, DidPid41D6] */
  { /*    12 */         28U,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EpsTqOvrlReq_ReadData        },  /* [#EpsTqOvrlReq, DidPid41D7] */
  { /*    13 */         28U,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_SteerOutpTq_ReadData         },  /* [#SteerOutpTq, DidPid41D9] */
  { /*    14 */         28U,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EpsStopStrtSts_ReadData      },  /* [#EpsStopStrtSts, DidPid43D0] */
  { /*    15 */         28U,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EpsApaAgOvrlReq_ReadData     },  /* [#EpsApaAgOvrlReq, DidPid446F] */
  { /*    16 */         28U,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_SysPwrMod_ReadData           },  /* [#SysPwrMod, DidPid8002] */
  { /*    17 */         28U,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_BattVltgEcu_ReadData         },  /* [#BattVltgEcu, DidPid8078] */
  { /*    18 */         28U,          4U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_SplrIntDtcInfo_ReadData      },  /* [#SplrIntDtcInfo, DidPidC000] */
  { /*    19 */         28U,          5U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_TiIgnOn_ReadData             }   /* [#TiIgnOn, DidPidC050] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DataElementTableCol2ElmtInd
**********************************************************************************************************************/
/** 
  \var    Dem_C_DataElementTableCol2ElmtInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_C_DataElementTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DataElementTableCol2ElmtIndType, DEM_CONST) Dem_C_DataElementTableCol2ElmtInd[19] = {
  /* Index    DataElementTableCol2ElmtInd      Referrable Keys */
  /*     0 */                          1U,  /* [DidPid4016] */
  /*     1 */                          2U,  /* [DidPid401B] */
  /*     2 */                          3U,  /* [DidPid4074] */
  /*     3 */                          4U,  /* [DidPid40AC] */
  /*     4 */                          5U,  /* [DidPid40AD] */
  /*     5 */                          6U,  /* [DidPid40BC] */
  /*     6 */                          7U,  /* [DidPid40BD] */
  /*     7 */                          8U,  /* [DidPid41D3] */
  /*     8 */                          9U,  /* [DidPid41D4] */
  /*     9 */                         10U,  /* [DidPid41D5] */
  /*    10 */                         11U,  /* [DidPid41D6] */
  /*    11 */                         12U,  /* [DidPid41D7] */
  /*    12 */                         13U,  /* [DidPid41D9] */
  /*    13 */                         14U,  /* [DidPid43D0] */
  /*    14 */                         15U,  /* [DidPid446F] */
  /*    15 */                         16U,  /* [DidPid8002] */
  /*    16 */                         17U,  /* [DidPid8078] */
  /*    17 */                         18U,  /* [DidPidC000] */
  /*    18 */                         19U   /* [DidPidC050] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DebounceTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_DebounceTable
  \details
  Element                   Description
  DecrementStepSize         (-1) * DemDebounceCounterDecrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  FailedThreshold           DemDebounceCounterFailedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  IncrementStepSize         DemDebounceCounterIncrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  PassedThreshold           DemDebounceCounterPassedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  EventDebounceAlgorithm    Used DemEventParameter/DemEventClass/DemDebounceAlgorithmClass
  MaskedBits                contains bitcoded the boolean data of Dem_C_DebounceContinuousOfDebounceTable, Dem_C_EventDebounceBehaviorOfDebounceTable, Dem_C_JumpDownOfDebounceTable, Dem_C_JumpUpOfDebounceTable, Dem_C_StorageOfDebounceTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DebounceTableType, DEM_CONST) Dem_C_DebounceTable[2] = {
    /* Index    DecrementStepSize  FailedThreshold  IncrementStepSize  PassedThreshold  EventDebounceAlgorithm                                                    MaskedBits        Referrable Keys */
  { /*     0 */                -1,             127,                 1,            -128, DEM_C_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x06U },  /* [CtrlrComChassisExpBusOff, CtrlrComHiSpdBusOff, DevPwrVltgOverMaxThd, DevPwrVltgUnderMinThd, DevPwrVltgUnderThd, EcuHwPrfmc, EcuSwPrfmcCalDataSetNotProgd, ElecSteerMotCirc, ElecSteerMotPosSnsrCir, FLS_E_COMPARE_FAILED, FLS_E_ERASE_FAILED, FLS_E_READ_FAILED, FLS_E_READ_FAILED_DED, FLS_E_WRITE_FAILED, InvldDataRxdFromBodtCtrlMod, InvldDataRxdFromElecBrkCtrlMod, InvldDataRxdFromElecBrkCtrlModChassisExp, InvldDataRxdFromEngCtrlMod, InvldDataRxdFromFrntCameraMod, InvldDataRxdFromParkAssiCtrlMod, InvldDataRxdFromTrsmCtrlMod, LostComWithBodyCtrlMod, LostComWithElecBrkCtrlMod, LostComWithElecBrkCtrlModChassisExp, LostComWithEngCtrlMod, LostComWithFrntCameraCtrlMod, LostComWithParkAssiCtrlMod, LostComWithTrsmCtrlMod, MCU_E_CLM_SELFDIAG_FAILURE, MCU_E_CLOCK_FAILURE, MCU_E_CVM_SELFDIAG_FAILURE, MCU_E_ECM_SELFDIAG_FAILURE, MCU_E_LOCKSTEP_SELFDIAG_FAILURE, MCU_E_WRITE_TIMEOUT_FAILURE, NVM_E_INTEGRITY_FAILED, NVM_E_LOSS_OF_REDUNDANCY, NVM_E_QUEUE_OVERFLOW, NVM_E_REQ_FAILED, NVM_E_VERIFY_FAILED, NVM_E_WRITE_PROTECTED, NVM_E_WRONG_BLOCK_ID, PORT_E_WRITE_TIMEOUT_FAILURE, SPI_E_DATA_TX_TIMEOUT_FAILURE, SPI_E_HARDWARE_ERROR, SteerFailrMtgtnLvl1LimpHomeMod, SteerFailrMtgtnLvl2LimpOver, SteerFailrMtgtnLvl3FadeOut, SteerWheelAgSnsrCalNorPrfmd, SteerWheelAgSnsrHwFlt, SteerWheelAgSnsrPlausly, SteerWhlTqInpSnsr, SteerWhlTqInpSnsrCalNoLrnd, SysThermErrTHi, WDG_E_DISABLE_REJECTED, WDG_E_MODE_FAILED, WDG_E_READBACK_FAILURE, WDG_E_TRIGGER_TIMEOUT] */
  { /*     1 */                 0,               0,                 0,               0, DEM_C_DEM_CFG_DEBOUNCETYPE_INVALID_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x00U }   /* [#EVENT_INVALID] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DtcTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_DtcTable
  \details
  Element    Description
  UdsDtc 
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DtcTableType, DEM_CONST) Dem_C_DtcTable[33] = {
    /* Index    UdsDtc              Referrable Keys */
  { /*     0 */ 0x00FFFFFFUL },  /* [#NoUdsDtcConfigured, #NoObdDtcConfigured, #NoJ1939DtcConfigured] */
  { /*     1 */ 0x0044604BUL },  /* [SteerWheelAgSnsrCalNorPrfmdClass] */
  { /*     2 */ 0x00417654UL },  /* [SysThermErrTHiClass] */
  { /*     3 */ 0x00C07700UL },  /* [CtrlrComChassisExpBusOffClass] */
  { /*     4 */ 0x00C07300UL },  /* [CtrlrComHiSpdBusOffClass] */
  { /*     5 */ 0x00480011UL },  /* [DevPwrVltgOverMaxThdClass] */
  { /*     6 */ 0x00480003UL },  /* [DevPwrVltgUnderThdClass] */
  { /*     7 */ 0x00456D00UL },  /* [EcuHwPrfmcClass] */
  { /*     8 */ 0x00456E42UL },  /* [EcuSwPrfmcCalDataSetNotProgdClass] */
  { /*     9 */ 0x00447500UL },  /* [ElecSteerMotCircClass] */
  { /*    10 */ 0x00447A00UL },  /* [ElecSteerMotPosSnsrCirClass] */
  { /*    11 */ 0x00C42271UL },  /* [InvldDataRxdFromBodtCtrlModClass] */
  { /*    12 */ 0x00C41571UL },  /* [InvldDataRxdFromElecBrkCtrlModClass] */
  { /*    13 */ 0x00E50271UL },  /* [InvldDataRxdFromElecBrkCtrlModChassisExpClass] */
  { /*    14 */ 0x00C40171UL },  /* [InvldDataRxdFromEngCtrlModClass] */
  { /*    15 */ 0x00C56B71UL },  /* [InvldDataRxdFromFrntCameraModClass] */
  { /*    16 */ 0x00C45A71UL },  /* [InvldDataRxdFromParkAssiCtrlModClass] */
  { /*    17 */ 0x00C40271UL },  /* [InvldDataRxdFromTrsmCtrlModClass] */
  { /*    18 */ 0x00C14000UL },  /* [LostComWithBodyCtrlModClass] */
  { /*    19 */ 0x00C12100UL },  /* [LostComWithElecBrkCtrlModClass] */
  { /*    20 */ 0x00D83300UL },  /* [LostComWithElecBrkCtrlModChassisExpClass] */
  { /*    21 */ 0x00C10000UL },  /* [LostComWithEngCtrlModClass] */
  { /*    22 */ 0x00C26A00UL },  /* [LostComWithFrntCameraCtrlModClass] */
  { /*    23 */ 0x00C15900UL },  /* [LostComWithParkAssiCtrlModClass] */
  { /*    24 */ 0x00C10100UL },  /* [LostComWithTrsmCtrlModClass] */
  { /*    25 */ 0x00559700UL },  /* [SteerFailrMtgtnLvl1LimpHomeModClass] */
  { /*    26 */ 0x00559800UL },  /* [SteerFailrMtgtnLvl2LimpOverClass] */
  { /*    27 */ 0x00559900UL },  /* [SteerFailrMtgtnLvl3FadeOutClass] */
  { /*    28 */ 0x00446058UL },  /* [SteerWheelAgSnsrHwFltClass] */
  { /*    29 */ 0x0044605AUL },  /* [SteerWheelAgSnsrPlauslyClass] */
  { /*    30 */ 0x00454500UL },  /* [SteerWhlTqInpSnsrClass] */
  { /*    31 */ 0x0045454BUL },  /* [SteerWhlTqInpSnsrCalNoLrndClass] */
  { /*    32 */ 0x00480012UL }   /* [DevPwrVltgUnderMinThdClass] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_EnableConditionTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_EnableConditionTable
  \details
  Element                Description
  EnableConditionMask    Bit mask combination for EnableConditionGroup. 0x01 is internally used, individual bits are: [DemEnableConditionJ=0x0002, DemEnableConditionA=0x0004, DemEnableConditionB=0x0008, DemEnableConditionC=0x0010, DemEnableConditionD=0x0020, DemEnableConditionE=0x0040, DemEnableConditionF=0x0080, DemEnableConditionG=0x0100, DemEnableConditionH=0x0200, DemEnableConditionI=0x0400]
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_EnableConditionTableType, DEM_CONST) Dem_C_EnableConditionTable[11] = {
    /* Index    EnableConditionMask        Referrable Keys */
  { /*     0 */        0x00000451UL },  /* [SteerWhlTqInpSnsrEna] */
  { /*     1 */        0x0000005DUL },  /* [SteerWheelAgSnsrHwFltEna] */
  { /*     2 */        0x000006EFUL },  /* [LostComWithElecBrkCtrlModChassisExpEna, LostComWithParkAssiCtrlModEna] */
  { /*     3 */        0x000005EFUL },  /* [InvldDataRxdFromTrsmCtrlModEna, LostComWithBodyCtrlModEna, LostComWithElecBrkCtrlModEna, LostComWithEngCtrlModEna, LostComWithFrntCameraCtrlModEna] */
  { /*     4 */        0x000004EFUL },  /* [InvldDataRxdFromBodtCtrlModEna, InvldDataRxdFromElecBrkCtrlModChassisExpEna, InvldDataRxdFromElecBrkCtrlModEna, InvldDataRxdFromEngCtrlModEna, InvldDataRxdFromFrntCameraModEna, InvldDataRxdFromParkAssiCtrlModEna, LostComWithTrsmCtrlModEna] */
  { /*     5 */        0x00000059UL },  /* [ElecSteerMotCircEna] */
  { /*     6 */        0x0000045DUL },  /* [EcuSwPrfmcCalDataSetNotProgdEna, SteerWheelAgSnsrCalNorPrfmdEna, SteerWheelAgSnsrPlauslyEna, SteerWhlTqInpSnsrCalNoLrndEna, SysThermErrTHiEna] */
  { /*     7 */        0x00000051UL },  /* [EcuHwPrfmcEna, ElecSteerMotPosSnsrCirEna] */
  { /*     8 */        0x0000040DUL },  /* [DevPwrVltgOverMaxThdEna, DevPwrVltgUnderMinThdEna, DevPwrVltgUnderThdEna] */
  { /*     9 */        0x0000006DUL },  /* [CtrlrComChassisExpBusOffEna, CtrlrComHiSpdBusOffEna, SteerFailrMtgtnLvl1LimpHomeModEna, SteerFailrMtgtnLvl2LimpOverEna, SteerFailrMtgtnLvl3FadeOutEna] */
  { /*    10 */        0x00000001UL }   /* [#NoEnableConditionGroupConfigured] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_EventTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_EventTable
  \details
  Element                         Description
  AgingCycleCounterThreshold      DemAgingCycleCounterThreshold of the DemEventParameter/DemEventClass, if AgingAllowedOfEventTable==FALSE we use '255' here, too.
  AgingCycleId                    DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemAgingCycleRef
  DebounceTableIdx                the index of the 1:1 relation pointing to Dem_C_DebounceTable
  DtcTableIdx                     the index of the 1:1 relation pointing to Dem_C_DtcTable
  EnableConditionTableIdx         the index of the 1:1 relation pointing to Dem_C_EnableConditionTable
  EventKind                       DemEventKind of the DemEventParameter
  FreezeFrameNumTableEndIdx       the end index of the 0:n relation pointing to Dem_C_FreezeFrameNumTable
  FreezeFrameNumTableStartIdx     the start index of the 0:n relation pointing to Dem_C_FreezeFrameNumTable
  FreezeFrameTableStdFFIdx        the index of the 1:1 relation pointing to Dem_C_FreezeFrameTable
  MaskedBits                      contains bitcoded the boolean data of Dem_C_AgingAllowedOfEventTable, Dem_C_EventLatchTFOfEventTable, Dem_C_FreezeFrameNumTableUsedOfEventTable, Dem_C_NormalIndicatorTableUsedOfEventTable
  NormalIndicatorTableEndIdx      the end index of the 0:n relation pointing to Dem_C_NormalIndicatorTable
  NormalIndicatorTableStartIdx    the start index of the 0:n relation pointing to Dem_C_NormalIndicatorTable
  OperationCycleId                DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemOperationCycleRef
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_EventTableType, DEM_CONST) Dem_C_EventTable[58] = {
    /* Index    AgingCycleCounterThreshold  AgingCycleId                          DebounceTableIdx  DtcTableIdx  EnableConditionTableIdx  EventKind                                       FreezeFrameNumTableEndIdx                       FreezeFrameNumTableStartIdx                       FreezeFrameTableStdFFIdx  MaskedBits  NormalIndicatorTableEndIdx                       NormalIndicatorTableStartIdx                       OperationCycleId                            Referrable Keys */
  { /*     0 */                       255U, /*no AgingCycle*/ 1U                ,               1U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, /*no OperationCycle*/ 1U             },  /* [#EVENT_INVALID] */
  { /*     1 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,          1U,                      6U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              2U,                                                1U, DemConf_DemOperationCycle_PowerCycle },  /* [SteerWheelAgSnsrCalNorPrfmd] */
  { /*     2 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,          2U,                      6U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [SysThermErrTHi] */
  { /*     3 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,          3U,                      9U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [CtrlrComChassisExpBusOff] */
  { /*     4 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,          4U,                      9U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [CtrlrComHiSpdBusOff] */
  { /*     5 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,          5U,                      8U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [DevPwrVltgOverMaxThd] */
  { /*     6 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,          6U,                      8U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              2U,                                                1U, DemConf_DemOperationCycle_PowerCycle },  /* [DevPwrVltgUnderThd] */
  { /*     7 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,          7U,                      7U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [EcuHwPrfmc] */
  { /*     8 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,          8U,                      6U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [EcuSwPrfmcCalDataSetNotProgd] */
  { /*     9 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,          9U,                      5U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [ElecSteerMotCirc] */
  { /*    10 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         10U,                      7U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [ElecSteerMotPosSnsrCir] */
  { /*    11 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         11U,                      4U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [InvldDataRxdFromBodtCtrlMod] */
  { /*    12 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         12U,                      4U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              2U,                                                1U, DemConf_DemOperationCycle_PowerCycle },  /* [InvldDataRxdFromElecBrkCtrlMod] */
  { /*    13 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         13U,                      4U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [InvldDataRxdFromElecBrkCtrlModChassisExp] */
  { /*    14 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         14U,                      4U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              2U,                                                1U, DemConf_DemOperationCycle_PowerCycle },  /* [InvldDataRxdFromEngCtrlMod] */
  { /*    15 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         15U,                      4U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [InvldDataRxdFromFrntCameraMod] */
  { /*    16 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         16U,                      4U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [InvldDataRxdFromParkAssiCtrlMod] */
  { /*    17 */                        20U, DemConf_DemOperationCycle_PowerCycle,               0U,         17U,                      3U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [InvldDataRxdFromTrsmCtrlMod] */
  { /*    18 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         18U,                      3U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [LostComWithBodyCtrlMod] */
  { /*    19 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         19U,                      3U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [LostComWithElecBrkCtrlMod] */
  { /*    20 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         20U,                      2U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [LostComWithElecBrkCtrlModChassisExp] */
  { /*    21 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         21U,                      3U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              2U,                                                1U, DemConf_DemOperationCycle_PowerCycle },  /* [LostComWithEngCtrlMod] */
  { /*    22 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         22U,                      3U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [LostComWithFrntCameraCtrlMod] */
  { /*    23 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         23U,                      2U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [LostComWithParkAssiCtrlMod] */
  { /*    24 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         24U,                      4U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0AU, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [LostComWithTrsmCtrlMod] */
  { /*    25 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         25U,                      9U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              1U,                                                0U, DemConf_DemOperationCycle_PowerCycle },  /* [SteerFailrMtgtnLvl1LimpHomeMod] */
  { /*    26 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         26U,                      9U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              1U,                                                0U, DemConf_DemOperationCycle_PowerCycle },  /* [SteerFailrMtgtnLvl2LimpOver] */
  { /*    27 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         27U,                      9U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              1U,                                                0U, DemConf_DemOperationCycle_PowerCycle },  /* [SteerFailrMtgtnLvl3FadeOut] */
  { /*    28 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         28U,                      1U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              2U,                                                1U, DemConf_DemOperationCycle_PowerCycle },  /* [SteerWheelAgSnsrHwFlt] */
  { /*    29 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         29U,                      6U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              2U,                                                1U, DemConf_DemOperationCycle_PowerCycle },  /* [SteerWheelAgSnsrPlausly] */
  { /*    30 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         30U,                      0U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [SteerWhlTqInpSnsr] */
  { /*    31 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         31U,                      6U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [SteerWhlTqInpSnsrCalNoLrnd] */
  { /*    32 */                        50U, DemConf_DemOperationCycle_PowerCycle,               0U,         32U,                      8U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U,                       1U,      0x0BU,                                              3U,                                                2U, DemConf_DemOperationCycle_PowerCycle },  /* [DevPwrVltgUnderMinThd] */
  { /*    33 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [FLS_E_COMPARE_FAILED] */
  { /*    34 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [FLS_E_ERASE_FAILED] */
  { /*    35 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [FLS_E_READ_FAILED] */
  { /*    36 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [FLS_E_READ_FAILED_DED] */
  { /*    37 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [FLS_E_WRITE_FAILED] */
  { /*    38 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [MCU_E_CLM_SELFDIAG_FAILURE] */
  { /*    39 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [MCU_E_CLOCK_FAILURE] */
  { /*    40 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [MCU_E_CVM_SELFDIAG_FAILURE] */
  { /*    41 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [MCU_E_WRITE_TIMEOUT_FAILURE] */
  { /*    42 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [NVM_E_INTEGRITY_FAILED] */
  { /*    43 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [NVM_E_LOSS_OF_REDUNDANCY] */
  { /*    44 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [NVM_E_QUEUE_OVERFLOW] */
  { /*    45 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [NVM_E_REQ_FAILED] */
  { /*    46 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [NVM_E_VERIFY_FAILED] */
  { /*    47 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [NVM_E_WRITE_PROTECTED] */
  { /*    48 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [NVM_E_WRONG_BLOCK_ID] */
  { /*    49 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [PORT_E_WRITE_TIMEOUT_FAILURE] */
    /* Index    AgingCycleCounterThreshold  AgingCycleId                          DebounceTableIdx  DtcTableIdx  EnableConditionTableIdx  EventKind                                       FreezeFrameNumTableEndIdx                       FreezeFrameNumTableStartIdx                       FreezeFrameTableStdFFIdx  MaskedBits  NormalIndicatorTableEndIdx                       NormalIndicatorTableStartIdx                       OperationCycleId                            Referrable Keys */
  { /*    50 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [SPI_E_DATA_TX_TIMEOUT_FAILURE] */
  { /*    51 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [SPI_E_HARDWARE_ERROR] */
  { /*    52 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [WDG_E_DISABLE_REJECTED] */
  { /*    53 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [WDG_E_MODE_FAILED] */
  { /*    54 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [WDG_E_READBACK_FAILURE] */
  { /*    55 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [WDG_E_TRIGGER_TIMEOUT] */
  { /*    56 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle },  /* [MCU_E_ECM_SELFDIAG_FAILURE] */
  { /*    57 */                       255U, /*no AgingCycle*/ 1U                ,               0U,          0U,                     10U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,      0x00U, DEM_C_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_C_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle }   /* [MCU_E_LOCKSTEP_SELFDIAG_FAILURE] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_FreezeFrameTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_FreezeFrameTable
  \details
  Element                                   Description
  DataCollectionTableFfm2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_C_DataCollectionTableFfm2CollInd
  DataCollectionTableFfm2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_C_DataCollectionTableFfm2CollInd
  RecordSize                                Summarized size of did data that is stored in Dem_Cfg_PrimaryEntryType.SnapshotData[][] (i.e. typically without size of dids containing internal data elements).
  RecordSizeUds                             Summarized size of did data, did numbers and snapshot header (i.e. dynamical payload size of the uds response message).
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_FreezeFrameTableType, DEM_CONST) Dem_C_FreezeFrameTable[2] = {
    /* Index    DataCollectionTableFfm2CollIndEndIdx                             DataCollectionTableFfm2CollIndStartIdx                             RecordSize  RecordSizeUds        Referrable Keys */
  { /*     0 */ DEM_C_NO_DATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE, DEM_C_NO_DATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE,         0U,            0U },  /* [#NoFreezeFrameConfigured, #EVENT_INVALID, FLS_E_COMPARE_FAILED, FLS_E_ERASE_FAILED, FLS_E_READ_FAILED, FLS_E_READ_FAILED_DED, FLS_E_WRITE_FAILED, MCU_E_CLM_SELFDIAG_FAILURE, MCU_E_CLOCK_FAILURE, MCU_E_CVM_SELFDIAG_FAILURE, MCU_E_WRITE_TIMEOUT_FAILURE, NVM_E_INTEGRITY_FAILED, NVM_E_LOSS_OF_REDUNDANCY, NVM_E_QUEUE_OVERFLOW, NVM_E_REQ_FAILED, NVM_E_VERIFY_FAILED, NVM_E_WRITE_PROTECTED, NVM_E_WRONG_BLOCK_ID, PORT_E_WRITE_TIMEOUT_FAILURE, SPI_E_DATA_TX_TIMEOUT_FAILURE, SPI_E_HARDWARE_ERROR, WDG_E_DISABLE_REJECTED, WDG_E_MODE_FAILED, WDG_E_READBACK_FAILURE, WDG_E_TRIGGER_TIMEOUT, MCU_E_ECM_SELFDIAG_FAILURE, MCU_E_LOCKSTEP_SELFDIAG_FAILURE] */
  { /*     1 */                                                             19U,                                                                0U,        35U,           75U }   /* [#DemFreezeFrameClass, SteerWheelAgSnsrCalNorPrfmd, SysThermErrTHi, CtrlrComChassisExpBusOff, CtrlrComHiSpdBusOff, DevPwrVltgOverMaxThd, DevPwrVltgUnderThd, EcuHwPrfmc, EcuSwPrfmcCalDataSetNotProgd, ElecSteerMotCirc, ElecSteerMotPosSnsrCir, InvldDataRxdFromBodtCtrlMod, InvldDataRxdFromElecBrkCtrlMod, InvldDataRxdFromElecBrkCtrlModChassisExp, InvldDataRxdFromEngCtrlMod, InvldDataRxdFromFrntCameraMod, InvldDataRxdFromParkAssiCtrlMod, InvldDataRxdFromTrsmCtrlMod, LostComWithBodyCtrlMod, LostComWithElecBrkCtrlMod, LostComWithElecBrkCtrlModChassisExp, LostComWithEngCtrlMod, LostComWithFrntCameraCtrlMod, LostComWithParkAssiCtrlMod, LostComWithTrsmCtrlMod, SteerFailrMtgtnLvl1LimpHomeMod, SteerFailrMtgtnLvl2LimpOver, SteerFailrMtgtnLvl3FadeOut, SteerWheelAgSnsrHwFlt, SteerWheelAgSnsrPlausly, SteerWhlTqInpSnsr, SteerWhlTqInpSnsrCalNoLrnd, DevPwrVltgUnderMinThd] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryBlockId
**********************************************************************************************************************/
/** 
  \var    Dem_C_MemoryBlockId
  \brief  The array contains these items: Admin, Status, 40 * Primary
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_MemoryBlockIdType, DEM_CONST) Dem_C_MemoryBlockId[42] = {
  /* Index    MemoryBlockId                                                           Referrable Keys */
  /*     0 */NvMConf_NvMBlockDescriptor_DemAdminDataBlock /*NvMBlockId=41*/     ,  /* [Dem_AdminData] */
  /*     1 */NvMConf_NvMBlockDescriptor_DemStatusDataBlock /*NvMBlockId=42*/    ,  /* [Dem_StatusData] */
  /*     2 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 /*NvMBlockId=43*/  ,  /* [Dem_PrimaryEntry0] */
  /*     3 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 /*NvMBlockId=44*/  ,  /* [Dem_PrimaryEntry1] */
  /*     4 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 /*NvMBlockId=45*/  ,  /* [Dem_PrimaryEntry2] */
  /*     5 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 /*NvMBlockId=46*/  ,  /* [Dem_PrimaryEntry3] */
  /*     6 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 /*NvMBlockId=47*/  ,  /* [Dem_PrimaryEntry4] */
  /*     7 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 /*NvMBlockId=48*/  ,  /* [Dem_PrimaryEntry5] */
  /*     8 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 /*NvMBlockId=49*/  ,  /* [Dem_PrimaryEntry6] */
  /*     9 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 /*NvMBlockId=50*/  ,  /* [Dem_PrimaryEntry7] */
  /*    10 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock8 /*NvMBlockId=9*/   ,  /* [Dem_PrimaryEntry8] */
  /*    11 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock9 /*NvMBlockId=10*/  ,  /* [Dem_PrimaryEntry9] */
  /*    12 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock10 /*NvMBlockId=11*/ ,  /* [Dem_PrimaryEntry10] */
  /*    13 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock11 /*NvMBlockId=12*/ ,  /* [Dem_PrimaryEntry11] */
  /*    14 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock12 /*NvMBlockId=13*/ ,  /* [Dem_PrimaryEntry12] */
  /*    15 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock13 /*NvMBlockId=14*/ ,  /* [Dem_PrimaryEntry13] */
  /*    16 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock14 /*NvMBlockId=15*/ ,  /* [Dem_PrimaryEntry14] */
  /*    17 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock15 /*NvMBlockId=16*/ ,  /* [Dem_PrimaryEntry15] */
  /*    18 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock16 /*NvMBlockId=17*/ ,  /* [Dem_PrimaryEntry16] */
  /*    19 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock17 /*NvMBlockId=18*/ ,  /* [Dem_PrimaryEntry17] */
  /*    20 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock18 /*NvMBlockId=19*/ ,  /* [Dem_PrimaryEntry18] */
  /*    21 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock19 /*NvMBlockId=20*/ ,  /* [Dem_PrimaryEntry19] */
  /*    22 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock20 /*NvMBlockId=21*/ ,  /* [Dem_PrimaryEntry20] */
  /*    23 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock21 /*NvMBlockId=22*/ ,  /* [Dem_PrimaryEntry21] */
  /*    24 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock22 /*NvMBlockId=23*/ ,  /* [Dem_PrimaryEntry22] */
  /*    25 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock23 /*NvMBlockId=24*/ ,  /* [Dem_PrimaryEntry23] */
  /*    26 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock24 /*NvMBlockId=25*/ ,  /* [Dem_PrimaryEntry24] */
  /*    27 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock25 /*NvMBlockId=26*/ ,  /* [Dem_PrimaryEntry25] */
  /*    28 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock26 /*NvMBlockId=27*/ ,  /* [Dem_PrimaryEntry26] */
  /*    29 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock27 /*NvMBlockId=28*/ ,  /* [Dem_PrimaryEntry27] */
  /*    30 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock28 /*NvMBlockId=29*/ ,  /* [Dem_PrimaryEntry28] */
  /*    31 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock29 /*NvMBlockId=30*/ ,  /* [Dem_PrimaryEntry29] */
  /*    32 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock30 /*NvMBlockId=31*/ ,  /* [Dem_PrimaryEntry30] */
  /*    33 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock31 /*NvMBlockId=32*/ ,  /* [Dem_PrimaryEntry31] */
  /*    34 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock32 /*NvMBlockId=33*/ ,  /* [Dem_PrimaryEntry32] */
  /*    35 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock33 /*NvMBlockId=34*/ ,  /* [Dem_PrimaryEntry33] */
  /*    36 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock34 /*NvMBlockId=35*/ ,  /* [Dem_PrimaryEntry34] */
  /*    37 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock35 /*NvMBlockId=36*/ ,  /* [Dem_PrimaryEntry35] */
  /*    38 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock36 /*NvMBlockId=37*/ ,  /* [Dem_PrimaryEntry36] */
  /*    39 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock37 /*NvMBlockId=38*/ ,  /* [Dem_PrimaryEntry37] */
  /*    40 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock38 /*NvMBlockId=39*/ ,  /* [Dem_PrimaryEntry38] */
  /*    41 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock39 /*NvMBlockId=40*/    /* [Dem_PrimaryEntry39] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryDataPtr
**********************************************************************************************************************/
/** 
  \var    Dem_C_MemoryDataPtr
  \brief  The array contains these items: Admin, Status, 40 * Primary
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_NvDataPtrType, DEM_CONST) Dem_C_MemoryDataPtr[42] = {
  /* Index    MemoryDataPtr                                                                                   Referrable Keys */
  /*     0 */(Dem_NvDataPtrType) &Dem_C_GetNvAdminData()         /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_AdminData] */
  /*     1 */(Dem_NvDataPtrType) &Dem_C_GetNvEventData()         /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_StatusData] */
  /*     2 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_0()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry0] */
  /*     3 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_1()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry1] */
  /*     4 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_2()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry2] */
  /*     5 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_3()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry3] */
  /*     6 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_4()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry4] */
  /*     7 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_5()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry5] */
  /*     8 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_6()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry6] */
  /*     9 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_7()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry7] */
  /*    10 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_8()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry8] */
  /*    11 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_9()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry9] */
  /*    12 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_10()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry10] */
  /*    13 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_11()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry11] */
  /*    14 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_12()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry12] */
  /*    15 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_13()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry13] */
  /*    16 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_14()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry14] */
  /*    17 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_15()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry15] */
  /*    18 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_16()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry16] */
  /*    19 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_17()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry17] */
  /*    20 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_18()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry18] */
  /*    21 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_19()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry19] */
  /*    22 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_20()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry20] */
  /*    23 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_21()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry21] */
  /*    24 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_22()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry22] */
  /*    25 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_23()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry23] */
  /*    26 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_24()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry24] */
  /*    27 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_25()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry25] */
  /*    28 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_26()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry26] */
  /*    29 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_27()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry27] */
  /*    30 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_28()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry28] */
  /*    31 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_29()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry29] */
  /*    32 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_30()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry30] */
  /*    33 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_31()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry31] */
  /*    34 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_32()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry32] */
  /*    35 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_33()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry33] */
  /*    36 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_34()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry34] */
  /*    37 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_35()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry35] */
  /*    38 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_36()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry36] */
  /*    39 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_37()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry37] */
  /*    40 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_38()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry38] */
  /*    41 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_39()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_PrimaryEntry39] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_PrimaryEntryType, DEM_CONST) Dem_C_MemoryEntryInit = { 0 };
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NormalIndicatorTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_NormalIndicatorTable
  \details
  Element    Description
  Id         DemIndicatorID referenced by DemEventClass/DemIndicatorAttribute/DemIndicatorRef
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_NormalIndicatorTableType, DEM_CONST) Dem_C_NormalIndicatorTable[3] = {
    /* Index    Id        Referrable Keys */
  { /*     0 */ 3U },  /* [SteerFailrMtgtnLvl1LimpHomeMod, SteerFailrMtgtnLvl2LimpOver, SteerFailrMtgtnLvl3FadeOut] */
  { /*     1 */ 2U },  /* [DevPwrVltgUnderThd, InvldDataRxdFromElecBrkCtrlMod, InvldDataRxdFromEngCtrlMod, LostComWithEngCtrlMod, SteerWheelAgSnsrCalNorPrfmd, SteerWheelAgSnsrHwFlt, SteerWheelAgSnsrPlausly] */
  { /*     2 */ 1U }   /* [CtrlrComChassisExpBusOff, CtrlrComHiSpdBusOff, DevPwrVltgOverMaxThd, DevPwrVltgUnderMinThd, EcuHwPrfmc, EcuSwPrfmcCalDataSetNotProgd, ElecSteerMotCirc, ElecSteerMotPosSnsrCir, SteerWhlTqInpSnsr, SteerWhlTqInpSnsrCalNoLrnd, SysThermErrTHi] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_CommitBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_CommitBufferType, DEM_VAR_NOINIT) Dem_C_CommitBuffer;  /* PRQA S 0759 */ /* MD_DEM_18.4 */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_EventDebounceValue
**********************************************************************************************************************/
/** 
  \var    Dem_C_EventDebounceValue
  \brief  size = DEM_NUMBER_OF_EVENTS; (DEM_CFG_SUPPORT_DEBOUNCE_COUNTER == STD_ON) || (DEM_CFG_SUPPORT_DEBOUNCE_TIME == STD_ON)
*/ 
#define DEM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_C_EventDebounceValueType, DEM_VAR_NOINIT) Dem_C_EventDebounceValue[58];
#define DEM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_EventInternalStatus
**********************************************************************************************************************/
/** 
  \var    Dem_C_EventInternalStatus
  \brief  size = DEM_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_Cfg_EventInternalStatusType, DEM_VAR_NOINIT) Dem_C_EventInternalStatus[58];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_EventQueueStatus
**********************************************************************************************************************/
/** 
  \var    Dem_C_EventQueueStatus
  \brief  size = DEM_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_C_EventQueueStatusType, DEM_VAR_NOINIT) Dem_C_EventQueueStatus[58];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_FilterReportedEvents
**********************************************************************************************************************/
/** 
  \var    Dem_C_FilterReportedEvents
  \brief  size = CEIL( DEM_NUMBER_OF_EVENTS / 8 )
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_C_FilterReportedEventsType, DEM_VAR_NOINIT) Dem_C_FilterReportedEvents[8];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_IndicatorBlinking
**********************************************************************************************************************/
/** 
  \var    Dem_C_IndicatorBlinking
  \brief  size: [DEM_NUMBER_OF_INDICATORS]
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_IndicatorBlinkingType, DEM_VAR_NOINIT) Dem_C_IndicatorBlinking[4];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_IndicatorContinuous
**********************************************************************************************************************/
/** 
  \var    Dem_C_IndicatorContinuous
  \brief  size: [DEM_NUMBER_OF_INDICATORS]
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_IndicatorContinuousType, DEM_VAR_NOINIT) Dem_C_IndicatorContinuous[4];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryCommitNumber
**********************************************************************************************************************/
/** 
  \var    Dem_C_MemoryCommitNumber
  \brief  The array contains these items: Admin, Status, 40 * Primary
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_C_MemoryCommitNumberType, DEM_VAR_NOINIT) Dem_C_MemoryCommitNumber[42];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryStatus
**********************************************************************************************************************/
/** 
  \var    Dem_C_MemoryStatus
  \brief  The array contains these items: Admin, Status, 40 * Primary
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_C_MemoryStatusType, DEM_VAR_NOINIT) Dem_C_MemoryStatus[42];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvAdminData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_AdminDataType, DEM_NVM_DATA_NOINIT) Dem_C_NvAdminData;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvEventData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_StatusDataType, DEM_NVM_DATA_NOINIT) Dem_C_NvEventData;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_0
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_0;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_1
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_1;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_10
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_10;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_11
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_11;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_12
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_12;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_13
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_13;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_14
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_14;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_15
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_15;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_16
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_16;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_17
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_17;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_18
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_18;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_19
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_19;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_2
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_2;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_20
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_20;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_21
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_21;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_22
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_22;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_23
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_23;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_24
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_24;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_25
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_25;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_26
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_26;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_27
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_27;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_28
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_28;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_29
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_29;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_3
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_3;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_30
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_30;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_31
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_31;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_32
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_32;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_33
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_33;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_34
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_34;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_35
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_35;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_36
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_36;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_37
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_37;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_38
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_38;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_39
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_39;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_4
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_4;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_5
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_5;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_6
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_6;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_7
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_7;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_8
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_8;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_9
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_9;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_PrimaryChronology
**********************************************************************************************************************/
/** 
  \var    Dem_C_PrimaryChronology
  \brief  size = DEM_CFG_MAX_NUMBER_EVENT_ENTRY_PRIMARY
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_MemoryIndexType, DEM_VAR_NOINIT) Dem_C_PrimaryChronology[40];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_ReadoutBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_VAR_NOINIT) Dem_C_ReadoutBuffer;
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define DEM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
#define DEM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

#define DEM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

 /*  Map uds dtc number to eventId.  */ 
FUNC(uint16, DEM_CODE) Dem_Cfg_FindEventFromUdsDtc(uint32 DTC, uint8 MemoryId) 
{ 
  Dem_EventIdType lLowerLimit;
  Dem_EventIdType lEventId;
  switch (MemoryId)
  {
  case DEM_CFG_MEMORYID_PRIMARY:
    lLowerLimit = Dem_Cfg_GlobalPrimaryFirst();
    lEventId    = Dem_Cfg_GlobalPrimaryLast();
    break;
  default:
    lLowerLimit = DEM_EVENT_INVALID;
    lEventId    = DEM_EVENT_INVALID;
    break;
  }
  
  if (lLowerLimit != DEM_EVENT_INVALID)
  {
    for (; lEventId >= lLowerLimit; --lEventId)
    {
      if (DTC == Dem_Cfg_EventUdsDtc(lEventId))
      {
        break;
      }
    }
    if (lEventId < lLowerLimit)
    {
      lEventId = DEM_EVENT_INVALID;
    }
  }
  
  return lEventId; 
} 

 
 /*  Map J1939 dtc number to eventId.  */ 
FUNC(uint16, DEM_CODE) Dem_Cfg_FindEventFromJ1939Dtc(uint32 DTC) 
{ 
  /* DEM_CFG_SUPPORT_J1939 == STD_OFF */
  DEM_IGNORE_UNUSED_ARGUMENT(DTC)                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */
  return DEM_EVENT_INVALID; 
}                                                                                                   /* PRQA S 2006 */ /* MD_MSR_14.7 */ 

 
 /*  Map GroupOfDtc dtc number to (internal) GROUPMASK.  */ 
FUNC(uint8, DEM_CODE) Dem_Cfg_FindGroupMaskFromUdsDtc(uint32 groupDtcNumber) 
{ 
  uint8 mask;
  switch (groupDtcNumber)
  {
    case 0x00FFFFFFUL: mask = DEM_CFG_GROUPMASK_ALLDTCS; break;
    default: mask = DEM_CFG_GROUPMASK_NONE; break;
  }
  return mask; 
} 

 
 /*  Map eventId to (internal) GroupOfDtc's GROUPMASK.
     Implementation specific: the GroupOfDtc number is the lowest UDS Dtc number of each group  */ 
FUNC(uint8, DEM_CODE) Dem_Cfg_EventGroupMask(uint16 eventId) 
{ 
  DEM_IGNORE_UNUSED_ARGUMENT(eventId)                                                               /* PRQA S 3112 */ /* MD_DEM_14.2 */
  return DEM_CFG_GROUPMASK_NONE; /* no GroupOfDtc configured */ 
}                                                                                                   /* PRQA S 6080 */ /* MD_MSR_STMIF */ 

 
#define DEM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */



/**********************************************************************************************************************
  END OF FILE: Dem_Lcfg.c     [Gm (Vector), VARIANT-PRE-COMPILE]
**********************************************************************************************************************/

