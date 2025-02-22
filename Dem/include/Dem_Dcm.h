
/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dem.h
 *      Project:  MICROSAR Diagnostic Event Manager (Dem)
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Static public API declarations of Dem.
 *                Dynamically available APIs are declared in the generated file Rte_Dem.h
 *  
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Stefan Huebner                vishrs        Vector Informatik GmbH
 *  Alexander Ditte               visade        Vector Informatik GmbH
 *  Matthias Heil                 vismhe        Vector Informatik GmbH
 *  Thomas Dedler                 visdth        Vector Informatik GmbH
 *  Anna Hoessle                  visanh        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  04.00.00  2012-06-29  vismhe  ESCAN00057159 AR4-82: DEM 4.x
 *                        visade  ESCAN00057159 AR4-82: DEM 4.x
 *  04.01.00  2012-09-07  vismhe  ESCAN00061254 VersionInfo API returns wrong version number
 *            2012-09-14  vismhe  ESCAN00061429 Autostart cycle has no effect
 *            2012-09-20  vismhe  ESCAN00061565 Wrong snapshot record number reported for 19 03
 *            2012-10-26  vismhe  ESCAN00062489 Compiler warning: Condition is always true
 *            2012-10-26  vismhe  ESCAN00062490 Compiler warning: Condition is always true
 *            2012-10-26  vismhe  ESCAN00062483 Unexpected ClearAllowed callback
 *  04.02.00  2012-11-05  vismhe  ESCAN00062646 Compiler warning: Function "Dem_Queue_CancelOperation" was declared but never referenced
 *            2012-11-05  vismhe  ESCAN00062647 Compiler warning: Variable "Dem_Mem_PrimaryInfo" was declared but never referenced
 *            2012-11-05  vismhe  ESCAN00062644 Compiler warning: Variable "lResult" was set but never used
 *            2012-11-06  vismhe  ESCAN00062645 Compiler warning: Variable "lOldEventStatus" was set but never used
 *            2012-11-06  visade  ESCAN00062771 Memory corruption after call of Dem_SetDTCFilter()
 *            2012-12-07  vismhe  ESCAN00061769 AR4-207: Support VCC Diagnostic specification and required Diagnostic RFCs
 *  04.03.00  2013-02-04  visdth  ESCAN00061747 OBDII Support: IUMPR handling added
 *            2013-03-05  vismhe  ESCAN00065600 DET error DEM_E_UNINIT in Dem_Mainfunction
 *            2013-03-08  visade  ESCAN00061747 AR4-55: DEM - OBDII Support
 *            2013-03-13  visdth  ESCAN00063590 OBD IUMPR Counting Misbehavior
 *            2013-03-13  visdth  ESCAN00065851 Support User Controlled Warning Indicator Request
 *            2013-03-13  visdth  ESCAN00065853 Support suppression of permanent DTC storage
 *            2013-03-13  visdth  ESCAN00065854 Support MIL Groups
 *            2013-03-13  vismhe  ESCAN00065867 Allow PendingDTC independent from event storage
 *            2013-03-13  vismhe  ESCAN00065868 Support different DTC aging protocols
 *  04.04.00  2013-04-02  visade  ESCAN00066314 Compiler warning: multiple dead assignments within Dem.c
 *            2013-04-03  vismhe  ESCAN00065209 AR4-375: Add Support of "Suppress DTC" in Dem
 *            2013-04-10  visdth  ESCAN00066201 Extension of Interface to read IUMPR data
 *            2013-04-26  vismhe  ESCAN00067007 Secondary Memory DTCs do not report Severity and FunctionalUnit information
 *  04.04.01  2013-05-15  visade  ESCAN00067368 Compiler error: OdometerAtClear is not a member of Dem_Cfg_AdminDataType_s
 *            2013-05-15  visade  ESCAN00067372 Compiler error: Dem_Cfg_ObdGetGlobalDenominator() not a modifiable lvalue
 *            2013-05-15  visade  ESCAN00067155 Missing type definitions if Dem is used without Rte
 *            2013-05-15  visade  ESCAN00067025 Include FiM.h only if IUMPR or FiM notification is enabled
 *            2013-05-22  vismhe  ESCAN00067180 Compiler warning: uninitialized local variable 'lDtcStatusNew' used
 *            2013-05-22  vismhe  ESCAN00067354 Compilation error: Undefined symbol
 *            2013-05-22  vismhe  ESCAN00067345 Compilation error: Undefined symbol
 *            2013-05-22  vismhe  ESCAN00067459 Compiler warning: dead assignment to "lReturnValue" eliminated
 *  04.05.00  2013-06-03  visade  ESCAN00067673 Change Permanent Activation Distance from absolute to relative distance calculation
 *            2013-06-10  visade  ESCAN00067618 Out-parameter not initialized in Dem_GetIUMPRGeneralData
 *            2013-06-19  visdth  ESCAN00068159 MIL Group trip counter not reset on ClearDTC
 *            2013-06-19  vismhe  ESCAN00067715 AR4-418: Support Event Combination Type 1
 *            2013-06-19  vismhe  ESCAN00068164 Immediately persist event status on ClearDTC
 *            2013-06-19  vismhe  ESCAN00068389 Extended use of Dem_GetSeverityOfDTC and Dem_GetFunctionalUnitOfDTC
 *            2013-06-27  vismhe  ESCAN00068390 OperationCycles not stopped during Shutdown
 *            2013-09-18  vismhe  ESCAN00070478 Unexpected value for EventStatusChanged and DTCStatusChanged callbacks
 *  04.05.01  2013-07-03  vismhe  ESCAN00068511 Compiler error: Dem.c: 'Dem_Cbk_InitMonitor' undefined
 *  04.05.02  2013-07-03  vismhe  ESCAN00068562 Mode 0x02 does not return data
 *            2013-07-04  vismhe  ESCAN00068508 IUMPR: Numerator is incremented without qualified test result
 *            2013-07-04  vismhe  ESCAN00068569 Suppression or UserControlled WIR has no effect
 *  04.05.03  2013-07-10  visade  ESCAN00068885 Provide OBD FreezeFrame in 0x1904 although Snapshots Records are disabled
 *            2013-07-18  visade  ESCAN00069154 Missing cast truncates OBD DTC number
 *            2013-07-22  vismhe  ESCAN00069132 Mixed internal and external data records are stored misaligned
 *            2013-07-22  vismhe  ESCAN00069237 Allow to override static / inline specific to Dem module
 *            2013-07-23  vismhe  ESCAN00069270 Too many increments of occurrence counter
 *            2013-07-23  vismhe  ESCAN00069271 DTC starts aging although it is still pending
 *            2013-07-23  visdth  ESCAN00068577 IUMPR Counters may be incremented more than once per DCY
 *  04.06.00  2013-07-24  visade  ESCAN00069311 Missing DID/PID validation check in Dem_GetEventFreezeFrameData()
 *            2013-07-24  visade  ESCAN00068636 AR4-419: Support Multiple OBD Freeze Frames
 *            2013-08-02  visade  ESCAN00069587 The code shall compile if NVM support is disabled and OBD support is enabled
 *            2013-08-06  visade  ESCAN00069626 OBD DTC Status does not qualify
 *            2013-08-07  visade  ESCAN00069423 OBD relevant data is not reset on configuration change
 *            2013-08-08  visade  ESCAN00069683 Erroneous indicator decrement during Mode 0x04
 *            2013-08-14  vismhe  ESCAN00069801 BSW error reporting after PreInit and before Init not possible
 *  05.00.00  2013-09-03  vismhe  ESCAN00068165 Compiler warning: Condition is always constant
 *            2013-09-03  vismhe  ESCAN00068395 AR4-292: Reporting of DET and DEM errors via DLT
 *            2013-09-03  vismhe  ESCAN00068416 AR4-420: Postbuild Loadable Support
 *            2013-09-03  vismhe  ESCAN00068465 AR4-371: Support signal interface
 *            2013-09-03  vismhe  ESCAN00068526 AR4-409: Support of OEM Volvo AB
 *            2013-09-03  vismhe  ESCAN00068530 AR4-542: Support of OEM Ford
 *            2013-09-03  vismhe  ESCAN00069882 Internal event is not cleared
 *            2013-09-03  vismhe  ESCAN00069989 Compiler warning: variable "lEntry" was set but never used
 *            2013-09-03  vismhe  ESCAN00069805 Add verification of EventKind to ReportErrorStatus and SetEventStatus
 *            2013-09-04  visdth  ESCAN00070048 OBD IUMPR: reading the same ratio several times is not possible
 *            2013-09-11  vismhe  ESCAN00070346 AgingCounter is reported with incorrect value
 *            2013-09-16  vismhe  ESCAN00069943 Delay WarmUpCycle until restart of Driving Cycle
 *            2013-09-16  vismhe  ESCAN00070219 Reset PID 0x21 if no OBD DTC requests the MIL for 40 warm-up cycles
 *            2013-09-19  vismhe  ESCAN00070500 Remove DET for consecutive qualified DCY reports
 *            2013-09-26  vismhe  ESCAN00070686 ConfirmedDTC is reset on initialization
 *            2013-10-02  vismhe  ESCAN00070834 Incorrect event displaced on overflow
 *            2013-11-27  vismhe  ESCAN00072203 Memory overwritten during initialization
 *  05.00.01  2013-11-13  vismhe  ESCAN00071873 DTCs do not age
 *            2013-11-14  vismhe  ESCAN00071948 Compiler warning: Definition different from declaration
 *  05.01.00  2013-10-17  visade  ESCAN00071182 Incorrect MIL group behavior after ClearAllDTCs
 *            2013-10-22  visade  ESCAN00071161 Change initialization of PID 0x31
 *            2013-10-22  visade  ESCAN00071162 Support ClearSingleDtc for OBD ECUs
 *            2013-10-25  visade  ESCAN00071244 Provide Dem internal EventId in Environmental Data
 *            2013-10-25  visade  ESCAN00071425 Provide OBD DTC in Environmental Data
 *            2013-10-30  visade  ESCAN00071346 Support application interface providing the permanent DTC activation state
 *            2013-11-20  vismhe  ESCAN00072084 Incorrect value for maximum FDC in current cycle
 *            2013-11-20  vismhe  ESCAN00071550 Incorrect status report handling for BSW errors
 *            2013-11-21  visade  ESCAN00072122 Stored UDS DTC does not have Confirmed and WarningIndicator bit set
 *            2013-11-28  vismhe  ESCAN00072310 Incorrect PID21 handling
 *  06.00.00  2014-02-04  visade  ESCAN00072994 Admin data is not persisted during shutdown if no Operation Cycle was started
 *            2014-02-04  vismhe  ESCAN00073575 Compile/Validation error: Incompatible prototypes
 *            2014-02-04  vismhe  ESCAN00073578 Rework NV MemoryAbstraction
 *            2014-02-04  vismhe  ESCAN00070873 AR4-402: Support of OEM Ford
 *            2014-02-04  visade  ESCAN00071380 AR4-465: Support for J1939 Diagnostics - API to DCM according AR 4.1.2
 *            2014-02-04  visade  ESCAN00071379 AR4-465: Support for J1939 Diagnostics
 *            2014-02-14  visade  ESCAN00073721 Driving cycle remains qualified after automatic end
 *            2014-02-18  vismhe  ESCAN00073792 Diagnostics locked when clearing DTCs
 *            2014-02-18  vismhe  ESCAN00079177 Compiler warning: Name Dem_DTCGroupType has already been declared
 *  06.01.00  2014-03-10  visdth  ESCAN00073613 Numerator is only incremented with fulfilled General Denominator conditions
 *            2014-03-12  vismhe  ESCAN00074193 NRC "conditions not correct" for services 19 04, 19 06
 *            2014-03-12  vismhe  ESCAN00074203 AR4-673: Diag_Asr4J1939Dcm + Diag_Asr4Dem shall work without Diag_Asr4Dcm
 *            2014-03-13  vismhe  ESCAN00074248 Compiler error: Missing type definition Dem_J1939DcmDiagnosticReadinessNType
 *            2014-03-12  visade  ESCAN00073876 Lock Numerator increment during active tester communication
 *            2014-03-13  visade  ESCAN00074253 Compile error if Aging is configured to start at passed
 *            2014-03-21  vismhe  ESCAN00074493 DTC does not re-enable after suppression
 *            2014-03-21  vismhe  ESCAN00074494 DTCs do not respect multiple trips
 *            2014-03-25  vismhe  ESCAN00074541 Hide Dependent OBD DTCs in UDS diagnostic services
 *            2014-03-25  vismhe  ESCAN00074410 Incorrect old DTC status in DtcStatusChangeCbk
 *            2014-03-26  vismhe  ESCAN00074566 Event does not debounce correctly
 *            2014-03-27  vismhe  ESCAN00074598 Significance value reported incorrectly in extended records
 *            2014-03-28  vismhe  ESCAN00074644 Time debounced events report wrong maximum debounce value
 *            2014-03-28  vismhe  ESCAN00074647 Occurrence Counter reported incorrectly
 *            2014-03-28  vismhe  ESCAN00073289 Add Operating Hours to Standardized Environmental Data
 *            2014-04-02  visade  ESCAN00074740 Possible out of bound access for variable Dem_Cfg_ObdIumprData.Status
 *            2014-04-02  vismhe  ESCAN00074743 Wrong result when reporting invalid event status
 *  06.02.00  2014-04-23  vismhe  ESCAN00074202 AR4-670: Support DTC Pre-storage
 *            2014-04-23  vismhe  ESCAN00075221 Support 16 Operation Cycles
 *            2014-04-23  vismhe  ESCAN00075100 Usage of OSEK OS symbol can cause errors during preprocessing
 *            2014-04-24  vismhe  ESCAN00075205 Provide API Dem_SetEventAvailable
 *            2014-04-24  vismhe  ESCAN00075207 Suppressed Events do not confirm
 *            2014-04-28  visade  ESCAN00073569 Do not track the ratio for suppressed DTCs/Events
 *            2014-05-05  vismhe  ESCAN00075368 Incorrect new DTC status reported in DTC status changed callback
 *            2014-05-07  visade  ESCAN00075400 PID 0x21 is not cleared if MIL is not triggered
 *            2014-05-08  visade  ESCAN00074965 Loop underrun in function Dem_EnablePermanentStorage()
 *            2014-06-04  vismhe  ESCAN00075786 Dem does not compile if PID 0x21 is not enabled
 *            2014-05-21  vismhe  ESCAN00075810 OBD Freeze Frame is not cleared correctly
 *            2014-06-04  vismhe  ESCAN00076016 Compile Error: Multiple errors for OBD DEM with feature OBD disabled
 *            2014-06-04  vismhe  ESCAN00076021 Compiler error: Undefined preprocessor identifier in Dem_Dcm.h
 *  07.00.00  2014-06-25  vismhe  ESCAN00076615 AR4-732: Application Trigger for NV Synchronization
 *            2014-06-25  vismhe  ESCAN00076615 AR4-732: Extend aging behavior to not require TFTOC==false
 *            2014-06-30  vismhe  ESCAN00076615 AR4-732: Added support for Clear DTC Limitation
 *            2014-07-02  vismhe  ESCAN00076615 AR4-732: Added support FDC trip / once per cycle
 *            2014-06-25  vismhe  ESCAN00076450 Compiler error: inline function's body is not declared previously
 *            2014-06-30  vismhe  ESCAN00077724 AR4-698: Move InitPointer to Dem_Init
 *            2014-07-02  visade  ESCAN00076529 AR4-607: Option to store the Fault Detection Counter in NVRAM
 *            2014-07-02  vismhe  ESCAN00076664 Improve DTC status recovery after power loss
 *            2014-07-02  visade  ESCAN00076667 Remove support of DEM_DTC_FORMAT_OBD from DTC suppression
 *            2014-07-10  vismhe  ESCAN00076878 Improve robustness against Shutdown
 *            2014-07-11  vismhe  ESCAN00076920 Wrong result when extended record is not stored
 *            2014-07-11  vismhe  ESCAN00076982 Implausible value for extended data records mapped to aging counter
 *            2014-07-23  visade  ESCAN00076612 AR4-741: Support multiple J1939 nodes in DEM and J1939DCM
 *            2014-08-07  vismhe  ESCAN00077685 Improve robustness of disable DTC record update
 *            2014-08-07  visade  ESCAN00077680 Do not report previously OBD relevant DTCs in Mode 0x0A
 *            2014-08-08  vismhe  ESCAN00077722 Compiler warning: 'EventId' : unreferenced formal parameter
 *            2014-08-12  vismhe  ESCAN00074759 Feature J1939 and EventCombination does not work together
 *            2014-08-25  vismhe  ESCAN00074190 Restore ConfirmedBit when StorageTrigger == Confirmed
 *            2014-08-25  vismhe  ESCAN00077999 Service 19 02 does not report all DTCs
 *            2014-09-12  vismhe  ESCAN00078381 Dem_GetIUMPRGeneralData returns an incorrect value for 'NumberOfRatios'
 *            2014-09-30  vismhe  ESCAN00078498 Recover external visible OBD Freeze Frame if event in memory is not OBD relevant by configuration (anymore)
 *            2014-10-01  visade  ESCAN00078639 Add NVRAM Recovery for Permanent Memesry
 *            2014-10-10  vismhe  ESCAN00078806 Wrong event displaced from event memory
 *            2014-10-13  vismhe  ESCAN00078902 Event availability not working with combined events
 *            2014-10-13  vismhe  ESCAN00068635 Compiler warning: expression always constant
 *            2014-10-13  vismhe  ESCAN00070124 Compiler warning: conditional expression is constant
 *            2014-10-13  vismhe  ESCAN00076527 AR4-572: Ford/Mazda Feature Complete - Ford in AR environment
 *            2014-10-13  vismhe  ESCAN00076605 AR4-669: Support for J1939 Diagnostics
 *            2014-10-13  vismhe  ESCAN00080571 Memory corruption when aging DTCs
 *            2015-01-14  vismhe  ESCAN00081016 Out of bound memory read access for Dem_Cfg_ObdIumprData.Status
 *  08.00.00  2014-11-24  vismhe  ESCAN00079766 Remove API Dem_GetNextIUMPRRatioData
 *            2014-11-24  vismhe  ESCAN00079776 Combined events not correctly unavailable in postbuild configuration
 *            2014-11-24  vismhe  ESCAN00079653 Change return value for API Dem_SetOperationCycleState()
 *            2014-11-24  visade  ESCAN00079787 Compiler warning: Dead assignment in function Dem_Data_PermanentEntryFind()
 *            2014-12-04  visade  ESCAN00079994 1-Trip DTC without the need for a qualified driving cycle
 *            2014-12-04  vismhe  ESCAN00079778 A Monitor Report is lost
 *            2014-12-05  vismhe  ESCAN00080187 FEAT-412 Support latching TestFailed of confirmed DTCs
 *            2014-12-11  vismhe  ESCAN00080187 FEAT-412 Support Freezing/Resetting the debouncing state by API
 *            2014-12-11  vismhe  ESCAN00080187 FEAT-412 Support init monitor notification when debouncing is reenabled
 *            2014-12-11  vismhe  ESCAN00080187 FEAT-412 Transport NvM error result to ClearDTC Api
 *            2014-12-17  visade  ESCAN00080224 Support of 3 Byte OBD DTC for DEM internal data element
 *            2015-01-12  vismhe  ESCAN00079539 FEAT-1200: Support of length information in Snapshot
 *            2015-01-12  vismhe  ESCAN00079539 FEAT-1200: Option to rest TF bit on operation cycle start
 *            2015-01-14  vismhe  ESCAN00080283 FEAT-427: Refactoring of large functions, rework function headers
 *            2015-01-21  visade  ESCAN00080705 Permanent DTC without permanent memory activation
 *            2015-01-21  visade  ESCAN00080718 Remove DCY wait state for permanent DTCs after CodeClear
 *            2015-01-21  visade  ESCAN00080178 Add DCY qualification as permanent DTC erase condition
 *            2015-01-28  vismhe  ESCAN00080898 Out of bounds memory read access
 *            2015-02-06  visade  ESCAN00081089 Improve NVRAM recovery for combined events in permanent memory
 *            2015-02-06  visade  ESCAN00081024 IUMPR - erroneous numerator increment
 *            2015-02-12  vismhe  ESCAN00081038 Event reports are not processed correctly before Dem_Init()
 *            2015-02-12  vismhe  ESCAN00081188 Keep auto-start cycles active after shutdown
 *            2015-02-15  vismhe  ESCAN00080245 FEAT-473: Support default initialization for event available state
 *            2015-02-18  vismhe  ESCAN00081328 Critical section is kept in lock state
 *            2015-02-20  vismhe  ESCAN00080555 Compiler warning: 'FreezeFrameIndex' : unreferenced formal parameter
 *            2015-02-23  visade  ESCAN00081400 Make active DTC immediately visible after permanent memory activation
 *            2015-02-25  visade  ESCAN00079859 FEAT-643: Support WWH OBD (Beta)
 *            2015-02-27  vismhe  ESCAN00081529 Blocking of ClearDTC while processing ClearSingleDTC
 *            2015-03-10  vismhe  ESCAN00081708 DTC aging starts too early
 *            2015-03-19  vismhe  ESCAN00079199 Compiler warning: 'FreezeFrameIndex' : unreferenced formal parameter
 *            2015-03-19  vismhe  ESCAN00079200 Compiler warning: 'SRecIndex' : unreferenced formal parameter
 *  09.00.00  2015-03-24  visade  ESCAN00082399 FEAT-1446: Make OBD II Freeze Frame optional in Service 0x1904
 *            2015-03-31  visade  ESCAN00082399 FEAT-1446: Optionally restart DCY on ClearAllDTCs
 *            2015-04-01  vismhe  ESCAN00082199 Compiler warning: Unitialized variable lReturnValue
 *            2015-04-08  visade  ESCAN00082399 FEAT-1446: Add option to displace Pending OBD Freeze Frame
 *            2015-04-09  vismhe  ESCAN00082289 Displacement of wrong DTC
 *            2015-04-09  vismhe  ESCAN00082319 Compiler error: Missing 'else' block
 *            2015-04-20  vismhe  ESCAN00082534 Compiler error or warning:  initializer type incompatible with object type
 *            2015-04-20  vismhe  ESCAN00082346 FEAT-56: Support data callbacks with EventId parameter
 *            2015-04-23  vismhe  ESCAN00082348 FEAT-285: Support healing for events without indicator
 *            2015-04-23  vismhe  ESCAN00082348 FEAT-285: Support debouncing while enable conditions are locked
 *            2015-05-05  visade  ESCAN00082811 Environmental data is missing for confirmed DTC
 *            2015-05-22  vismhe  ESCAN00082348 FEAT-285: Support entry retry
 *            2015-06-03  vismhe  ESCAN00082346 FEAT-56: Support data callbacks without NV storage
 *            2015-06-03  vismhe  ESCAN00082346 FEAT-56: Support JLR specific snapshot trigger
 *            2015-06-09  vismhe  ESCAN00082346 FEAT-56: Support aging at passed trigger for aging target == 0
 *            2015-06-26  vismhe  ESCAN00079889 Status change callback called without change of status
 *            2015-06-29  visade  ESCAN00083654 1-Trip DTC not available in Mode 0x0A
 *            2015-07-02  vismhe  ESCAN00083400 Compiler warning:  narrowing or signed-to-unsigned type conversion found
 *            2015-07-06  vismhe  ESCAN00083803 Combined events age without completed test
 *            2015-07-08  vismhe  ESCAN00082762 Compiler error: E0516: Zero sized structure 'DebounceInfo', E0823: Too long macro expansion 'VStdMemSet'
 *            2015-07-21  vismhe  ESCAN00084110 DID length is not included in snapshot record
 *  09.01.00  2015-09-04  vismhe  ESCAN00084615 ClearDTC for secondary memory deletes wrong DTCs
 *            2015-09-10  vismhe  ESCAN00085009 Support non-volatile availability setting
 *            2015-09-10  vismhe  ESCAN00084044 Indicator is reported active without requesting DTC
 *********************************************************************************************************************/

