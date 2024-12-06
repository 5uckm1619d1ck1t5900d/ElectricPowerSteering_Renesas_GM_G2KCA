%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 18-Jan-2017 16:07:58       %
%                                  Created with tool release: 2.51.0     %
%                                  Synergy file: %version: X %           %
%                                  Derived by: %derived_by: X %          %
%%-----------------------------------------------------------------------%

CM620C = DataDict.FDD;
CM620C.Version = '1.6.X';
CM620C.LongName = 'Motor Angle 0 Measurement';
CM620C.ShoName  = 'MotAg0Meas';
CM620C.DesignASIL = 'D';
CM620C.Description = [...
  'Measurement function of Motor Angle 0.  This function includes configu' ...
  'ration and use of the CSIH1 peripheral'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
MotAg0MeasInit1 = DataDict.Runnable;
MotAg0MeasInit1.Context = 'Rte';
MotAg0MeasInit1.TimeStep = 0;
MotAg0MeasInit1.Description = [...
  'Intial Function for Motor Angle 0 Measurement'];

MotAg0MeasPer1 = DataDict.Runnable;
MotAg0MeasPer1.Context = 'NonRte';
MotAg0MeasPer1.TimeStep = 'MotorControl';
MotAg0MeasPer1.Description = [...
  'Periodic 1 for Motor Angle 0 Measurement'];

MotAg0MeasPer2 = DataDict.Runnable;
MotAg0MeasPer2.Context = 'Rte';
MotAg0MeasPer2.TimeStep = 0.002;
MotAg0MeasPer2.Description = [...
  'Periodic 2 for Motor Angle 0 Measurement'];

MotAg0MeasPer3 = DataDict.Runnable;
MotAg0MeasPer3.Context = 'Rte';
MotAg0MeasPer3.TimeStep = 0.002;
MotAg0MeasPer3.Description = [...
  'Periodic 3 for Motor Angle 0 Measurement'];

MotAg0CoeffTblRead = DataDict.SrvRunnable;
MotAg0CoeffTblRead.Context = 'Rte';
MotAg0CoeffTblRead.Description = [...
  'used to get the data from motor angle 0 coefficient table'];
MotAg0CoeffTblRead.Return = DataDict.CSReturn;
MotAg0CoeffTblRead.Return.Type = 'None';
MotAg0CoeffTblRead.Return.Min = [];
MotAg0CoeffTblRead.Return.Max = [];
MotAg0CoeffTblRead.Return.TestTolerance = [];
MotAg0CoeffTblRead.Arguments(1) = DataDict.CSArguments;
MotAg0CoeffTblRead.Arguments(1).Name = 'MotAgCoeffTbl';
MotAg0CoeffTblRead.Arguments(1).EngDT = dt.float32;
MotAg0CoeffTblRead.Arguments(1).EngMin = -0.03100585937;
MotAg0CoeffTblRead.Arguments(1).EngMax = 0.03100585937;
MotAg0CoeffTblRead.Arguments(1).TestTolerance = 0;
MotAg0CoeffTblRead.Arguments(1).Units = 'Uls';
MotAg0CoeffTblRead.Arguments(1).Direction = 'Out';
MotAg0CoeffTblRead.Arguments(1).InitRowCol = [26   1];
MotAg0CoeffTblRead.Arguments(1).Description = 'Table index';

MotAg0CoeffTblWr = DataDict.SrvRunnable;
MotAg0CoeffTblWr.Context = 'Rte';
MotAg0CoeffTblWr.Description = [...
  'used to write the data to motor angle 0 coefficient table'];
MotAg0CoeffTblWr.Return = DataDict.CSReturn;
MotAg0CoeffTblWr.Return.Type = 'None';
MotAg0CoeffTblWr.Return.Min = [];
MotAg0CoeffTblWr.Return.Max = [];
MotAg0CoeffTblWr.Return.TestTolerance = [];
MotAg0CoeffTblWr.Arguments(1) = DataDict.CSArguments;
MotAg0CoeffTblWr.Arguments(1).Name = 'MotAgCoeffTbl';
MotAg0CoeffTblWr.Arguments(1).EngDT = dt.float32;
MotAg0CoeffTblWr.Arguments(1).EngMin = -0.03100585937;
MotAg0CoeffTblWr.Arguments(1).EngMax = 0.03100585937;
MotAg0CoeffTblWr.Arguments(1).Units = 'Uls';
MotAg0CoeffTblWr.Arguments(1).Direction = 'In';
MotAg0CoeffTblWr.Arguments(1).InitRowCol = [26   1];
MotAg0CoeffTblWr.Arguments(1).Description = 'coefficient table index';


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------
GetMotAg3Mecl = DataDict.Client;
GetMotAg3Mecl.CallLocation = {'MotAg0MeasPer1','MotAg0MeasPer3'};
GetMotAg3Mecl.Description = [...
  'client server to get Motor Angle 3 in mechanical units'];
GetMotAg3Mecl.Return = DataDict.CSReturn;
GetMotAg3Mecl.Return.Type = 'Standard';
GetMotAg3Mecl.Return.Min = 0;
GetMotAg3Mecl.Return.Max = 1;
GetMotAg3Mecl.Return.TestTolerance = [];
GetMotAg3Mecl.Return.Description = 'Return to get Motor Angle 3';
GetMotAg3Mecl.Arguments(1) = DataDict.CSArguments;
GetMotAg3Mecl.Arguments(1).Name = 'MotAgMecl';
GetMotAg3Mecl.Arguments(1).EngDT = dt.u0p16;
GetMotAg3Mecl.Arguments(1).EngMin = 0;
GetMotAg3Mecl.Arguments(1).EngMax = 0.9999847412;
GetMotAg3Mecl.Arguments(1).TestTolerance = 1.525878906e-05;
GetMotAg3Mecl.Arguments(1).Units = 'MotRev';
GetMotAg3Mecl.Arguments(1).Direction = 'Out';
GetMotAg3Mecl.Arguments(1).InitRowCol = [1  1];
GetMotAg3Mecl.Arguments(1).Description = [...
  'Motor Angle 3 value in mechanical units'];


GetNtcQlfrSts = DataDict.Client;
GetNtcQlfrSts.CallLocation = {'MotAg0MeasPer2'};
GetNtcQlfrSts.Description = [...
  'client server to get NTC qualifier status Core'];
GetNtcQlfrSts.Return = DataDict.CSReturn;
GetNtcQlfrSts.Return.Type = 'Standard';
GetNtcQlfrSts.Return.Min = 0;
GetNtcQlfrSts.Return.Max = 1;
GetNtcQlfrSts.Return.TestTolerance = [];
GetNtcQlfrSts.Return.Description = 'Return to get NTC qualifier status';
GetNtcQlfrSts.Arguments(1) = DataDict.CSArguments;
GetNtcQlfrSts.Arguments(1).Name = 'NtcNr';
GetNtcQlfrSts.Arguments(1).EngDT = enum.NtcNr1;
GetNtcQlfrSts.Arguments(1).EngMin = NtcNr1.NTCNR_0X001;
GetNtcQlfrSts.Arguments(1).EngMax = NtcNr1.NTCNR_0X1FF;
GetNtcQlfrSts.Arguments(1).Units = 'Cnt';
GetNtcQlfrSts.Arguments(1).Direction = 'In';
GetNtcQlfrSts.Arguments(1).InitRowCol = [1  1];
GetNtcQlfrSts.Arguments(1).Description = 'NTC number';
GetNtcQlfrSts.Arguments(2) = DataDict.CSArguments;
GetNtcQlfrSts.Arguments(2).Name = 'NtcQlfr';
GetNtcQlfrSts.Arguments(2).EngDT = enum.SigQlfr1;
GetNtcQlfrSts.Arguments(2).EngMin = SigQlfr1.SIGQLFR_NORES;
GetNtcQlfrSts.Arguments(2).EngMax = SigQlfr1.SIGQLFR_FAILD;
GetNtcQlfrSts.Arguments(2).TestTolerance = 0;
GetNtcQlfrSts.Arguments(2).Units = 'Cnt';
GetNtcQlfrSts.Arguments(2).Direction = 'Out';
GetNtcQlfrSts.Arguments(2).InitRowCol = [1  1];
GetNtcQlfrSts.Arguments(2).Description = 'NTC Qualifier';


GetRefTmr1MicroSec32bit = DataDict.Client;
GetRefTmr1MicroSec32bit.CallLocation = {'MotAg0MeasPer1','MotAg0MeasPer3'};
GetRefTmr1MicroSec32bit.Description = 'To get 1micro sec timer';
GetRefTmr1MicroSec32bit.Return = DataDict.CSReturn;
GetRefTmr1MicroSec32bit.Return.Type = 'None';
GetRefTmr1MicroSec32bit.Return.Min = [];
GetRefTmr1MicroSec32bit.Return.Max = [];
GetRefTmr1MicroSec32bit.Return.TestTolerance = [];
GetRefTmr1MicroSec32bit.Arguments(1) = DataDict.CSArguments;
GetRefTmr1MicroSec32bit.Arguments(1).Name = 'RefTmr';
GetRefTmr1MicroSec32bit.Arguments(1).EngDT = dt.u32;
GetRefTmr1MicroSec32bit.Arguments(1).EngMin = 0;
GetRefTmr1MicroSec32bit.Arguments(1).EngMax = 4294967295;
GetRefTmr1MicroSec32bit.Arguments(1).TestTolerance = 0;
GetRefTmr1MicroSec32bit.Arguments(1).Units = 'Cnt';
GetRefTmr1MicroSec32bit.Arguments(1).Direction = 'Out';
GetRefTmr1MicroSec32bit.Arguments(1).InitRowCol = [1  1];
GetRefTmr1MicroSec32bit.Arguments(1).Description = 'Refference Timer';


GetTiSpan1MicroSec32bit = DataDict.Client;
GetTiSpan1MicroSec32bit.CallLocation = {'MotAg0MeasPer3'};
GetTiSpan1MicroSec32bit.Description = 'To get 1micro second timer';
GetTiSpan1MicroSec32bit.Return = DataDict.CSReturn;
GetTiSpan1MicroSec32bit.Return.Type = 'None';
GetTiSpan1MicroSec32bit.Return.Min = [];
GetTiSpan1MicroSec32bit.Return.Max = [];
GetTiSpan1MicroSec32bit.Return.TestTolerance = [];
GetTiSpan1MicroSec32bit.Arguments(1) = DataDict.CSArguments;
GetTiSpan1MicroSec32bit.Arguments(1).Name = 'RefTmr';
GetTiSpan1MicroSec32bit.Arguments(1).EngDT = dt.u32;
GetTiSpan1MicroSec32bit.Arguments(1).EngMin = 0;
GetTiSpan1MicroSec32bit.Arguments(1).EngMax = 4294967295;
GetTiSpan1MicroSec32bit.Arguments(1).Units = 'Cnt';
GetTiSpan1MicroSec32bit.Arguments(1).Direction = 'In';
GetTiSpan1MicroSec32bit.Arguments(1).InitRowCol = [1  1];
GetTiSpan1MicroSec32bit.Arguments(1).Description = '';
GetTiSpan1MicroSec32bit.Arguments(2) = DataDict.CSArguments;
GetTiSpan1MicroSec32bit.Arguments(2).Name = 'TiSpan';
GetTiSpan1MicroSec32bit.Arguments(2).EngDT = dt.u32;
GetTiSpan1MicroSec32bit.Arguments(2).EngMin = 0;
GetTiSpan1MicroSec32bit.Arguments(2).EngMax = 4294967295;
GetTiSpan1MicroSec32bit.Arguments(2).TestTolerance = 0;
GetTiSpan1MicroSec32bit.Arguments(2).Units = 'Cnt';
GetTiSpan1MicroSec32bit.Arguments(2).Direction = 'Out';
GetTiSpan1MicroSec32bit.Arguments(2).InitRowCol = [1  1];
GetTiSpan1MicroSec32bit.Arguments(2).Description = '';


IoHwAb_SetFctGpioMotAg0 = DataDict.Client;
IoHwAb_SetFctGpioMotAg0.CallLocation = {'MotAg0MeasPer3'};
IoHwAb_SetFctGpioMotAg0.Description = 'Set GPIO mode';
IoHwAb_SetFctGpioMotAg0.Return = DataDict.CSReturn;
IoHwAb_SetFctGpioMotAg0.Return.Type = 'Standard';
IoHwAb_SetFctGpioMotAg0.Return.Min = 0;
IoHwAb_SetFctGpioMotAg0.Return.Max = 1;
IoHwAb_SetFctGpioMotAg0.Return.TestTolerance = [];
IoHwAb_SetFctGpioMotAg0.Return.Description = 'Set CSIH to GPIO mode';


IoHwAb_SetFctPrphlCsihMotAg0 = DataDict.Client;
IoHwAb_SetFctPrphlCsihMotAg0.CallLocation = {'MotAg0MeasPer3'};
IoHwAb_SetFctPrphlCsihMotAg0.Description = 'Set peripheral to CSIH mode';
IoHwAb_SetFctPrphlCsihMotAg0.Return = DataDict.CSReturn;
IoHwAb_SetFctPrphlCsihMotAg0.Return.Type = 'Standard';
IoHwAb_SetFctPrphlCsihMotAg0.Return.Min = 0;
IoHwAb_SetFctPrphlCsihMotAg0.Return.Max = 1;
IoHwAb_SetFctPrphlCsihMotAg0.Return.TestTolerance = [];
IoHwAb_SetFctPrphlCsihMotAg0.Return.Description = 'Set to CSIH Peripheral';


IoHwAb_SetGpioMotAg0CsihCs = DataDict.Client;
IoHwAb_SetGpioMotAg0CsihCs.CallLocation = {'MotAg0MeasPer3'};
IoHwAb_SetGpioMotAg0CsihCs.Description = 'Set chip select of CSIH peripheral';
IoHwAb_SetGpioMotAg0CsihCs.Return = DataDict.CSReturn;
IoHwAb_SetGpioMotAg0CsihCs.Return.Type = 'Standard';
IoHwAb_SetGpioMotAg0CsihCs.Return.Min = 0;
IoHwAb_SetGpioMotAg0CsihCs.Return.Max = 1;
IoHwAb_SetGpioMotAg0CsihCs.Return.TestTolerance = [];
IoHwAb_SetGpioMotAg0CsihCs.Return.Description = 'Set CSIH Chip Select Pin';


MotAg0CoeffTbl_GetErrorStatus = DataDict.Client;
MotAg0CoeffTbl_GetErrorStatus.CallLocation = {'MotAg0MeasInit1'};
MotAg0CoeffTbl_GetErrorStatus.Description = [...
  'Client to get motor angle coefficient table error status'];
MotAg0CoeffTbl_GetErrorStatus.Return = DataDict.CSReturn;
MotAg0CoeffTbl_GetErrorStatus.Return.Type = 'Standard';
MotAg0CoeffTbl_GetErrorStatus.Return.Min = 0;
MotAg0CoeffTbl_GetErrorStatus.Return.Max = 1;
MotAg0CoeffTbl_GetErrorStatus.Return.TestTolerance = [];
MotAg0CoeffTbl_GetErrorStatus.Return.Description = 'Return perameters ';
MotAg0CoeffTbl_GetErrorStatus.Arguments(1) = DataDict.CSArguments;
MotAg0CoeffTbl_GetErrorStatus.Arguments(1).Name = 'RequestResultPtr';
MotAg0CoeffTbl_GetErrorStatus.Arguments(1).EngDT = dt.u08;
MotAg0CoeffTbl_GetErrorStatus.Arguments(1).EngMin = 0;
MotAg0CoeffTbl_GetErrorStatus.Arguments(1).EngMax = 255;
MotAg0CoeffTbl_GetErrorStatus.Arguments(1).TestTolerance = 0;
MotAg0CoeffTbl_GetErrorStatus.Arguments(1).Units = 'Cnt';
MotAg0CoeffTbl_GetErrorStatus.Arguments(1).Direction = 'Out';
MotAg0CoeffTbl_GetErrorStatus.Arguments(1).InitRowCol = [1  1];
MotAg0CoeffTbl_GetErrorStatus.Arguments(1).Description = [...
  'Polarity for requested error status result'];


MotAg0CoeffTbl_SetRamBlockStatus = DataDict.Client;
MotAg0CoeffTbl_SetRamBlockStatus.CallLocation = {'MotAg0CoeffTblWr'};
MotAg0CoeffTbl_SetRamBlockStatus.Description = [...
  'Client to set random access memory to motor angle coefficient table'];
MotAg0CoeffTbl_SetRamBlockStatus.Return = DataDict.CSReturn;
MotAg0CoeffTbl_SetRamBlockStatus.Return.Type = 'Standard';
MotAg0CoeffTbl_SetRamBlockStatus.Return.Min = 0;
MotAg0CoeffTbl_SetRamBlockStatus.Return.Max = 1;
MotAg0CoeffTbl_SetRamBlockStatus.Return.TestTolerance = 0;
MotAg0CoeffTbl_SetRamBlockStatus.Return.Description = 'Return perameters';
MotAg0CoeffTbl_SetRamBlockStatus.Arguments(1) = DataDict.CSArguments;
MotAg0CoeffTbl_SetRamBlockStatus.Arguments(1).Name = 'BlockChanged';
MotAg0CoeffTbl_SetRamBlockStatus.Arguments(1).EngDT = dt.lgc;
MotAg0CoeffTbl_SetRamBlockStatus.Arguments(1).EngMin = 0;
MotAg0CoeffTbl_SetRamBlockStatus.Arguments(1).EngMax = 1;
MotAg0CoeffTbl_SetRamBlockStatus.Arguments(1).Units = 'Cnt';
MotAg0CoeffTbl_SetRamBlockStatus.Arguments(1).Direction = 'In';
MotAg0CoeffTbl_SetRamBlockStatus.Arguments(1).InitRowCol = [1  1];
MotAg0CoeffTbl_SetRamBlockStatus.Arguments(1).Description = 'change of the block in the memory';


SetNtcSts = DataDict.Client;
SetNtcSts.CallLocation = {'MotAg0MeasPer2'};
SetNtcSts.Description = 'To set NTC status';
SetNtcSts.Return = DataDict.CSReturn;
SetNtcSts.Return.Type = 'Standard';
SetNtcSts.Return.Min = 0;
SetNtcSts.Return.Max = 1;
SetNtcSts.Return.TestTolerance = [];
SetNtcSts.Return.Description = 'Return parameters';
SetNtcSts.Arguments(1) = DataDict.CSArguments;
SetNtcSts.Arguments(1).Name = 'NtcNr';
SetNtcSts.Arguments(1).EngDT = enum.NtcNr1;
SetNtcSts.Arguments(1).EngMin = NtcNr1.NTCNR_0X001;
SetNtcSts.Arguments(1).EngMax = NtcNr1.NTCNR_0X1FF;
SetNtcSts.Arguments(1).Units = 'Cnt';
SetNtcSts.Arguments(1).Direction = 'In';
SetNtcSts.Arguments(1).InitRowCol = [1  1];
SetNtcSts.Arguments(1).Description = 'NTC number';
SetNtcSts.Arguments(2) = DataDict.CSArguments;
SetNtcSts.Arguments(2).Name = 'NtcStInfo';
SetNtcSts.Arguments(2).EngDT = dt.u08;
SetNtcSts.Arguments(2).EngMin = 0;
SetNtcSts.Arguments(2).EngMax = 255;
SetNtcSts.Arguments(2).Units = 'Cnt';
SetNtcSts.Arguments(2).Direction = 'In';
SetNtcSts.Arguments(2).InitRowCol = [1  1];
SetNtcSts.Arguments(2).Description = 'NTC status information';
SetNtcSts.Arguments(3) = DataDict.CSArguments;
SetNtcSts.Arguments(3).Name = 'NtcSts';
SetNtcSts.Arguments(3).EngDT = enum.NtcSts1;
SetNtcSts.Arguments(3).EngMin = NtcSts1.NTCSTS_PASSD;
SetNtcSts.Arguments(3).EngMax = NtcSts1.NTCSTS_PREFAILD;
SetNtcSts.Arguments(3).Units = 'Cnt';
SetNtcSts.Arguments(3).Direction = 'In';
SetNtcSts.Arguments(3).InitRowCol = [1  1];
SetNtcSts.Arguments(3).Description = 'NTC Status';
SetNtcSts.Arguments(4) = DataDict.CSArguments;
SetNtcSts.Arguments(4).Name = 'DebStep';
SetNtcSts.Arguments(4).EngDT = dt.u16;
SetNtcSts.Arguments(4).EngMin = 0;
SetNtcSts.Arguments(4).EngMax = 65535;
SetNtcSts.Arguments(4).Units = 'Cnt';
SetNtcSts.Arguments(4).Direction = 'In';
SetNtcSts.Arguments(4).InitRowCol = [1  1];
SetNtcSts.Arguments(4).Description = 'Debounce step for an NTC';



%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
MotAgMecl0Polarity = DataDict.IpSignal;
MotAgMecl0Polarity.LongName = 'Motor Angle Mechanical 0 Polarity';
MotAgMecl0Polarity.Description = 'Polarity value of Motor Angle 0';
MotAgMecl0Polarity.DocUnits = 'Uls';
MotAgMecl0Polarity.EngDT = dt.s08;
MotAgMecl0Polarity.EngInit = 1;
MotAgMecl0Polarity.EngMin = -1;
MotAgMecl0Polarity.EngMax = 1;
MotAgMecl0Polarity.ReadIn = {'MotAg0MeasPer2'};
MotAgMecl0Polarity.ReadType = 'Rte';


MotCtrlMotAg0Offs = DataDict.IpSignal;
MotCtrlMotAg0Offs.LongName = 'Motor Control Motor Angle 0 Offset';
MotCtrlMotAg0Offs.Description = [...
  'Motor Angle 0 calculated offset value'];
MotCtrlMotAg0Offs.DocUnits = 'Cnt';
MotCtrlMotAg0Offs.EngDT = dt.s32;
MotCtrlMotAg0Offs.EngInit = 0;
MotCtrlMotAg0Offs.EngMin = -2147483648;
MotCtrlMotAg0Offs.EngMax = 2147483647;
MotCtrlMotAg0Offs.ReadIn = {'MotAg0MeasPer1'};
MotCtrlMotAg0Offs.ReadType = 'NonRte';


RegInpCSIH1STR0 = DataDict.IpSignal;
RegInpCSIH1STR0.LongName = 'Register Input CSIH1STR0';
RegInpCSIH1STR0.Description = 'Register CSIH1STR0 Value';
RegInpCSIH1STR0.DocUnits = 'Cnt';
RegInpCSIH1STR0.EngDT = dt.u32;
RegInpCSIH1STR0.EngInit = 0;
RegInpCSIH1STR0.EngMin = 0;
RegInpCSIH1STR0.EngMax = 4294967295;
RegInpCSIH1STR0.ReadIn = {'MotAg0MeasPer3'};
RegInpCSIH1STR0.ReadType = 'Phy';


RegInptCSIH1RX0W = DataDict.IpSignal;
RegInptCSIH1RX0W.LongName = 'Register Input CSIH1RX0W';
RegInptCSIH1RX0W.Description = 'Register CSIH1RX0W Value';
RegInptCSIH1RX0W.DocUnits = 'Cnt';
RegInptCSIH1RX0W.EngDT = dt.u32;
RegInptCSIH1RX0W.EngInit = 0;
RegInptCSIH1RX0W.EngMin = 0;
RegInptCSIH1RX0W.EngMax = 4294967295;
RegInptCSIH1RX0W.ReadIn = {'MotAg0MeasPer2'};
RegInptCSIH1RX0W.ReadType = 'Phy';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
MotAg0MeclQlfr = DataDict.OpSignal;
MotAg0MeclQlfr.LongName = 'Motor Angle 0 Mechanical Qualifier';
MotAg0MeclQlfr.Description = 'Qualifer output of motor angle 0';
MotAg0MeclQlfr.DocUnits = 'Cnt';
MotAg0MeclQlfr.SwcShoName = 'MotAg0Meas';
MotAg0MeclQlfr.EngDT = enum.SigQlfr1;
MotAg0MeclQlfr.EngInit = SigQlfr1.SIGQLFR_NORES;
MotAg0MeclQlfr.EngMin = SigQlfr1.SIGQLFR_NORES;
MotAg0MeclQlfr.EngMax = SigQlfr1.SIGQLFR_FAILD;
MotAg0MeclQlfr.TestTolerance = 0;
MotAg0MeclQlfr.WrittenIn = {'MotAg0MeasPer2'};
MotAg0MeclQlfr.WriteType = 'Rte';


MotAg0MeclRollgCntr = DataDict.OpSignal;
MotAg0MeclRollgCntr.LongName = 'Motor Angle 0 Rolling Counter';
MotAg0MeclRollgCntr.Description = [...
  'Rolling counter of Motor Angle 0, indicating protocol status of angle ' ...
  'measurement.'];
MotAg0MeclRollgCntr.DocUnits = 'Cnt';
MotAg0MeclRollgCntr.SwcShoName = 'MotAg0Meas';
MotAg0MeclRollgCntr.EngDT = dt.u08;
MotAg0MeclRollgCntr.EngInit = 0;
MotAg0MeclRollgCntr.EngMin = 0;
MotAg0MeclRollgCntr.EngMax = 255;
MotAg0MeclRollgCntr.TestTolerance = 0;
MotAg0MeclRollgCntr.WrittenIn = {'MotAg0MeasPer2'};
MotAg0MeclRollgCntr.WriteType = 'Rte';


MotAg0Offs = DataDict.OpSignal;
MotAg0Offs.LongName = 'Motor Angle 0 Offset';
MotAg0Offs.Description = [...
  'Calculated Motor Angle 0 Offset (MotAg3 vs MotAg0)'];
MotAg0Offs.DocUnits = 'Cnt';
MotAg0Offs.SwcShoName = 'MotAg0Meas';
MotAg0Offs.EngDT = dt.s32;
MotAg0Offs.EngInit = 0;
MotAg0Offs.EngMin = -2147483648;
MotAg0Offs.EngMax = 2147483647;
MotAg0Offs.TestTolerance = 0;
MotAg0Offs.WrittenIn = {'MotAg0MeasPer2'};
MotAg0Offs.WriteType = 'Rte';


MotCtrlMotAg0Mecl = DataDict.OpSignal;
MotCtrlMotAg0Mecl.LongName = 'Motor Angle 0 Mechanical';
MotCtrlMotAg0Mecl.Description = [...
  'Motor Control Motor Angle 0 in mechanical units'];
MotCtrlMotAg0Mecl.DocUnits = 'MotRev';
MotCtrlMotAg0Mecl.SwcShoName = 'MotAg0Meas';
MotCtrlMotAg0Mecl.EngDT = dt.u0p16;
MotCtrlMotAg0Mecl.EngInit = 0;
MotCtrlMotAg0Mecl.EngMin = 0;
MotCtrlMotAg0Mecl.EngMax = 0.9999847412;
MotCtrlMotAg0Mecl.TestTolerance = 1.525878906e-05;
MotCtrlMotAg0Mecl.WrittenIn = {'MotAg0MeasPer1'};
MotCtrlMotAg0Mecl.WriteType = 'NonRte';


MotCtrlMotAgMeasTi = DataDict.OpSignal;
MotCtrlMotAgMeasTi.LongName = 'Motor Control Motor Angle 0 Measurement Time';
MotCtrlMotAgMeasTi.Description = [...
  'Measurement time of Motor Angle 0 in counts representing uSec.'];
MotCtrlMotAgMeasTi.DocUnits = 'Cnt';
MotCtrlMotAgMeasTi.SwcShoName = 'MotAg0Meas';
MotCtrlMotAgMeasTi.EngDT = dt.u32;
MotCtrlMotAgMeasTi.EngInit = 0;
MotCtrlMotAgMeasTi.EngMin = 0;
MotCtrlMotAgMeasTi.EngMax = 4294967295;
MotCtrlMotAgMeasTi.TestTolerance = 0;
MotCtrlMotAgMeasTi.WrittenIn = {'MotAg0MeasPer1'};
MotCtrlMotAgMeasTi.WriteType = 'NonRte';


RegOutpCSIH1MCTL2 = DataDict.OpSignal;
RegOutpCSIH1MCTL2.LongName = 'Register Output CSIH1MCTL2';
RegOutpCSIH1MCTL2.Description = 'CSIH1MCTL2 Register write';
RegOutpCSIH1MCTL2.DocUnits = 'Cnt';
RegOutpCSIH1MCTL2.SwcShoName = 'MotAg0Meas';
RegOutpCSIH1MCTL2.EngDT = dt.u32;
RegOutpCSIH1MCTL2.EngInit = 0;
RegOutpCSIH1MCTL2.EngMin = 0;
RegOutpCSIH1MCTL2.EngMax = 4294967295;
RegOutpCSIH1MCTL2.TestTolerance = 0;
RegOutpCSIH1MCTL2.WrittenIn = {'MotAg0MeasPer3','MotAg0MeasInit1'};
RegOutpCSIH1MCTL2.WriteType = 'Phy';


RegOutpCSIH1MRWP0 = DataDict.OpSignal;
RegOutpCSIH1MRWP0.LongName = 'Register Output CSIH1MRWP0';
RegOutpCSIH1MRWP0.Description = 'CSIH1MRWP0 Register';
RegOutpCSIH1MRWP0.DocUnits = 'Cnt';
RegOutpCSIH1MRWP0.SwcShoName = 'MotAg0Meas';
RegOutpCSIH1MRWP0.EngDT = dt.u32;
RegOutpCSIH1MRWP0.EngInit = 0;
RegOutpCSIH1MRWP0.EngMin = 0;
RegOutpCSIH1MRWP0.EngMax = 4294967295;
RegOutpCSIH1MRWP0.TestTolerance = 0;
RegOutpCSIH1MRWP0.WrittenIn = {'MotAg0MeasPer2'};
RegOutpCSIH1MRWP0.WriteType = 'Phy';



%%-------------------------------------------
%% Inter-Runnable Variable Definition        
%%-------------------------------------------
MotAg0DiagcAg = DataDict.IRV;
MotAg0DiagcAg.LongName = 'Motor Angle 0 Diagnostic Angle';
MotAg0DiagcAg.Description = [...
  'Motor angle mechanical used for diagnostics'];
MotAg0DiagcAg.DocUnits = 'MotRev';
MotAg0DiagcAg.EngDT = dt.u0p16;
MotAg0DiagcAg.EngInit = 0;
MotAg0DiagcAg.EngMin = 0;
MotAg0DiagcAg.EngMax = 0.9999847412;
MotAg0DiagcAg.ReadIn = {'MotAg0MeasPer2'};
MotAg0DiagcAg.WrittenIn = {'MotAg0MeasPer3'};


MotAg0SpiTrsmEna = DataDict.IRV;
MotAg0SpiTrsmEna.LongName = 'Motor Angle 0 Serial Peripheral Interface Transmission Enable';
MotAg0SpiTrsmEna.Description = [...
  'Flag describing Spi transmission is Idle or Communicating'];
MotAg0SpiTrsmEna.DocUnits = 'Cnt';
MotAg0SpiTrsmEna.EngDT = dt.lgc;
MotAg0SpiTrsmEna.EngInit = 0;
MotAg0SpiTrsmEna.EngMin = 0;
MotAg0SpiTrsmEna.EngMax = 1;
MotAg0SpiTrsmEna.ReadIn = {'MotAg0MeasPer2'};
MotAg0SpiTrsmEna.WrittenIn = {'MotAg0MeasPer3'};


MotAg3Mecl = DataDict.IRV;
MotAg3Mecl.LongName = 'Motor Angle 3 Mechanical';
MotAg3Mecl.Description = [...
  'Motor Angle 3 value in mechanical units'];
MotAg3Mecl.DocUnits = 'MotRev';
MotAg3Mecl.EngDT = dt.u0p16;
MotAg3Mecl.EngInit = 0;
MotAg3Mecl.EngMin = 0;
MotAg3Mecl.EngMax = 0.9999847412;
MotAg3Mecl.ReadIn = {'MotAg0MeasPer2'};
MotAg3Mecl.WrittenIn = {'MotAg0MeasPer3'};



%%-------------------------------------------
%% Calibrations Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Imported Calibrations Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Non-Volatile Memory Definition            
%%-------------------------------------------
MotAg0CoeffTbl = DataDict.NVM;
MotAg0CoeffTbl.LongName = 'Motor Angle 0 Coefficient Table';
MotAg0CoeffTbl.Description = [...
  'Coefficient table for Motor Angle 0.'];
MotAg0CoeffTbl.DocUnits = 'MotRev';
MotAg0CoeffTbl.EngDT = dt.float32;
MotAg0CoeffTbl.EngInit = [];
MotAg0CoeffTbl.EngMin = -0.03100585937;
MotAg0CoeffTbl.EngMax = 0.03100585937;
MotAg0CoeffTbl.CustomerVisible = false;
MotAg0CoeffTbl.Impact = 'H';
MotAg0CoeffTbl.TuningOwner = 'CSE';
MotAg0CoeffTbl.CoderInfo.Alias = '';
MotAg0CoeffTbl.InitRowCol = [1  26];



%%-------------------------------------------
%% Display Variable Definition               
%%-------------------------------------------
dMotAg0MeasMotAg0Delta = DataDict.Display;
dMotAg0MeasMotAg0Delta.LongName = 'Motor Angle 0 Delta';
dMotAg0MeasMotAg0Delta.Description = [...
  'Display variable of difference between angle from encoder interfaceand' ...
  ' angle from SPI bus'];
dMotAg0MeasMotAg0Delta.DocUnits = 'MotRev';
dMotAg0MeasMotAg0Delta.EngDT = dt.u0p16;
dMotAg0MeasMotAg0Delta.EngMin = 0;
dMotAg0MeasMotAg0Delta.EngMax = 0.9999847412;
dMotAg0MeasMotAg0Delta.InitRowCol = [1  1];


dMotAg0MeasMotAg0RawAgReg = DataDict.Display;
dMotAg0MeasMotAg0RawAgReg.LongName = 'Motor Angle 0 Raw Angle Register';
dMotAg0MeasMotAg0RawAgReg.Description = [...
  'Display variable for Motor Angle 0 Raw Angle Register'];
dMotAg0MeasMotAg0RawAgReg.DocUnits = 'Cnt';
dMotAg0MeasMotAg0RawAgReg.EngDT = dt.u32;
dMotAg0MeasMotAg0RawAgReg.EngMin = 0;
dMotAg0MeasMotAg0RawAgReg.EngMax = 67108863;
dMotAg0MeasMotAg0RawAgReg.InitRowCol = [1  1];


dMotAg0MeasMotAg0RawErrReg = DataDict.Display;
dMotAg0MeasMotAg0RawErrReg.LongName = 'Motor Angle 0 Raw Error Register';
dMotAg0MeasMotAg0RawErrReg.Description = [...
  'Display variable for Motor Angle 0 Raw Error Register'];
dMotAg0MeasMotAg0RawErrReg.DocUnits = 'Cnt';
dMotAg0MeasMotAg0RawErrReg.EngDT = dt.u32;
dMotAg0MeasMotAg0RawErrReg.EngMin = 0;
dMotAg0MeasMotAg0RawErrReg.EngMax = 67108863;
dMotAg0MeasMotAg0RawErrReg.InitRowCol = [1  1];


dMotAg0MeasMotAg0RawReg = DataDict.Display;
dMotAg0MeasMotAg0RawReg.LongName = 'Motor Angle 0 Raw Register';
dMotAg0MeasMotAg0RawReg.Description = [...
  'Display variable for Motor Angle 0 Raw Register Values'];
dMotAg0MeasMotAg0RawReg.DocUnits = 'Cnt';
dMotAg0MeasMotAg0RawReg.EngDT = dt.u32;
dMotAg0MeasMotAg0RawReg.EngMin = 0;
dMotAg0MeasMotAg0RawReg.EngMax = 67108863;
dMotAg0MeasMotAg0RawReg.InitRowCol = [10   1];


dMotAg0MeasMotAg0RawTurnCntrReg = DataDict.Display;
dMotAg0MeasMotAg0RawTurnCntrReg.LongName = 'Motor Angle 0 Raw Turn Counter Register';
dMotAg0MeasMotAg0RawTurnCntrReg.Description = [...
  'Display variable Motor Angle 0 Raw Turn Counter Register'];
dMotAg0MeasMotAg0RawTurnCntrReg.DocUnits = 'Cnt';
dMotAg0MeasMotAg0RawTurnCntrReg.EngDT = dt.u32;
dMotAg0MeasMotAg0RawTurnCntrReg.EngMin = 0;
dMotAg0MeasMotAg0RawTurnCntrReg.EngMax = 67108863;
dMotAg0MeasMotAg0RawTurnCntrReg.InitRowCol = [1  1];


dMotAg0MeasMotAg0RtOffs = DataDict.Display;
dMotAg0MeasMotAg0RtOffs.LongName = 'Motor Angle 0 Runtime Offset';
dMotAg0MeasMotAg0RtOffs.Description = [...
  'Display variable of Motor Angle 0 Runtime Offset'];
dMotAg0MeasMotAg0RtOffs.DocUnits = 'Cnt';
dMotAg0MeasMotAg0RtOffs.EngDT = dt.s32;
dMotAg0MeasMotAg0RtOffs.EngMin = -2147483648;
dMotAg0MeasMotAg0RtOffs.EngMax = 2147483647;
dMotAg0MeasMotAg0RtOffs.InitRowCol = [1  1];


dMotAg0MeasMotAg0SpiCntrAg = DataDict.Display;
dMotAg0MeasMotAg0SpiCntrAg.LongName = 'Motor Angle 0 Serial Peripheral Interface Counter Angle';
dMotAg0MeasMotAg0SpiCntrAg.Description = [...
  'Display variable of Motor Angle 0 SPI IIF Counter Angle'];
dMotAg0MeasMotAg0SpiCntrAg.DocUnits = 'Cnt';
dMotAg0MeasMotAg0SpiCntrAg.EngDT = dt.u0p16;
dMotAg0MeasMotAg0SpiCntrAg.EngMin = 0;
dMotAg0MeasMotAg0SpiCntrAg.EngMax = 0.9999847412;
dMotAg0MeasMotAg0SpiCntrAg.InitRowCol = [1  1];


dMotAg0MeasMotAg0SpiMecl = DataDict.Display;
dMotAg0MeasMotAg0SpiMecl.LongName = 'Motor Angle 0 Serial Peripheral Interface Mechanical';
dMotAg0MeasMotAg0SpiMecl.Description = [...
  'Display variable of Motor Angle 0 SPI Angle calculated from Angle Regi' ...
  'ster'];
dMotAg0MeasMotAg0SpiMecl.DocUnits = 'Cnt';
dMotAg0MeasMotAg0SpiMecl.EngDT = dt.u0p16;
dMotAg0MeasMotAg0SpiMecl.EngMin = 0;
dMotAg0MeasMotAg0SpiMecl.EngMax = 0.9999847412;
dMotAg0MeasMotAg0SpiMecl.InitRowCol = [1  1];


dMotAg0MeasMotAg0TurnCntr = DataDict.Display;
dMotAg0MeasMotAg0TurnCntr.LongName = 'Motor Angle 0 Turn Counter';
dMotAg0MeasMotAg0TurnCntr.Description = [...
  'Display variable Motor Angle 0 Turn Counter Value'];
dMotAg0MeasMotAg0TurnCntr.DocUnits = 'Cnt';
dMotAg0MeasMotAg0TurnCntr.EngDT = dt.float32;
dMotAg0MeasMotAg0TurnCntr.EngMin = -92160;
dMotAg0MeasMotAg0TurnCntr.EngMax = 92160;
dMotAg0MeasMotAg0TurnCntr.InitRowCol = [1  1];


dMotAg0MeasMotCtrlMotAg3Mecl = DataDict.Display;
dMotAg0MeasMotCtrlMotAg3Mecl.LongName = 'Motor Control Motor Angle 3 Mecahnical';
dMotAg0MeasMotCtrlMotAg3Mecl.Description = [...
  'Display variable of Motor Angle 3 run in Motor Control in mechanical u' ...
  'nits'];
dMotAg0MeasMotCtrlMotAg3Mecl.DocUnits = 'Cnt';
dMotAg0MeasMotCtrlMotAg3Mecl.EngDT = dt.u0p16;
dMotAg0MeasMotCtrlMotAg3Mecl.EngMin = 0;
dMotAg0MeasMotCtrlMotAg3Mecl.EngMax = 0.9999847412;
dMotAg0MeasMotCtrlMotAg3Mecl.InitRowCol = [1  1];



%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------
MotAg0CorrnTbl = DataDict.PIM;
MotAg0CorrnTbl.LongName = 'Motor Angle 0 Correction Table';
MotAg0CorrnTbl.Description = [...
  'Correction table for Motor Angle 0.'];
MotAg0CorrnTbl.DocUnits = 'MotRev';
MotAg0CorrnTbl.EngDT = dt.sm5p12;
MotAg0CorrnTbl.EngMin = -0.03100585937;
MotAg0CorrnTbl.EngMax = 0.03100585937;
MotAg0CorrnTbl.InitRowCol = [128    1];


MotAg0Diagc = DataDict.PIM;
MotAg0Diagc.LongName = 'Motor Angle 0 Diagnostic';
MotAg0Diagc.Description = [...
  'Motor Angle 0 Mechanical used for diagnostics'];
MotAg0Diagc.DocUnits = 'MotRev';
MotAg0Diagc.EngDT = dt.u0p16;
MotAg0Diagc.EngMin = 0;
MotAg0Diagc.EngMax = 0.9999847412;
MotAg0Diagc.InitRowCol = [1  1];


MotAg0InitOffs = DataDict.PIM;
MotAg0InitOffs.LongName = 'Motor Angle 0 Initial Offset';
MotAg0InitOffs.Description = [...
  'Initializing Motor Angle 0 Offset calculation'];
MotAg0InitOffs.DocUnits = 'Cnt';
MotAg0InitOffs.EngDT = dt.u08;
MotAg0InitOffs.EngMin = 0;
MotAg0InitOffs.EngMax = 255;
MotAg0InitOffs.InitRowCol = [1  1];


MotAg0PrevOffs = DataDict.PIM;
MotAg0PrevOffs.LongName = 'Motor Angle 0 Previous Offset';
MotAg0PrevOffs.Description = 'Last known Offeset value';
MotAg0PrevOffs.DocUnits = 'Cnt';
MotAg0PrevOffs.EngDT = dt.s32;
MotAg0PrevOffs.EngMin = -2147483648;
MotAg0PrevOffs.EngMax = 2147483647;
MotAg0PrevOffs.InitRowCol = [1  1];


MotAg0PrevRollgCntr = DataDict.PIM;
MotAg0PrevRollgCntr.LongName = 'Motor Angle 0 Previous Rolling Counter';
MotAg0PrevRollgCntr.Description = 'Previous value of rolling counter';
MotAg0PrevRollgCntr.DocUnits = 'Cnt';
MotAg0PrevRollgCntr.EngDT = dt.u08;
MotAg0PrevRollgCntr.EngMin = 0;
MotAg0PrevRollgCntr.EngMax = 255;
MotAg0PrevRollgCntr.InitRowCol = [1  1];


MotAg0PrevSpiErrFltCntr = DataDict.PIM;
MotAg0PrevSpiErrFltCntr.LongName = 'Motor Angle 0 Spi Error Previous Fault Counter';
MotAg0PrevSpiErrFltCntr.Description = [...
  'Motor Angle 0 Spi Error Previous Fault Counter Value'];
MotAg0PrevSpiErrFltCntr.DocUnits = 'Cnt';
MotAg0PrevSpiErrFltCntr.EngDT = dt.u16;
MotAg0PrevSpiErrFltCntr.EngMin = 0;
MotAg0PrevSpiErrFltCntr.EngMax = 65535;
MotAg0PrevSpiErrFltCntr.InitRowCol = [1  1];



%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
ARCHGLBPRM_2PI_ULS_F32 = DataDict.Constant;
ARCHGLBPRM_2PI_ULS_F32.LongName = 'Two Times Pi';
ARCHGLBPRM_2PI_ULS_F32.Description = '2 times the value of Pi';
ARCHGLBPRM_2PI_ULS_F32.DocUnits = 'Uls';
ARCHGLBPRM_2PI_ULS_F32.EngDT = dt.float32;
ARCHGLBPRM_2PI_ULS_F32.EngVal = 6.2831853;
ARCHGLBPRM_2PI_ULS_F32.Define = 'Global';


COEFFTBLELMSIZE_CNT_U08 = DataDict.Constant;
COEFFTBLELMSIZE_CNT_U08.LongName = 'Coeffecient Table Element Size';
COEFFTBLELMSIZE_CNT_U08.Description = [...
  'Number of elements in a coefficient row'];
COEFFTBLELMSIZE_CNT_U08.DocUnits = 'Cnt';
COEFFTBLELMSIZE_CNT_U08.EngDT = dt.u08;
COEFFTBLELMSIZE_CNT_U08.EngVal = 2;
COEFFTBLELMSIZE_CNT_U08.Define = 'Local';


COEFFTBLSIZE_CNT_U08 = DataDict.Constant;
COEFFTBLSIZE_CNT_U08.LongName = 'Coefficient Table Size';
COEFFTBLSIZE_CNT_U08.Description = [...
  'Number of rows in the coefficient table'];
COEFFTBLSIZE_CNT_U08.DocUnits = 'Cnt';
COEFFTBLSIZE_CNT_U08.EngDT = dt.u08;
COEFFTBLSIZE_CNT_U08.EngVal = 13;
COEFFTBLSIZE_CNT_U08.Define = 'Local';


CORRNTBLAGSTEPSIZE_MATRAD_F32 = DataDict.Constant;
CORRNTBLAGSTEPSIZE_MATRAD_F32.LongName = 'Correction Table Angle Step Size';
CORRNTBLAGSTEPSIZE_MATRAD_F32.Description = [...
  'Correction Table Angle Step Size.  .EngVal = 2 * pi / CORRNTBLSIZE_CNT' ...
  '_U16 '];
CORRNTBLAGSTEPSIZE_MATRAD_F32.DocUnits = 'MatRad';
CORRNTBLAGSTEPSIZE_MATRAD_F32.EngDT = dt.float32;
CORRNTBLAGSTEPSIZE_MATRAD_F32.EngVal = 0.04908738521;
CORRNTBLAGSTEPSIZE_MATRAD_F32.Define = 'Local';


CORRNTBLSIDXOFFS_CNT_U16 = DataDict.Constant;
CORRNTBLSIDXOFFS_CNT_U16.LongName = 'Correction Table Index Offset';
CORRNTBLSIDXOFFS_CNT_U16.Description = 'Correction Table Index Offset';
CORRNTBLSIDXOFFS_CNT_U16.DocUnits = 'Cnt';
CORRNTBLSIDXOFFS_CNT_U16.EngDT = dt.u16;
CORRNTBLSIDXOFFS_CNT_U16.EngVal = 7;
CORRNTBLSIDXOFFS_CNT_U16.Define = 'Local';


CORRNTBLSIZEMASK_CNT_U08 = DataDict.Constant;
CORRNTBLSIZEMASK_CNT_U08.LongName = 'Correction Table Size Mask';
CORRNTBLSIZEMASK_CNT_U08.Description = [...
  'Mask used to prevent indexing out of range'];
CORRNTBLSIZEMASK_CNT_U08.DocUnits = 'Cnt';
CORRNTBLSIZEMASK_CNT_U08.EngDT = dt.u08;
CORRNTBLSIZEMASK_CNT_U08.EngVal = 127;
CORRNTBLSIZEMASK_CNT_U08.Define = 'Local';


CORRNTBLSIZE_CNT_U16 = DataDict.Constant;
CORRNTBLSIZE_CNT_U16.LongName = 'Motor Angle 0 Correction Table Size';
CORRNTBLSIZE_CNT_U16.Description = [...
  'Motor Angle 0 Correction Table Size'];
CORRNTBLSIZE_CNT_U16.DocUnits = 'Cnt';
CORRNTBLSIZE_CNT_U16.EngDT = dt.u16;
CORRNTBLSIZE_CNT_U16.EngVal = 128;
CORRNTBLSIZE_CNT_U16.Define = 'Local';


MOTAG0ERRTHD_MOTREV_U0P16 = DataDict.Constant;
MOTAG0ERRTHD_MOTREV_U0P16.LongName = 'Motor Angle 0 Error Threshold';
MOTAG0ERRTHD_MOTREV_U0P16.Description = [...
  'Error threshold between Motor Angle 0 (SPI) and Motor Angle 3 (ENCA):8' ...
  '0 degrees Elec'];
MOTAG0ERRTHD_MOTREV_U0P16.DocUnits = 'MotRev';
MOTAG0ERRTHD_MOTREV_U0P16.EngDT = dt.u0p16;
MOTAG0ERRTHD_MOTREV_U0P16.EngVal = 0.055;
MOTAG0ERRTHD_MOTREV_U0P16.Define = 'Local';


MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM = DataDict.ConfigParam;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.LongName = 'Motor Angle 0 Protocol Fault NTC Number';
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.Description = [...
  'Motor Angle 0 Protocol Fault NTC Number'];
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.IsBuildPrm = false;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.DocUnits = 'Cnt';
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X083;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.EngMin = NtcNr1.NTCNR_0X083;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.EngMax = NtcNr1.NTCNR_0X08A;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.Define = 'Global';


MOTAG0PRTCLFLTFAILSTEP_CNT_U16 = DataDict.Constant;
MOTAG0PRTCLFLTFAILSTEP_CNT_U16.LongName = 'Motor Angle 0 Protocol Fault Fail Step';
MOTAG0PRTCLFLTFAILSTEP_CNT_U16.Description = [...
  'Debounce Fail Step for motor angle o Diagnostic'];
MOTAG0PRTCLFLTFAILSTEP_CNT_U16.DocUnits = 'Cnt';
MOTAG0PRTCLFLTFAILSTEP_CNT_U16.EngDT = dt.u16;
MOTAG0PRTCLFLTFAILSTEP_CNT_U16.EngVal = 3276;
MOTAG0PRTCLFLTFAILSTEP_CNT_U16.Define = 'Local';


MOTAG0PRTCLFLTPASSSTEP_CNT_U16 = DataDict.Constant;
MOTAG0PRTCLFLTPASSSTEP_CNT_U16.LongName = 'Motor Angle 0 Protocol Faul Pass Step';
MOTAG0PRTCLFLTPASSSTEP_CNT_U16.Description = [...
  'Debounce Pass Step for Motor Angle 0 Diagnostic'];
MOTAG0PRTCLFLTPASSSTEP_CNT_U16.DocUnits = 'Cnt';
MOTAG0PRTCLFLTPASSSTEP_CNT_U16.EngDT = dt.u16;
MOTAG0PRTCLFLTPASSSTEP_CNT_U16.EngVal = 655;
MOTAG0PRTCLFLTPASSSTEP_CNT_U16.Define = 'Local';


MOTAGCPTLIMFLTMASK_CNT_U32 = DataDict.Constant;
MOTAGCPTLIMFLTMASK_CNT_U32.LongName = 'Motor Angle Component Limit Fault Mask';
MOTAGCPTLIMFLTMASK_CNT_U32.Description = [...
  'Mask for X Y (Sin Cos) components out of limit check'];
MOTAGCPTLIMFLTMASK_CNT_U32.DocUnits = 'Cnt';
MOTAGCPTLIMFLTMASK_CNT_U32.EngDT = dt.u32;
MOTAGCPTLIMFLTMASK_CNT_U32.EngVal = 64;
MOTAGCPTLIMFLTMASK_CNT_U32.Define = 'Local';


MOTAGDELTAPERCORRNPT_CNT_U16 = DataDict.Constant;
MOTAGDELTAPERCORRNPT_CNT_U16.LongName = 'Motor Angle Delta per Correction Point';
MOTAGDELTAPERCORRNPT_CNT_U16.Description = [...
  'Amount of motor angle movement covered by 1 correction point table ent' ...
  'ry.  Number is based on a correction table size of 128 & p16 motor ang' ...
  'le: 65536/128 = 512'];
MOTAGDELTAPERCORRNPT_CNT_U16.DocUnits = 'Cnt';
MOTAGDELTAPERCORRNPT_CNT_U16.EngDT = dt.u16;
MOTAGDELTAPERCORRNPT_CNT_U16.EngVal = 512;
MOTAGDELTAPERCORRNPT_CNT_U16.Define = 'Local';


MOTAGFLTMASK_CNT_U32 = DataDict.Constant;
MOTAGFLTMASK_CNT_U32.LongName = 'Motor Angle Fault Mask';
MOTAGFLTMASK_CNT_U32.Description = [...
  'Mask for detecting motor angle faults'];
MOTAGFLTMASK_CNT_U32.DocUnits = 'Cnt';
MOTAGFLTMASK_CNT_U32.EngDT = dt.u32;
MOTAGFLTMASK_CNT_U32.EngVal = 6372;
MOTAGFLTMASK_CNT_U32.Define = 'Local';


MOTAGIDXMASK_CNT_U16 = DataDict.Constant;
MOTAGIDXMASK_CNT_U16.LongName = 'Motor Angle Index Mask';
MOTAGIDXMASK_CNT_U16.Description = [...
  'Mask used to round down motor angle to the nearest table index point. ' ...
  'MOTAGIDXMASK.EngVal = 65536 - 512'];
MOTAGIDXMASK_CNT_U16.DocUnits = 'Cnt';
MOTAGIDXMASK_CNT_U16.EngDT = dt.u16;
MOTAGIDXMASK_CNT_U16.EngVal = 65024;
MOTAGIDXMASK_CNT_U16.Define = 'Local';


MOTAGLIMMASK_CNT_S32 = DataDict.Constant;
MOTAGLIMMASK_CNT_S32.LongName = 'Motor Angle Limit Mask';
MOTAGLIMMASK_CNT_S32.Description = [...
  'Mask to limit Motor Angle to 16-bit value'];
MOTAGLIMMASK_CNT_S32.DocUnits = 'Cnt';
MOTAGLIMMASK_CNT_S32.EngDT = dt.s32;
MOTAGLIMMASK_CNT_S32.EngVal = 65535;
MOTAGLIMMASK_CNT_S32.Define = 'Local';


MOTAGMGNLIMFLTMASK_CNT_U32 = DataDict.Constant;
MOTAGMGNLIMFLTMASK_CNT_U32.LongName = 'Motor Angle Magnitude Limit Fault Mask';
MOTAGMGNLIMFLTMASK_CNT_U32.Description = [...
  'Mask motor angle magnitude out of limit fault check'];
MOTAGMGNLIMFLTMASK_CNT_U32.DocUnits = 'Cnt';
MOTAGMGNLIMFLTMASK_CNT_U32.EngDT = dt.u32;
MOTAGMGNLIMFLTMASK_CNT_U32.EngVal = 128;
MOTAGMGNLIMFLTMASK_CNT_U32.Define = 'Local';


MOTAGMINWAITPERD_CNT_U32 = DataDict.Constant;
MOTAGMINWAITPERD_CNT_U32.LongName = 'Motor Angle Minimum Wait Period';
MOTAGMINWAITPERD_CNT_U32.Description = [...
  'Minimum wait time to synchronize the SPI and ENCA Values'];
MOTAGMINWAITPERD_CNT_U32.DocUnits = 'Cnt';
MOTAGMINWAITPERD_CNT_U32.EngDT = dt.u32;
MOTAGMINWAITPERD_CNT_U32.EngVal = 2;
MOTAGMINWAITPERD_CNT_U32.Define = 'Local';


MOTAGOFFS_CNT_S32 = DataDict.Constant;
MOTAGOFFS_CNT_S32.LongName = 'Motor Angle Offset';
MOTAGOFFS_CNT_S32.Description = [...
  'Offset used to convert incoming motor angle as unsigned number into a ' ...
  'signed number'];
MOTAGOFFS_CNT_S32.DocUnits = 'Cnt';
MOTAGOFFS_CNT_S32.EngDT = dt.s32;
MOTAGOFFS_CNT_S32.EngVal = 32768;
MOTAGOFFS_CNT_S32.Define = 'Local';


MOTAGOVFFLTMASK_CNT_U32 = DataDict.Constant;
MOTAGOVFFLTMASK_CNT_U32.LongName = 'Motor Angle Overflow Fault Mask';
MOTAGOVFFLTMASK_CNT_U32.Description = 'Mask for overflow check';
MOTAGOVFFLTMASK_CNT_U32.DocUnits = 'Cnt';
MOTAGOVFFLTMASK_CNT_U32.EngDT = dt.u32;
MOTAGOVFFLTMASK_CNT_U32.EngVal = 32;
MOTAGOVFFLTMASK_CNT_U32.Define = 'Local';


MOTAGSPITRSMMASK_CNT_U32 = DataDict.Constant;
MOTAGSPITRSMMASK_CNT_U32.LongName = 'Motor Angle Fault Mask';
MOTAGSPITRSMMASK_CNT_U32.Description = [...
  'Mask for detecting motor angle faults'];
MOTAGSPITRSMMASK_CNT_U32.DocUnits = 'Cnt';
MOTAGSPITRSMMASK_CNT_U32.EngDT = dt.u32;
MOTAGSPITRSMMASK_CNT_U32.EngVal = 128;
MOTAGSPITRSMMASK_CNT_U32.Define = 'Local';


MOTAGVLTGFLTMASK_CNT_U32 = DataDict.Constant;
MOTAGVLTGFLTMASK_CNT_U32.LongName = 'Motor Angle Voltage Fault Mask';
MOTAGVLTGFLTMASK_CNT_U32.Description = 'Mask for voltage fault check';
MOTAGVLTGFLTMASK_CNT_U32.DocUnits = 'Cnt';
MOTAGVLTGFLTMASK_CNT_U32.EngDT = dt.u32;
MOTAGVLTGFLTMASK_CNT_U32.EngVal = 4;
MOTAGVLTGFLTMASK_CNT_U32.Define = 'Local';


NOMOTAGFLTMASK_CNT_U32 = DataDict.Constant;
NOMOTAGFLTMASK_CNT_U32.LongName = 'No Motor Angle Fault Mask';
NOMOTAGFLTMASK_CNT_U32.Description = [...
  'Mask for detecting whether motor angle is avaliable from the sensor or' ...
  ' not'];
NOMOTAGFLTMASK_CNT_U32.DocUnits = 'Cnt';
NOMOTAGFLTMASK_CNT_U32.EngDT = dt.u32;
NOMOTAGFLTMASK_CNT_U32.EngVal = 4096;
NOMOTAGFLTMASK_CNT_U32.Define = 'Local';


READBUFADR_CNT_U32 = DataDict.Constant;
READBUFADR_CNT_U32.LongName = 'Read Buffer Address';
READBUFADR_CNT_U32.Description = 'Read Data (Rx) Buffer Address';
READBUFADR_CNT_U32.DocUnits = 'Cnt';
READBUFADR_CNT_U32.EngDT = dt.u32;
READBUFADR_CNT_U32.EngVal = 589824;
READBUFADR_CNT_U32.Define = 'Local';


READBUFIDX_CNT_U08 = DataDict.Constant;
READBUFIDX_CNT_U08.LongName = 'Read Buffer Index';
READBUFIDX_CNT_U08.Description = 'Read Buffer Index';
READBUFIDX_CNT_U08.DocUnits = 'Cnt';
READBUFIDX_CNT_U08.EngDT = dt.u08;
READBUFIDX_CNT_U08.EngVal = 10;
READBUFIDX_CNT_U08.Define = 'Local';


SNSRAGMASK_CNT_U32 = DataDict.Constant;
SNSRAGMASK_CNT_U32.LongName = 'Sensor Angle Mask';
SNSRAGMASK_CNT_U32.Description = 'Mask for sensor angle';
SNSRAGMASK_CNT_U32.DocUnits = 'Cnt';
SNSRAGMASK_CNT_U32.EngDT = dt.u32;
SNSRAGMASK_CNT_U32.EngVal = 32767;
SNSRAGMASK_CNT_U32.Define = 'Local';


SNSRCNTMASK_CNT_U32 = DataDict.Constant;
SNSRCNTMASK_CNT_U32.LongName = 'Sensor Count Mask';
SNSRCNTMASK_CNT_U32.Description = 'Mask for Sensor IIF counts';
SNSRCNTMASK_CNT_U32.DocUnits = 'Cnt';
SNSRCNTMASK_CNT_U32.EngDT = dt.u32;
SNSRCNTMASK_CNT_U32.EngVal = 16383;
SNSRCNTMASK_CNT_U32.Define = 'Local';


SPIAGCNTREGIDX_CNT_U08 = DataDict.Constant;
SPIAGCNTREGIDX_CNT_U08.LongName = 'Serial Peripheral Interface Angle Count Register Index';
SPIAGCNTREGIDX_CNT_U08.Description = [...
  'Serial Peripheral Interface Angle Count Index'];
SPIAGCNTREGIDX_CNT_U08.DocUnits = 'Cnt';
SPIAGCNTREGIDX_CNT_U08.EngDT = dt.u08;
SPIAGCNTREGIDX_CNT_U08.EngVal = 9;
SPIAGCNTREGIDX_CNT_U08.Define = 'Local';


SPIAGREGIDX_CNT_U08 = DataDict.Constant;
SPIAGREGIDX_CNT_U08.LongName = 'Serial Peripheral Interface Angle Register Index';
SPIAGREGIDX_CNT_U08.Description = [...
  'Serial Peripheral Interface Angle Index'];
SPIAGREGIDX_CNT_U08.DocUnits = 'Cnt';
SPIAGREGIDX_CNT_U08.EngDT = dt.u08;
SPIAGREGIDX_CNT_U08.EngVal = 3;
SPIAGREGIDX_CNT_U08.Define = 'Local';


SPISTATREGIDX_CNT_U08 = DataDict.Constant;
SPISTATREGIDX_CNT_U08.LongName = 'Serial Peripheral Interface Status Register Index';
SPISTATREGIDX_CNT_U08.Description = [...
  'Serial Peripheral Interface Status Register Index'];
SPISTATREGIDX_CNT_U08.DocUnits = 'Cnt';
SPISTATREGIDX_CNT_U08.EngDT = dt.u08;
SPISTATREGIDX_CNT_U08.EngVal = 0;
SPISTATREGIDX_CNT_U08.Define = 'Local';


SPITURNCNTRREGIDX_CNT_U08 = DataDict.Constant;
SPITURNCNTRREGIDX_CNT_U08.LongName = 'Serial Peripheral Interface Turns Counter Register Index';
SPITURNCNTRREGIDX_CNT_U08.Description = [...
  'Serial Peripheral Interface Turns Counter Register Index'];
SPITURNCNTRREGIDX_CNT_U08.DocUnits = 'Cnt';
SPITURNCNTRREGIDX_CNT_U08.EngDT = dt.u08;
SPITURNCNTRREGIDX_CNT_U08.EngVal = 6;
SPITURNCNTRREGIDX_CNT_U08.Define = 'Local';


STRTPTRINITVAL_CNT_U32 = DataDict.Constant;
STRTPTRINITVAL_CNT_U32.LongName = 'Start Pointer Initial Value';
STRTPTRINITVAL_CNT_U32.Description = [...
  'Start pointer and No. of data value for inital Spi Transmission'];
STRTPTRINITVAL_CNT_U32.DocUnits = 'Cnt';
STRTPTRINITVAL_CNT_U32.EngDT = dt.u32;
STRTPTRINITVAL_CNT_U32.EngVal = 2148007936;
STRTPTRINITVAL_CNT_U32.Define = 'Local';


STRTPTRPERVAL_CNT_U32 = DataDict.Constant;
STRTPTRPERVAL_CNT_U32.LongName = 'Start Pointer Periodic Value';
STRTPTRPERVAL_CNT_U32.Description = [...
  'Start pointer and No. of data value for Periodic Spi Transmission'];
STRTPTRPERVAL_CNT_U32.DocUnits = 'Cnt';
STRTPTRPERVAL_CNT_U32.EngDT = dt.u32;
STRTPTRPERVAL_CNT_U32.EngVal = 2148270088;
STRTPTRPERVAL_CNT_U32.Define = 'Local';


TURNCNTRHALFOFFS_CNT_S16 = DataDict.Constant;
TURNCNTRHALFOFFS_CNT_S16.LongName = 'Turn Counter Half Offset';
TURNCNTRHALFOFFS_CNT_S16.Description = [...
  'Half offset used to convert incoming turn counter as unsigned number i' ...
  'nto a signed number'];
TURNCNTRHALFOFFS_CNT_S16.DocUnits = 'Cnt';
TURNCNTRHALFOFFS_CNT_S16.EngDT = dt.s16;
TURNCNTRHALFOFFS_CNT_S16.EngVal = 256;
TURNCNTRHALFOFFS_CNT_S16.Define = 'Local';


TURNCNTROFFS_CNT_S16 = DataDict.Constant;
TURNCNTROFFS_CNT_S16.LongName = 'Turn Counter Offset';
TURNCNTROFFS_CNT_S16.Description = [...
  'Offset used to convert incoming turn counter as unsigned number into a' ...
  ' signed number'];
TURNCNTROFFS_CNT_S16.DocUnits = 'Cnt';
TURNCNTROFFS_CNT_S16.EngDT = dt.s16;
TURNCNTROFFS_CNT_S16.EngVal = 512;
TURNCNTROFFS_CNT_S16.Define = 'Local';


TURNCNTRREGMASK_CNT_U32 = DataDict.Constant;
TURNCNTRREGMASK_CNT_U32.LongName = 'Turns Counter Register Mask';
TURNCNTRREGMASK_CNT_U32.Description = [...
  'Mask to find Motor Angle 0 Turn Counter'];
TURNCNTRREGMASK_CNT_U32.DocUnits = 'Cnt';
TURNCNTRREGMASK_CNT_U32.EngDT = dt.u32;
TURNCNTRREGMASK_CNT_U32.EngVal = 511;
TURNCNTRREGMASK_CNT_U32.Define = 'Local';


VLDMOTAGFLTMASK_CNT_U32 = DataDict.Constant;
VLDMOTAGFLTMASK_CNT_U32.LongName = 'Valid Motor Angle Fault Mask';
VLDMOTAGFLTMASK_CNT_U32.Description = [...
  'Mask for Motor Angles validity check'];
VLDMOTAGFLTMASK_CNT_U32.DocUnits = 'Cnt';
VLDMOTAGFLTMASK_CNT_U32.EngDT = dt.u32;
VLDMOTAGFLTMASK_CNT_U32.EngVal = 2048;
VLDMOTAGFLTMASK_CNT_U32.Define = 'Local';



%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
MotAg0PrtclFlt = DataDict.NTC;
MotAg0PrtclFlt.NtcNr = 'MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM';
MotAg0PrtclFlt.NtcTyp = 'Deb';
MotAg0PrtclFlt.LongName = 'Motor Angle 0 Protocol Fault';
MotAg0PrtclFlt.Description = 'Motor Angle 0 Protocol Fault.  MotAg0PrtclFlt.NtcNr = MOTAG0PRTCLFLTNTCNR_CNT_ENUM;';
MotAg0PrtclFlt.NtcStInfo = DataDict.NtcStInfoBitPacked;
MotAg0PrtclFlt.NtcStInfo.Bit0Descr = 'Invalid Motor Angle';
MotAg0PrtclFlt.NtcStInfo.Bit1Descr = 'Invalid Sin Cos Components';
MotAg0PrtclFlt.NtcStInfo.Bit2Descr = 'Magnetic Loss';
MotAg0PrtclFlt.NtcStInfo.Bit3Descr = 'Sin Cos Out of Limit Error';
MotAg0PrtclFlt.NtcStInfo.Bit4Descr = 'Overflow Error';
MotAg0PrtclFlt.NtcStInfo.Bit5Descr = 'Voltage Fault';
MotAg0PrtclFlt.NtcStInfo.Bit6Descr = 'IIF-ENCA vs SPI Angle Error';
MotAg0PrtclFlt.NtcStInfo.Bit7Descr = 'Unused';


%end of Data Dictionary
