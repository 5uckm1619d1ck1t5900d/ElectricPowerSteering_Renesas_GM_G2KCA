/* Kernbauer Version: 2.16 Konfiguration: RH850 Erzeugungsgangnummer: 222 Zweig: 4 */

/*****************************************************************************
| Project Name: MICROSAR OS
|    File Name: osSysCall.c
|
|  Module version: $vv$=1.05
|
|  Description: Implements RH850 system calls for Green Hills compiler
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2011-2015 Vector Informatik GmbH          All rights reserved.
|****************************************************************************/

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

#if defined USE_QUOTE_INCLUDES
 #include "osek.h"
 #include "osekext.h"
#else
 #include <osek.h>
 #include <osekext.h>
#endif

/* CovComment 0:  file: osSysCall.c */

/* This file contains compiler specific code which causes MISRA warnings.
   This cannot be prevented. Therefore this file is excluded from MISRA checking. */
/* PRQA S 1-9999 EOF */

/* KB begin osekStartOfCModule (overwritten) */
#pragma ghs section bss=".os_bss"
#pragma ghs section data=".os_data"
#pragma ghs section sbss=".os_sbss"
#pragma ghs section sdata=".os_sdata"
#pragma ghs section text=".os_text"
#pragma ghs section rodata=".os_rodata"
#pragma ghs section rosdata=".os_rosdata"
/* KB end osekStartOfCModule */

extern osuint32 osSysCallOffset00[];
extern osuint32 osSysCallOffset01[];
extern osuint32 osSysCallOffset02[];
extern osuint32 osSysCallOffset03[];
extern osuint32 osSysCallOffset04[];
extern osuint32 osSysCallOffset05[];
extern osuint32 osSysCallOffset06[];
extern osuint32 osSysCallOffset07[];
extern osuint32 osSysCallOffset08[];
extern osuint32 osSysCallOffset09[];

extern osuint32 osSysCallOffset10[];
extern osuint32 osSysCallOffset11[];
extern osuint32 osSysCallOffset12[];
extern osuint32 osSysCallOffset13[];
extern osuint32 osSysCallOffset14[];
extern osuint32 osSysCallOffset15[];
extern osuint32 osSysCallOffset16[];
extern osuint32 osSysCallOffset17[];
extern osuint32 osSysCallOffset18[];
extern osuint32 osSysCallOffset19[];

extern osuint32 osSysCallOffset20[];
extern osuint32 osSysCallOffset21[];
extern osuint32 osSysCallOffset22[];
extern osuint32 osSysCallOffset23[];
extern osuint32 osSysCallOffset24[];
extern osuint32 osSysCallOffset25[];
extern osuint32 osSysCallOffset26[];
extern osuint32 osSysCallOffset27[];
extern osuint32 osSysCallOffset28[];
extern osuint32 osSysCallOffset29[];

extern osuint32 osSysCallOffset30[];
extern osuint32 osSysCallOffset31[];
extern osuint32 osSysCallOffset32[];
extern osuint32 osSysCallOffset33[];
extern osuint32 osSysCallOffset34[];
extern osuint32 osSysCallOffset35[];
extern osuint32 osSysCallOffset36[];
extern osuint32 osSysCallOffset37[];
extern osuint32 osSysCallOffset38[];
extern osuint32 osSysCallOffset39[];

extern osuint32 osSysCallOffset40[];
extern osuint32 osSysCallOffset41[];
extern osuint32 osSysCallOffset42[];
extern osuint32 osSysCallOffset43[];
extern osuint32 osSysCallOffset44[];
extern osuint32 osSysCallOffset45[];
extern osuint32 osSysCallOffset46[];
extern osuint32 osSysCallOffset47[];
extern osuint32 osSysCallOffset48[];
extern osuint32 osSysCallOffset49[];

extern osuint32 osSysCallOffset50[];
extern osuint32 osSysCallOffset51[];
extern osuint32 osSysCallOffset52[];
extern osuint32 osSysCallOffset53[];
extern osuint32 osSysCallOffset54[];
extern osuint32 osSysCallOffset55[];
extern osuint32 osSysCallOffset56[];
extern osuint32 osSysCallOffset57[];
extern osuint32 osSysCallOffset58[];
extern osuint32 osSysCallOffset59[];

extern osuint32 osSysCallOffset60[];
extern osuint32 osSysCallOffset61[];
extern osuint32 osSysCallOffset62[];
extern osuint32 osSysCallOffset63[];
extern osuint32 osSysCallOffset64[];
extern osuint32 osSysCallOffset65[];
extern osuint32 osSysCallOffset66[];
extern osuint32 osSysCallOffset67[];
extern osuint32 osSysCallOffset68[];
extern osuint32 osSysCallOffset69[];
extern osuint32 osSysCallOffset70[];
extern osuint32 osSysCallOffset71[];
extern osuint32 osSysCallOffset72[];
extern osuint32 osSysCallOffset73[];
extern osuint32 osSysCallOffset74[];
extern osuint32 osSysCallOffset75[];
extern osuint32 osSysCallOffset76[];

#pragma ghs startdata
#pragma ghs section rodata=".osSysCallTable"
#pragma alignvar(16)
const osuint32 osSysCallTable[osdNumberOfSysCallFunctions] =
{
   (osuint32)osSysCallOffset00,
   (osuint32)osSysCallOffset01,
   (osuint32)osSysCallOffset02,
   (osuint32)osSysCallOffset03,
   (osuint32)osSysCallOffset04,
   (osuint32)osSysCallOffset05,
   (osuint32)osSysCallOffset06,
   (osuint32)osSysCallOffset07,
   (osuint32)osSysCallOffset08,
   (osuint32)osSysCallOffset09,

   (osuint32)osSysCallOffset10,
   (osuint32)osSysCallOffset11,
   (osuint32)osSysCallOffset12,
   (osuint32)osSysCallOffset13,
   (osuint32)osSysCallOffset14,
   (osuint32)osSysCallOffset15,
   (osuint32)osSysCallOffset16,
   (osuint32)osSysCallOffset17,
   (osuint32)osSysCallOffset18,
   (osuint32)osSysCallOffset19,

   (osuint32)osSysCallOffset20,
   (osuint32)osSysCallOffset21,
   (osuint32)osSysCallOffset22,
   (osuint32)osSysCallOffset23,
   (osuint32)osSysCallOffset24,
   (osuint32)osSysCallOffset25,
   (osuint32)osSysCallOffset26,
   (osuint32)osSysCallOffset27,
   (osuint32)osSysCallOffset28,
   (osuint32)osSysCallOffset29,

   (osuint32)osSysCallOffset30,
   (osuint32)osSysCallOffset31,
   (osuint32)osSysCallOffset32,
   (osuint32)osSysCallOffset33,
   (osuint32)osSysCallOffset34,
   (osuint32)osSysCallOffset35,
   (osuint32)osSysCallOffset36,
   (osuint32)osSysCallOffset37,
   (osuint32)osSysCallOffset38,
   (osuint32)osSysCallOffset39,

   (osuint32)osSysCallOffset40,
   (osuint32)osSysCallOffset41,
   (osuint32)osSysCallOffset42,
   (osuint32)osSysCallOffset43,
   (osuint32)osSysCallOffset44,
   (osuint32)osSysCallOffset45,
   (osuint32)osSysCallOffset46,
   (osuint32)osSysCallOffset47,
   (osuint32)osSysCallOffset48,
   (osuint32)osSysCallOffset49,

   (osuint32)osSysCallOffset50,
   (osuint32)osSysCallOffset51,
   (osuint32)osSysCallOffset52,
   (osuint32)osSysCallOffset53,
   (osuint32)osSysCallOffset54,
   (osuint32)osSysCallOffset55,
   (osuint32)osSysCallOffset56,
   (osuint32)osSysCallOffset57,
   (osuint32)osSysCallOffset58,
   (osuint32)osSysCallOffset59,
   
   (osuint32)osSysCallOffset60,
   (osuint32)osSysCallOffset61,
   (osuint32)osSysCallOffset62,
   (osuint32)osSysCallOffset63,
   (osuint32)osSysCallOffset64,
   (osuint32)osSysCallOffset65,
   (osuint32)osSysCallOffset66,
   (osuint32)osSysCallOffset67,
   (osuint32)osSysCallOffset68,
   (osuint32)osSysCallOffset69,
   (osuint32)osSysCallOffset70,
   (osuint32)osSysCallOffset71,
   (osuint32)osSysCallOffset72,
   (osuint32)osSysCallOffset73,
   (osuint32)osSysCallOffset74,
   (osuint32)osSysCallOffset75,
   (osuint32)osSysCallOffset76
};
#pragma ghs enddata
#pragma ghs section rodata=".os_rodata"

#pragma asm
   .section ".os_text"
#ifdef osdSoftwareStackCheck
osdAsmSoftwareStackCheck .equ 1
#else
osdAsmSoftwareStackCheck .equ 0
#endif
#pragma endasm

#define osPsysDummy(FuncName)      \
   .align  4                     ; \
   .globl  _osSysCall##FuncName  ; \
