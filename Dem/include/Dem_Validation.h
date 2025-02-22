
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
 *         File:  Dem_Validation.h
 *      Project:  MICROSAR Diagnostic Event Manager (Dem)
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Configuration sanity checks. Please note, the validation performed in this file is intentionally
 *                incomplete and restricted to basic verifications.  Not all combinations of options are supported
 *                even if the compilation of this file is successful. This is intended behavior.
 *                Exhaustive verifications are performed by the generation tool before configuration files are
 *                created.
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

#if !defined (DEM_VALIDATION_H)
#define DEM_VALIDATION_H

/* ********************************************************************************************************************
 *  VERIFY BASIC MACROS EXIST
 *********************************************************************************************************************/
#if !defined (STD_ON) || (STD_ON != 1)
# error "STD_ON is not correctly defined"
#endif

#if !defined (STD_OFF) || (STD_OFF != 0)
# error "STD_OFF is not correctly defined"
#endif

/**********************************************************************************************************************
 *  VERIFY SENSIBLE COMBINATION OF CONFIGURATION SWITCHES
 *********************************************************************************************************************/

#if ((DEM_CFG_SUPPORT_AGINGCYCLE_STATE_API == STD_ON) && (DEM_CFG_SUPPORT_AGINGCYCLE_COUNTER_API == STD_ON))
# error "(DEM_CFG_SUPPORT_AGINGCYCLE_STATE_API == STD_ON) && (DEM_CFG_SUPPORT_AGINGCYCLE_COUNTER_API == STD_ON) is not\
 a valid combination"
#endif

#if ((DEM_CFG_SUPPORT_SRECS_CALCULATED  == STD_ON) && (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON))
# error "(DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON) && (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON) is not\
 a valid combination"
#endif

#if ((DEM_CFG_SUPPORT_OPCYCLE_STORAGE != STD_ON) && (DEM_CFG_SUPPORT_OPCYCLE_AUTOMATIC_END == STD_ON))
# error "(DEM_CFG_SUPPORT_OPCYCLE_STORAGE != STD_ON) && (DEM_CFG_SUPPORT_OPCYCLE_AUTOMATIC_END == STD_ON) is not\
  a valid combination: without nonvolatile storage of cycle state there is no way NOT to end a cycle."
#endif

#if (DEM_CFG_PROCESS_PDTC_ALL_DTC == DEM_CFG_PROCESS_PDTC_STOREDONLY)
# error "Exactly one of the settings DEM_CFG_PROCESS_PDTC_ALL_DTC, DEM_CFG_PROCESS_PDTC_STOREDONLY must be enabled"
#endif

#if (DEM_CFG_PROCESS_CDTC_ALL_DTC == DEM_CFG_PROCESS_CDTC_STOREDONLY)
# error "Exactly one of the settings DEM_CFG_PROCESS_CDTC_ALL_DTC, DEM_CFG_PROCESS_CDTC_STOREDONLY must be enabled"
#endif

#if ((DEM_CFG_PROCESS_TFSLC_ALL_DTC + DEM_CFG_PROCESS_TFSLC_STOREDONLY + DEM_CFG_PROCESS_TFSLC_CLEARONLY) > STD_ON)
# error "Exactly one of the settings DEM_CFG_PROCESS_TFSLC_ALL_DTC, DEM_CFG_PROCESS_TFSLC_STOREDONLY must be enabled"
#endif

#if (DEM_CFG_PROCESS_WIR_ALL_DTC == DEM_CFG_PROCESS_WIR_STOREDONLY)
# error "Exactly one of the settings DEM_CFG_PROCESS_WIR_ALL_DTC, DEM_CFG_PROCESS_WIR_STOREDONLY must be enabled"
#endif

#if !defined PRQA_SIZE_T && !defined _lint

#endif

#if (DEM_CFG_SUPPORT_DEBOUNCE_TIME == STD_OFF) && ((DEM_CFG_SUPPORT_DEBOUNCE_TIME_HR == STD_ON) || (DEM_CFG_SUPPORT_DEBOUNCE_TIME_LR == STD_ON))
# error "(DEM_CFG_SUPPORT_DEBOUNCE_TIME == STD_OFF) && ((DEM_CFG_SUPPORT_DEBOUNCE_TIME_HR == STD_ON) || (DEM_CFG_SUPPORT_DEBOUNCE_TIME_LR == STD_ON))\
  is not a valid combination"
#endif

