/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2012 - 2017 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Fee
 *           Program: GM Global A / FR (MSR_Gm_SLP2)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701311
 *    License Scope : The usage is restricted to CBD1400351_D03
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fee_Cfg.h
 *   Generation Time: 2017-02-06 11:11:43
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
 *  PUBLIC SECTION
 *********************************************************************************************************************/
#if !defined (FEE_CFG_H_PUBLIC)
# define FEE_CFG_H_PUBLIC

  /********************************************************************************************************************
   *  GLOBAL CONSTANT MACROS
   *******************************************************************************************************************/
  /****************************************************************************
   * VERSION IDENTIFICATION
   ***************************************************************************/
# define FEE_CFG_MAJOR_VERSION                    (8u)
# define FEE_CFG_MINOR_VERSION                    (0u)
# define FEE_CFG_PATCH_VERSION                    (0u)

  /****************************************************************************
   * API CONFIGURATION
   ***************************************************************************/
# define FEE_VERSION_INFO_API                     (STD_OFF)
# define FEE_GET_ERASE_CYCLE_API                  (STD_OFF)
# define FEE_GET_WRITE_CYCLE_API                  (STD_OFF)
# define FEE_FORCE_SECTOR_SWITCH_API              (STD_OFF)
# define FEE_FSS_CONTROL_API              		  (STD_OFF)

# define FEE_DATA_CONVERSION_API                  (STD_OFF)

  /****************************************************************************
   * DEVELOPMENT CONFIGURATION
   ***************************************************************************/
# define FEE_DEV_ERROR_DETECT                     (STD_ON)
# define FEE_CFG_CHK_PARAM_BLOCK_NUMBER           (STD_ON)

# if (STD_ON == FEE_DEV_ERROR_DETECT)

#  define FEE_CFG_CHK_STATUS_UNINIT               (STD_ON)
#  define FEE_CFG_CHK_BUSY                        (STD_ON)
#  define FEE_CFG_CHK_IMMEDIATE_DATA              (STD_ON)
#  define FEE_CFG_DO_PARAM_CHK                    (STD_ON)

#  if (STD_ON == FEE_CFG_DO_PARAM_CHK)
#   define FEE_CFG_CHK_PARAM_SECTOR_NUMBER        (STD_ON)
#   define FEE_CFG_CHK_PARAM_NULL_POINTER         (STD_ON)
#   define FEE_CFG_CHK_PARAM_LENGTH_OFFSET        (STD_ON)
#   define FEE_CFG_CHK_PARAM_MODE                 (STD_ON)
#  else
#   define FEE_CFG_CHK_PARAM_SECTOR_NUMBER        (STD_OFF)
#   define FEE_CFG_CHK_PARAMR_NULL_POINTER        (STD_OFF)
#   define FEE_CFG_CHK_PARAM_LENGTH_OFFSET        (STD_OFF)
#   define FEE_CFG_CHK_PARAM_MODE                 (STD_OFF)
#  endif

#  define FEE_DEBUG_REPORTING                     (STD_ON)

# else

#  define FEE_CFG_CHK_STATUS_UNINIT                                   (STD_OFF)
#  define FEE_CFG_CHK_BUSY                                            (STD_OFF)
#  define FEE_CFG_CHK_IMMEDIATE_DATA                                  (STD_OFF)
#  define FEE_CFG_DO_PARAM_CHK                                        (STD_OFF)
#  define FEE_CFG_CHK_PARAM_SECTOR_NUMBER                             (STD_OFF)
#  define FEE_CFG_CHK_PARAM_NULL_POINTER                              (STD_OFF)
#  define FEE_CFG_CHK_PARAM_LENGTH_OFFSET                             (STD_OFF)
#  define FEE_CFG_CHK_PARAM_MODE                                      (STD_OFF)
#  define FEE_DEBUG_REPORTING                                         (STD_OFF)

# endif

  /****************************************************************************
   * GENERAL CONFIGURATION PARAMETER
   ***************************************************************************/