_osSysCall##FuncName:            ; \
   jr   _osSysCall##FuncName

#define osPsysWrapper1(FuncName)          \
   .align  4                            ; \
   .globl  _osPsysCall##FuncName        ; \
_osPsysCall##FuncName:                  ; \
   stsr    PSW, r11                     ; /* r11 = PSW */ \
   shr     30, r11                      ; /* r11 = r11 >> 30 */ \
   cmp     zero, r11                    ; /* r11 == 0 */ \
   bne     _osPsysUM##FuncName          ; /* if r11 != 0 branch to label _osPsysUM<FuncName> */ \
   pushsp  lp-lp                        ; /* push lp onto stack */ \
   jarl    _os##FuncName, lp            ; /* call _os<FuncName> */ \
   popsp   lp-lp                        ; /* restore lp from stack */ \
   jmp     [lp]                         ; /* branch to caller */ \
_osPsysUM##FuncName:                    ; \
   nop                                  ; /* improve interrupt latency */ \
   syscall osdSysCall##FuncName         ; /* call <FuncName> via syscall */ \
   jmp     [lp]                         ; /* branch to caller */ \
   .align  4                            ; \
   .globl  _osSysCall##FuncName         ; \
_osSysCall##FuncName:                   ; \
   stsr    EIPC,  r11                   ; /* r11 = EIPC */ \
   stsr    EIPSW, r12                   ; /* r12 = EIPSW */ \
   pushsp  r11-r12                      ; /* push EIPC and EIPSW onto stack */ \
   andi    0x20, r12, r12               ; /* r12 &= 0x20 */ \
   cmp     r0, r12                      ; /* r12 == 0 */ \
   bne     _osPsysStart##FuncName       ; /* if r12 != 0 branch to  label _osPsysStart<FuncName> */ \
   ei                                   ; /* enable interrupts */ \
_osPsysStart##FuncName:                 ; \
   pushsp  lp-lp                        ; /* push lp onto stack */ \
   jarl    _os##FuncName, lp            ; /* call _os<FuncName> */ \
   popsp   lp-lp                        ; /* restore lp from stack */ \
   di                                   ; /* disable interrupts */ \
.if osdAsmSoftwareStackCheck==1         ; \
   stsr    MPLA0, r11                   ; /* r11 = MPLA0 */ \
   ld.w    0[r11], r11                  ; /* r11 = *(uint32*)(r11) */ \
   mov     osdStackCheckPattern, r12    ; /* r12 = osdStackCheckPattern */ \
   cmp     r11, r12                     ; /* r11 == r12 */ \
   bne     _osStackCheckFailed          ; /* if r11 != r12 branch to label _osStackCheckFailed */ \
.endif                                  ; \
   popsp   r11-r12                      ; /* restore EIPC and EIPSW from stack */ \
   ldsr    r11, EIPC                    ; /* EIPC = r11 */ \
   ldsr    r12, EIPSW                   ; /* EIPSW = r12 */ \
   eiret                                ; /* return from exception */

#define osPsysWrapper2(FuncName)          \
   .align  4                            ; \
   .globl  _osPsysCall##FuncName        ; \
_osPsysCall##FuncName:                  ; \
   stsr    PSW, r11                     ; /* r11 = PSW */ \
   shr     30, r11                      ; /* r11 = r11 >> 30 */ \
   cmp     zero, r11                    ; /* r11 == 0 */ \
   bne     _osPsysUM##FuncName          ; /* if r11 != 0 branch to label _osPsysUM<FuncName> */ \
   pushsp  lp-lp                        ; /* push lp onto stack */ \
   jarl    _os##FuncName, lp            ; /* call _os<FuncName> */ \
   popsp   lp-lp                        ; /* restore lp from stack */ \
   nop                                  ; /* improve interrupt latency */ \
   syscall osdSysCallDispatcher         ; /* start dispatcher via syscall */ \
   jmp     [lp]                         ; /* return to caller */ \
_osPsysUM##FuncName:                    ; \
   nop                                  ; /* improve interrupt latency */ \
   syscall osdSysCall##FuncName         ; /* start function via syscall */ \
   jmp     [lp]                         ; /* return to caller */ \
   .align  4                            ; \
   .globl  _osSysCall##FuncName         ; \
_osSysCall##FuncName:                   ; \
   stsr    EIPC,  r11                   ; /* r11 = EIPC */ \
   stsr    EIPSW, r12                   ; /* r12 = EIPSW */ \
   pushsp  r11-r12                      ; /* push EIPC and EIPSW onto stack */ \
   andi    0x20, r12, r12               ; /* r12 = r12 & 0x20 = EIPSW & 0x20 */ \
   cmp     r0, r12                      ; /* cmp r12 == 0 */ \
   bne     _osPsysStart##FuncName       ; /* if r12 != 0 then branch to _osPsysStart<FuncName> */ \
   ei                                   ; /* enable global interrupts */ \
_osPsysStart##FuncName:                 ; \
   pushsp  lp-lp                        ; /* push lp onto stack */ \
   jarl    _os##FuncName, lp            ; /* call API function _os<FuncName> */ \
   popsp   lp-lp                        ; /* restore lp from stack */ \
   di                                   ; /* disable global interrupts */ \
   popsp   r11-r12                      ; /* restore EIPC and EIPSW from stack */ \
   ldsr    r11, EIPC                    ; /* EIPC  = r11 */ \
   ldsr    r12, EIPSW                   ; /* EIPSW = r12 */ \
   jr      _osTrapDispatcher_c0         ; /* call the dispatcher */
   
#define osPsysWrapper3(FuncName)   \
   .align  4                     ; \
   .globl  _osPsysCall##FuncName ; \
_osPsysCall##FuncName:           ; \
   nop                           ; /* improve interrupt latency */ \
   syscall osdSysCall##FuncName  ; /* start function via syscall */ \
   jmp     [lp]                  ; /* return to caller */ \
   .align  4                     ; \
   .globl  _osSysCall##FuncName  ; \
_osSysCall##FuncName:            ; \
   pushsp  lp-lp                 ; /* push lp onto stack */ \
   jarl    _os##FuncName, lp     ; /* call  os<FuncName> */ \
   popsp   lp-lp                 ; /* restore lp from stack */ \
   eiret                         ; /* return from exception */

#define osPsysWrapper4(FuncName)   \
   .align  4                     ; \
   .globl  _osPsysCall##FuncName ; \
_osPsysCall##FuncName:           ; \
   stsr    PSW, r11              ; /* r11 = PSW */ \
   shr     30, r11               ; /* r11 = r11 >> 30 */ \
   cmp     zero, r11             ; /* r11 == 0 */ \
   bne     _osPsysUM##FuncName   ; /* if r11 != 0 branch to label _osPsysUM<FuncName> */ \
   pushsp  lp-lp                 ; /* push lp onto stack */ \
   jarl    _osos##FuncName, lp   ; /* call os<FuncName> */ \
   popsp   lp-lp                 ; /* restore lp from stack */ \
   jmp     [lp]                  ; /* branch to caller */ \
_osPsysUM##FuncName:             ; \
   nop                           ; /* improve interrupt latency */ \
   syscall osdSysCall##FuncName  ; /* start function via syscall */ \
   jmp     [lp]                  ; /* return to caller */ \
   .align  4                     ; \
   .globl  _osSysCall##FuncName  ; \
_osSysCall##FuncName:            ; \
   pushsp  lp-lp                 ; /* push lp onto stack */ \
   jarl    _osos##FuncName, lp   ; /* call  os<FuncName> */ \
   popsp   lp-lp                 ; /* restore lp from stack */ \
   eiret                         ; /* return from exception */


#ifdef osdSoftwareStackCheck     
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osStackCheckFailed
_osStackCheckFailed:   
   jarl    _osStackOverflowDetected, lp
#pragma endasm
#endif