#if !defined (DEM_DCM_H)
#define DEM_DCM_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
                                                               /* Dem itself */
/* ------------------------------------------------------------------------- */
#include "Dem.h"
/* ------------------------------------------------------------------------- */

#if (DEM_CFG_SUPPORT_DCM != STD_ON)
# error "Dcm API is not supported"
#endif

/* ********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

                                                       /* Generic properties */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmGetTranslationType
 *****************************************************************************/
/*!
 * \brief         Gets the UDS DTC format.
 *
 * \return        The configured DTC format.
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_DTCTranslationFormatType, DEM_CODE)
Dem_DcmGetTranslationType(
  void
  );

/* ****************************************************************************
 * Dem_DcmGetDTCStatusAvailabilityMask
 *****************************************************************************/
/*!
 * \brief         Gets the supported UDS DTC status availability mask.
 *
 * \param[out]    DTCStatusMask
 *                Pointer to receive the status availability mask
 *
 * \retval        E_OK
 *                The DTCStatusMask was returned
 * \retval        E_NOT_OK
 *                The DTCStatusMask was not returned
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmGetDTCStatusAvailabilityMask(
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatusMask
  );

                                                           /* DTC properties */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmGetStatusOfDTC
 *****************************************************************************/
/*!
 * \brief         Gets the current Uds status of a Dtc
 *
 * \param[in]     DTC
 *                The UDS DTC number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[out]    DTCStatus
 *                Pointer to receive the Uds status
 *
 * \retval        DEM_STATUS_OK
 *                The requested status was returned
 * \retval        DEM_STATUS_WRONG_DTC
 *                DTC does not exist in DTCOrigin
 * \retval        DEM_STATUS_WRONG_DTCORIGIN
 *                DTCOrigin does not exist
 * \retval        DEM_STATUS_FAILED
 *                A generic error occurred.
 * \retval        DEM_STATUS_PENDING
 *                Never returned by this implementation
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE)
Dem_DcmGetStatusOfDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus
  );

/* ****************************************************************************
 * Dem_DcmGetSeverityOfDTC
 *****************************************************************************/
