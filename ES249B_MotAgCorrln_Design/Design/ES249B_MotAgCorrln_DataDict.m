%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 15-Dec-2015 11:57:25       %
%                                  Created with tool release: 2.26.0     %
%                                  Synergy file: 1.0.0                   %
%                                  Date Modified: 22-Dec-2015            %
%                                  Derived by: Muragesh Asundi           %
%%-----------------------------------------------------------------------%

ES249B = DataDict.FDD;
ES249B.Version = '1.0.X';
ES249B.LongName = 'Motor Angle Correlation';
ES249B.ShoName  = 'MotAgCorrln';
ES249B.DesignASIL = 'D';
ES249B.Description = [...
  'Performs cross check of available signals'];
ES249B.Dependencies = ...
	{'SysGlbPrm', 'FLTINJ'};


%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
MotAgCorrlnInit1 = DataDict.Runnable;
MotAgCorrlnInit1.Context = 'Rte';
MotAgCorrlnInit1.TimeStep = 0;

MotAgCorrlnPer1 = DataDict.Runnable;
MotAgCorrlnPer1.Context = 'Rte';
MotAgCorrlnPer1.TimeStep = 0.002;


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------
FltInj_u08 = DataDict.Client;
FltInj_u08.CallLocation = {'MotAgCorrlnPer1'};
FltInj_u08.Return = DataDict.CSReturn;
FltInj_u08.Return.Type = 'None';
FltInj_u08.Return.Min = [];
FltInj_u08.Return.Max = [];
FltInj_u08.Return.TestTolerance = [];
FltInj_u08.Arguments(1) = DataDict.CSArguments;
FltInj_u08.Arguments(1).Name = 'SigPah';
FltInj_u08.Arguments(1).EngMin = 0;
FltInj_u08.Arguments(1).EngMax = 3;
FltInj_u08.Arguments(1).EngDT = dt.u08;
FltInj_u08.Arguments(1).Units = 'Cnt';
FltInj_u08.Arguments(1).Direction = 'InOut';
FltInj_u08.Arguments(1).InitRowCol = [1  1];
FltInj_u08.Arguments(2) = DataDict.CSArguments;
FltInj_u08.Arguments(2).Name = 'LocnKey';
FltInj_u08.Arguments(2).EngMin = 0;
FltInj_u08.Arguments(2).EngMax = 65535;
FltInj_u08.Arguments(2).EngDT = dt.u16;
FltInj_u08.Arguments(2).Units = 'Cnt';
FltInj_u08.Arguments(2).Direction = 'In';
FltInj_u08.Arguments(2).InitRowCol = [1  1];


GetNtcQlfrSts = DataDict.Client;
GetNtcQlfrSts.CallLocation = {'MotAgCorrlnPer1'};
GetNtcQlfrSts.Return = DataDict.CSReturn;
GetNtcQlfrSts.Return.Type = 'Standard';
GetNtcQlfrSts.Return.Min = 0;
GetNtcQlfrSts.Return.Max = 1;
GetNtcQlfrSts.Return.TestTolerance = [];
GetNtcQlfrSts.Arguments(1) = DataDict.CSArguments;
GetNtcQlfrSts.Arguments(1).Name = 'NtcNr';
GetNtcQlfrSts.Arguments(1).EngMin = NtcNr1.NTCNR_0X001;
GetNtcQlfrSts.Arguments(1).EngMax = NtcNr1.NTCNR_0X1FF;
GetNtcQlfrSts.Arguments(1).EngDT = enum.NtcNr1;
GetNtcQlfrSts.Arguments(1).Units = 'Cnt';
GetNtcQlfrSts.Arguments(1).Direction = 'In';
GetNtcQlfrSts.Arguments(1).InitRowCol = [1  1];
GetNtcQlfrSts.Arguments(2) = DataDict.CSArguments;
GetNtcQlfrSts.Arguments(2).Name = 'NtcQlfr';
GetNtcQlfrSts.Arguments(2).EngMin = SigQlfr1.SIGQLFR_NORES;
GetNtcQlfrSts.Arguments(2).EngMax = SigQlfr1.SIGQLFR_FAILD;
GetNtcQlfrSts.Arguments(2).EngDT = enum.SigQlfr1;
GetNtcQlfrSts.Arguments(2).Units = 'Cnt';
GetNtcQlfrSts.Arguments(2).Direction = 'Out';
GetNtcQlfrSts.Arguments(2).InitRowCol = [1  1];