#define FeeConf_FeeBlockConfiguration_FeeConfigBlock (230UL) 
#define FeeConf_FeeBlockConfiguration_FeeCurrMeasMotEol_Deprecated (228UL) 
#define FeeConf_FeeBlockConfiguration_FeePolarityCfgSaved (226UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl (224UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf (218UL) 
#define FeeConf_FeeBlockConfiguration_FeeMotPrmNom (222UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr (220UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_IgnCntr (216UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl (212UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_HwAg0Meas_HwAg0Offs (214UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_NvMProxy_ShtdwnClsChk (210UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_HwAg1Meas_HwAg1Offs (208UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt (198UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_HwTqCorrln_HwTqChBCmnModCmpLpFilSt (206UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_HwTq1Meas_HwTq1Offs (204UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_HwTq3Meas_HwTq3Offs (202UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_HwTq2Meas_HwTq2Offs (200UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_HwTq0Meas_HwTq0Offs (196UL) 
#define FeeConf_FeeBlockConfiguration_FeeMotAg2Meas_Deprecated (194UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry (190UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_EotLrng_EotNvmData (192UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSet (184UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSet (188UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrRepairShopCod (186UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrSysName (182UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrCcaMfgTrakg (180UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrSysCodVersNr (178UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrNxtrMfgTrakg (176UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrEndMdlPartNr (174UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrBasMdlPartNr (172UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrCtrlPidSeedKey (158UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrVinData (170UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrProgmDate (168UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrDataUniversalNrSysId (166UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrCalProgdSts (164UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrCustMfgEnaCntr (162UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PartNr_PartNrProgmSessionSeedKey (160UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf4 (148UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_EpsSysSerlNr (156UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf3 (154UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_DiRestore (152UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf2 (150UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf1 (140UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_CcaHwPartNr (146UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf0 (144UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_CcaSerlNr (142UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_DutyCycThermProtn_FilStVal (2UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_PullCmpActv_PullCmpLongTerm (138UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_MotTqCmdSca_MotTqScaFac (136UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_SnsrOffsLrng_SnsrOffsLrnd (134UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_GmOvrlStMgr_GmLoaIgnCntr (132UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_MotRplCoggCfg_MotRplCoggPrm (130UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CDD_MotRplCoggCmd_MotCoggCmdY (128UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_StHlthSigStc_SigStcHistDataAry (126UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_HwAgVehCentrTrim_HwAgTrimVal_Deprecated (124UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_WhlImbRejctn_MaxCompPerc (122UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_WhlImbRejctn_ActvCmpBand3 (120UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_WhlImbRejctn_ActvCmpBand1 (118UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_WhlImbRejctn_RiPeakPrev (116UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_WhlImbRejctn_LePeakPrev (114UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_WhlImbRejctn_ActvCmpBand2 (112UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_HwAgVehCentrTrim_HwAgTrimData (110UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_SysFricLrng_FricNonLrngData (108UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_SysFricLrng_FricLrngData (106UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_Bootloader_EcuId (104UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_Bootloader_NbId (102UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_Bootloader_SBAT (100UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemAdminDataBlock (98UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemStatusDataBlock (96UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock0 (94UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock1 (92UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock2 (90UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock3 (88UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock4 (86UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock5 (84UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock6 (82UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock7 (80UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock8 (16UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock9 (18UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock10 (20UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock11 (22UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock12 (24UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock13 (26UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock14 (28UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock15 (30UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock16 (32UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock17 (34UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock18 (36UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock19 (38UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock20 (40UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock21 (42UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock22 (44UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock23 (46UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock24 (48UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock25 (50UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock26 (52UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock27 (54UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock28 (56UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock29 (58UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock30 (60UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock31 (62UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock32 (64UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock33 (66UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock34 (68UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock35 (70UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock36 (72UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock37 (74UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock38 (76UL) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock39 (78UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CustDiagc_GmIgnCntr (14UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_GmMsg778BusHiSpd_DtcTrigStsAry (12UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_DiagcMgr_SnpshtDataAry (10UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_HwAgSnsrls_StordLstPrm (8UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_EotLrng_MaxHwAgCwAndCcw (6UL) 
#define FeeConf_FeeBlockConfiguration_FeeRte_NvmBlock_CmnMfgSrv_SeedKey (4UL) 


#define FEE0 (0U) 
#define FEE1 (1U) 


#define FEE_NUMBER_OF_PARTITIONS (2)

#endif /* FEE_CFG_H_PUBLIC */

/**********************************************************************************************************************
 *  END OF FILE: Fee_Cfg.h
 *********************************************************************************************************************/
 

