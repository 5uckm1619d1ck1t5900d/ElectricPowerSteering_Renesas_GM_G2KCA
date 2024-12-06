%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 21-Dec-2016 11:38:30       %
%                                  Created with tool release: 2.51.0     %
%                                  Synergy file: %version: 6 %           %
%                                  Derived by: %derived_by: tz8cy0 %          %
%%-----------------------------------------------------------------------%

CM640C = DataDict.FDD;
CM640C.Version = '1.5.X';
CM640C.LongName = 'Motor Angle 1 Measurement';
CM640C.ShoName  = 'MotAg1Meas';
CM640C.DesignASIL = 'D';
CM640C.Description = [...
  'Measurement function of Motor Angle 1.  This function includes configu' ...
  'ration and use of the CSIH3 peripheral'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
MotAg1MeasInit1 = DataDict.Runnable;
MotAg1MeasInit1.Context = 'Rte';
MotAg1MeasInit1.TimeStep = 0;
MotAg1MeasInit1.Description = [...
  'Intial Function for Motor Angle 1 Measurement'];

MotAg1MeasPer1 = DataDict.Runnable;
MotAg1MeasPer1.Context = 'NonRte';
MotAg1MeasPer1.TimeStep = 'MotorControl';
MotAg1MeasPer1.Description = [...
  'Periodic 1 for Motor Angle 1 Measurement'];

MotAg1MeasPer2 = DataDict.Runnable;
MotAg1MeasPer2.Context = 'Rte';
MotAg1MeasPer2.TimeStep = 0.002;
MotAg1MeasPer2.Description = [...
  'Periodic 2 for Motor Angle 1 Measurement'];

MotAg1MeasPer3 = DataDict.Runnable;
MotAg1MeasPer3.Context = 'Rte';
MotAg1MeasPer3.TimeStep = 0.002;
MotAg1MeasPer3.Description = [...
  'Periodic 3 for Motor Angle 1 Measurement'];

MotAg1CoeffTblRead = DataDict.SrvRunnable;
MotAg1CoeffTblRead.Context = 'Rte';
MotAg1CoeffTblRead.Description = [...
  'used to get the data from motor angle 1 coefficient table'];
MotAg1CoeffTblRead.Return = DataDict.CSReturn;
MotAg1CoeffTblRead.Return.Type = 'None';
MotAg1CoeffTblRead.Return.Min = [];
MotAg1CoeffTblRead.Return.Max = [];
MotAg1CoeffTblRead.Return.TestTolerance = [];
MotAg1CoeffTblRead.Arguments(1) = DataDict.CSArguments;
MotAg1CoeffTblRead.Arguments(1).Name = 'MotAgCoeffTbl';
MotAg1CoeffTblRead.Arguments(1).EngDT = dt.float32;
MotAg1CoeffTblRead.Arguments(1).EngMin = -0.03100585937;
MotAg1CoeffTblRead.Arguments(1).EngMax = 0.03100585937;
MotAg1CoeffTblRead.Arguments(1).TestTolerance = 0;
MotAg1CoeffTblRead.Arguments(1).Units = 'Uls';
MotAg1CoeffTblRead.Arguments(1).Direction = 'Out';
MotAg1CoeffTblRead.Arguments(1).InitRowCol = [26   1];
MotAg1CoeffTblRead.Arguments(1).Description = 'Table index';

MotAg1CoeffTblWr = DataDict.SrvRunnable;
MotAg1CoeffTblWr.Context = 'Rte';
MotAg1CoeffTblWr.Description = [...
  'used to write the data to motor angle 1 coefficient table'];
MotAg1CoeffTblWr.Return = DataDict.CSReturn;
MotAg1CoeffTblWr.Return.Type = 'None';
MotAg1CoeffTblWr.Return.Min = [];
MotAg1CoeffTblWr.Return.Max = [];
MotAg1CoeffTblWr.Return.TestTolerance = [];
MotAg1CoeffTblWr.Arguments(1) = DataDict.CSArguments;
MotAg1CoeffTblWr.Arguments(1).Name = 'MotAgCoeffTbl';
MotAg1CoeffTblWr.Arguments(1).EngDT = dt.float32;
MotAg1CoeffTblWr.Arguments(1).EngMin = -0.03100585937;
MotAg1CoeffTblWr.Arguments(1).EngMax = 0.03100585937;
MotAg1CoeffTblWr.Arguments(1).Units = 'Uls';
MotAg1CoeffTblWr.Arguments(1).Direction = 'In';
MotAg1CoeffTblWr.Arguments(1).InitRowCol = [26   1];
MotAg1CoeffTblWr.Arguments(1).Description = 'coefficient table index';


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------
GetMotAg4Mecl = DataDict.Client;
GetMotAg4Mecl.CallLocation = {'MotAg1MeasPer1','MotAg1MeasPer3'};
GetMotAg4Mecl.Description = [...
  'client server to get Motor Angle 4 in mechanical units'];
GetMotAg4Mecl.Return = DataDict.CSReturn;
GetMotAg4Mecl.Return.Type = 'Standard';
GetMotAg4Mecl.Return.Min = 0;
GetMotAg4Mecl.Return.Max = 1;
GetMotAg4Mecl.Return.TestTolerance = [];
GetMotAg4Mecl.Return.Description = 'Return to get Motor Angle 4';
GetMotAg4Mecl.Arguments(1) = DataDict.CSArguments;
GetMotAg4Mecl.Arguments(1).Name = 'MotAgMecl';
GetMotAg4Mecl.Arguments(1).EngDT = dt.u0p16;
GetMotAg4Mecl.Arguments(1).EngMin = 0;
GetMotAg4Mecl.Arguments(1).EngMax = 0.9999847412;
GetMotAg4Mecl.Arguments(1).TestTolerance = 1.525878906e-05;
GetMotAg4Mecl.Arguments(1).Units = 'MotRev';
GetMotAg4Mecl.Arguments(1).Direction = 'Out';
GetMotAg4Mecl.Arguments(1).InitRowCol = [1  1];
GetMotAg4Mecl.Arguments(1).Description = [...
  'Motor Angle 4 value in mechanical units'];


GetNtcQlfrSts = DataDict.Client;
GetNtcQlfrSts.CallLocation = {'MotAg1MeasPer2'};
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
GetRefTmr1MicroSec32bit.CallLocation = {'MotAg1MeasPer3'};
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
GetRefTmr1MicroSec32bit.Arguments(1).Description = 'Reference Timer';


GetTiSpan1MicroSec32bit = DataDict.Client;
GetTiSpan1MicroSec32bit.CallLocation = {'MotAg1MeasPer3'};
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


IoHwAb_SetFctGpioMotAg1 = DataDict.Client;
IoHwAb_SetFctGpioMotAg1.CallLocation = {'MotAg1MeasPer3'};
IoHwAb_SetFctGpioMotAg1.Description = 'Set GPIO mode';
IoHwAb_SetFctGpioMotAg1.Return = DataDict.CSReturn;
IoHwAb_SetFctGpioMotAg1.Return.Type = 'Standard';
IoHwAb_SetFctGpioMotAg1.Return.Min = 0;
IoHwAb_SetFctGpioMotAg1.Return.Max = 1;
IoHwAb_SetFctGpioMotAg1.Return.TestTolerance = [];
IoHwAb_SetFctGpioMotAg1.Return.Description = 'Set CSIH to GPIO mode';


IoHwAb_SetFctPrphlCsihMotAg1 = DataDict.Client;
IoHwAb_SetFctPrphlCsihMotAg1.CallLocation = {'MotAg1MeasPer3'};
IoHwAb_SetFctPrphlCsihMotAg1.Description = 'Set peripheral to CSIH mode';
IoHwAb_SetFctPrphlCsihMotAg1.Return = DataDict.CSReturn;
IoHwAb_SetFctPrphlCsihMotAg1.Return.Type = 'Standard';
IoHwAb_SetFctPrphlCsihMotAg1.Return.Min = 0;
IoHwAb_SetFctPrphlCsihMotAg1.Return.Max = 1;
IoHwAb_SetFctPrphlCsihMotAg1.Return.TestTolerance = [];
IoHwAb_SetFctPrphlCsihMotAg1.Return.Description = 'Set to CSIH Peripheral';


IoHwAb_SetGpioMotAg1CsihCs = DataDict.Client;
IoHwAb_SetGpioMotAg1CsihCs.CallLocation = {'MotAg1MeasPer3'};
IoHwAb_SetGpioMotAg1CsihCs.Description = 'Set chip select of CSIH peripheral';
IoHwAb_SetGpioMotAg1CsihCs.Return = DataDict.CSReturn;
IoHwAb_SetGpioMotAg1CsihCs.Return.Type = 'Standard';
IoHwAb_SetGpioMotAg1CsihCs.Return.Min = 0;
IoHwAb_SetGpioMotAg1CsihCs.Return.Max = 1;
IoHwAb_SetGpioMotAg1CsihCs.Return.TestTolerance = [];
IoHwAb_SetGpioMotAg1CsihCs.Return.Description = 'Set CSIH Chip Select Pin';


MotAg1CoeffTbl_GetErrorStatus = DataDict.Client;
MotAg1CoeffTbl_GetErrorStatus.CallLocation = {'MotAg1MeasInit1'};
MotAg1CoeffTbl_GetErrorStatus.Description = [...
  'Client to get motor angle coefficient table error status'];
MotAg1CoeffTbl_GetErrorStatus.Return = DataDict.CSReturn;
MotAg1CoeffTbl_GetErrorStatus.Return.Type = 'Standard';
MotAg1CoeffTbl_GetErrorStatus.Return.Min = 0;
MotAg1CoeffTbl_GetErrorStatus.Return.Max = 1;
MotAg1CoeffTbl_GetErrorStatus.Return.TestTolerance = [];
MotAg1CoeffTbl_GetErrorStatus.Return.Description = 'Return perameters ';
MotAg1CoeffTbl_GetErrorStatus.Arguments(1) = DataDict.CSArguments;
MotAg1CoeffTbl_GetErrorStatus.Arguments(1).Name = 'RequestResultPtr';
MotAg1CoeffTbl_GetErrorStatus.Arguments(1).EngDT = dt.u08;
MotAg1CoeffTbl_GetErrorStatus.Arguments(1).EngMin = 0;
MotAg1CoeffTbl_GetErrorStatus.Arguments(1).EngMax = 255;
MotAg1CoeffTbl_GetErrorStatus.Arguments(1).TestTolerance = 0;
MotAg1CoeffTbl_GetErrorStatus.Arguments(1).Units = 'Cnt';
MotAg1CoeffTbl_GetErrorStatus.Arguments(1).Direction = 'Out';
MotAg1CoeffTbl_GetErrorStatus.Arguments(1).InitRowCol = [1  1];
MotAg1CoeffTbl_GetErrorStatus.Arguments(1).Description = [...
  'Polarity for requested error status result'];


MotAg1CoeffTbl_SetRamBlockStatus = DataDict.Client;
MotAg1CoeffTbl_SetRamBlockStatus.CallLocation = {'MotAg1CoeffTblWr'};
MotAg1CoeffTbl_SetRamBlockStatus.Description = [...
  'Client to set random access memory to motor angle coefficient table'];
MotAg1CoeffTbl_SetRamBlockStatus.Return = DataDict.CSReturn;
MotAg1CoeffTbl_SetRamBlockStatus.Return.Type = 'Standard';
MotAg1CoeffTbl_SetRamBlockStatus.Return.Min = 0;
MotAg1CoeffTbl_SetRamBlockStatus.Return.Max = 1;
MotAg1CoeffTbl_SetRamBlockStatus.Return.TestTolerance = 0;
MotAg1CoeffTbl_SetRamBlockStatus.Return.Description = 'Return perameters';
MotAg1CoeffTbl_SetRamBlockStatus.Arguments(1) = DataDict.CSArguments;
MotAg1CoeffTbl_SetRamBlockStatus.Arguments(1).Name = 'BlockChanged';
MotAg1CoeffTbl_SetRamBlockStatus.Arguments(1).EngDT = dt.lgc;
MotAg1CoeffTbl_SetRamBlockStatus.Arguments(1).EngMin = 0;
MotAg1CoeffTbl_SetRamBlockStatus.Arguments(1).EngMax = 1;
MotAg1CoeffTbl_SetRamBlockStatus.Arguments(1).Units = 'Cnt';
MotAg1CoeffTbl_SetRamBlockStatus.Arguments(1).Direction = 'In';
MotAg1CoeffTbl_SetRamBlockStatus.Arguments(1).InitRowCol = [1  1];
MotAg1CoeffTbl_SetRamBlockStatus.Arguments(1).Description = 'change of the block in the memory';


SetNtcSts = DataDict.Client;
SetNtcSts.CallLocation = {'MotAg1MeasPer2'};
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
MotAgMecl1Polarity = DataDict.IpSignal;
MotAgMecl1Polarity.LongName = 'Motor Angle Mechanical 1 Polarity';
MotAgMecl1Polarity.Description = 'Polarity value of Motor Angle 1';
MotAgMecl1Polarity.DocUnits = 'Uls';
MotAgMecl1Polarity.EngDT = dt.s08;
MotAgMecl1Polarity.EngInit = 1;
MotAgMecl1Polarity.EngMin = -1;
MotAgMecl1Polarity.EngMax = 1;
MotAgMecl1Polarity.ReadIn = {'MotAg1MeasPer2'};
MotAgMecl1Polarity.ReadType = 'Rte';


MotCtrlMotAg1Offs = DataDict.IpSignal;
MotCtrlMotAg1Offs.LongName = 'Motor Control Motor Angle 1 Offset';
MotCtrlMotAg1Offs.Description = [...
  'Motor Angle 1 calculated offset value'];
MotCtrlMotAg1Offs.DocUnits = 'Cnt';
MotCtrlMotAg1Offs.EngDT = dt.s32;
MotCtrlMotAg1Offs.EngInit = 0;
MotCtrlMotAg1Offs.EngMin = -2147483648;
MotCtrlMotAg1Offs.EngMax = 2147483647;
MotCtrlMotAg1Offs.ReadIn = {'MotAg1MeasPer1'};
MotCtrlMotAg1Offs.ReadType = 'NonRte';


RegInpCSIH3STR0 = DataDict.IpSignal;
RegInpCSIH3STR0.LongName = 'Register Input CSIH3STR0';
RegInpCSIH3STR0.Description = 'Register CSIH3STR0 Value';
RegInpCSIH3STR0.DocUnits = 'Cnt';
RegInpCSIH3STR0.EngDT = dt.u32;
RegInpCSIH3STR0.EngInit = 0;
RegInpCSIH3STR0.EngMin = 0;
RegInpCSIH3STR0.EngMax = 4294967295;
RegInpCSIH3STR0.ReadIn = {'MotAg1MeasPer3'};
RegInpCSIH3STR0.ReadType = 'Phy';


RegInptCSIH3RX0W = DataDict.IpSignal;
RegInptCSIH3RX0W.LongName = 'Register Input CSIH3RX0W';
RegInptCSIH3RX0W.Description = 'Register CSIH3RX0W Value';
RegInptCSIH3RX0W.DocUnits = 'Cnt';
RegInptCSIH3RX0W.EngDT = dt.u32;
RegInptCSIH3RX0W.EngInit = 0;
RegInptCSIH3RX0W.EngMin = 0;
RegInptCSIH3RX0W.EngMax = 4294967295;
RegInptCSIH3RX0W.ReadIn = {'MotAg1MeasPer2'};
RegInptCSIH3RX0W.ReadType = 'Phy';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
MotAg1MeclQlfr = DataDict.OpSignal;
MotAg1MeclQlfr.LongName = 'Motor Angle 1 Mechanical Qualifier';
MotAg1MeclQlfr.Description = 'Qualifer output of Motor Angle 1';
MotAg1MeclQlfr.DocUnits = 'Cnt';
MotAg1MeclQlfr.SwcShoName = 'MotAg1Meas';
MotAg1MeclQlfr.EngDT = enum.SigQlfr1;
MotAg1MeclQlfr.EngInit = SigQlfr1.SIGQLFR_NORES;
MotAg1MeclQlfr.EngMin = SigQlfr1.SIGQLFR_NORES;
MotAg1MeclQlfr.EngMax = SigQlfr1.SIGQLFR_FAILD;
MotAg1MeclQlfr.TestTolerance = 0;
MotAg1MeclQlfr.WrittenIn = {'MotAg1MeasPer2'};
MotAg1MeclQlfr.WriteType = 'Rte';


MotAg1MeclRollgCntr = DataDict.OpSignal;
MotAg1MeclRollgCntr.LongName = 'Motor Angle 1 Rolling Counter';
MotAg1MeclRollgCntr.Description = [...
  'Rolling counter of Motor Angle 1, indicating protocol status of angle ' ...
  'measurement.'];
MotAg1MeclRollgCntr.DocUnits = 'Cnt';
MotAg1MeclRollgCntr.SwcShoName = 'MotAg1Meas';
MotAg1MeclRollgCntr.EngDT = dt.u08;
MotAg1MeclRollgCntr.EngInit = 0;
MotAg1MeclRollgCntr.EngMin = 0;
MotAg1MeclRollgCntr.EngMax = 255;
MotAg1MeclRollgCntr.TestTolerance = 0;
MotAg1MeclRollgCntr.WrittenIn = {'MotAg1MeasPer2'};
MotAg1MeclRollgCntr.WriteType = 'Rte';


MotAg1Offs = DataDict.OpSignal;
MotAg1Offs.LongName = 'Motor Angle 1 Offset';
MotAg1Offs.Description = [...
  'Calculated Motor Angle 1 Offset (MotAg4 vs MotAg1)'];
MotAg1Offs.DocUnits = 'Cnt';
MotAg1Offs.SwcShoName = 'MotAg1Meas';
MotAg1Offs.EngDT = dt.s32;
MotAg1Offs.EngInit = 0;
MotAg1Offs.EngMin = -2147483648;
MotAg1Offs.EngMax = 2147483647;
MotAg1Offs.TestTolerance = 0;
MotAg1Offs.WrittenIn = {'MotAg1MeasPer2'};
MotAg1Offs.WriteType = 'Rte';


MotCtrlMotAg1Mecl = DataDict.OpSignal;
MotCtrlMotAg1Mecl.LongName = 'Motor Angle 1 Mechanical';
MotCtrlMotAg1Mecl.Description = [...
  'Motor Control Motor Angle 1 in mechanical units'];
MotCtrlMotAg1Mecl.DocUnits = 'MotRev';
MotCtrlMotAg1Mecl.SwcShoName = 'MotAg1Meas';
MotCtrlMotAg1Mecl.EngDT = dt.u0p16;
MotCtrlMotAg1Mecl.EngInit = 0;
MotCtrlMotAg1Mecl.EngMin = 0;
MotCtrlMotAg1Mecl.EngMax = 0.9999847412;
MotCtrlMotAg1Mecl.TestTolerance = 1.525878906e-05;
MotCtrlMotAg1Mecl.WrittenIn = {'MotAg1MeasPer1'};
MotCtrlMotAg1Mecl.WriteType = 'NonRte';


RegOutpCSIH3MCTL2 = DataDict.OpSignal;
RegOutpCSIH3MCTL2.LongName = 'Register Output CSIH3MCTL2';
RegOutpCSIH3MCTL2.Description = 'CSIH3MCTL2 Register write';
RegOutpCSIH3MCTL2.DocUnits = 'Cnt';
RegOutpCSIH3MCTL2.SwcShoName = 'MotAg1Meas';
RegOutpCSIH3MCTL2.EngDT = dt.u32;
RegOutpCSIH3MCTL2.EngInit = 0;
RegOutpCSIH3MCTL2.EngMin = 0;
RegOutpCSIH3MCTL2.EngMax = 4294967295;
RegOutpCSIH3MCTL2.TestTolerance = 0;
RegOutpCSIH3MCTL2.WrittenIn = {'MotAg1MeasPer3','MotAg1MeasInit1'};
RegOutpCSIH3MCTL2.WriteType = 'Phy';


RegOutpCSIH3MRWP0 = DataDict.OpSignal;
RegOutpCSIH3MRWP0.LongName = 'Register Output CSIH3MRWP0';
RegOutpCSIH3MRWP0.Description = 'CSIH3MRWP0 Register';
RegOutpCSIH3MRWP0.DocUnits = 'Cnt';
RegOutpCSIH3MRWP0.SwcShoName = 'MotAg1Meas';
RegOutpCSIH3MRWP0.EngDT = dt.u32;
RegOutpCSIH3MRWP0.EngInit = 0;
RegOutpCSIH3MRWP0.EngMin = 0;
RegOutpCSIH3MRWP0.EngMax = 4294967295;
RegOutpCSIH3MRWP0.TestTolerance = 0;
RegOutpCSIH3MRWP0.WrittenIn = {'MotAg1MeasPer2'};
RegOutpCSIH3MRWP0.WriteType = 'Phy';



%%-------------------------------------------
%% Inter-Runnable Variable Definition        
%%-------------------------------------------
MotAg1SpiTrsmEna = DataDict.IRV;
MotAg1SpiTrsmEna.LongName = 'Motor Angle 1 Serial Peripheral Interface Transmission Enable';
MotAg1SpiTrsmEna.Description = [...
  'Flag describing Spi transmission is Idle or Communicating'];
MotAg1SpiTrsmEna.DocUnits = 'Cnt';
MotAg1SpiTrsmEna.EngDT = dt.lgc;
MotAg1SpiTrsmEna.EngInit = 0;
MotAg1SpiTrsmEna.EngMin = 0;
MotAg1SpiTrsmEna.EngMax = 1;
MotAg1SpiTrsmEna.ReadIn = {'MotAg1MeasPer2'};
MotAg1SpiTrsmEna.WrittenIn = {'MotAg1MeasPer3'};


MotAg4Mecl = DataDict.IRV;
MotAg4Mecl.LongName = 'Motor Angle 4 Mechanical';
MotAg4Mecl.Description = [...
  'Motor Angle 4 value in mechanical units'];
MotAg4Mecl.DocUnits = 'MotRev';
MotAg4Mecl.EngDT = dt.u0p16;
MotAg4Mecl.EngInit = 0;
MotAg4Mecl.EngMin = 0;
MotAg4Mecl.EngMax = 0.9999847412;
MotAg4Mecl.ReadIn = {'MotAg1MeasPer2'};
MotAg4Mecl.WrittenIn = {'MotAg1MeasPer3'};


MotAg1DiagcAg = DataDict.IRV;
MotAg1DiagcAg.LongName = 'Motor Angle 1 Diagnostic Angle';
MotAg1DiagcAg.Description = [...
  'Motor angle mechanical used for diagnostics'];
MotAg1DiagcAg.DocUnits = 'MotRev';
MotAg1DiagcAg.EngDT = dt.u0p16;
MotAg1DiagcAg.EngInit = 0;
MotAg1DiagcAg.EngMin = 0;
MotAg1DiagcAg.EngMax = 0.9999847412;
MotAg1DiagcAg.ReadIn = {'MotAg1MeasPer2'};
MotAg1DiagcAg.WrittenIn = {'MotAg1MeasPer3'};

%%-------------------------------------------
%% Calibrations Definition                   
%%-------------------------------------------
MotAg1MeasMotAgOffs = DataDict.Calibration;
MotAg1MeasMotAgOffs.LongName = 'Motor Angle 1 Measurement Motor Angle Offset';
MotAg1MeasMotAgOffs.Description = 'Motor Angle 1 Offset';
MotAg1MeasMotAgOffs.DocUnits = 'MotRev';
MotAg1MeasMotAgOffs.EngDT = dt.u0p16;
MotAg1MeasMotAgOffs.EngVal = 0.5;
MotAg1MeasMotAgOffs.EngMin = 0;
MotAg1MeasMotAgOffs.EngMax = 0.9999847412;
MotAg1MeasMotAgOffs.Cardinality = 'Inin';
MotAg1MeasMotAgOffs.CustomerVisible = false;
MotAg1MeasMotAgOffs.Online = false;
MotAg1MeasMotAgOffs.Impact = 'H';
MotAg1MeasMotAgOffs.TuningOwner = 'EPDT';
MotAg1MeasMotAgOffs.GraphLink = {''};
MotAg1MeasMotAgOffs.Monotony = 'None';
MotAg1MeasMotAgOffs.MaxGrad = 999;
MotAg1MeasMotAgOffs.PortName = 'MotAg1MeasMotAgOffs';



%%-------------------------------------------
%% Imported Calibrations Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Non-Volatile Memory Definition            
%%-------------------------------------------
MotAg1CoeffTbl = DataDict.NVM;
MotAg1CoeffTbl.LongName = 'Motor Angle 1 Coefficient Table';
MotAg1CoeffTbl.Description = [...
  'Coefficient table for Motor Angle 1.'];
MotAg1CoeffTbl.DocUnits = 'MotRev';
MotAg1CoeffTbl.EngDT = dt.float32;
MotAg1CoeffTbl.EngInit = [];
MotAg1CoeffTbl.EngMin = -0.03100585937;
MotAg1CoeffTbl.EngMax = 0.03100585937;
MotAg1CoeffTbl.CustomerVisible = false;
MotAg1CoeffTbl.Impact = 'H';
MotAg1CoeffTbl.TuningOwner = 'CSE';
MotAg1CoeffTbl.CoderInfo.Alias = '';
MotAg1CoeffTbl.InitRowCol = [1  26];



%%-------------------------------------------
%% Display Variable Definition               
%%-------------------------------------------
dMotAg1MeasMotAg1RawAgReg = DataDict.Display;
dMotAg1MeasMotAg1RawAgReg.LongName = 'Motor Angle 1 Raw Angle Register';
dMotAg1MeasMotAg1RawAgReg.Description = [...
  'Display variable for Motor Angle 1 Raw Angle Register'];
dMotAg1MeasMotAg1RawAgReg.DocUnits = 'Cnt';
dMotAg1MeasMotAg1RawAgReg.EngDT = dt.u32;
dMotAg1MeasMotAg1RawAgReg.EngMin = 0;
dMotAg1MeasMotAg1RawAgReg.EngMax = 67108863;
dMotAg1MeasMotAg1RawAgReg.InitRowCol = [1  1];


dMotAg1MeasMotAg1RawErrReg = DataDict.Display;
dMotAg1MeasMotAg1RawErrReg.LongName = 'Motor Angle 1 Raw Error Register';
dMotAg1MeasMotAg1RawErrReg.Description = [...
  'Display variable for Motor Angle 1 Raw Error Register'];
dMotAg1MeasMotAg1RawErrReg.DocUnits = 'Cnt';
dMotAg1MeasMotAg1RawErrReg.EngDT = dt.u32;
dMotAg1MeasMotAg1RawErrReg.EngMin = 0;
dMotAg1MeasMotAg1RawErrReg.EngMax = 67108863;
dMotAg1MeasMotAg1RawErrReg.InitRowCol = [1  1];


dMotAg1MeasMotAg1RawReg = DataDict.Display;
dMotAg1MeasMotAg1RawReg.LongName = 'Motor Angle 1 Raw Register';
dMotAg1MeasMotAg1RawReg.Description = [...
  'Display variable for Motor Angle 1 Raw Register Values'];
dMotAg1MeasMotAg1RawReg.DocUnits = 'Cnt';
dMotAg1MeasMotAg1RawReg.EngDT = dt.u32;
dMotAg1MeasMotAg1RawReg.EngMin = 0;
dMotAg1MeasMotAg1RawReg.EngMax = 67108863;
dMotAg1MeasMotAg1RawReg.InitRowCol = [10   1];


dMotAg1MeasMotAg1RawTurnCntrReg = DataDict.Display;
dMotAg1MeasMotAg1RawTurnCntrReg.LongName = 'Motor Angle 1 Raw Turn Counter Register';
dMotAg1MeasMotAg1RawTurnCntrReg.Description = [...
  'Display variable Motor Angle 1 Raw Turn Counter Register'];
dMotAg1MeasMotAg1RawTurnCntrReg.DocUnits = 'Cnt';
dMotAg1MeasMotAg1RawTurnCntrReg.EngDT = dt.u32;
dMotAg1MeasMotAg1RawTurnCntrReg.EngMin = 0;
dMotAg1MeasMotAg1RawTurnCntrReg.EngMax = 67108863;
dMotAg1MeasMotAg1RawTurnCntrReg.InitRowCol = [1  1];


dMotAg1MeasMotAg1RtOffs = DataDict.Display;
dMotAg1MeasMotAg1RtOffs.LongName = 'Motor Angle 1 Runtime Offset';
dMotAg1MeasMotAg1RtOffs.Description = [...
  'Display variable of Motor Angle 1 Runtime Offset'];
dMotAg1MeasMotAg1RtOffs.DocUnits = 'Cnt';
dMotAg1MeasMotAg1RtOffs.EngDT = dt.s32;
dMotAg1MeasMotAg1RtOffs.EngMin = -2147483648;
dMotAg1MeasMotAg1RtOffs.EngMax = 2147483647;
dMotAg1MeasMotAg1RtOffs.InitRowCol = [1  1];


dMotAg1MeasMotAg1SpiCntrAg = DataDict.Display;
dMotAg1MeasMotAg1SpiCntrAg.LongName = 'Motor Angle 1 Serial Peripheral Interface Counter Angle';
dMotAg1MeasMotAg1SpiCntrAg.Description = [...
  'Display variable of Motor Angle 1 SPI IIF Counter Angle'];
dMotAg1MeasMotAg1SpiCntrAg.DocUnits = 'Cnt';
dMotAg1MeasMotAg1SpiCntrAg.EngDT = dt.u0p16;
dMotAg1MeasMotAg1SpiCntrAg.EngMin = 0;
dMotAg1MeasMotAg1SpiCntrAg.EngMax = 0.9999847412;
dMotAg1MeasMotAg1SpiCntrAg.InitRowCol = [1  1];


dMotAg1MeasMotAg1SpiMecl = DataDict.Display;
dMotAg1MeasMotAg1SpiMecl.LongName = 'Motor Angle 1 Serial Peripheral Interface Mechanical';
dMotAg1MeasMotAg1SpiMecl.Description = [...
  'Display variable of Motor Angle 1 SPI Angle calculated from Angle Regi' ...
  'ster'];
dMotAg1MeasMotAg1SpiMecl.DocUnits = 'Cnt';
dMotAg1MeasMotAg1SpiMecl.EngDT = dt.u0p16;
dMotAg1MeasMotAg1SpiMecl.EngMin = 0;
dMotAg1MeasMotAg1SpiMecl.EngMax = 0.9999847412;
dMotAg1MeasMotAg1SpiMecl.InitRowCol = [1  1];


dMotAg1MeasMotAg1TurnCntr = DataDict.Display;
dMotAg1MeasMotAg1TurnCntr.LongName = 'Motor Angle 1 Turn Counter';
dMotAg1MeasMotAg1TurnCntr.Description = [...
  'Display variable Motor Angle 1 Turn Counter Value'];
dMotAg1MeasMotAg1TurnCntr.DocUnits = 'Cnt';
dMotAg1MeasMotAg1TurnCntr.EngDT = dt.float32;
dMotAg1MeasMotAg1TurnCntr.EngMin = -92160;
dMotAg1MeasMotAg1TurnCntr.EngMax = 92160;
dMotAg1MeasMotAg1TurnCntr.InitRowCol = [1  1];


dMotAg1MeasMotCtrlMotAg4Mecl = DataDict.Display;
dMotAg1MeasMotCtrlMotAg4Mecl.LongName = 'Motor Control Motor Angle 4 Mecahnical';
dMotAg1MeasMotCtrlMotAg4Mecl.Description = [...
  'Display variable of Motor Angle 4 run in Motor Control in mechanical u' ...
  'nits'];
dMotAg1MeasMotCtrlMotAg4Mecl.DocUnits = 'Cnt';
dMotAg1MeasMotCtrlMotAg4Mecl.EngDT = dt.u0p16;
dMotAg1MeasMotCtrlMotAg4Mecl.EngMin = 0;
dMotAg1MeasMotCtrlMotAg4Mecl.EngMax = 0.9999847412;
dMotAg1MeasMotCtrlMotAg4Mecl.InitRowCol = [1  1];


dMotAg1MeasMotAg1Delta = DataDict.Display;
dMotAg1MeasMotAg1Delta.LongName = 'Motor Angle 1 Delta';
dMotAg1MeasMotAg1Delta.Description = [...
  'Display variable of difference between angle from encoder interface' ...
  'and angle from SPI bus'];
dMotAg1MeasMotAg1Delta.DocUnits = 'MotRev';
dMotAg1MeasMotAg1Delta.EngDT = dt.u0p16;
dMotAg1MeasMotAg1Delta.EngMin = 0;
dMotAg1MeasMotAg1Delta.EngMax = 0.9999847412;
dMotAg1MeasMotAg1Delta.InitRowCol = [1  1];

%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------
MotAg1CorrnTbl = DataDict.PIM;
MotAg1CorrnTbl.LongName = 'Motor Angle 1 Correction Table';
MotAg1CorrnTbl.Description = [...
  'Correction table for Motor Angle 1.'];
MotAg1CorrnTbl.DocUnits = 'MotRev';
MotAg1CorrnTbl.EngDT = dt.sm5p12;
MotAg1CorrnTbl.EngMin = -0.03100585937;
MotAg1CorrnTbl.EngMax = 0.03100585937;
MotAg1CorrnTbl.InitRowCol = [128    1];


MotAg1InitOffs = DataDict.PIM;
MotAg1InitOffs.LongName = 'Motor Angle 1 Initial Offset';
MotAg1InitOffs.Description = [...
  'Initializing Motor Angle 1 Offset calculation'];
MotAg1InitOffs.DocUnits = 'Cnt';
MotAg1InitOffs.EngDT = dt.u08;
MotAg1InitOffs.EngMin = 0;
MotAg1InitOffs.EngMax = 255;
MotAg1InitOffs.InitRowCol = [1  1];


MotAg1PrevOffs = DataDict.PIM;
MotAg1PrevOffs.LongName = 'Motor Angle 1 Previous Offset';
MotAg1PrevOffs.Description = 'Last known Offeset value';
MotAg1PrevOffs.DocUnits = 'Cnt';
MotAg1PrevOffs.EngDT = dt.s32;
MotAg1PrevOffs.EngMin = -2147483648;
MotAg1PrevOffs.EngMax = 2147483647;
MotAg1PrevOffs.InitRowCol = [1  1];


MotAg1PrevRollgCntr = DataDict.PIM;
MotAg1PrevRollgCntr.LongName = 'Motor Angle 1 Previous Rolling Counter';
MotAg1PrevRollgCntr.Description = 'Previous value of rolling counter';
MotAg1PrevRollgCntr.DocUnits = 'Cnt';
MotAg1PrevRollgCntr.EngDT = dt.u08;
MotAg1PrevRollgCntr.EngMin = 0;
MotAg1PrevRollgCntr.EngMax = 255;
MotAg1PrevRollgCntr.InitRowCol = [1  1];


MotAg1PrevSpiErrFltCntr = DataDict.PIM;
MotAg1PrevSpiErrFltCntr.LongName = 'Motor Angle 1 Spi Error Previous Fault Counter';
MotAg1PrevSpiErrFltCntr.Description = [...
  'Motor Angle 1 Spi Error Previous Fault Counter Value'];
MotAg1PrevSpiErrFltCntr.DocUnits = 'Cnt';
MotAg1PrevSpiErrFltCntr.EngDT = dt.u16;
MotAg1PrevSpiErrFltCntr.EngMin = 0;
MotAg1PrevSpiErrFltCntr.EngMax = 65535;
MotAg1PrevSpiErrFltCntr.InitRowCol = [1  1];


MotAg1Diagc = DataDict.PIM;
MotAg1Diagc.LongName = 'Motor Angle 1 Diagnostic';
MotAg1Diagc.Description = [...
  'Motor Angle 1 Mechanical used for diagnostics'];
MotAg1Diagc.DocUnits = 'MotRev';
MotAg1Diagc.EngDT = dt.u0p16;
MotAg1Diagc.EngMin = 0;
MotAg1Diagc.EngMax = 0.9999847412;
MotAg1Diagc.InitRowCol = [1  1];


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


CNTPERREV_MOTREV_S15P16 = DataDict.Constant;
CNTPERREV_MOTREV_S15P16.LongName = 'Count Per Motor Revolution';
CNTPERREV_MOTREV_S15P16.Description = [...
  'Constant used normalize motor position for motor angle signals of data' ...
  ' type p16.'];
CNTPERREV_MOTREV_S15P16.DocUnits = 'MotRev';
CNTPERREV_MOTREV_S15P16.EngDT = dt.s15p16;
CNTPERREV_MOTREV_S15P16.EngVal = 1;
CNTPERREV_MOTREV_S15P16.Define = 'Local';


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
CORRNTBLSIZE_CNT_U16.LongName = 'Motor Angle 1 Correction Table Size';
CORRNTBLSIZE_CNT_U16.Description = [...
  'Motor Angle 1 Correction Table Size'];
CORRNTBLSIZE_CNT_U16.DocUnits = 'Cnt';
CORRNTBLSIZE_CNT_U16.EngDT = dt.u16;
CORRNTBLSIZE_CNT_U16.EngVal = 128;
CORRNTBLSIZE_CNT_U16.Define = 'Local';


MOTAG1ERRTHD_MOTREV_U0P16 = DataDict.Constant;
MOTAG1ERRTHD_MOTREV_U0P16.LongName = 'Motor Angle 1 Error Threshold';
MOTAG1ERRTHD_MOTREV_U0P16.Description = [...
  'Error threshold between Motor Angle 1 (SPI) and Motor Angle 4 (ENCA) 8' ...
  '0 degrees Elec'];
MOTAG1ERRTHD_MOTREV_U0P16.DocUnits = 'MotRev';
MOTAG1ERRTHD_MOTREV_U0P16.EngDT = dt.u0p16;
MOTAG1ERRTHD_MOTREV_U0P16.EngVal = 0.055;
MOTAG1ERRTHD_MOTREV_U0P16.Define = 'Local';


MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM = DataDict.ConfigParam;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.LongName = 'Motor Angle 1 Protocol Fault NTC Number';
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.Description = [...
  'Motor Angle 1 Protocol Fault NTC Number'];
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.IsBuildPrm = false;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.DocUnits = 'Cnt';
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X085;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.EngMin = NtcNr1.NTCNR_0X083;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.EngMax = NtcNr1.NTCNR_0X08A;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.Define = 'Global';


MOTAG1PRTCLFLTFAILSTEP_CNT_U16 = DataDict.Constant;
MOTAG1PRTCLFLTFAILSTEP_CNT_U16.LongName = 'Motor Angle 1 Protocol Fault Fail Step';
MOTAG1PRTCLFLTFAILSTEP_CNT_U16.Description = [...
  'Debounce Fail Step for motor angle o Diagnostic'];
MOTAG1PRTCLFLTFAILSTEP_CNT_U16.DocUnits = 'Cnt';
MOTAG1PRTCLFLTFAILSTEP_CNT_U16.EngDT = dt.u16;
MOTAG1PRTCLFLTFAILSTEP_CNT_U16.EngVal = 3276;
MOTAG1PRTCLFLTFAILSTEP_CNT_U16.Define = 'Local';


MOTAG1PRTCLFLTPASSSTEP_CNT_U16 = DataDict.Constant;
MOTAG1PRTCLFLTPASSSTEP_CNT_U16.LongName = 'Motor Angle 1 Protocol Faul Pass Step';
MOTAG1PRTCLFLTPASSSTEP_CNT_U16.Description = [...
  'Debounce Pass Step for Motor Angle 1 Diagnostic'];
MOTAG1PRTCLFLTPASSSTEP_CNT_U16.DocUnits = 'Cnt';
MOTAG1PRTCLFLTPASSSTEP_CNT_U16.EngDT = dt.u16;
MOTAG1PRTCLFLTPASSSTEP_CNT_U16.EngVal = 655;
MOTAG1PRTCLFLTPASSSTEP_CNT_U16.Define = 'Local';


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
  'Mask to find Motor Angle 1 Turn Counter'];
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
MotAg1PrtclFlt = DataDict.NTC;
MotAg1PrtclFlt.NtcNr = 'MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM';
MotAg1PrtclFlt.NtcTyp = 'Deb';
MotAg1PrtclFlt.LongName = 'Motor Angle 1 Protocol Fault';
MotAg1PrtclFlt.Description = 'Motor Angle 1 Protocol Fault.  MotAg1PrtclFlt.NtcNr = MotAg1PRTCLFLTNTCNR_CNT_ENUM;';
MotAg1PrtclFlt.NtcStInfo = DataDict.NtcStInfoBitPacked;
MotAg1PrtclFlt.NtcStInfo.Bit0Descr = 'Invalid Motor Angle';
MotAg1PrtclFlt.NtcStInfo.Bit1Descr = 'Invalid Sin Cos Components';
MotAg1PrtclFlt.NtcStInfo.Bit2Descr = 'Magnetic Loss';
MotAg1PrtclFlt.NtcStInfo.Bit3Descr = 'Sin Cos Out of Limit Error';
MotAg1PrtclFlt.NtcStInfo.Bit4Descr = 'Overflow Error';
MotAg1PrtclFlt.NtcStInfo.Bit5Descr = 'Voltage Fault';
MotAg1PrtclFlt.NtcStInfo.Bit6Descr = 'IIF-ENCA vs SPI Angle Error';
MotAg1PrtclFlt.NtcStInfo.Bit7Descr = 'Unused';


%end of Data Dictionary