#pragma asm
   .section ".os_text"

   osPsysWrapper2(ActivateTask)
   osPsysWrapper2(ChainTask)
   osPsysWrapper2(TerminateTask)
   osPsysWrapper2(Schedule)
   osPsysWrapper2(IncrementCounter)   
      
   osPsysWrapper1(GetResource)
   osPsysWrapper2(ReleaseResource)
   
   osPsysWrapper1(SetAbsAlarm)
   osPsysWrapper1(SetRelAlarm)
   osPsysWrapper1(CancelAlarm)
   osPsysWrapper1(GetAlarm)
   
   osPsysWrapper1(GetEvent)
   osPsysWrapper1(ClearEvent)
   osPsysWrapper2(WaitEvent)
   osPsysWrapper2(SetEvent)   
   
   osPsysWrapper1(StartScheduleTableAbs)
   osPsysWrapper1(StartScheduleTableRel)
   osPsysWrapper1(StopScheduleTable)
   osPsysWrapper1(NextScheduleTable)
   osPsysWrapper1(GetScheduleTableStatus)   
   
   #if (osdNumberOfSemaphores > 0)   
   osPsysWrapper2(GetSemaphore)
   osPsysWrapper2(ReleaseSemaphore)
   #else
   osPsysDummy(GetSemaphore)
   osPsysDummy(ReleaseSemaphore)            
   #endif

   osPsysWrapper3(CheckObjectOwnership)
   osPsysWrapper3(CheckObjectAccess)
         
   osPsysWrapper3(GetTaskID)
   osPsysWrapper3(GetTaskState)
   osPsysWrapper3(GetApplicationState)
   osPsysWrapper3(GetCounterValue)
   osPsysWrapper3(GetElapsedValue)
   
   osPsysWrapper3(DisableAllInterrupts)         
   osPsysWrapper3(EnableAllInterrupts)         
   
   osPsysWrapper3(SuspendOSInterrupts)         
   osPsysWrapper3(ResumeOSInterrupts)         
   
   osPsysWrapper3(SuspendAllInterrupts)         
   osPsysWrapper3(ResumeAllInterrupts)

   osPsysWrapper4(ReadPeripheral8)
   osPsysWrapper4(ReadPeripheral16)
   osPsysWrapper4(ReadPeripheral32)      

   osPsysWrapper4(WritePeripheral8)
   osPsysWrapper4(WritePeripheral16)
   osPsysWrapper4(WritePeripheral32)         
   
   osPsysWrapper4(ModifyPeripheral8)
   osPsysWrapper4(ModifyPeripheral16)
   osPsysWrapper4(ModifyPeripheral32)

#pragma endasm

/*****************************************************************************/
/* Function osStartNonTrustedTask                                            */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osStartNonTrustedTask
_osStartNonTrustedTask:
   -- r6 contains task stack start address
   -- r7 contains task stack end address   
   -- r8 contains task function start address
   #ifdef osdSoftwareStackCheck
   stsr    MPLA0, r11                       -- r11 = MPLA0
   ld.w    0[r11], r11                      -- r11 = *(uint32*)r11 -> get value from system stack bottom address
   mov     osdStackCheckPattern, r12        -- r12 = osdStackCheckPattern
   cmp     r11, r12                         -- compare r11 and r12
   bne     _osStackCheckFailed              -- if r11 != r12 then branch to _osStackOverflowDetected   
   #endif   
   _osDisableFEINT                          -- disable FE level interrupts   
   ldsr    r6, MPLA0                        -- MLPA0 = r6 -> stack bottom address
   mov     r7, sp                           -- sp = r7 -> switch to task stack  
   addi    -4, r7, r7                       -- r7 = r7 - 4 -> MPU granularity adjustment  
   ldsr    r7, MPUA0                        -- MPUA0 = r7 -> stack top address
   ldsr    r8, EIPC                         -- EIPC = r8 -> set task start address
   stsr    EIPSW, r8                        -- r8 = EIPSW
   mov     0xFFFFFF5F, r7                   -- r7 = 0xFFFFFF5F -> prepare mask for global EI and FE interrupts enabled
   and     r7, r8                           -- r8 = r7 & r8 
   mov     0x40000000, r7                   -- r7 = 0x40000000 -> prepare mask for user mode
   or      r7, r8                           -- r8 = r7 | r8
   ldsr    r8, EIPSW                        -- EIPSW = r8
   #if (STATUS_LEVEL == EXTENDED_STATUS) && (osdNumberOfAllTasks > 0)
   mov     _osPsysMissingTerminateTask, lp  -- lp = _osMissingTerminateTask -> prepare missing terminate error
   #endif
   eiret                                    -- return from exception 
#pragma endasm

#if (STATUS_LEVEL == EXTENDED_STATUS) && (osdNumberOfAllTasks > 0)
/*****************************************************************************/
/* Function osPsysMissingTerminateTask                                       */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysMissingTerminateTask
_osPsysMissingTerminateTask:
   nop                                       -- improve interrupt latency
   syscall osdSysCallMissingTerminateTask    -- start function via syscall
   jmp     [lp]                              -- return to caller
#pragma endasm
#endif

#if (osdNumberOfCat2ISRs > 0)
/*****************************************************************************/
/* Function osStartNonTrustedISR                                             */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osStartNonTrustedISR
_osStartNonTrustedISR:
   -- r6 contains ISR function address
   -- r7 contains new PSW
   -- r8 contains new PMR
   pushsp  r1-r2                           -- push r1 and r2 onto stack      
   pushsp  r4-r31                          -- push r4 ... r31 onto stack
   stsr    MPUA0, r11                      -- r11 = MPUA0
   pushsp  r11-r11                         -- push MPUA0 onto stack
   addi    -4, sp, r11                     -- r11 = sp - 4 -> prepare MPUA0
   ldsr    r11, MPUA0                      -- MPUA0 = r11 -> stack top address
   
   mov     _osReturnFromNonTrustedIsr, lp  -- lp = _osReturnFromNonTrustedIsr -> prepare return address 
   ldsr    r7, PSW                         -- PSW = r7
   jmp     [r6]                            -- branch to ISR function with address given in r6
   
_osReturnFromNonTrustedIsr:
   nop                                     -- improve interrupt latency
   syscall osdSysCallSwitchToSVMode        -- switch to supervisor mode via syscall
_osReturnPrivilegedModeNonTrustedIsr:
   di                                      -- disable global interrupts         
   popsp   r11-r11                         -- restore MPUA0 from stack
   ldsr    r11, MPUA0                      -- MPUA0 = r11                    
   popsp   r4-r31                          -- restore r4 ... r31 from stack
   popsp   r1-r2                           -- restore r1 and r2 from stack
   jmp     [lp]                            -- return to caller
#pragma endasm
#endif

/*****************************************************************************/
/* Wrapper for osShutdownOS                                                  */
/*****************************************************************************/                                                                        
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysShutdownOS
_osPsysShutdownOS:
   nop                                 -- improve interrupt latency
   syscall osdSysCallShutdownOS        -- start function via syscall
   jmp     [lp]                        -- return to caller

   .align  4
   .globl  _osSysCallShutdownOS
_osSysCallShutdownOS:
   stsr    MPLA0, r11                  -- r11 = MPLA0
   stsr    MPUA0, r12                  -- r12 = MPUA0
   pushsp  r11-r12                     -- push MPLA0 and MPUA0 onto current stack
   
   mov     sp, r12                     -- r12 = sp
   _osSwitchToCoreSystemStack          -- switch to system stack
   pushsp  r12-r12                     -- push old stack stack pointer onto system stack      

   pushsp  lp-lp                       -- push LP onto current stack   
   jarl    _osShutdownOS, lp           -- call osShutdownOS   
   popsp   lp-lp                       -- restore LP from stack
   ld.w    0[sp], sp                   -- sp = *(sp) -> switch back to previous stack
      
   popsp   r11-r12                     -- restore MPLA0 and MPUA0 from stack   
   ldsr    r11, MPLA0                  -- MPLA0 = r11
   ldsr    r12, MPUA0                  -- MPUA0 = r12
   eiret                               -- return from exception
#pragma endasm

/*****************************************************************************/
/* Wrapper for osCallTrustedFunction                                         */
/*****************************************************************************/                                                                        
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysCallTrustedFunction
_osPsysCallTrustedFunction:
   nop                                 -- improve interrupt latency
   syscall osdSysCallTrustedFunction   -- start function via syscall
   jmp     [lp]                        -- return to caller

   .align  4
   .globl  _osSysCallTrustedFunction
_osSysCallTrustedFunction:
   stsr    EIPC,  r11                  -- r11 = EIPC
   stsr    EIPSW, r12                  -- r12 = EIPSW
   pushsp  r11-r12                     -- push EIPC and EIPSW onto stack
   
   andi    0x20, r12, r12              -- r12 &= 0x20
   cmp     r0, r12                     -- compare r12 == 0
   bne     _osSysCallStartTrustedFunc  -- if r12 != 0 then branch to label _osSysCallStartTrustedFunc
   ei                                  -- enable interrupts
_osSysCallStartTrustedFunc:
   pushsp  lp-lp                       -- push LP onto stack
   jarl    _osCallTrustedFunction, lp  -- call osCallTrustedFunction
   popsp   lp-lp                       -- restore LP from stack   
   stsr    PSW, r13                    -- r13 = PSW
   di                                  -- disable interrupts

   #ifdef osdSoftwareStackCheck
   stsr    MPLA0, r11                  -- r11 = MPLA0
   ld.w    0[r11], r11                 -- r11 = *(uint32*)r11 -> get value from stack bottom address
   mov     osdStackCheckPattern, r12   -- r12 = osdStackCheckPattern
   cmp     r11, r12                    -- compare r11 == r12
   bne     _osStackCheckFailed         -- Jump to osStackOverflowDetected with no return
   #endif
   
   popsp   r11-r12                     -- restore EIPC and EIPSW from stack
   ldsr    r11, EIPC                   -- EIPC  = r11
   mov     0xFFFFFFDF, r11             -- r11 = 0xFFFFFFDF
   and     r11, r12                    -- r12 &= r11
   andi    0x20, r13, r13              -- r13 &= 0x20
   or      r13, r12                    -- r12 |= r13
   ldsr    r12, EIPSW                  -- EIPSW = r12
   eiret                               -- return from exception
