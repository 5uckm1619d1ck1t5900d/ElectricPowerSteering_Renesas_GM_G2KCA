/*============================================================================*/
/* Project		= AUTOSAR Renesas X1x MCAL Components						  */
/* Module		= Port_Version.h											  */
/*============================================================================*/
/*									COPYRIGHT								  */
/*============================================================================*/
/* Copyright(c) 2012-2013 Renesas Electronics Corporation					  */
/*============================================================================*/
/* Purpose:																	  */
/* This file contains macros required for checking release versions of		  */
/* modules included by PORT Driver											  */
/*																			  */
/*============================================================================*/
/*																			  */
/* Unless otherwise agreed upon in writing between your company and			  */
/* Renesas Electronics Corporation the following shall apply!				  */
/*																			  */
/* Warranty Disclaimer														  */
/*																			  */
/* There is no warranty of any kind whatsoever granted by Renesas. Any		  */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of	  */
/* intellectual property, merchantability and/or fitness for the particular	  */
/* purpose.																	  */
/*																			  */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.				  */
/*																			  */
/* Each User is solely responsible for determining the appropriateness of	  */
/* using the Product(s) and assumes all risks associated with its exercise	  */
/* of rights under this Agreement, including, but not limited to the risks	  */
/* and costs of program errors, compliance with applicable laws, damage to	  */
/* or loss of data, programs or equipment, and unavailability or			  */
/* interruption of operations.												  */
/*																			  */
/* Limitation of Liability													  */
/*																			  */
/* In no event shall Renesas be liable to the User for any incidental,		  */
/* consequential, indirect, or punitive damage (including but not limited	  */
/* to lost profits) regardless of whether such liability is based on breach	  */
/* of contract, tort, strict liability, breach of warranties, failure of	  */
/* essential purpose or otherwise and even if advised of the possibility of	  */
/* such damages. Renesas shall not be liable for any services or products	  */
/* provided by third party vendors, developers or consultants identified or	  */
/* referred to the User by Renesas in connection with the Product(s) and/or	  */
/* the Application.															  */
/*																			  */
/*============================================================================*/
/* Environment:																  */
/*				Devices:		X1x											  */
/*============================================================================*/

/*******************************************************************************
**						Revision Control History							  **
*******************************************************************************/
/*
 * V1.0.0:	30-Aug-2012	 : Initial Version
 *
 * V1.0.1:	26-Sep-2012	 : As per SCR 018, following changes are made:
 *						   1. The macro is added for Higher version under
 *							  Include Section.
 *						   2. Versions for DET and DEM are updated.
 *
 * V1.0.2:	26-Sep-2012	 : As per SCR 027, following changes are made:
 *						   1. Version Information for SchM is added.
 *						   2. SchM.h is added under Include Section.
 * V1.0.3:	29-Nov-2012	 : As per SCR 047, Version Information for SchM
 *						   is updated.
 *
 * V1.0.4:	21-Dec-2012	 : As per SCR 055, SchM stub versions is updated.
 *
 * V1.0.5:	05-Aug-2013	 : As per CR 225, as part of merging activity, Header
 *						   and Environment sections are updated to change the
 *						   device name.
 */
/******************************************************************************/
#ifndef PORT_VERSION_H
#define PORT_VERSION_H
/*******************************************************************************
**						Include Section										  **
*******************************************************************************/
/* Included for module version information */
#include "Port.h"
#if (PORT_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
/*
 * RTE module version information is required only when critical section
 * protection is enabled
 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#include "Rte.h"
#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
#include "SchM.h"
#endif /*END of PORT_AR_VERSION*/
#endif
#include "Dem.h"
/*******************************************************************************
**						Version Information									  **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define PORT_VERSION_AR_RELEASE_MAJOR_VERSION	 PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_VERSION_AR_RELEASE_MINOR_VERSION	 PORT_AR_RELEASE_MINOR_VERSION
#define PORT_VERSION_AR_RELEASE_REVISION_VERSION \
											  PORT_AR_RELEASE_REVISION_VERSION

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* Autosar Specification Version */
#define PORT_VERSION_AR_MAJOR_VERSION	PORT_AR_MAJOR_VERSION_VALUE
#define PORT_VERSION_AR_MINOR_VERSION	PORT_AR_MINOR_VERSION_VALUE
#define PORT_VERSION_AR_PATCH_VERSION	PORT_AR_PATCH_VERSION_VALUE

/* Included Files Autosar Specification Version */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#define PORT_DET_AR_MAJOR_VERSION  2
#define PORT_DET_AR_MINOR_VERSION  2
#endif

#define PORT_DEM_AR_MAJOR_VERSION  3
#define PORT_DEM_AR_MINOR_VERSION  3

#define PORT_SCHM_AR_MAJOR_VERSION	1
#define PORT_SCHM_AR_MINOR_VERSION	2
#endif

/* Module Software version information */
#define PORT_VERSION_SW_MAJOR_VERSION	 PORT_SW_MAJOR_VERSION
#define PORT_VERSION_SW_MINOR_VERSION	 PORT_SW_MINOR_VERSION
/*******************************************************************************
**						Global Symbols										  **
*******************************************************************************/
#endif /* PORT_VERSION_H */
/*******************************************************************************
**						End of File											  **
*******************************************************************************/