SetNtcSts = DataDict.Client;
SetNtcSts.CallLocation = {'MotAgCorrlnPer1'};
SetNtcSts.Return = DataDict.CSReturn;
SetNtcSts.Return.Type = 'Standard';
SetNtcSts.Return.Min = 0;
SetNtcSts.Return.Max = 1;
SetNtcSts.Return.TestTolerance = [];
SetNtcSts.Arguments(1) = DataDict.CSArguments;
SetNtcSts.Arguments(1).Name = 'NtcNr';
SetNtcSts.Arguments(1).EngMin = NtcNr1.NTCNR_0X001;
SetNtcSts.Arguments(1).EngMax = NtcNr1.NTCNR_0X1FF;
SetNtcSts.Arguments(1).EngDT = enum.NtcNr1;
SetNtcSts.Arguments(1).Units = 'Cnt';
SetNtcSts.Arguments(1).Direction = 'In';
SetNtcSts.Arguments(1).InitRowCol = [1  1];
SetNtcSts.Arguments(2) = DataDict.CSArguments;
SetNtcSts.Arguments(2).Name = 'NtcStInfo';
SetNtcSts.Arguments(2).EngMin = 0;
SetNtcSts.Arguments(2).EngMax = 255;
SetNtcSts.Arguments(2).EngDT = dt.u08;
SetNtcSts.Arguments(2).Units = 'Cnt';
SetNtcSts.Arguments(2).Direction = 'In';
SetNtcSts.Arguments(2).InitRowCol = [1  1];
SetNtcSts.Arguments(3) = DataDict.CSArguments;
SetNtcSts.Arguments(3).Name = 'NtcSts';
SetNtcSts.Arguments(3).EngMin = NtcSts1.NTCSTS_PASSD;
SetNtcSts.Arguments(3).EngMax = NtcSts1.NTCSTS_PREFAILD;
SetNtcSts.Arguments(3).EngDT = enum.NtcSts1;
SetNtcSts.Arguments(3).Units = 'Cnt';
SetNtcSts.Arguments(3).Direction = 'In';
SetNtcSts.Arguments(3).InitRowCol = [1  1];
SetNtcSts.Arguments(4) = DataDict.CSArguments;
SetNtcSts.Arguments(4).Name = 'DebStep';
SetNtcSts.Arguments(4).EngMin = 0;
SetNtcSts.Arguments(4).EngMax = 65535;
SetNtcSts.Arguments(4).EngDT = dt.u16;
SetNtcSts.Arguments(4).Units = 'Cnt';
SetNtcSts.Arguments(4).Direction = 'In';
SetNtcSts.Arguments(4).InitRowCol = [1  1];



%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
MotAgAMecl = DataDict.IpSignal;
MotAgAMecl.LongName = 'Motor Angle A';
MotAgAMecl.DocUnits = 'MotRev';
MotAgAMecl.EngDT = dt.u0p16;
MotAgAMecl.EngInit = 0;
MotAgAMecl.EngMin = 0;
MotAgAMecl.EngMax = 0.9999847412;
MotAgAMecl.ReadIn = {'MotAgCorrlnPer1'};
MotAgAMecl.ReadType = 'Rte';


MotAgAMeclQlfr = DataDict.IpSignal;
MotAgAMeclQlfr.LongName = 'Motor Angle a Qualifier';
MotAgAMeclQlfr.DocUnits = 'Cnt';
MotAgAMeclQlfr.EngDT = enum.SigQlfr1;
MotAgAMeclQlfr.EngInit = SigQlfr1.SIGQLFR_NORES;
MotAgAMeclQlfr.EngMin = SigQlfr1.SIGQLFR_NORES;
MotAgAMeclQlfr.EngMax = SigQlfr1.SIGQLFR_FAILD;
MotAgAMeclQlfr.ReadIn = {'MotAgCorrlnPer1'};
MotAgAMeclQlfr.ReadType = 'Rte';