#pragma endasm

/*****************************************************************************/
/* Wrapper for osCallNonTrustedFunction                                      */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysCallNonTrustedFunction
_osPsysCallNonTrustedFunction:
   nop                                    -- improve interrupt latency
   syscall osdSysCallNonTrustedFunction   -- start function via syscall
   jmp     [lp]                           -- return to caller

   .align  4
   .globl  _osSysCallNonTrustedFunction
_osSysCallNonTrustedFunction:
   stsr    EIPC,  r11                     -- r11 = EIPC  
   stsr    EIPSW, r12                     -- r12 = EIPSW
   pushsp  r11-r12                        -- push EIPC and EIPSW onto stack

   #if osdRH850_FPU
   stsr    FPSR,  r11                     -- r11 = FPSR
   stsr    FPEPC, r12                     -- r12 = FPEPC
   pushsp  r11-r12                        -- push FPSR and FPEPC onto stack    
   #endif   

   pushsp  lp-lp                          -- push LP onto stack   
   jarl    _osCallNonTrustedFunction, lp  -- call osCallNonTrustedFunction
   popsp   lp-lp                          -- restore LP from stack
   
   #if osdRH850_FPU
   popsp   r11-r12                        -- restore FPSR and FPEPC from stack       
   ldsr    r11, FPSR                      -- FPSR = r11
   ldsr    r12, FPEPC                     -- FPEPC = r12
   #endif     
      
   popsp   r11-r12                        -- restore EIPC and EIPSW from stack
   ldsr    r11, EIPC                      -- EIPC  = r11
   mov     0xFFFFFFDF, r11                -- r11 = 0xFFFFFFDF
   and     r11, r12                       -- r12 &= r11
   stsr    EIPSW, r11                     -- r11 = EIPSW   
   andi    0x20, r11, r11                 -- r11 &= 0x20      
   or      r11, r12                       -- r12 |= r11  
   ldsr    r12, EIPSW                     -- EIPSW = r12
   eiret                                  -- return from exception
#pragma endasm

/*****************************************************************************/
/* Function osStartNonTrustedFunc                                            */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osStartNonTrustedFunc
_osStartNonTrustedFunc:
   -- r6 contains function index which shall not be overwritten
   -- r7 contains function params which shall not be overwritten
   -- r8 contains function start address which shall not be overwritten
   pushsp  r1-r2                            -- push r1 and r2 onto stack
   pushsp  r4-r31                           -- push r4 ... r31 onto stack
   stsr    MPLA0, r11                       -- r11 = MPLA0 
   stsr    MPUA0, r12                       -- r12 = MPUA0 
   pushsp  r11-r12                          -- push MPLA0 and MPUA0 onto stack   
      
   addi    -4, sp, r11                      -- r11 = sp - 4 -> prepare MPUA0 
   ldsr    r11, MPUA0                       -- MPUA0 = r11
   mov     _osReturnFromNonTrustedFunc, lp  -- lp = _osReturnFromNonTrustedFunc -> prepare return address 

   stsr    PSW, r11                         -- r11 = PSW
   mov     0xFFFFFFDF, r12                  -- r12 = 0xFFFFFFDF -> prepare global interrupts enabled
   and     r12, r11                         -- r11 = r11 & r12
   mov     0x40000000, r12                  -- r12 = 0x40000000 -> prepare CPU in user mode
   or      r12, r11                         -- r11 = r11 | r12
   stsr    EIPSW, r12                       -- r12 = EIPSW
   andi    0x20, r12, r12                   -- r12 &= 0x20
   or      r12, r11                         -- r11 = r11 | r12   
   ldsr    r11, PSW                         -- PSW = r11
   jmp     [r8]                             -- branch to non-trusted function with address given in r8
                                           
_osReturnFromNonTrustedFunc:
   nop                                      -- improve interrupt latency
   syscall osdSysCallSwitchToSVMode         -- switch to supervisor mode via syscall
_osReturnPrivilegedModeNonTrustedFunc:   
   stsr    PSW, r11                         -- r11 = PSW
   di                                       -- disable global interrupts
   ldsr    r11, EIPSW                       -- EIPSW = r11
   popsp   r11-r12                          -- restore MPLA0 and MPUA0 from stack
   ldsr    r11, MPLA0                       -- MPLA0 = r11
   ldsr    r12, MPUA0                       -- MPUA0 = r12
   popsp   r4-r31                           -- restore r4 ... r31 from stack
   popsp   r1-r2                            -- restore r1 and r2 from stack                                                 
   jmp     [lp]                             -- return to caller
#pragma endasm

/*****************************************************************************/
/* Wrapper for osWriteICRxLo                                                 */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysWriteICRxLo
_osPsysWriteICRxLo:
   nop                                       -- improve interrupt latency
   syscall osdSysCallWriteICRxLo             -- start function via syscall
   jmp     [lp]                              -- return to caller

   .align  4
   .globl  _osSysCallWriteICRxLo
_osSysCallWriteICRxLo:
   mov     osdIntMaxIndex, r11               -- r11 = osdIntMaxIndex
   cmp     r11, r6                           -- compare r6 < r11
   bh      _osSysCallWriteICRxLoInvalidIndex -- if r6 > r11 then branch to _osSysCallWriteICRxLoInvalidIndex
   mov     osdICRBASE1, r11                  -- r11 = osdICRBASE1
   mov     31, r12                           -- r12 = 31
   cmp     r12, r6                           -- compare r6 > r12
   bh      _osSysCallWriteICRx8Lo            -- if r6 > r12 then branch to _osSysCallWriteICRx8Lo
   mov     osdICRBASE0, r11                  -- r11 = osdICRBASE0   
_osSysCallWriteICRx8Lo:
   shl     1, r6                             -- r6 = r6 << 1
   add     r11, r6                           -- r6 = r6 + r11
   st.b    r7, 0[r6]                         -- *(uint8*)r6 = r7
   ld.bu   0[r6], r7                         -- dummy read
   syncm                                     -- sync memory access
   eiret                                     -- return from exception  
         
_osSysCallWriteICRxLoInvalidIndex:
   mov     E_OS_SYS_API_ERROR, r6               -- r6 = E_OS_SYS_API_ERROR  
   mov     osdErrPIWriteICRxLoInvalidIndex, r7  -- r7 = osdErrPIWriteICRxLoInvalidIndex
   jr      _osEnterSafeState                    -- branch to _osEnterSafeState
#pragma endasm

/*****************************************************************************/
/* Wrapper for osWriteICRxHi                                                 */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysWriteICRxHi
_osPsysWriteICRxHi:
   nop                                       -- improve interrupt latency
   syscall osdSysCallWriteICRxHi             -- start function via syscall
   jmp     [lp]                              -- return to caller

   .align  4
   .globl  _osSysCallWriteICRxHi
_osSysCallWriteICRxHi:
   mov     osdIntMaxIndex, r11               -- r11 = osdIntMaxIndex
   cmp     r11, r6                           -- compare r6 < r11
   bh      _osSysCallWriteICRxHiInvalidIndex -- if r6 > r11 then branch to _osSysCallWriteICRxHiInvalidIndex
   mov     osdICRBASE1, r11                  -- r11 = osdICRBASE1
   mov     31, r12                           -- r12 = 31
   cmp     r12, r6                           -- compare r6 > r12
   bh      _osSysCallWriteICRx8Hi            -- if r6 > r12 then branch to _osSysCallWriteICRx8Hi
   mov     osdICRBASE0, r11                  -- r11 = osdICRBASE0
_osSysCallWriteICRx8Hi:
   shl     1, r6                             -- r6 = r6 << 1
   add     r11, r6                           -- r6 = r6 + r11
   st.b    r7, 1[r6]                         -- *(uint8*)(r6+1) = r7
   ld.bu   1[r6], r7                         -- dummy read   
   syncm                                     -- sync memory access
   eiret                                     -- return from exception           

_osSysCallWriteICRxHiInvalidIndex:
   mov     E_OS_SYS_API_ERROR, r6               -- r6 = E_OS_SYS_API_ERROR  
   mov     osdErrPIWriteICRxHiInvalidIndex, r7  -- r7 = osdErrPIWriteICRxHiInvalidIndex
   jr      _osEnterSafeState                    -- branch to _osEnterSafeState
#pragma endasm

/*****************************************************************************/
/* Wrapper for osWriteICRx16                                                 */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysWriteICRx16
_osPsysWriteICRx16:
   nop                                        -- improve interrupt latency
   syscall osdSysCallWriteICRx16              -- start function via syscall
   jmp     [lp]                               -- return to caller

   .align  4
   .globl  _osSysCallWriteICRx16
_osSysCallWriteICRx16:
   mov     osdIntMaxIndex, r11                -- r11 = osdIntMaxIndex
   cmp     r11, r6                            -- compare r6 > r11
   bh      _osSysCallWriteICRx16InvalidIndex  -- if r6 > r11 then branch to _osSysCallWriteICRx16InvalidIndex
   mov     osdICRBASE1, r11                   -- r11 = osdICRBASE1
   mov     31, r12                            -- r12 = 31
   cmp     r12, r6                            -- compare r6 > r12
   bh      _osSysCallWriteICRx16Bit           -- if r6 > r12 then branch to _osSysCallWriteICRx16Bit
   mov     osdICRBASE0, r11                   -- r11 = osdICRBASE0