/*!
 * \brief         Gets the severity of a Dtc
 *
 * \param[in]     DTC
 *                The UDS DTC number
 * \param[out]    DTCSeverity
 *                Pointer to receive the DTC severity
 *
 * \retval        DEM_GET_SEVERITYOFDTC_OK
 *                The requested severity was returned
 * \retval        DEM_GET_SEVERITYOFDTC_WRONG_DTC
 *                The DTC does not exist in origin PRIMARY
 * \retval        DEM_GET_SEVERITYOFDTC_NOSEVERITY
 *                Severities do not exist
 * \retval        DEM_GET_SEVERITYOFDTC_PENDING
 *                Never returned by this implementation
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE)
Dem_DcmGetSeverityOfDTC(
  uint32  DTC,
  P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_DCM_DATA)  DTCSeverity
  );

/* ****************************************************************************
 * Dem_DcmGetFunctionalUnitOfDTC
 *****************************************************************************/
/*!
 * \brief         Gets the functional unit of a Dtc.
 *
 * \param[in]     DTC
 *                The DTC number
 * \param[out]    DTCFunctionalUnit
 *                Pointer to receive the DTC functional unit
 *
 * \retval        DEM_GET_FUNCTIONALUNITOFDTC_OK
 *                The requested functional unit was returned
 * \retval        DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC
 *                The DTC does not exist in origin PRIMARY
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE)
Dem_DcmGetFunctionalUnitOfDTC(
  uint32  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCFunctionalUnit
  );

                                                               /* DTC filter */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmSetDTCFilter
 *****************************************************************************/
