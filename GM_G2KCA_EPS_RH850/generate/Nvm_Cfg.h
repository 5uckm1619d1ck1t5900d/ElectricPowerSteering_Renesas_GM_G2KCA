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
 *            Module: NvM
 *           Program: GM Global A / FR (MSR_Gm_SLP2)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701311
 *    License Scope : The usage is restricted to CBD1400351_D03
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_Cfg.h
 *   Generation Time: 2016-11-29 18:39:18
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

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
/* public section - to be used by NvM itself and its users */
#if (!defined NVM_CFG_H_PUBLIC)
#define NVM_CFG_H_PUBLIC

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_CFG_MAJOR_VERSION    (5u)
#define NVM_CFG_MINOR_VERSION    (2u)
#define NVM_CFG_PATCH_VERSION    (0u)

/**********************************************************************************************************************
 * NVM API TYPE INCLUDES
 *********************************************************************************************************************/
#include "Rte_NvM_Type.h"

#include "NvM_Types.h"

/**********************************************************************************************************************
 * API CFG TYPE DEFINITIONS
 *********************************************************************************************************************/
/* Type for an the additional published parameter Compiled Configuration ID
 * (see CompiledConfigurationId in NvM.h)
 */
/* Compiled Config Id Type */
/* PRQA S 0750 2 */ /* MD_MSR_18.4 */
typedef union
{
    uint16 Word_u16;
    uint8  Bytes_au8[2u];
} NvM_CompiledConfigIdType;

/**********************************************************************************************************************
 * CFG COMMON PARAMETER
 *********************************************************************************************************************/
/* --------------------  DEVELOPMENT / PRODUCTION MODE -------------------- */
/* switch between Debug- or Production-Mode */
#define NVM_DEV_ERROR_DETECT                  (STD_ON)

/* Preprocessor switch that is used in NvM_ReadAll() */
#define NVM_DYNAMIC_CONFIGURATION             (STD_ON)

#define NVM_API_CONFIG_CLASS_1  (1u)
#define NVM_API_CONFIG_CLASS_2  (3u)
#define NVM_API_CONFIG_CLASS_3  (7u)

#define NVM_API_CONFIG_CLASS                  (NVM_API_CONFIG_CLASS_3)

#define NVM_JOB_PRIORISATION                  STD_OFF

/* define compiled Block ID */
#define NVM_COMPILED_CONFIG_ID                (1U)

/* switch for enablinig fast mode during multi block requests */
#define NVM_DRV_MODE_SWITCH                   (STD_ON)

/* switch for enablinig polling mode and disabling notifications */
#define NVM_POLLING_MODE                      (STD_ON)

/* switch for enabling the internal buffer for Crc handling */
#define NVM_CRC_INT_BUFFER                    (STD_ON)

/* switch that is "ON" if dataset blocks are used */
#define NVM_USE_DATASETS                      (STD_ON)

/* switch that gives the user (EcuM) the possibility to time-out WriteAll cancellation */
#define NVM_KILL_WRITEALL_API                 (STD_OFF)

/* enabled or disable the whole repair redundant blocks feature */
#define NVM_REPAIR_REDUNDANT_BLOCKS_API       (STD_OFF)

/* NVM does not need this macro. It is intended for underlying modules,
 * relying on its existence
 */
#define NVM_DATASET_SELECTION_BITS (1U)

/* block offset for DCM blocks */
#define NVM_DCM_BLOCK_OFFSET    0x8000u

/* returns corresponding DCM BlockId of an original NVRAM Block */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define NvM_GetDcmBlockId(MyApplBlockId)    ((MyApplBlockId) | NVM_DCM_BLOCK_OFFSET)

/* BlockId's:
 * Note: The numbers of the following list must meet the configured blocks
 *       in the NvM_BlockDescriptorTable_at
 */