_osSysCallWriteICRx16Bit:
   shl     1, r6                              -- r6 = r6 << 1
   add     r11, r6                            -- r6 = r6 + r11
   st.h    r7, 0[r6]                          -- *(uint16*)r6 = r7
   ld.hu   0[r6], r7                          -- dummy read   
   syncm                                      -- sync memory access
   eiret                                      -- return from exception           

_osSysCallWriteICRx16InvalidIndex:
   mov     E_OS_SYS_API_ERROR, r6               -- r6 = E_OS_SYS_API_ERROR  
   mov     osdErrPIWriteICRx16InvalidIndex, r7  -- r7 = osdErrPIWriteICRx16InvalidIndex
   jr      _osEnterSafeState                    -- branch to _osEnterSafeState
#pragma endasm

/*****************************************************************************/
/* Wrapper for osWriteICR8                                                   */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysWriteICR8
_osPsysWriteICR8:
   nop                          -- improve interrupt latency
   syscall osdSysCallWriteICR8  -- start function via syscall
   jmp     [lp]                 -- return to caller

   .align  4
   .globl  _osSysCallWriteICR8
_osSysCallWriteICR8:
   mov     osdICR0MIN, r11                 -- r11 = osdICR0MIN
   cmp     r11, r6                         -- compare r6 < r11
   bl      _osSysCallWriteICR8InvalidAddr  -- if r6 < r11 then branch to _osSysCallWriteICR8InvalidAddr
   mov     osdICR0MAX8, r11                -- r11 = osdICR0MAX8
   cmp     r11, r6                         -- compare r6 < r11
   bl      _osSysCallWriteICR8Reg          -- if r6 < r11 then branch to _osSysCallWriteICR8Reg
                                    
   mov     osdICRxMIN, r11                 -- r11 = osdICRxMIN
   cmp     r11, r6                         -- compare r6 < r11
   bl      _osSysCallWriteICR8InvalidAddr  -- if r6 < r11 then branch to _osSysCallWriteICR8InvalidAddr
   mov     osdICRxMAX8, r11                -- r11 = osdICRxMAX8
   cmp     r11, r6                         -- compare r6 > r11
   bh      _osSysCallWriteICR8InvalidAddr  -- if r6 > r11 then branch to _osSysCallWriteICR8InvalidAddr
                                    
_osSysCallWriteICR8Reg:                    
   st.b    r7, 0[r6]                       -- *(uint8*)r6 = r7
   ld.bu   0[r6], r7                       -- dummy read   
   syncm                                   -- sync memory access
   eiret                                   -- return from exception           
   
_osSysCallWriteICR8InvalidAddr:
   mov     E_OS_SYS_API_ERROR, r6            -- r6 = E_OS_SYS_API_ERROR  
   mov     osdErrPIWriteICR8InvalidAddr, r7  -- r7 = osdErrPIWriteICR8InvalidAddr
   jr      _osEnterSafeState                 -- branch to _osEnterSafeState  
#pragma endasm

/*****************************************************************************/
/* Wrapper for osWriteICR16                                                  */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysWriteICR16
_osPsysWriteICR16:
   nop                           -- improve interrupt latency
   syscall osdSysCallWriteICR16  -- start function via syscall
   jmp     [lp]                  -- return to caller

   .align  4
   .globl  _osSysCallWriteICR16
_osSysCallWriteICR16:
   mov     osdICR0MIN, r11                  -- r11 = osdICR0MIN
   cmp     r11, r6                          -- compare r6 < r11
   bl      _osSysCallWriteICR16InvalidAddr  -- if r6 < r11 then branch to _osSysCallWriteICR16InvalidAddr
   mov     osdICR0MAX16, r11                -- r11 = osdICR0MAX16
   cmp     r11, r6                          -- compare r6 < r11
   bl      _osSysCallWriteICR16Reg          -- if r6 < r11 then branch to _osSysCallWriteICR16Reg

   mov     osdICRxMIN, r11                  -- r11 = osdICRxMIN
   cmp     r11, r6                          -- compare r6 < r11
   bl      _osSysCallWriteICR16InvalidAddr  -- if r6 < r11 then branch to _osSysCallWriteICR16InvalidAddr
   mov     osdICRxMAX16, r11                -- r11 = osdICRxMAX16
   cmp     r11, r6                          -- compare r6 > r11
   bh      _osSysCallWriteICR16InvalidAddr  -- if r6 > r11 then branch to _osSysCallWriteICR16InvalidAddr

_osSysCallWriteICR16Reg:                    
   st.h    r7, 0[r6]                        -- *(uint16*)r6 = r7
   ld.hu   0[r6], r7                        -- dummy read   
   syncm                                    -- sync memory access
   eiret                                    -- return from exception           

_osSysCallWriteICR16InvalidAddr:
   mov     E_OS_SYS_API_ERROR, r6             -- r6 = E_OS_SYS_API_ERROR  
   mov     osdErrPIWriteICR16InvalidAddr, r7  -- r7 = osdErrPIWriteICR16InvalidAddr
   jr      _osEnterSafeState                  -- branch to _osEnterSafeState  
#pragma endasm

/*****************************************************************************/
/* Wrapper for osSetICRMask                                                  */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysSetICRMask
_osPsysSetICRMask:
   nop                           -- improve interrupt latency
   syscall osdSysCallSetICRMask  -- start function via syscall
   jmp     [lp]                  -- return to caller

   .align  4
   .globl  _osSysCallSetICRMask
_osSysCallSetICRMask:
   mov     osdICR0MIN, r11                  -- r11 = osdICR0MIN
   cmp     r11, r6                          -- compare r6 < r11
   bl      _osSysCallSetICRMaskInvalidAddr  -- if r6 < r11 then branch to _osSysCallSetICRMaskInvalidAddr
   mov     osdICR0MAX16, r11                -- r11 = osdICR0MAX16
   cmp     r11, r6                          -- compare r6 < r11
   bl      _osSysCallSetICRMaskReg          -- if r6 < r11 then branch to _osSysCallSetICRMaskReg

   mov     osdICRxMIN, r11                  -- r11 = osdICRxMIN
   cmp     r11, r6                          -- compare r6 < r11
   bl      _osSysCallSetICRMaskInvalidAddr  -- if r6 < r11 then branch to _osSysCallSetICRMaskInvalidAddr
   mov     osdICRxMAX16, r11                -- r11 = osdICRxMAX16
   cmp     r11, r6                          -- compare r6 > r11
   bh      _osSysCallSetICRMaskInvalidAddr  -- if r6 > r11 then branch to _osSysCallSetICRMaskInvalidAddr

_osSysCallSetICRMaskReg:                    
   set1    7, 0[r6]                         -- *(uint8*)r6 |= 0x80 -> set bit 7
   ld.bu   0[r6], r6                        -- dummy read
   syncm                                    -- sync memory access
   eiret                                    -- return from exception
   
_osSysCallSetICRMaskInvalidAddr:
   mov     E_OS_SYS_API_ERROR, r6             -- r6 = E_OS_SYS_API_ERROR  
   mov     osdErrPISetICRMaskInvalidAddr, r7  -- r7 = osdErrPISetICRMaskInvalidAddr
   jr      _osEnterSafeState                  -- branch to _osEnterSafeState  
#pragma endasm

/*****************************************************************************/
/* Wrapper for osClearICRMask                                                */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysClearICRMask
_osPsysClearICRMask:
   nop                             -- improve interrupt latency
   syscall osdSysCallClearICRMask  -- start function via syscall
   jmp     [lp]                    -- return to caller

   .align  4
   .globl  _osSysCallClearICRMask
_osSysCallClearICRMask:
   mov     osdICR0MIN, r11                    -- r11 = osdICR0MIN
   cmp     r11, r6                            -- compare r6 < r11
   bl      _osSysCallClearICRMaskInvalidAddr  -- if r6 < r11 then branch to _osSysCallClearICRMaskInvalidAddr
   mov     osdICR0MAX16, r11                  -- r11 = osdICR0MAX16
   cmp     r11, r6                            -- compare r6 < r11
   bl      _osSysCallClearICRMaskReg          -- if r6 < r11 then branch to _osSysCallClearICRMaskReg

   mov     osdICRxMIN, r11                    -- r11 = osdICRxMIN
   cmp     r11, r6                            -- compare r6 < r11
   bl      _osSysCallClearICRMaskInvalidAddr  -- if r6 < r11 then branch to _osSysCallClearICRMaskInvalidAddr
   mov     osdICRxMAX16, r11                  -- r11 = osdICRxMAX16
   cmp     r11, r6                            -- compare r6 > r11
   bh      _osSysCallClearICRMaskInvalidAddr  -- if r6 > r11 then branch to _osSysCallClearICRMaskInvalidAddr