/*!
 * \brief         Initializes the Dcm DTC filter with the given criteria
 *
 * \param[in]     DTCStatusMask
 *                Requested status bits according to ISO14229-1
 *                0x04, 0x08 and 0x0C filter in chronologic order
 *                0x00 reports all DTCs, 0x01..0xFF apply the mask
 * \param[in]     DTCKind
 *                The DTC kind to filter
 * \param[in]     DTCFormat
 *                The DTC format
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     FilterWithSeverity
 *                Select severity as filter criterion
 * \param[in]     DTCSeverityMask
 *                Severity filter (conditional)
 * \param[in]     FilterForFaultDetectionCounter
 *                Select fault detection counter as filter criterion
 *
 * \retval        DEM_FILTER_ACCEPTED
 *                The filter parameters were accepted
 * \retval        DEM_WRONG_FILTER
 *                Wrong filter selected
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnSetFilterType, DEM_CODE)
Dem_DcmSetDTCFilter(
  uint8  DTCStatusMask,
  Dem_DTCKindType  DTCKind,
  Dem_DTCFormatType  DTCFormat,
  Dem_DTCOriginType  DTCOrigin,
  Dem_FilterWithSeverityType  FilterWithSeverity,
  Dem_DTCSeverityType  DTCSeverityMask,
  Dem_FilterForFDCType  FilterForFaultDetectionCounter
  );

/* ****************************************************************************
 * Dem_DcmSetFreezeFrameRecordFilter
 *****************************************************************************/
