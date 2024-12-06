%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 15-Mar-2016 07:37:06       %
%                                  Created with tool release: 2.32.0     %
%                                  Synergy file: %version: 4 %           %
%                                  Date Modified: %date_modified: X %    %
%                                  Derived by: %derived_by: fzg88y %          %
%%-----------------------------------------------------------------------%


SF005A = DataDict.FDD;
SF005A.Version = '1.3.X';
SF005A.LongName = 'State Output Control';
SF005A.ShoName  = 'StOutpCtrl';
SF005A.DesignASIL = 'D';
SF005A.Description = [...
  'The State Output Control Function implements the system ramping functi' ...
  'ons based on inputs from other modules.  Ramping due to diagnostics an' ...
  'd other functions are requested and this function does the actual impl' ...
  'ementation of the ramping.  The ramping rate can also be increased thr' ...
  'ough the use of a serial comm service.'];
SF005A.Dependencies = {'ArchGlbPrm'};



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
StOutpCtrlInit1 = DataDict.Runnable;
StOutpCtrlInit1.Context = 'Rte';
StOutpCtrlInit1.TimeStep = 0;

StOutpCtrlPer1 = DataDict.Runnable;
StOutpCtrlPer1.Context = 'Rte';
StOutpCtrlPer1.TimeStep = 0.002;


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------

%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
LoaSca = DataDict.IpSignal;
LoaSca.LongName = 'Loss of Assist Scale';
LoaSca.DocUnits = 'Uls';
LoaSca.EngDT = dt.float32;
LoaSca.EngInit = 1;
LoaSca.EngMin = 0;
LoaSca.EngMax = 1;
LoaSca.ReadIn = {'StOutpCtrlPer1'};
LoaSca.ReadType = 'Rte';


LoaRateLim = DataDict.IpSignal;
LoaRateLim.LongName = 'Loss of Assist Ramp Rate Limit';
LoaRateLim.DocUnits = 'UlsPerSec';
LoaRateLim.EngDT = dt.float32;
LoaRateLim.EngInit = 1;
LoaRateLim.EngMin = 0.01;
LoaRateLim.EngMax = 500;
LoaRateLim.ReadIn = {'StOutpCtrlPer1'};
LoaRateLim.ReadType = 'Rte';


SysDiMotTqCmdSca = DataDict.IpSignal;
SysDiMotTqCmdSca.LongName = 'System Disable Motor Torque Command Scale';
SysDiMotTqCmdSca.DocUnits = 'Uls';
SysDiMotTqCmdSca.EngDT = dt.float32;
SysDiMotTqCmdSca.EngInit = 1;
SysDiMotTqCmdSca.EngMin = 0;
SysDiMotTqCmdSca.EngMax = 1;
SysDiMotTqCmdSca.ReadIn = {'StOutpCtrlPer1'};
SysDiMotTqCmdSca.ReadType = 'Rte';


SysDiRampRate = DataDict.IpSignal;
SysDiRampRate.LongName = 'System Disable Ramp Rate';
SysDiRampRate.DocUnits = 'UlsPerSec';
SysDiRampRate.EngDT = dt.float32;
SysDiRampRate.EngInit = 1;
SysDiRampRate.EngMin = 0.1;
SysDiRampRate.EngMax = 500;
SysDiRampRate.ReadIn = {'StOutpCtrlPer1'};
SysDiRampRate.ReadType = 'Rte';


SysMotTqCmdRampRateDi = DataDict.IpSignal;
SysMotTqCmdRampRateDi.LongName = 'System Motor Torque Command Ramp Rate Disable';
SysMotTqCmdRampRateDi.DocUnits = 'Cnt';
SysMotTqCmdRampRateDi.EngDT = dt.lgc;
SysMotTqCmdRampRateDi.EngInit = 0;
SysMotTqCmdRampRateDi.EngMin = 0;
SysMotTqCmdRampRateDi.EngMax = 1;
SysMotTqCmdRampRateDi.ReadIn = {'StOutpCtrlPer1'};
SysMotTqCmdRampRateDi.ReadType = 'Rte';


SysOperMotTqCmdSca = DataDict.IpSignal;
SysOperMotTqCmdSca.LongName = 'System Operational Motor Torque Command Scale';
SysOperMotTqCmdSca.DocUnits = 'Uls';
SysOperMotTqCmdSca.EngDT = dt.float32;
SysOperMotTqCmdSca.EngInit = 1;
SysOperMotTqCmdSca.EngMin = 0;
SysOperMotTqCmdSca.EngMax = 1;
SysOperMotTqCmdSca.ReadIn = {'StOutpCtrlPer1'};
SysOperMotTqCmdSca.ReadType = 'Rte';