MotAgAMeclRollgCntr = DataDict.IpSignal;
MotAgAMeclRollgCntr.LongName = 'Motor Angle a Rolling Counter';
MotAgAMeclRollgCntr.DocUnits = 'Cnt';
MotAgAMeclRollgCntr.EngDT = dt.u08;
MotAgAMeclRollgCntr.EngInit = 0;
MotAgAMeclRollgCntr.EngMin = 0;
MotAgAMeclRollgCntr.EngMax = 255;
MotAgAMeclRollgCntr.ReadIn = {'MotAgCorrlnPer1'};
MotAgAMeclRollgCntr.ReadType = 'Rte';


MotAgBMecl = DataDict.IpSignal;
MotAgBMecl.LongName = 'Motor Angle B';
MotAgBMecl.DocUnits = 'MotRev';
MotAgBMecl.EngDT = dt.u0p16;
MotAgBMecl.EngInit = 0;
MotAgBMecl.EngMin = 0;
MotAgBMecl.EngMax = 0.9999847412;
MotAgBMecl.ReadIn = {'MotAgCorrlnPer1'};
MotAgBMecl.ReadType = 'Rte';


MotAgBMeclQlfr = DataDict.IpSignal;
MotAgBMeclQlfr.LongName = 'Motor Angle B Qualifier';
MotAgBMeclQlfr.DocUnits = 'Cnt';
MotAgBMeclQlfr.EngDT = enum.SigQlfr1;
MotAgBMeclQlfr.EngInit = SigQlfr1.SIGQLFR_NORES;
MotAgBMeclQlfr.EngMin = SigQlfr1.SIGQLFR_NORES;
MotAgBMeclQlfr.EngMax = SigQlfr1.SIGQLFR_FAILD;
MotAgBMeclQlfr.ReadIn = {'MotAgCorrlnPer1'};
MotAgBMeclQlfr.ReadType = 'Rte';


MotAgBMeclRollgCntr = DataDict.IpSignal;
MotAgBMeclRollgCntr.LongName = 'Motor Angle B Rolling Counter';
MotAgBMeclRollgCntr.DocUnits = 'Cnt';
MotAgBMeclRollgCntr.EngDT = dt.u08;
MotAgBMeclRollgCntr.EngInit = 0;
MotAgBMeclRollgCntr.EngMin = 0;
MotAgBMeclRollgCntr.EngMax = 255;
MotAgBMeclRollgCntr.ReadIn = {'MotAgCorrlnPer1'};
MotAgBMeclRollgCntr.ReadType = 'Rte';


%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
MotAgMeclCorrlnSt = DataDict.OpSignal;
MotAgMeclCorrlnSt.LongName = 'Motor Angle Correlation Status';
MotAgMeclCorrlnSt.Description = [...
  'Indicates the status of the motor angle correlation function'];
MotAgMeclCorrlnSt.DocUnits = 'Cnt';
MotAgMeclCorrlnSt.SwcShoName = 'MotAgCorrln';
MotAgMeclCorrlnSt.EngDT = dt.b08;
MotAgMeclCorrlnSt.EngInit = 3;
MotAgMeclCorrlnSt.EngMin = 0;
MotAgMeclCorrlnSt.EngMax = 3;
MotAgMeclCorrlnSt.TestTolerance = 0;
MotAgMeclCorrlnSt.WrittenIn = {'MotAgCorrlnPer1'};
MotAgMeclCorrlnSt.WriteType = 'Rte';


MotAgMeclIdptSig = DataDict.OpSignal;
MotAgMeclIdptSig.LongName = 'Number of Independent Motor Position Signals';
MotAgMeclIdptSig.Description = [...
  'Indicates the number of motor angle signals usable'];
MotAgMeclIdptSig.DocUnits = 'Cnt';
MotAgMeclIdptSig.SwcShoName = 'MotAgCorrln';
MotAgMeclIdptSig.EngDT = dt.u08;
MotAgMeclIdptSig.EngInit = 2;
MotAgMeclIdptSig.EngMin = 0;
MotAgMeclIdptSig.EngMax = 2;
MotAgMeclIdptSig.TestTolerance = 0;
MotAgMeclIdptSig.WrittenIn = {'MotAgCorrlnPer1'};
MotAgMeclIdptSig.WriteType = 'Rte';



%%-------------------------------------------
%% Inter-Runnable Variable Definition        
%%-------------------------------------------