/*!
 * \brief         Initializes the DTC record filter with the given criteria.
 *
 * \param[in]     DTCFormat
 *                The DTC format
 * \param[out]    NumberOfFilteredRecords
 *                Pointer to receive the number of stored snapshot records
 *
 * \retval        DEM_FILTER_ACCEPTED
 *                The filter parameters were accepted
 * \retval        DEM_WRONG_FILTER
 *                Wrong filter selected
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnSetFilterType, DEM_CODE)
Dem_DcmSetFreezeFrameRecordFilter(
  Dem_DTCFormatType  DTCFormat,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  NumberOfFilteredRecords
  );

/* ****************************************************************************
 * Dem_DcmGetNumberOfFilteredDTC
 *****************************************************************************/
/*!
 * \brief         Calculates the number of DTCs matching the filter criteria
 *
 * \param[out]    NumberOfFilteredDTC
 *                Pointer to receive the DTC count
 *
 * \retval        DEM_NUMBER_OK
 *                The number of matching DTCs was returned
 * \retval        DEM_NUMBER_FAILED
 *                The number of matching DTCs could not be calculated
 * \retval        DEM_NUMBER_PENDING
 *                Counting is currently in progress
 *
 * \pre           The Dcm filter has to be initialized by Dem_DcmSetDTCFilter
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE)
Dem_DcmGetNumberOfFilteredDTC(
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  NumberOfFilteredDTC
  );

/* ****************************************************************************
 * Dem_DcmGetNextFilteredDTC
 *****************************************************************************/