#if (DEM_CFG_STORAGE_AT_CONFIRMED != STD_ON) && (DEM_CFG_STORAGE_AT_FAILED != STD_ON) && (DEM_CFG_STORAGE_AT_FDC != STD_ON)
# error "At least one DEM_CFG_STORAGE_AT_XXX must be defined to STD_ON"
#endif

#if (DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && ((DEM_CFG_STORAGE_AT_FAILED == STD_ON) || (DEM_CFG_STORAGE_AT_FDC == STD_ON))
# error "At most one DEM_CFG_STORAGE_AT_XXX must be defined to STD_ON"
#endif

#if (DEM_CFG_STORAGE_AT_FAILED == STD_ON) && (DEM_CFG_STORAGE_AT_FDC == STD_ON)
# error "At most one DEM_CFG_STORAGE_AT_XXX must be defined to STD_ON"
#endif

#if ((DEM_CFG_SUPPORT_ERECS != STD_ON) && (DEM_CFG_SUPPORT_USER_ERECS == STD_ON))
# error "((DEM_CFG_SUPPORT_ERECS != STD_ON) && (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)) is not a valid combination"
#endif

#if ((DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && (DEM_CFG_PROCESS_PDTC_STOREDONLY == STD_ON))
# error "((DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && (DEM_CFG_PROCESS_PDTC_STOREDONLY == STD_ON)) is not a valid combination"
#endif

#if ((DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && (DEM_CFG_PROCESS_TFSLC_STOREDONLY == STD_ON))
# error "((DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && (DEM_CFG_PROCESS_TFSLC_STOREDONLY == STD_ON)) is not a valid combination"
#endif

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_OFF) && (DEM_CFG_SUPPORT_EVENTAVAILABLE_NV == STD_ON)
# error "(DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_OFF) && (DEM_CFG_SUPPORT_EVENTAVAILABLE_NV == STD_ON) is not a valid combination"
#endif

#if ((DEM_CFG_SUPPORT_EVENTAVAILABLE_DEFAULT == STD_ON) && (DEM_CFG_SUPPORT_EVENTAVAILABLE_NV == STD_ON))
# error "(DEM_CFG_SUPPORT_EVENTAVAILABLE_DEFAULT == STD_ON) && (DEM_CFG_SUPPORT_EVENTAVAILABLE_NV == STD_ON) "
#endif

/* ********************************************************************************************************************
 *  UNSUPPORTED ASR FEATURES
 *********************************************************************************************************************/
#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
# error "DEM_CFG_SUPPORT_OBDII == STD_ON is not supported"
#endif /* (DEM_CFG_SUPPORT_OBDII == STD_ON) */
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
# error "DEM_CFG_SUPPORT_WWHOBD == STD_ON is not supported"
#endif /* (DEM_CFG_SUPPORT_WWHOBD == STD_ON) */

#if (DEM_CFG_SUPPORT_DLT == STD_ON)
# error "DEM_CFG_SUPPORT_DLT == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_VID08 == STD_ON)
# error "DEM_CFG_SUPPORT_VID08 == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_VID0B == STD_ON)
# error "DEM_CFG_SUPPORT_VID0B == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_MIRROR == STD_ON)
# error "DEM_CFG_SUPPORT_MIRROR == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
# error "DEM_CFG_SUPPORT_PERMANENT == STD_ON is not supported for non-OBD/WWH-OBD use cases"
#endif /* (DEM_CFG_SUPPORT_PERMANENT == STD_ON) */

#if (DEM_CFG_SUPPORT_AGINGCYCLE_STATE_API == STD_ON)
# error "DEM_CFG_SUPPORT_AGINGCYCLE_STATE_API == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_AGINGCYCLE_COUNTER_API == STD_ON)
# error "DEM_CFG_SUPPORT_AGINGCYCLE_COUNTER_API == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
# error "DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON is not yet supported"
#endif

#if (DEM_CFG_CAPTURE_EXTDATA_TESTFAILED == STD_ON)
# error "DEM_CFG_CAPTURE_EXTDATA_TESTFAILED == STD_ON is not yet supported"
#endif

#if (DEM_CFG_CAPTURE_FREEZEF_TESTFAILED == STD_ON)
# error "DEM_CFG_CAPTURE_FREEZEF_TESTFAILED == STD_ON is not yet supported"
#endif

#if (DEM_CFG_CLEAR_REINIT_BEFORE_RESPONSE != STD_ON)
# error "DEM_CFG_CLEAR_REINIT_BEFORE_RESPONSE == STD_OFF is not supported"
#endif

#endif  /* DEM_VALIDATION_H */

/* ********************************************************************************************************************
 *  END OF FILE: Dem_Validation.h
 *********************************************************************************************************************/