_osSysCallClearICRMaskReg:                    
   clr1    7, 0[r6]                           -- *(uint8*)r6 &= 0x7F -> clear bit 7
   ld.bu   0[r6], r6                          -- dummy read
   syncm                                      -- sync memory access
   eiret                                      -- return from exceptionreturn from exception           
   
_osSysCallClearICRMaskInvalidAddr:
   mov     E_OS_SYS_API_ERROR, r6               -- r6 = E_OS_SYS_API_ERROR  
   mov     osdErrPIClearICRMaskInvalidAddr, r7  -- r7 = osdErrPIClearICRMaskInvalidAddr
   jr      _osEnterSafeState                    -- branch to _osEnterSafeState  
#pragma endasm

/*****************************************************************************/
/* Wrapper for osSetICRReq                                                   */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysSetICRReq
_osPsysSetICRReq:
   nop                          -- improve interrupt latency
   syscall osdSysCallSetICRReq  -- start function via syscall
   jmp     [lp]                 -- return to caller

   .align  4
   .globl  _osSysCallSetICRReq
_osSysCallSetICRReq:
   mov     osdICR0MIN, r11                 -- r11 = osdICR0MIN
   cmp     r11, r6                         -- compare r6 < r11
   bl      _osSysCallSetICRReqInvalidAddr  -- if r6 < r11 then branch to _osSysCallSetICRReqInvalidAddr
   mov     osdICR0MAX8, r11                -- r11 = osdICR0MAX8
   cmp     r11, r6                         -- compare r6 < r11
   bl      _osSysCallSetICRReqReg          -- if r6 < r11 then branch to _osSysCallSetICRReqReg

   mov     osdICRxMIN, r11                 -- r11 = osdICRxMIN
   cmp     r11, r6                         -- compare r6 < r11
   bl      _osSysCallSetICRReqInvalidAddr  -- if r6 < r11 then branch to _osSysCallSetICRReqInvalidAddr
   mov     osdICRxMAX8, r11                -- r11 = osdICRxMAX8
   cmp     r11, r6                         -- compare r6 > r11
   bh      _osSysCallSetICRReqInvalidAddr  -- if r6 > r11 then branch to _osSysCallSetICRReqInvalidAddr

_osSysCallSetICRReqReg:                   
   ori     0x01, r6, r6                    -- r6 = r6 | 0x01 -> adjust destination address
   set1    4, 0[r6]                        -- *(uint8*)r6 |= 0x10 -> set bit 4
   ld.bu   0[r6], r6                       -- dummy read   
   syncm                                   -- sync memory access
   eiret                                   -- return from exception
   
_osSysCallSetICRReqInvalidAddr:
   mov     E_OS_SYS_API_ERROR, r6            -- r6 = E_OS_SYS_API_ERROR  
   mov     osdErrPISetICRReqInvalidAddr, r7  -- r7 = osdErrPISetICRReqInvalidAddr
   jr      _osEnterSafeState                 -- branch to _osEnterSafeState  
#pragma endasm

/*****************************************************************************/
/* Wrapper for osClearICRReq                                                 */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysClearICRReq
_osPsysClearICRReq:
   nop                            -- improve interrupt latency
   syscall osdSysCallClearICRReq  -- start function via syscall
   jmp     [lp]                   -- return to caller

   .align  4
   .globl  _osSysCallClearICRReq
_osSysCallClearICRReq:
   mov     osdICR0MIN, r11                   -- r11 = osdICR0MIN
   cmp     r11, r6                           -- compare r6 < r11
   bl      _osSysCallClearICRReqInvalidAddr  -- if r6 < r11 then branch to _osSysCallClearICRReqInvalidAddr
   mov     osdICR0MAX8, r11                  -- r11 = osdICR0MAX8
   cmp     r11, r6                           -- compare r6 < r11
   bl      _osSysCallClearICRReqReg          -- if r6 < r11 then branch to _osSysCallClearICRReqReg
                                              
   mov     osdICRxMIN, r11                   -- r11 = osdICRxMIN
   cmp     r11, r6                           -- compare r6 < r11
   bl      _osSysCallClearICRReqInvalidAddr  -- if r6 < r11 then branch to _osSysCallClearICRReqInvalidAddr
   mov     osdICRxMAX8, r11                  -- r11 = osdICRxMAX8
   cmp     r11, r6                           -- compare r6 > r11
   bh      _osSysCallClearICRReqInvalidAddr  -- if r6 > r11 then branch to _osSysCallClearICRReqInvalidAddr
                                              
_osSysCallClearICRReqReg:                    
   ori     0x01, r6, r6                      -- r6 = r6 | 0x01 -> adjust destination address
   clr1    4, 0[r6]                          -- *(uint8*)r6 &= 0xEF -> clear bit 4
   ld.bu   0[r6], r6                         -- dummy read
   syncm                                     -- sync memory access
   eiret                                     -- return from exception

_osSysCallClearICRReqInvalidAddr:                 
   mov     E_OS_SYS_API_ERROR, r6              -- r6 = E_OS_SYS_API_ERROR   
   mov     osdErrPIClearICRReqInvalidAddr, r7  -- r7 = osdErrPIClearICRReqInvalidAddr 
   jr      _osEnterSafeState                   -- branch to _osEnterSafeState   
#pragma endasm

/*****************************************************************************/
/* Wrapper for SwitchToSVMode                                                */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osSysCallSwitchToSVMode
_osSysCallSwitchToSVMode:
   stsr    EIPC, r11                                  -- r1 = EIPC
   mov     _osReturnPrivilegedModeNonTrustedIsr, r12  -- r12 = &_osReturnPrivilegedModeNonTrustedIsr -> get address of label _osReturnFromNonTrustedIsr
   cmp     r11, r12                                   -- compare r11 with r12
   be      _osSysCallSwitchToPrivileged               -- if equal then branch to _osSysCallSwitchToPrivileged

   stsr    EIPC, r11                                  -- r11 = EIPC
   mov     _osReturnPrivilegedModeNonTrustedFunc, r12 -- r12 = &_osReturnPrivilegedModeNonTrustedFunc -> get address of label _osReturnFromNonTrustedFunc
   cmp     r11, r12                                   -- compare r11 with r12
   be      _osSysCallSwitchToPrivileged               -- if equal then branch to _osSysCallSwitchToPrivileged   

   mov     E_OS_SYS_ABORT, r6                         -- r6 = E_OS_SYS_ABORT  
   mov     osdErrSCWrongSysCallParameter, r7          -- r7 = osdErrSCWrongSysCallParameter
   jr      _osEnterSafeState                          -- branch to _osEnterSafeState  
   
_osSysCallSwitchToPrivileged:   
   stsr    EIPSW, r11                        -- r11 = EIPSW
   mov     0xBFFFFFFF, r12                   -- r12 = 0xBFFFFFFF
   and     r12, r11                          -- r11 = r11 & r12
   ldsr    r11, EIPSW                        -- EIPSW = r11
   eiret                                     -- return from exception           
#pragma endasm            

/*****************************************************************************/
/* Wrapper for osGetIMR                                                      */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysGetIMR
_osPsysGetIMR:                             -- r6 contains IMR index
   mov     osdIntMaxIndex, r11             -- r11 = osdIntMaxIndex
   cmp     r11, r6                         -- compare r6 > r11
   bh      _osPsysGetIMRInvalidIndex       -- if r6 > r11 then branch to _osPsysGetIMRInvalidIndex
   mov     osdIMR0MIN, r12                 -- r12 = osdIMR0MIN
   mov     32, r11                         -- r11 = 32
   cmp     r11, r6                         -- compare r6 < r11
   bl      _osPsysGetIMRmEI                -- if r6 < r11 then branch to _osPsysGetIMRmEI
   mov     osdIMRxMIN-4, r12               -- r12 = osdIMRxMIN-4
_osPsysGetIMRmEI:                         
   andi    0x07, r6, r11                   -- r11 = r6 & 0x07 -> get bit index
   shr     3, r6                           -- r6 = r6 >> 3 -> get byte index
   add     r6, r12                         -- r12 = r6 + r12
   ld.bu   0[r12], r10                     -- r10 = *(uint8*)r12
   shr     r11, r10                        -- r10 = r10 >> r11
   andi    0x01, r10, r10                  -- r10 = r10 & 0x01
   jmp     [lp]                            -- return to caller
_osPsysGetIMRInvalidIndex:
   mov     E_OS_SYS_API_ERROR, r6          -- r6 = E_OS_SYS_API_ERROR  
   mov     osdErrPIGetIMRInvalidIndex, r7  -- r7 = osdErrPIGetIMRInvalidIndex 
   jr      _osEnterSafeState               -- branch to _osEnterSafeState  
#pragma endasm

/*****************************************************************************/
/* Wrapper for osSetIMR                                                      */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysSetIMR
_osPsysSetIMR:
   nop                       -- improve interrupt latency
   syscall osdSysCallSetIMR  -- start function via syscall
   jmp     [lp]              -- return to caller

   .align  4
   .globl  _osSysCallSetIMR