/*!
 * \brief         Iterates the next matching DTC
 *
 * \param[out]    DTC
 *                Pointer to receive the UDS/OBD DTC number
 * \param[out]    DTCStatus
 *                Pointer to receive the DTC status
 *
 * \retval        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \retval        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \pre           The Dcm filter has to be initialized by Dem_DcmSetDTCFilter
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredDTC(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus
  );

/* ****************************************************************************
 * Dem_DcmGetDTCByOccurrenceTime
 *****************************************************************************/
/*!
 * \brief         Gets a DTC based on occurrence time
 *
 * \param[in]     DTCRequest
 *                The occurrence time
 * \param[out]    DTC
 *                Pointer to receive the UDS DTC number
 *
 * \retval        DEM_OCCURR_OK 
 *                The requested DTC was returned
 * \retval        DEM_OCCURR_NOT_AVAILABLE
 *                No DTC is available for the given occurrence time
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE)
Dem_DcmGetDTCByOccurrenceTime(
  Dem_DTCRequestType  DTCRequest,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC
  );

/* ****************************************************************************
 * Dem_DcmGetNextFilteredRecord
 *****************************************************************************/
/*!
 * \brief         Iterates the next record
 *
 * \param[out]    DTC
 *                Pointer to receive the UDS DTC number
 * \param[out]    RecordNumber
 *                Pointer to receive the snapshot record number
 *
 * \retval        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \retval        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \pre           The record filter has been initilaized by 
 *                Dem_DcmSetFreezeFrameRecordFilter
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredRecord(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  RecordNumber
  );

/* ****************************************************************************
 * Dem_DcmGetNextFilteredDTCAndFDC
 *****************************************************************************/
/*!
 * \brief         Iterates the next matching DTC
 *
 * \param[out]    DTC
 *                Pointer to receive the UDS/OBD DTC number
 * \param[out]    DTCFaultDetectionCounter
 *                Pointer to receive the fault detection counter
 *
 * \retval        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \retval        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \pre           The Dcm filter has to be initialized by Dem_DcmSetDTCFilter
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredDTCAndFDC(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(sint8, AUTOMATIC, DEM_DCM_DATA)  DTCFaultDetectionCounter
  );

/* ****************************************************************************
 * Dem_DcmGetNextFilteredDTCAndSeverity
 *****************************************************************************/