SysOperRampRate = DataDict.IpSignal;
SysOperRampRate.LongName = 'System Operational Ramp Rate';
SysOperRampRate.DocUnits = 'UlsPerSec';
SysOperRampRate.EngDT = dt.float32;
SysOperRampRate.EngInit = 1;
SysOperRampRate.EngMin = 0.1;
SysOperRampRate.EngMax = 500;
SysOperRampRate.ReadIn = {'StOutpCtrlPer1'};
SysOperRampRate.ReadType = 'Rte';


SysStFltOutpReqDi = DataDict.IpSignal;
SysStFltOutpReqDi.LongName = 'System State Fault Output Request Disable';
SysStFltOutpReqDi.DocUnits = 'Cnt';
SysStFltOutpReqDi.EngDT = dt.lgc;
SysStFltOutpReqDi.EngInit = 0;
SysStFltOutpReqDi.EngMin = 0;
SysStFltOutpReqDi.EngMax = 1;
SysStFltOutpReqDi.ReadIn = {'StOutpCtrlPer1'};
SysStFltOutpReqDi.ReadType = 'Rte';


VehStrtStopMotTqCmdSca = DataDict.IpSignal;
VehStrtStopMotTqCmdSca.LongName = 'Vehicle Start Stop Motor Torque Command Scale';
VehStrtStopMotTqCmdSca.DocUnits = 'Uls';
VehStrtStopMotTqCmdSca.EngDT = dt.float32;
VehStrtStopMotTqCmdSca.EngInit = 1;
VehStrtStopMotTqCmdSca.EngMin = 0;
VehStrtStopMotTqCmdSca.EngMax = 1;
VehStrtStopMotTqCmdSca.ReadIn = {'StOutpCtrlPer1'};
VehStrtStopMotTqCmdSca.ReadType = 'Rte';


VehStrtStopRampRate = DataDict.IpSignal;
VehStrtStopRampRate.LongName = 'Vehicle Start Stop Ramp Rate';
VehStrtStopRampRate.DocUnits = 'UlsPerSec';
VehStrtStopRampRate.EngDT = dt.float32;
VehStrtStopRampRate.EngInit = 1;
VehStrtStopRampRate.EngMin = 0.1;
VehStrtStopRampRate.EngMax = 500;
VehStrtStopRampRate.ReadIn = {'StOutpCtrlPer1'};
VehStrtStopRampRate.ReadType = 'Rte';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
SysMotTqCmdSca = DataDict.OpSignal;
SysMotTqCmdSca.LongName = 'System Motor Torque Command Scale';
SysMotTqCmdSca.Description = [...
  'scaling multiplier used to perform ramp down of motor torque'];
SysMotTqCmdSca.DocUnits = 'Uls';
SysMotTqCmdSca.SwcShoName = 'StOutpCtrl';
SysMotTqCmdSca.EngDT = dt.float32;
SysMotTqCmdSca.EngInit = 1;
SysMotTqCmdSca.EngMin = 0;
SysMotTqCmdSca.EngMax = 1;
SysMotTqCmdSca.TestTolerance = 1;
SysMotTqCmdSca.WrittenIn = {'StOutpCtrlPer1'};
SysMotTqCmdSca.WriteType = 'Rte';


SysStReqDi = DataDict.OpSignal;
SysStReqDi.LongName = 'System State Request Disable';
SysStReqDi.Description = [...
  'This sends a request to disable the system state'];
SysStReqDi.DocUnits = 'Cnt';
SysStReqDi.SwcShoName = 'StOutpCtrl';
SysStReqDi.EngDT = dt.lgc;
SysStReqDi.EngInit = 0;
SysStReqDi.EngMin = 0;
SysStReqDi.EngMax = 1;
SysStReqDi.TestTolerance = 0;
SysStReqDi.WrittenIn = {'StOutpCtrlPer1'};
SysStReqDi.WriteType = 'Rte';



%%-------------------------------------------
%% Inter-Runnable Variable Definition        
%%-------------------------------------------

%%-------------------------------------------
%% Calibrations Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Imported Calibrations Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Non-Volatile Memory Definition            
%%-------------------------------------------

%%-------------------------------------------
%% Display Variable Definition               
%%-------------------------------------------
dStOutpCtrlRateLim = DataDict.Display;
dStOutpCtrlRateLim.LongName = 'Rate Limit';
dStOutpCtrlRateLim.Description = 'Rate Limit of the slew';
dStOutpCtrlRateLim.DocUnits = 'UlsPerSec';
dStOutpCtrlRateLim.EngDT = dt.float32;
dStOutpCtrlRateLim.EngMin = 0;
dStOutpCtrlRateLim.EngMax = 500;
dStOutpCtrlRateLim.InitRowCol = [1  1];