_osSysCallSetIMR:
   mov     osdIntMaxIndex, r11           -- r11 = osdIntMaxIndex
   cmp     r11, r6                       -- compare r6 > r11
   bh      _osSysCallSetIMRInvalidIndex  -- if r6 > r11 then branch to _osSysCallSetIMRInvalidIndex
   mov     osdIMR0MIN, r12               -- r12 = osdIMR0MIN
   mov     32, r11                       -- r11 = 32
   cmp     r11, r6                       -- compare r6 < r11
   bl      _osSysCallSetIMRxReg          -- if r6 < r11 then branch to _osSysCallSetIMRxReg 
   mov     osdIMRxMIN-4, r12             -- r12 = osdIMRxMIN-4
_osSysCallSetIMRxReg:              
   andi    0x07, r6, r11                 -- r11 = r6 & 0x07 -> get bit index
   shr     3, r6                         -- r6 = r6 >> 3 -> get byte index
   add     r6, r12                       -- r12 += r6
   set1    r11, [r12]                    -- set bit at position=r11 at address=r12
   ld.bu   0[r12], r11                   -- dummy read   
   syncm                                 -- sync memory access
   eiret                                 -- return from exception 
_osSysCallSetIMRInvalidIndex:
   mov     E_OS_SYS_API_ERROR, r6          -- r6 = E_OS_SYS_API_ERROR 
   mov     osdErrPISetIMRInvalidIndex, r7  -- r7 = osdErrPISetIMRInvalidIndex
   jr      _osEnterSafeState               -- branch to _osEnterSafeState 
#pragma endasm

/*****************************************************************************/
/* Wrapper for osClearIMR                                                    */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysClearIMR
_osPsysClearIMR:
   nop                         -- improve interrupt latency
   syscall osdSysCallClearIMR  -- start function via syscall
   jmp     [lp]                -- return to caller

   .align  4
   .globl  _osSysCallClearIMR
_osSysCallClearIMR:
   mov     osdIntMaxIndex, r11             -- r11 = osdIntMaxIndex
   cmp     r11, r6                         -- compare r6 > r11
   bh      _osSysCallClearIMRInvalidIndex  -- if r6 > r11 then branch to _osSysCallSetIMRInvalidIndex
   mov     osdIMR0MIN, r12                 -- r12 = osdIMR0MIN
   mov     32, r11                         -- r11 = 32
   cmp     r11, r6                         -- compare r6 < r11
   bl      _osSysCallClearIMRxReg          -- if r6 < r11 then branch to _osSysCallSetIMRxReg 
   mov     osdIMRxMIN-4, r12               -- r12 = osdIMRxMIN-4
_osSysCallClearIMRxReg:                  
   andi    0x07, r6, r11                   -- r11 = r6 & 0x07 -> get bit index
   shr     3, r6                           -- r6 = r6 >> 3 -> get byte index
   add     r6, r12                         -- r12 += r6
   clr1    r11, [r12]                      -- clear bit at position=r11 at address=r12
   ld.bu   0[r12], r11                     -- dummy read   
   syncm                                   -- sync memory access
   eiret                                   -- return from exception           
_osSysCallClearIMRInvalidIndex:
   mov     E_OS_SYS_API_ERROR, r6            -- r6 = E_OS_SYS_API_ERROR 
   mov     osdErrPIClearIMRInvalidIndex, r7  -- r7 = osdErrPIClearIMRInvalidIndex
   jr      _osEnterSafeState                 -- branch to _osEnterSafeState 
#pragma endasm

/*****************************************************************************/
/* Wrapper for osWriteIMR8                                                   */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysWriteIMR8
_osPsysWriteIMR8:
   nop                          -- improve interrupt latency
   syscall osdSysCallWriteIMR8  -- start function via syscall
   jmp     [lp]                 -- return to caller

   .align  4
   .globl  _osSysCallWriteIMR8
_osSysCallWriteIMR8:
   mov     osdIMR0MIN, r11                   -- r11 = osdIMR0MIN
   cmp     r11, r6                           -- compare r6 < r11
   bl      _osSysCallWriteIMR8InvalidAddr    -- if r6 < r11 then branch to _osSysCallWriteIMR8InvalidAddr
   mov     osdIMR0MAX8, r11                  -- r11 = osdIMR0MAX8   
   cmp     r11, r6                           -- compare r6 < r11
   bl      _osSysCallWriteIMR8Reg            -- if r6 < r11 then branch to _osSysCallWriteIMR8Reg
   mov     osdIMRxMIN, r11                   -- r11 = osdIMRxMIN
   cmp     r11, r6                           -- compare r6 < r11
   bl      _osSysCallWriteIMR8InvalidAddr    -- if r6 < r11 then branch to _osSysCallWriteIMR8InvalidAddr
   mov     osdIMRxMAX8, r11                  -- r11 = osdIMRxMAX8
   cmp     r11, r6                           -- compare r6 > r11
   bh      _osSysCallWriteIMR8InvalidAddr    -- if r6 > r11 then branch to _osSysCallWriteIMR8InvalidAddr
      
_osSysCallWriteIMR8Reg:                     
   st.b    r7, 0[r6]                         -- *(uint8*)r6 = r7
   ld.bu   0[r6], r7                         -- dummy read      
   syncm                                     -- sync memory access   
   eiret                                     -- return from exception           
   
_osSysCallWriteIMR8InvalidAddr:
   mov     E_OS_SYS_API_ERROR, r6            -- r6 = E_OS_SYS_API_ERROR 
   mov     osdErrPIWriteIMR8InvalidAddr, r7  -- r7 = osdErrPIWriteIMR8InvalidAddr
   jr      _osEnterSafeState                 -- branch to _osEnterSafeState 
#pragma endasm

/*****************************************************************************/
/* Wrapper for osWriteIMR16                                                  */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysWriteIMR16
_osPsysWriteIMR16:
   nop                           -- improve interrupt latency
   syscall osdSysCallWriteIMR16  -- start function via syscall
   jmp     [lp]                  -- return to caller

   .align  4
   .globl  _osSysCallWriteIMR16
_osSysCallWriteIMR16:
   mov     osdIMR0MIN, r11                    -- r11 = osdIMR0MIN
   cmp     r11, r6                            -- compare r6 < r11
   bl      _osSysCallWriteIMR16InvalidAddr    -- if r6 < r11 then branch to _osSysCallWriteIMR16InvalidAddr
   mov     osdIMR0MAX16, r11                  -- r11 = osdIMR0MAX16
   cmp     r11, r6                            -- compare r6 < r11
   bl      _osSysCallWriteIMR16Reg            -- if r6 < r11 then branch to _osSysCallWriteIMR16Reg
   mov     osdIMRxMIN, r11                    -- r11 = osdIMRxMIN
   cmp     r11, r6                            -- compare r6 < r11
   bl      _osSysCallWriteIMR16InvalidAddr    -- if r6 < r11 then branch to _osSysCallWriteIMR16InvalidAddr
   mov     osdIMRxMAX16, r11                  -- r11 = osdIMRxMAX16
   cmp     r11, r6                            -- compare r6 > r11
   bh      _osSysCallWriteIMR16InvalidAddr    -- if r6 > r11 then branch to _osSysCallWriteIMR16InvalidAddr
   
_osSysCallWriteIMR16Reg:                    
   st.h    r7, 0[r6]                          -- *(uint16*)r6 = r7
   ld.hu   0[r6], r7                          -- dummy read   
   syncm                                      -- sync memory access   
   eiret                                      -- return from exception           
   
_osSysCallWriteIMR16InvalidAddr:
   mov     E_OS_SYS_API_ERROR, r6             -- r6 = E_OS_SYS_API_ERROR 
   mov     osdErrPIWriteIMR16InvalidAddr, r7  -- r7 = osdErrPIWriteIMR16InvalidAddr
   jr      _osEnterSafeState                  -- branch to _osEnterSafeState 
#pragma endasm

/*****************************************************************************/
/* Wrapper for osWriteIMR32                                                  */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osPsysWriteIMR32
_osPsysWriteIMR32:
   nop                           -- improve interrupt latency
   syscall osdSysCallWriteIMR32  -- start function via syscall
   jmp     [lp]                  -- return to caller

   .align  4
   .globl  _osSysCallWriteIMR32
_osSysCallWriteIMR32:
   mov     osdIMR0MIN, r11                    -- r11 = osdIMR0MIN
   cmp     r11, r6                            -- compare r6 == r11
   be      _osSysCallWriteIMR32Reg            -- if r6 == r11 then branch to _osSysCallWriteIMR32Reg
   
   mov     osdIMRxMIN, r11                    -- r11 = osdIMRxMIN
   cmp     r11, r6                            -- compare r6 < r11
   bl      _osSysCallWriteIMR32InvalidAddr    -- if r6 < r11 then branch to _osSysCallWriteIMR32InvalidAddr
   mov     osdIMRxMAX32, r11                  -- r11 = osdIMRxMAX32
   cmp     r11, r6                            -- compare r6 > r11
   bh      _osSysCallWriteIMR32InvalidAddr    -- if r6 > r11 then branch to _osSysCallWriteIMR32InvalidAddr
   
_osSysCallWriteIMR32Reg:                        
   st.w    r7, 0[r6]                          -- *(uint32*)r6 = r7
   ld.w    0[r6], r7                          -- dummy read
   syncm                                      -- sync memory access   
   eiret                                      -- return from exception                
   
_osSysCallWriteIMR32InvalidAddr:               
   mov     E_OS_SYS_API_ERROR, r6             -- r6 = E_OS_SYS_API_ERROR 
   mov     osdErrPIWriteIMR32InvalidAddr, r7  -- r7 = osdErrPIWriteIMR32InvalidAddr
   jr      _osEnterSafeState                  -- branch to _osEnterSafeState 
#pragma endasm

/*****************************************************************************/
/* Wrapper for osSysCallError                                                */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4   
   .globl  _osSysCallError   
_osSysCallError:
   mov     E_OS_SYS_ABORT, r6                 -- r6 = E_OS_SYS_ABORT
   mov     osdErrSCWrongSysCallParameter, r7  -- r7 = osdErrSCWrongSysCallParameter   
   jr      _osEnterSafeState                  -- branch to _osEnterSafeState
#pragma endasm

/*****************************************************************************/
/* Wrapper for osPsysEnterSafeState                                          */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4      
   .globl  _osPsysEnterSafeState
_osPsysEnterSafeState:
   nop                               -- improve interrupt latency
   syscall osdSysCallEnterSafeState  -- start function via syscall
   jmp     [lp]                      -- return to caller

   .align  4
   .globl  _osSysCallEnterSafeState
_osSysCallEnterSafeState:
   jr      _osEnterSafeState         -- branch to _osEnterSafeState
#pragma endasm

/*****************************************************************************/
/* Wrapper for osDisableLevelUM                                              */
/*****************************************************************************/
#pragma asm
   .section ".os_text"

   .align  4                     
   .globl  _osPsysCallDisableLevelUM
_osPsysCallDisableLevelUM:          
   nop                              -- improve interrupt latency
   syscall osdSysCallDisableLevelUM -- start function via syscall
   jmp     [lp]                     -- return to caller
   
   .align  4   
   .globl  _osSysCallDisableLevelUM
_osSysCallDisableLevelUM:
   mov     osdSystemLevelMask, r11  -- r11 = osdSystemLevelMask
   ldsr    r11, PMR                 -- PMR = r11
#if osdCallTimingHooks
   pushsp  r6-r7
   pushsp  lp-lp
   mov     OS_VTHP_CAT2INTERRUPTS, r6   
   mov     zero, r7      
   jarl    _Callback_OS_VTH_DISABLEDINT, lp   
   popsp   lp-lp   
   popsp   r6-r7
#endif
   eiret                            -- return from exception
#pragma endasm

/*****************************************************************************/
/* Wrapper for osEnableLevelUM                                               */
/*****************************************************************************/
#pragma asm
   .section ".os_text"

   .align  4                     
   .globl  _osPsysCallEnableLevelUM
_osPsysCallEnableLevelUM:          
   nop                              -- improve interrupt latency
   syscall osdSysCallEnableLevelUM  -- start function via syscall
   jmp     [lp]                     -- return to caller
   
   .align  4   
   .globl  _osSysCallEnableLevelUM
_osSysCallEnableLevelUM:
#if osdCallTimingHooks
   pushsp  r6-r7
   pushsp  lp-lp
   mov     OS_VTHP_CAT2INTERRUPTS, r6   
   mov     zero, r7      
   jarl    _Callback_OS_VTH_ENABLEDINT, lp   
   popsp   lp-lp   
   popsp   r6-r7
#endif
   ldsr    r0, PMR   -- PMR = r0 = 0
   eiret             -- return from exception
#pragma endasm

/*****************************************************************************/
/* Wrapper for osDisableGlobalUM                                             */
/*****************************************************************************/
#pragma asm
   .section ".os_text"

   .align  4                     
   .globl  _osPsysCallDisableGlobalUM
_osPsysCallDisableGlobalUM:
   nop                               -- improve interrupt latency
   syscall osdSysCallDisableGlobalUM -- start function via syscall
   jmp     [lp]                      -- return to caller   
   
   .align  4
   .globl  _osSysCallDisableGlobalUM
_osSysCallDisableGlobalUM:
   stsr    EIPSW, r11       -- r11 = EIPSW
   ori     0x20, r11, r11   -- r11 |= 0x20
   ldsr    r11, EIPSW       -- EIPSW = r11
#if osdCallTimingHooks
   pushsp  r6-r7
   pushsp  lp-lp
   mov     OS_VTHP_ALLINTERRUPTS, r6   
   mov     zero, r7      
   jarl    _Callback_OS_VTH_DISABLEDINT, lp   
   popsp   lp-lp   
   popsp   r6-r7
#endif
   eiret                    -- return from exception
#pragma endasm

/*****************************************************************************/
/* Wrapper for osEnableGlobalUM                                              */
/*****************************************************************************/
#pragma asm
   .section ".os_text"

   .align  4                     
   .globl  _osPsysCallEnableGlobalUM
_osPsysCallEnableGlobalUM:
   nop                               -- improve interrupt latency
   syscall osdSysCallEnableGlobalUM  -- start function via syscall
   jmp     [lp]                      -- return to caller      
   
   .align  4
   .globl  _osSysCallEnableGlobalUM
_osSysCallEnableGlobalUM:
#if osdCallTimingHooks
   pushsp  r6-r7
   pushsp  lp-lp
   mov     OS_VTHP_ALLINTERRUPTS, r6   
   mov     zero, r7      
   jarl    _Callback_OS_VTH_ENABLEDINT, lp   
   popsp   lp-lp   
   popsp   r6-r7
#endif
   stsr    EIPSW, r11       -- r11 = EIPSW
   mov     0xFFFFFFDF, r12  -- r12 = 0xFFFFFFDF
   and     r12, r11         -- r11 = r11 & r12
   ldsr    r11, EIPSW       -- EIPSW = r11
   eiret                    -- return from exception
#pragma endasm

/*****************************************************************************/
/* Function osCheckMpuAsm                                                    */
/* osuint8 osCheckMpuAsm(osuint32 addr)                                      */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4
   .globl  _osCheckMpuAsm
_osCheckMpuAsm:              -- r6 contains address for read and write access
   pushsp  r11-r12           -- push r11 and r12 onto stack
   mov     0, r10            -- r10 = 0
   
__osCheckMpuRead:   
   ld.bu   0[r6], r12        -- r12 = *((osuint8)*(r6))

__osCheckMpuWrite:
   st.b    r12, 0[r6]        -- *((osuint8*)r6) = (osuint8)r12
   
__osCheckMpuReturn:
   popsp   r11-r12           -- restore r11 and r12 from stack
   jmp     [lp]              -- return to caller
#pragma endasm

/*****************************************************************************/
/* Exception Handler osMemoryProtectionViolation                             */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4   
   .globl  _osMemoryProtectionViolation   
_osMemoryProtectionViolation: 
   -- if osCheckMpuAsm was called then r11 and r12 are already saved onto stack
   -- otherwise we do not return and the context must not be saved  
   stsr    FEPC, r11                      -- r11 = FEPC
   mov     __osCheckMpuRead, r12          -- r12 = &__osCheckMpuRead -> get address of label __osCheckMpuRead 
   cmp     r11, r12                       -- compare r11 with r12
   be      _osMemProtectCheckMpuReturn    -- if equal then branch to __osMemProtectMpuCheck
   mov     __osCheckMpuWrite, r12         -- r12 = &__osCheckMpuWrite -> get address of label __osCheckMpuWrite 
   cmp     r11, r12                       -- compare r11 with r12
   bne     _osMemProtectException         -- if not equal then branch to _osMemProtectException
          
_osMemProtectCheckMpuReturn:   
   mov     1, r10                         -- r10 = 1
   mov     __osCheckMpuReturn, r11        -- r11 = &__osCheckMpuReturn
   ldsr    r11, FEPC                      -- FEPC = r11 -> prepare return address
   feret                                  -- return from protection trap
   
_osMemProtectException:
   _osSwitchToCoreSystemStack             -- switch to system stack
   jarl    _osMemoryProtectionHandler, lp -- call protection handler   
   feret                                
#pragma endasm

/*****************************************************************************/
/* Exception Handler osPrivilegedInstructionException                         */
/*****************************************************************************/
#pragma asm
   .section ".os_text"
   .align  4   
   .globl  _osPrivilegedInstructionException   
_osPrivilegedInstructionException: 
   _osSwitchToCoreSystemStack                -- switch to system stack
   jarl    _osInstructProtectionHandler, lp  -- call protection handler   
   feret                                 
#pragma endasm

/* KB begin osekEndOfCModule (overwritten) */
#pragma ghs section bss=default
#pragma ghs section data=default
#pragma ghs section sbss=default
#pragma ghs section sdata=default
#pragma ghs section text=default
#pragma ghs section rodata=default
#pragma ghs section rosdata=default
/* KB end osekEndOfCModule */