/*!
 * \brief         Iterates the next matching DTC
 *
 * \param[out]    DTC
 *                Pointer to receive the UDS/OBD DTC number
 * \param[out]    DTCStatus
 *                Pointer to receive the DTC status
 * \param[out]    DTCSeverity
 *                Pointer to receive the DTC severity
 * \param[out]    DTCFunctionalUnit
 *                Pointer to receive the DTC functional unit
 *
 * \retval        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \retval        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \pre           The Dcm filter has to be initialized by Dem_DcmSetDTCFilter
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredDTCAndSeverity(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus,
  P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_DCM_DATA)  DTCSeverity,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCFunctionalUnit
  );

                                                          /* Data Protection */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmDisableDTCRecordUpdate
 *****************************************************************************/
/*!
 * \brief         Prepares a memory entry for readout by the Dcm
 *
 * \param[in]     DTC
 *                The UDS DTC number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 *
 * \retval        DEM_DISABLE_DTCRECUP_OK
 *                The memory entry is ready for readout
 * \retval        DEM_DISABLE_DTCRECUP_WRONG_DTC
 *                The DTC value does not exist in this evcent memory
 * \retval        DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN
 *                Wrong DTC origin
 * \retval        DEM_DISABLE_DTCRECUP_PENDING
 *                The operation was started and is currently processed
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE)
Dem_DcmDisableDTCRecordUpdate(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin
  );

/* ****************************************************************************
 * Dem_DcmEnableDTCRecordUpdate
 *****************************************************************************/
/*!
 * \brief         Release a previously prepared memory entry
 *
 * \retval        E_OK
 *                The memory entry has been released
 * \retval        E_NOT_OK
 *                There was no memory entry to release
 *
 * \pre           -
 * 
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmEnableDTCRecordUpdate(
  void
  );

                                                                 /* DTC Data */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmGetOBDFreezeFrameData
 *****************************************************************************/
/*!
 * \brief         Reads the OBD freeze frame via UDS protocol (19 05).
 *
 * \param[out]    DTC
 *                Pointer to receive the DTC number
 * \param[out]    DestBuffer
 *                Pointer to receive the snapshot data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data.
 *                Out: Number of written bytes.
 *
 * \retval        E_OK
 *                DTC and OBD freeze frame have been returned
 * \retval        E_NOT_OK
 *                No DTC and OBD freeze frame data available
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmGetOBDFreezeFrameData(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  BufSize
  );

/* ****************************************************************************
 * Dem_DcmGetFreezeFrameDataByDTC
 *****************************************************************************/
/*!
 * \brief         Reads a snapshot record stored for a DTC (19 04)
 *
 * \param[in]     DTC
 *                The Dtc number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[out]    DestBuffer
 *                Pointer to receive the snapshot data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data.
 *                Out: Number of written bytes.
 *
 * \retval        DEM_GET_FFDATABYDTC_OK
 *                The requested data was returned
 * \retval        DEM_GET_FFDATABYDTC_WRONG_DTC
 *                The requested DTC is not available in that event memory
 * \retval        DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN
 *                The requested event memory is not available
 * \retval        DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER
 *                The requested record is not available
 * \retval        DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE
 *                The destination buffer is too small
 * \retval        DEM_GET_FFDATABYDTC_PENDING
 *                Not used by this implementation
 *
 * \pre           The data of the requested DTC has to be initialized by
 *                Dem_DcmDisableDTCRecordUpdate
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)
Dem_DcmGetFreezeFrameDataByDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  uint8  RecordNumber,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  BufSize
  );

/* ****************************************************************************
 * Dem_DcmGetSizeOfFreezeFrameByDTC
 *****************************************************************************/
/*!
 * \brief         Gets the size of a formatted snapshot record stored for a DTC
 *                (19 04)
 *
 * \param[in]     DTC
 *                The Dtc number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[out]    SizeOfFreezeFrame
 *                Pointer to receive the size in bytes
 *
 * \retval        DEM_GETSIZEBYDTC_OK
 *                The requested data was returned
 * \retval        DEM_GETSIZEBYDTC_WRONG_DTC
 *                The requested DTC is not available in that event memory
 * \retval        DEM_GETSIZEBYDTC_WRONG_DTCORIGIN
 *                The requested event memory is not available
 * \retval        DEM_GETSIZEBYDTC_WRONG_RECNUM
 *                The requested record is not available
 * \retval        DEM_GETSIZEBYDTC_PENDING
 *                Not used by this implementation
 *
 * \pre           The data of the requested DTC has to be initialized by
 *                Dem_DcmDisableDTCRecordUpdate
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)
Dem_DcmGetSizeOfFreezeFrameByDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  uint8  RecordNumber,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame
  );

/* ****************************************************************************
 * Dem_DcmGetExtendedDataRecordByDTC
 *****************************************************************************/