dStOutpCtrlTarSca = DataDict.Display;
dStOutpCtrlTarSca.LongName = 'Target Scale';
dStOutpCtrlTarSca.Description = [...
  'Target Scale before slew is applied'];
dStOutpCtrlTarSca.DocUnits = 'Uls';
dStOutpCtrlTarSca.EngDT = dt.float32;
dStOutpCtrlTarSca.EngMin = 0;
dStOutpCtrlTarSca.EngMax = 1;
dStOutpCtrlTarSca.InitRowCol = [1  1];



%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------
StOutpCtrlPrevCmdSca = DataDict.PIM;
StOutpCtrlPrevCmdSca.LongName = 'Previous Command Scale';
StOutpCtrlPrevCmdSca.Description = 'This is the Previous Command Scale';
StOutpCtrlPrevCmdSca.DocUnits = 'Uls';
StOutpCtrlPrevCmdSca.EngDT = dt.float32;
StOutpCtrlPrevCmdSca.EngMin = 0;
StOutpCtrlPrevCmdSca.EngMax = 1;
StOutpCtrlPrevCmdSca.InitRowCol = [1  1];


StOutpCtrlPrevSrc = DataDict.PIM;
StOutpCtrlPrevSrc.LongName = 'Previous Source';
StOutpCtrlPrevSrc.Description = [...
  'This is the Previous Rate Source in Target Selection'];
StOutpCtrlPrevSrc.DocUnits = 'Cnt';
StOutpCtrlPrevSrc.EngDT = dt.u08;
StOutpCtrlPrevSrc.EngMin = 1;
StOutpCtrlPrevSrc.EngMax = 4;
StOutpCtrlPrevSrc.InitRowCol = [1  1];



%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
BIGSLEW_ULSPERSEC_F32 = DataDict.Constant;
BIGSLEW_ULSPERSEC_F32.LongName = 'Big Slew';
BIGSLEW_ULSPERSEC_F32.Description = [...
  'Slew Rate Value Large Enough to Go from 1 to 0 or 0 to 1 in 2ms'];
BIGSLEW_ULSPERSEC_F32.DocUnits = 'UlsPerSec';
BIGSLEW_ULSPERSEC_F32.EngDT = dt.float32;
BIGSLEW_ULSPERSEC_F32.EngVal = 500;
BIGSLEW_ULSPERSEC_F32.Header = ' ';
BIGSLEW_ULSPERSEC_F32.Define = 'Local';


DI_CNT_U08 = DataDict.Constant;
DI_CNT_U08.LongName = 'Disable';
DI_CNT_U08.Description = [...
  'Number Representation for Disable State'];
DI_CNT_U08.DocUnits = 'Cnt';
DI_CNT_U08.EngDT = dt.u08;
DI_CNT_U08.EngVal = 4;
DI_CNT_U08.Header = ' ';
DI_CNT_U08.Define = 'Local';


LOA_CNT_U08 = DataDict.Constant;
LOA_CNT_U08.LongName = 'LOA';
LOA_CNT_U08.Description = [...
  'Number Representation for LOA State'];
LOA_CNT_U08.DocUnits = 'Cnt';
LOA_CNT_U08.EngDT = dt.u08;
LOA_CNT_U08.EngVal = 2;
LOA_CNT_U08.Header = ' ';
LOA_CNT_U08.Define = 'Local';


OPER_CNT_U08 = DataDict.Constant;
OPER_CNT_U08.LongName = 'Operational';
OPER_CNT_U08.Description = [...
  'Number Representation for Operational State'];
OPER_CNT_U08.DocUnits = 'Cnt';
OPER_CNT_U08.EngDT = dt.u08;
OPER_CNT_U08.EngVal = 1;
OPER_CNT_U08.Header = ' ';
OPER_CNT_U08.Define = 'Local';


RATELIMITHI_ULSPERSEC_F32 = DataDict.Constant;
RATELIMITHI_ULSPERSEC_F32.LongName = 'Rate Limit High';
RATELIMITHI_ULSPERSEC_F32.Description = [...
  'The highest value Rate Limit can be. It is determined from 0 to 1 in o' ...
  'ne time step.'];