%%-------------------------------------------
%% Calibrations Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Imported Calibrations Definition                   
%%-------------------------------------------
SysGlbPrmMotPoleCnt = DataDict.ImprtdCal;
SysGlbPrmMotPoleCnt.DocUnits = 'Cnt';
SysGlbPrmMotPoleCnt.EngDT = dt.u08;
SysGlbPrmMotPoleCnt.EngVal = 6;
SysGlbPrmMotPoleCnt.EngMin = 2;
SysGlbPrmMotPoleCnt.EngMax = 12;
SysGlbPrmMotPoleCnt.PortName = 'SysGlbPrmMotPoleCnt';



%%-------------------------------------------
%% Non-Volatile Memory Definition            
%%-------------------------------------------

%%-------------------------------------------
%% Display Variable Definition               
%%-------------------------------------------
dMotAgCorrlnMotAgABOk = DataDict.Display;
dMotAgCorrlnMotAgABOk.LongName = 'Immediate State of Motor Angle A & B';
dMotAgCorrlnMotAgABOk.Description = 'Immediate State of Motor Angle A & B';
dMotAgCorrlnMotAgABOk.DocUnits = 'Cnt';
dMotAgCorrlnMotAgABOk.EngDT = dt.lgc;
dMotAgCorrlnMotAgABOk.EngMin = 0;
dMotAgCorrlnMotAgABOk.EngMax = 1;
dMotAgCorrlnMotAgABOk.InitRowCol = [1  1];

%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------
MotAgCorrlnErrThd = DataDict.PIM;
MotAgCorrlnErrThd.LongName = 'Angle Difference Threshold Between Two Sensor Signals';
MotAgCorrlnErrThd.Description = [...
  'Angle Difference Threshold Between Two Sensor Signals'];
MotAgCorrlnErrThd.DocUnits = 'MotRev';
MotAgCorrlnErrThd.EngDT = dt.u0p16;
MotAgCorrlnErrThd.EngMin = 0;
MotAgCorrlnErrThd.EngMax = 0.9999847412;
MotAgCorrlnErrThd.InitRowCol = [1  1];


MotAgCorrlnMotAgARollgCntPrev = DataDict.PIM;
MotAgCorrlnMotAgARollgCntPrev.LongName = 'Rolling Counter State Variable Motor Angle A';
MotAgCorrlnMotAgARollgCntPrev.Description = [...
  'Rolling Counter State Variable Motor Angle A'];
MotAgCorrlnMotAgARollgCntPrev.DocUnits = 'Cnt';
MotAgCorrlnMotAgARollgCntPrev.EngDT = dt.u08;
MotAgCorrlnMotAgARollgCntPrev.EngMin = 0;
MotAgCorrlnMotAgARollgCntPrev.EngMax = 255;
MotAgCorrlnMotAgARollgCntPrev.InitRowCol = [1  1];


MotAgCorrlnMotAgAStallCntPrev = DataDict.PIM;
MotAgCorrlnMotAgAStallCntPrev.LongName = 'Stall Counter State Variable for Motor Angle A';
MotAgCorrlnMotAgAStallCntPrev.Description = [...
  'Stall Counter State Variable For Motor Angle A'];
MotAgCorrlnMotAgAStallCntPrev.DocUnits = 'Cnt';
MotAgCorrlnMotAgAStallCntPrev.EngDT = dt.u08;
MotAgCorrlnMotAgAStallCntPrev.EngMin = 0;
MotAgCorrlnMotAgAStallCntPrev.EngMax = 255;
MotAgCorrlnMotAgAStallCntPrev.InitRowCol = [1  1];


MotAgCorrlnMotAgBRollgCntPrev = DataDict.PIM;
MotAgCorrlnMotAgBRollgCntPrev.LongName = 'Rolling Counter State Variable Motor Angle B';
MotAgCorrlnMotAgBRollgCntPrev.Description = [...
  'Rolling Counter State Variable Motor Angle B'];
MotAgCorrlnMotAgBRollgCntPrev.DocUnits = 'Cnt';
MotAgCorrlnMotAgBRollgCntPrev.EngDT = dt.u08;
MotAgCorrlnMotAgBRollgCntPrev.EngMin = 0;
MotAgCorrlnMotAgBRollgCntPrev.EngMax = 255;
MotAgCorrlnMotAgBRollgCntPrev.InitRowCol = [1  1];