/*!
 * \brief         Reads an extended record stored for a DTC
 *
 * \param[in]     DTC
 *                The Dtc number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     ExtendedDataNumber
 *                The extended record number
 * \param[out]    DestBuffer
 *                Pointer to receive the extended record data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data
 *                Out: Number of written bytes
 *
 * \retval        DEM_RECORD_OK
 *                The requested data was returned
 * \retval        DEM_RECORD_WRONG_DTC
 *                The requested DTC is not available in that event memory
 * \retval        DEM_RECORD_WRONG_DTCORIGIN
 *                The requested event memory is not available
 * \retval        DEM_RECORD_WRONG_NUMBER
 *                The requested record is not available
 * \retval        DEM_RECORD_WRONG_BUFFERSIZE
 *                The destination buffer is too small
 * \retval        DEM_RECORD_PENDING
 *                Not used by this implementation
 *
 * \pre           The data of the requested DTC has to be initialized by
 *                Dem_DcmDisableDTCRecordUpdate
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)
Dem_DcmGetExtendedDataRecordByDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  uint8  ExtendedDataNumber,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  BufSize
  );

/* ****************************************************************************
 * Dem_DcmGetSizeOfExtendedDataRecordByDTC
 *****************************************************************************/
/*!
 * \brief         Gets the size of a formatted extended data record stored for
 *                a DTC
 *
 * \param[in]     DTC
 *                The Dtc number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     ExtendedDataNumber
 *                The extended data record
 * \param[out]    SizeOfExtendedDataRecord
 *                Pointer to receive the size in bytes
 *
 * \retval        DEM_GETSIZEBYDTC_OK
 *                The requested data was returned
 * \retval        DEM_GETSIZEBYDTC_WRONG_DTC
 *                The requested DTC is not available in that event memory
 * \retval        DEM_GETSIZEBYDTC_WRONG_DTCORIGIN
 *                The requested event memory is not available
 * \retval        DEM_GETSIZEBYDTC_WRONG_RECNUM
 *                The requested record is not available
 * \retval        DEM_GETSIZEBYDTC_PENDING
 *                Not used by this implementation
 *
 * \pre           The data of the requested DTC has to be initialized by
 *                Dem_DcmDisableDTCRecordUpdate
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)
Dem_DcmGetSizeOfExtendedDataRecordByDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  uint8  ExtendedDataNumber,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfExtendedDataRecord
  );

                                                                /* Clear DTC */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmClearDTC
 *****************************************************************************/
/*!
 * \brief         Clear DTC memory
 *
 * \param[in]     DTC
 *                DTC number of a single DTC to clear this DTC
 *                DTC number of a DTC group to clear all DTCs in the group
 *                DTC number '0xFFFFFF' to clear all DTCs
 * \param[in]     DTCFormat
 *                The DTC format
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 *
 * \retval        DEM_CLEAR_OK
 *                Clearing is completed, the requested DTC(s) are reset.
 * \retval        DEM_CLEAR_WRONG_DTC
 *                The requested DTC is not valid in the context of DTCFormat
 *                and DTCOrigin
 * \retval        DEM_CLEAR_WRONG_DTCORIGIN
 *                The requested DTC origin is not available in the context of
 *                DTCFormat
 * \retval        DEM_CLEAR_FAILED
 *                The clear operation could not be started
 * \retval        DEM_CLEAR_MEMORY_ERROR
 *                The clear operation has completed, but the NV synchronization
 *                has failed
 * \retval        DEM_CLEAR_PENDING
 *                The clear operation was started and is currently processed
 * \retval        DEM_CLEAR_BUSY
 *                Another clear operation is currently processing
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_ReturnClearDTCType, DEM_CODE)
Dem_DcmClearDTC(
  uint32  DTC,
  Dem_DTCFormatType  DTCFormat,
  Dem_DTCOriginType  DTCOrigin
  );

                                                     /* Control DTC Settings */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmDisableDTCSetting
 *****************************************************************************/
/*!
 * \brief         Disables the DTC setting (UDS 0x19 85)
 *
 * \param[in]     DTCGroup
 *                Only all DTCs is supported
 * \param[in]     DTCKind
 *                Only all kind of DTCs is supported
 *
 * \retval        DEM_CONTROL_DTC_SETTING_OK
 *                DTCs setting was disabled
 * \retval        DEM_CONTROL_DTC_SETTING_N_OK
 *                DTCs setting was not disabled
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)
Dem_DcmDisableDTCSetting(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType  DTCKind
  );

/* ****************************************************************************
 * Dem_DcmEnableDTCSetting
 *****************************************************************************/
/*!
 * \brief         Enables the DTC setting (UDS 0x19 85)
 *
 * \param[in]     DTCGroup
 *                Only all DTCs is supported
 * \param[in]     DTCKind
 *                Only all kind of DTCs is supported
 *
 * \retval        DEM_CONTROL_DTC_SETTING_OK
 *                DTCs setting was disabled
 * \retval        DEM_CONTROL_DTC_SETTING_N_OK
 *                DTCs setting was not disabled
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)
Dem_DcmEnableDTCSetting(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType  DTCKind
  );

                                                 /* Control DTC Notification */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmControlDTCStatusChangedNotification
 *****************************************************************************/
/*!
 * \brief         Toggles DTC status change notification
 *
 * \param[in]     TriggerNotification
 *                New notification setting
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(void, DEM_CODE)
Dem_DcmControlDTCStatusChangedNotification(
  boolean TriggerNotification
  );

                                                         /* Cancel Operation */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmCancelOperation
 *****************************************************************************/
/*!
*  \note       SERVICE ID   0x2A
*  \note       SYNC/ASYNC   Synchronous
*  \note       REENTRANCY   Reentrant
*
*  \brief      Aborts pending (asynchronous) operation
*  \pre        Dem has been initialized.
*  \context    task level or interrupt
*  \note       CALLED BY    External
*****************************************************************************/
FUNC(void, DEM_CODE)
Dem_DcmCancelOperation(
  void
  );

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif
