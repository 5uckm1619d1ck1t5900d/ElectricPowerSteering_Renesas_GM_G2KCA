/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BswM_UserTypes.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  User Types header file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Module File Name: BswM_UserTypes.h
* Module Description: BswM Included user types
* Project           : GM T1xx
* Author            : Jared Julien
***********************************************************************************************************************
* Version Control:
* %version:           1 %
* %derived_by:        CZ8L9T %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
**********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _BSWM_USERTYPES_H
# define _BSWM_USERTYPES_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Rte_CustDiagc_Type.h"
#include "Rte_GmMsg1F1BusHiSpd_Type.h"
#include "Dem.h"

/* RTE Signals used for DEM/DiagcMgr Enable Conditions */
extern VAR(uint8, AUTOMATIC) Rte_SysStMod_SysSt_Val;
extern VAR(GmSysPwrMod1, AUTOMATIC) Rte_GmMsg1F1BusHiSpd_SysPwrMod_Val;
extern VAR(boolean, AUTOMATIC) Rte_GmMsg0C9BusHiSpd_EngRunActv_Logl;
extern VAR(boolean, AUTOMATIC) Rte_GmMsg1F1BusHiSpd_MissMsg1F1_Logl;
extern VAR(boolean, AUTOMATIC) Rte_GmMsg0C9BusHiSpd_MissMsg0C9_Logl;
extern VAR(float32, AUTOMATIC) Rte_BattVltg_BrdgVltg_Val;
extern VAR(boolean, AUTOMATIC) Rte_SerlComOutpProxy_BusOffHiSpd_Logl;
extern VAR(boolean, AUTOMATIC) Rte_SerlComOutpProxy_BusOffChassisExp_Logl;
extern VAR(MfgEnaSt1, AUTOMATIC) Rte_PartNr_CustMfgEnSt_Val;
extern VAR(boolean, AUTOMATIC) Rte_CustDiagc_SerlComDi_Logl;


static INLINE FUNC(boolean, AUTOMATIC) BswMUser_GetDtcFailed(VAR(Dem_EventIdType, AUTOMATIC) EventId)
{
	VAR(boolean, AUTOMATIC) Faild_Cnt_T_logl = FALSE;

	if (Dem_GetEventFailed(EventId, &Faild_Cnt_T_logl) != E_OK)
	{
		Faild_Cnt_T_logl = TRUE;
	}

	return Faild_Cnt_T_logl;
}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#endif /* _RTE_USERTYPES_H */