MotAgCorrlnMotAgBStallCntPrev = DataDict.PIM;
MotAgCorrlnMotAgBStallCntPrev.LongName = 'Stall Counter State Variable for Motor Angle B';
MotAgCorrlnMotAgBStallCntPrev.Description = [...
  'Stall Counter State Variable For Motor Angle B'];
MotAgCorrlnMotAgBStallCntPrev.DocUnits = 'Cnt';
MotAgCorrlnMotAgBStallCntPrev.EngDT = dt.u08;
MotAgCorrlnMotAgBStallCntPrev.EngMin = 0;
MotAgCorrlnMotAgBStallCntPrev.EngMax = 255;
MotAgCorrlnMotAgBStallCntPrev.InitRowCol = [1  1];


%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
FLTINJ_MOTAGCORRLN_MOTAGIDPTSIG = DataDict.Constant;
FLTINJ_MOTAGCORRLN_MOTAGIDPTSIG.LongName = 'Fault Injection Motor Angle Correlation Motor Angle Independent Signal';
FLTINJ_MOTAGCORRLN_MOTAGIDPTSIG.Description = [...
  'Fault Injection Motor Angle Correlation Motor Angle Independent Signal' ...
  ' Constant'];
FLTINJ_MOTAGCORRLN_MOTAGIDPTSIG.DocUnits = 'Uls';
FLTINJ_MOTAGCORRLN_MOTAGIDPTSIG.EngDT = dt.u16;
FLTINJ_MOTAGCORRLN_MOTAGIDPTSIG.EngVal = 28;
FLTINJ_MOTAGCORRLN_MOTAGIDPTSIG.Header = 'FltInj.h';
FLTINJ_MOTAGCORRLN_MOTAGIDPTSIG.Define = 'Global';


HALFREV_MOTREV_U0P16 = DataDict.Constant;
HALFREV_MOTREV_U0P16.LongName = 'Half Revolution';
HALFREV_MOTREV_U0P16.Description = [...
  'Half revolution of motor angle, used as inflection determination for e' ...
  'rror calculation.'];
HALFREV_MOTREV_U0P16.DocUnits = 'MotRev';
HALFREV_MOTREV_U0P16.EngDT = dt.u0p16;
HALFREV_MOTREV_U0P16.EngVal = 0.5;
HALFREV_MOTREV_U0P16.Header = 'None';
HALFREV_MOTREV_U0P16.Define = 'Local';


MOTAGACORRLNST_CNT_U08 = DataDict.Constant;
MOTAGACORRLNST_CNT_U08.LongName = 'Bit Location of Motor Angle a Status';
MOTAGACORRLNST_CNT_U08.Description = [...
  'Bit Location of Motor Angle a Status'];
MOTAGACORRLNST_CNT_U08.DocUnits = 'Cnt';
MOTAGACORRLNST_CNT_U08.EngDT = dt.u08;
MOTAGACORRLNST_CNT_U08.EngVal = 1;
MOTAGACORRLNST_CNT_U08.Header = 'None';
MOTAGACORRLNST_CNT_U08.Define = 'Local';


MOTAGBCORRLNST_CNT_U08 = DataDict.Constant;
MOTAGBCORRLNST_CNT_U08.LongName = 'Bit Location of Motor Angle B Status';
MOTAGBCORRLNST_CNT_U08.Description = [...
  'Bit Location of Motor Angle B Status'];
MOTAGBCORRLNST_CNT_U08.DocUnits = 'Cnt';
MOTAGBCORRLNST_CNT_U08.EngDT = dt.u08;
MOTAGBCORRLNST_CNT_U08.EngVal = 2;
MOTAGBCORRLNST_CNT_U08.Header = 'None';
MOTAGBCORRLNST_CNT_U08.Define = 'Local';


MOTAGCORRLNERRTHD_MOTREVELEC_U0P16 = DataDict.Constant;
MOTAGCORRLNERRTHD_MOTREVELEC_U0P16.LongName = 'Angle Difference Threshold Between Two Sensor Signals';
MOTAGCORRLNERRTHD_MOTREVELEC_U0P16.Description = [...
  'Angle Difference Threshold Between Two Sensor Signals In Electrical Un' ...
  'its'];