/* Alignment of the handles of all blocks */
/* Id 0 is reserved for multiblock calls */
/* Id 1 is reserved for config ID  */
#define NvMConf___MultiBlockRequest (0U) 
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock (1UL) 
#define NvMConf_NvMBlockDescriptor_CurrMeasMotEol_Deprecated (2UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_SeedKey (3UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_EotLrng_MaxHwAgCwAndCcw (4UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_HwAgSnsrls_StordLstPrm (5UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_DiagcMgr_SnpshtDataAry (6UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_GmMsg778BusHiSpd_DtcTrigStsAry (7UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CustDiagc_GmIgnCntr (8UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock8 (9UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock9 (10UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock10 (11UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock11 (12UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock12 (13UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock13 (14UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock14 (15UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock15 (16UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock16 (17UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock17 (18UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock18 (19UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock19 (20UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock20 (21UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock21 (22UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock22 (23UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock23 (24UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock24 (25UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock25 (26UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock26 (27UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock27 (28UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock28 (29UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock29 (30UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock30 (31UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock31 (32UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock32 (33UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock33 (34UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock34 (35UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock35 (36UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock36 (37UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock37 (38UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock38 (39UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock39 (40UL) 
#define NvMConf_NvMBlockDescriptor_DemAdminDataBlock (41UL) 
#define NvMConf_NvMBlockDescriptor_DemStatusDataBlock (42UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 (43UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 (44UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 (45UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 (46UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 (47UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 (48UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 (49UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 (50UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_Bootloader_SBAT (51UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_Bootloader_NbId (52UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_Bootloader_EcuId (53UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_SysFricLrng_FricNonLrngData (54UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_SysFricLrng_FricLrngData (55UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_HwAgVehCentrTrim_HwAgTrimData (56UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_WhlImbRejctn_MaxCompPerc (57UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_WhlImbRejctn_ActvCmpBand3 (58UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_WhlImbRejctn_ActvCmpBand1 (59UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_WhlImbRejctn_RiPeakPrev (60UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_WhlImbRejctn_LePeakPrev (61UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_WhlImbRejctn_ActvCmpBand2 (62UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_HwAgVehCentrTrim_HwAgTrimVal_Deprecated (63UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_StHlthSigStc_SigStcHistDataAry (64UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_MotRplCoggCfg_MotRplCoggPrm (65UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_MotRplCoggCmd_MotCoggCmdY (66UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_GmOvrlStMgr_GmLoaIgnCntr (67UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_SnsrOffsLrng_SnsrOffsLrnd (68UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_MotTqCmdSca_MotTqScaFac (69UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm (70UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_DutyCycThermProtn_FilStVal (71UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4 (72UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr (73UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3 (74UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_DiRestore (75UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2 (76UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1 (77UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr (78UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0 (79UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_CcaSerlNr (80UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrRepairShopCod (81UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrSysName (82UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrCcaMfgTrakg (83UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrSysCodVersNr (84UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrNxtrMfgTrakg (85UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrEndMdlPartNr (86UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrBasMdlPartNr (87UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrCtrlPidSeedKey (88UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrVinData (89UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrProgmDate (90UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrDataUniversalNrSysId (91UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrCalProgdSts (92UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrCustMfgEnaCntr (93UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PartNr_PartNrProgmSessionSeedKey (94UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSet (95UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSet (96UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_EotLrng_EotNvmData (97UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry (98UL) 
#define NvMConf_NvMBlockDescriptor_MotAg2Meas_Deprecated (99UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_HwTq0Meas_HwTq0Offs (100UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_HwTq1Meas_HwTq1Offs (101UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_HwTq3Meas_HwTq3Offs (102UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_HwTq2Meas_HwTq2Offs (103UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt (104UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_HwTqCorrln_HwTqChBCmnModCmpLpFilSt (105UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_HwAg1Meas_HwAg1Offs (106UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_NvMProxy_ShtdwnClsChk (107UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_HwAg0Meas_HwAg0Offs (108UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl (109UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr (110UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_IgnCntr (111UL) 
#define NvMConf_NvMBlockDescriptor_MotPrmNom (112UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf (113UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl (114UL) 
#define NvMConf_NvMBlockDescriptor_PolarityCfgSaved (115UL) 


/* number of defined NV blocks */
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS    (116UL)

/* version info api switch */
#define NVM_VERSION_INFO_API             (STD_OFF)

/* switch to enable the ram block status api */
#define NVM_SET_RAM_BLOCK_STATUS_API     (STD_ON)

/* CONST_DESCRIPTOR_TABLE contains all block relevant data,
 * including the compiled config ID
 */
#define NVM_START_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

/* Additional published parameter because e.g. in case of validate all RAM
 * Blocks it is nice to know the number of Blocks. But take care: this number
 * of Blocks includes Block 0 and Block 1, which are the MultiBlock and the
 * Configuration Block - user Blocks start wiht index 2!
 */
extern CONST(uint16, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t;

/* Additional published parameter because in case of a clear EEPROM, it is
 * necessary, to write the Configuration Block containing this Compiled
 * Configuration ID to EEPROM
 */
/* Compiled Configuration ID as defined in NvM_Cfg.c */
/* PRQA S 0759 1 */ /* MD_MSR_18.4 */
extern CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t;

#define NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

/* Component define block (available, if EcuC module is active, otherwise only NVM_DUMMY_STATEMENTs are defined*/
#ifndef NVM_USE_DUMMY_FUNCTIONS
#define NVM_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef NVM_USE_DUMMY_STATEMENT
#define NVM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef NVM_DUMMY_STATEMENT
#define NVM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT_CONST
#define NVM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef NVM_ATOMIC_VARIABLE_ACCESS
#define NVM_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef NVM_PROCESSOR_RH850_1311
#define NVM_PROCESSOR_RH850_1311
#endif
#ifndef NVM_COMP_GREENHILLS
#define NVM_COMP_GREENHILLS
#endif
#ifndef NVM_GEN_GENERATOR_MSR
#define NVM_GEN_GENERATOR_MSR
#endif
#ifndef NVM_CPUTYPE_BITORDER_LSB2MSB
#define NVM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef NVM_CONFIGURATION_VARIANT_PRECOMPILE
#define NVM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef NVM_CONFIGURATION_VARIANT_LINKTIME
#define NVM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef NVM_CONFIGURATION_VARIANT
#define NVM_CONFIGURATION_VARIANT NVM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef NVM_POSTBUILD_VARIANT_SUPPORT
#define NVM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* ---- end public configuration section ---------------------------------- */

#endif /* NVM_CFG_H_PUBLIC */

/*---- End of File ---------------------------------------------------------*/