RATELIMITHI_ULSPERSEC_F32.DocUnits = 'UlsPerSec';
RATELIMITHI_ULSPERSEC_F32.EngDT = dt.float32;
RATELIMITHI_ULSPERSEC_F32.EngVal = 500;
RATELIMITHI_ULSPERSEC_F32.Header = ' ';
RATELIMITHI_ULSPERSEC_F32.Define = 'Local';


RATELIMITLO_ULSPERSEC_F32 = DataDict.Constant;
RATELIMITLO_ULSPERSEC_F32.LongName = 'Rate Limit Low';
RATELIMITLO_ULSPERSEC_F32.Description = [...
  'The lowest value Rate Limit. It is close to the minimum sampling rate ' ...
  'for 90 seconds.'];
RATELIMITLO_ULSPERSEC_F32.DocUnits = 'UlsPerSec';
RATELIMITLO_ULSPERSEC_F32.EngDT = dt.float32;
RATELIMITLO_ULSPERSEC_F32.EngVal = 0.1;
RATELIMITLO_ULSPERSEC_F32.Header = ' ';
RATELIMITLO_ULSPERSEC_F32.Define = 'Local';


STRTSTOP_CNT_U08 = DataDict.Constant;
STRTSTOP_CNT_U08.LongName = 'Start Stop';
STRTSTOP_CNT_U08.Description = [...
  'Number Representation for Start Stop State'];
STRTSTOP_CNT_U08.DocUnits = 'Cnt';
STRTSTOP_CNT_U08.EngDT = dt.u08;
STRTSTOP_CNT_U08.EngVal = 3;
STRTSTOP_CNT_U08.Header = ' ';
STRTSTOP_CNT_U08.Define = 'Local';


TARGETSCALEHI_ULS_F32 = DataDict.Constant;
TARGETSCALEHI_ULS_F32.LongName = 'Target Scale High';
TARGETSCALEHI_ULS_F32.Description = [...
  'The maximum value for the Target Scale.'];
TARGETSCALEHI_ULS_F32.DocUnits = 'Uls';
TARGETSCALEHI_ULS_F32.EngDT = dt.float32;
TARGETSCALEHI_ULS_F32.EngVal = 1;
TARGETSCALEHI_ULS_F32.Header = ' ';
TARGETSCALEHI_ULS_F32.Define = 'Local';


TARGETSCALELO_ULS_F32 = DataDict.Constant;
TARGETSCALELO_ULS_F32.LongName = 'Target Scale Low';
TARGETSCALELO_ULS_F32.Description = [...
  'The minimum value for the Target Scale'];
TARGETSCALELO_ULS_F32.DocUnits = 'Uls';
TARGETSCALELO_ULS_F32.EngDT = dt.float32;
TARGETSCALELO_ULS_F32.EngVal = 0;
TARGETSCALELO_ULS_F32.Header = ' ';
TARGETSCALELO_ULS_F32.Define = 'Local';

ARCHGLBPRM_FLOATZEROTHD_ULS_F32 = DataDict.Constant;
ARCHGLBPRM_FLOATZEROTHD_ULS_F32.LongName = 'Float Zero Threshold';
ARCHGLBPRM_FLOATZEROTHD_ULS_F32.Description = [...
  'Zero Threshold for float comparisons; renamed float.h FLT_EPSILON beca' ...
  'use that name is reserved in MATLAB'];
ARCHGLBPRM_FLOATZEROTHD_ULS_F32.DocUnits = 'Uls';
ARCHGLBPRM_FLOATZEROTHD_ULS_F32.EngDT = dt.float32;
ARCHGLBPRM_FLOATZEROTHD_ULS_F32.EngVal = 1.1920929e-07;
ARCHGLBPRM_FLOATZEROTHD_ULS_F32.Header = 'ArchGlbPrm';
ARCHGLBPRM_FLOATZEROTHD_ULS_F32.Define = 'Global';

ARCHGLBPRM_2MILLISEC_SEC_F32 = DataDict.Constant;
ARCHGLBPRM_2MILLISEC_SEC_F32.LongName = '2 Milliseconds';
ARCHGLBPRM_2MILLISEC_SEC_F32.Description = '2ms periodic loop time step';
ARCHGLBPRM_2MILLISEC_SEC_F32.DocUnits = 'Sec';
ARCHGLBPRM_2MILLISEC_SEC_F32.EngDT = dt.float32;
ARCHGLBPRM_2MILLISEC_SEC_F32.EngVal = 0.002;
ARCHGLBPRM_2MILLISEC_SEC_F32.Header = 'ArchGlbPrm';
ARCHGLBPRM_2MILLISEC_SEC_F32.Define = 'Global';

%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
%end of Data Dictionary