MOTAGCORRLNERRTHD_MOTREVELEC_U0P16.DocUnits = 'MotRevElec';
MOTAGCORRLNERRTHD_MOTREVELEC_U0P16.EngDT = dt.u0p16;
MOTAGCORRLNERRTHD_MOTREVELEC_U0P16.EngVal = 0.2222;
MOTAGCORRLNERRTHD_MOTREVELEC_U0P16.Header = 'None';
MOTAGCORRLNERRTHD_MOTREVELEC_U0P16.Define = 'Local';


MOTAGCORRLNNTCFAILSTEP_CNT_U16 = DataDict.Constant;
MOTAGCORRLNNTCFAILSTEP_CNT_U16.LongName = 'Debounce Fail Step for Motor Angle Correlation Diagnostic';
MOTAGCORRLNNTCFAILSTEP_CNT_U16.Description = [...
  'Debounce Fail Step for Motor Angle Correlation Diagnostic'];
MOTAGCORRLNNTCFAILSTEP_CNT_U16.DocUnits = 'Cnt';
MOTAGCORRLNNTCFAILSTEP_CNT_U16.EngDT = dt.u16;
MOTAGCORRLNNTCFAILSTEP_CNT_U16.EngVal = 3277;
MOTAGCORRLNNTCFAILSTEP_CNT_U16.Header = 'None';
MOTAGCORRLNNTCFAILSTEP_CNT_U16.Define = 'Local';


MOTAGCORRLNNTCPASSSTEP_CNT_U16 = DataDict.Constant;
MOTAGCORRLNNTCPASSSTEP_CNT_U16.LongName = 'Debounce Pass Step for Motor Angle Correlation Diagnostic';
MOTAGCORRLNNTCPASSSTEP_CNT_U16.Description = [...
  'Debounce Pass Step for Motor Angle Correlation Diagnostic'];
MOTAGCORRLNNTCPASSSTEP_CNT_U16.DocUnits = 'Cnt';
MOTAGCORRLNNTCPASSSTEP_CNT_U16.EngDT = dt.u16;
MOTAGCORRLNNTCPASSSTEP_CNT_U16.EngVal = 655;
MOTAGCORRLNNTCPASSSTEP_CNT_U16.Header = 'None';
MOTAGCORRLNNTCPASSSTEP_CNT_U16.Define = 'Local';


MOTAGMAXSTALLCNTR_CNT_U08 = DataDict.Constant;
MOTAGMAXSTALLCNTR_CNT_U08.LongName = 'Max Stall Counter for Motor Angle Availability';
MOTAGMAXSTALLCNTR_CNT_U08.Description = [...
  'Max Stall Counter for Motor Angle Availability'];
MOTAGMAXSTALLCNTR_CNT_U08.DocUnits = 'Cnt';
MOTAGMAXSTALLCNTR_CNT_U08.EngDT = dt.u08;
MOTAGMAXSTALLCNTR_CNT_U08.EngVal = 200;
MOTAGMAXSTALLCNTR_CNT_U08.Header = 'None';
MOTAGMAXSTALLCNTR_CNT_U08.Define = 'Local';



%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
MotAgAMotAgBCorrln = DataDict.NTC;
MotAgAMotAgBCorrln.NtcNr = NtcNr2.NTCNR_0X080;
MotAgAMotAgBCorrln.NtcTyp = 'Deb';
MotAgAMotAgBCorrln.LongName = 'Motor Angle A Motor Angle B Correlation';
MotAgAMotAgBCorrln.Description = 'A diagnostic that verifies correlation of MotAgA & MotAgB';
MotAgAMotAgBCorrln.NtcStInfo = DataDict.NtcStInfoBitPacked;
MotAgAMotAgBCorrln.NtcStInfo.Bit0Descr = 'Motor Angle A Motor Angle B Correlation Failure';
MotAgAMotAgBCorrln.NtcStInfo.Bit1Descr = 'Unused';
MotAgAMotAgBCorrln.NtcStInfo.Bit2Descr = 'Unused';
MotAgAMotAgBCorrln.NtcStInfo.Bit3Descr = 'Unused';
MotAgAMotAgBCorrln.NtcStInfo.Bit4Descr = 'Unused';
MotAgAMotAgBCorrln.NtcStInfo.Bit5Descr = 'Unused';
MotAgAMotAgBCorrln.NtcStInfo.Bit6Descr = 'Unused';
MotAgAMotAgBCorrln.NtcStInfo.Bit7Descr = 'Unused';

%end of Data Dictionary
