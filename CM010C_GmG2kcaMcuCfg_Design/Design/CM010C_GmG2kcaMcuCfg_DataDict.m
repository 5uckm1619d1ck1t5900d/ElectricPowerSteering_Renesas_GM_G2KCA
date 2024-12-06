%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 10-Oct-2016 18:26:57       %
%                                  Created with tool release: 2.47.0     %
%                                  Synergy file: %version: 1 %           %
%                                  Derived by: %derived_by: nz3zln %          %
%%-----------------------------------------------------------------------%

CM010C = DataDict.FDD;
CM010C.Version = '1.0.X';
CM010C.LongName = 'GM G2KCA MCU Configuration';
CM010C.ShoName  = 'GmG2kcaMcuCfg';
CM010C.DesignASIL = 'D';
CM010C.Description = [...
  'Program specific I/O and Constant settings for the GM G2KCA Program'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
GmG2kcaMcuCfgInit1 = DataDict.Runnable;
GmG2kcaMcuCfgInit1.Context = 'Rte';
GmG2kcaMcuCfgInit1.TimeStep = 0;
GmG2kcaMcuCfgInit1.Description = 'None';

GmG2kcaMcuCfgInit2 = DataDict.Runnable;
GmG2kcaMcuCfgInit2.Context = 'Rte';
GmG2kcaMcuCfgInit2.TimeStep = 0;
GmG2kcaMcuCfgInit2.Description = 'None';

GmG2kcaMcuCfgInit3 = DataDict.Runnable;
GmG2kcaMcuCfgInit3.Context = 'Rte';
GmG2kcaMcuCfgInit3.TimeStep = 0;
GmG2kcaMcuCfgInit3.Description = 'None';

GmG2kcaMcuCfgPer1 = DataDict.Runnable;
GmG2kcaMcuCfgPer1.Context = 'NonRte';
GmG2kcaMcuCfgPer1.TimeStep = 'MotorControl';
GmG2kcaMcuCfgPer1.Description = 'None';

GmG2kcaMcuCfgPer2 = DataDict.Runnable;
GmG2kcaMcuCfgPer2.Context = 'Rte';
GmG2kcaMcuCfgPer2.TimeStep = 0.002;
GmG2kcaMcuCfgPer2.Description = 'None';

GmG2kcaMcuCfgPer3 = DataDict.Runnable;
GmG2kcaMcuCfgPer3.Context = 'Rte';
GmG2kcaMcuCfgPer3.TimeStep = 0.002;
GmG2kcaMcuCfgPer3.Description = 'None';


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------
GetRefTmr1MicroSec32bit = DataDict.Client;
GetRefTmr1MicroSec32bit.CallLocation = {'GmG2kcaMcuCfgInit2'};
GetRefTmr1MicroSec32bit.Description = 'None';
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
GetRefTmr1MicroSec32bit.Arguments(1).TestTolerance = 999;
GetRefTmr1MicroSec32bit.Arguments(1).Units = 'Cnt';
GetRefTmr1MicroSec32bit.Arguments(1).Direction = 'Out';
GetRefTmr1MicroSec32bit.Arguments(1).InitRowCol = [1  1];
GetRefTmr1MicroSec32bit.Arguments(1).Description = '';


GetTiSpan1MicroSec32bit = DataDict.Client;
GetTiSpan1MicroSec32bit.CallLocation = {'GmG2kcaMcuCfgInit2'};
GetTiSpan1MicroSec32bit.Description = 'None';
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
GetTiSpan1MicroSec32bit.Arguments(2).TestTolerance = 999;
GetTiSpan1MicroSec32bit.Arguments(2).Units = 'Cnt';
GetTiSpan1MicroSec32bit.Arguments(2).Direction = 'Out';
GetTiSpan1MicroSec32bit.Arguments(2).InitRowCol = [1  1];
GetTiSpan1MicroSec32bit.Arguments(2).Description = '';



%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
Adc0Faild = DataDict.IpSignal;
Adc0Faild.LongName = 'ADC 0 Failed';
Adc0Faild.Description = 'None';
Adc0Faild.DocUnits = 'Cnt';
Adc0Faild.EngDT = dt.lgc;
Adc0Faild.EngInit = 0;
Adc0Faild.EngMin = 0;
Adc0Faild.EngMax = 1;
Adc0Faild.ReadIn = {'GmG2kcaMcuCfgPer3'};
Adc0Faild.ReadType = 'Rte';


Adc1Faild = DataDict.IpSignal;
Adc1Faild.LongName = 'ADC 1 Failed';
Adc1Faild.Description = 'None';
Adc1Faild.DocUnits = 'Cnt';
Adc1Faild.EngDT = dt.lgc;
Adc1Faild.EngInit = 0;
Adc1Faild.EngMin = 0;
Adc1Faild.EngMax = 1;
Adc1Faild.ReadIn = {'GmG2kcaMcuCfgPer3'};
Adc1Faild.ReadType = 'Rte';


Adc1RawRes = DataDict.IpSignal;
Adc1RawRes.LongName = 'Adc1 Raw Results';
Adc1RawRes.Description = 'None';
Adc1RawRes.DocUnits = 'Cnt';
Adc1RawRes.EngDT = dt.u16;
Adc1RawRes.EngInit =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0];
Adc1RawRes.EngMin = 0;
Adc1RawRes.EngMax = 4095;
Adc1RawRes.ReadIn = {'GmG2kcaMcuCfgPer2'};
Adc1RawRes.ReadType = 'NonRte';


MotCtrlAdc0RawRes = DataDict.IpSignal;
MotCtrlAdc0RawRes.LongName = 'Adc0 Raw Results';
MotCtrlAdc0RawRes.Description = 'None';
MotCtrlAdc0RawRes.DocUnits = 'Cnt';
MotCtrlAdc0RawRes.EngDT = dt.u16;
MotCtrlAdc0RawRes.EngInit =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0];
MotCtrlAdc0RawRes.EngMin = 0;
MotCtrlAdc0RawRes.EngMax = 4095;
MotCtrlAdc0RawRes.ReadIn = {'GmG2kcaMcuCfgPer1'};
MotCtrlAdc0RawRes.ReadType = 'NonRte';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
Adc1ScanGroup2Ref0 = DataDict.OpSignal;
Adc1ScanGroup2Ref0.LongName = 'ADC 1 Scan Group 2 Reference 0';
Adc1ScanGroup2Ref0.Description = [...
  'ADC 1 reference voltage read at start of Scan Group 2'];
Adc1ScanGroup2Ref0.DocUnits = 'Volt';
Adc1ScanGroup2Ref0.SwcShoName = 'GmG2kcaMcuCfg';
Adc1ScanGroup2Ref0.EngDT = dt.float32;
Adc1ScanGroup2Ref0.EngInit = 0;
Adc1ScanGroup2Ref0.EngMin = 0;
Adc1ScanGroup2Ref0.EngMax = 5;
Adc1ScanGroup2Ref0.TestTolerance = 0.001221001221;
Adc1ScanGroup2Ref0.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
Adc1ScanGroup2Ref0.WriteType = 'Rte';


Adc1ScanGroup2Ref1 = DataDict.OpSignal;
Adc1ScanGroup2Ref1.LongName = 'ADC 1 Scan Group 2 Reference 1';
Adc1ScanGroup2Ref1.Description = [...
  'ADC 1 reference voltage read at end of Scan Group 2'];
Adc1ScanGroup2Ref1.DocUnits = 'Volt';
Adc1ScanGroup2Ref1.SwcShoName = 'GmG2kcaMcuCfg';
Adc1ScanGroup2Ref1.EngDT = dt.float32;
Adc1ScanGroup2Ref1.EngInit = 0;
Adc1ScanGroup2Ref1.EngMin = 0;
Adc1ScanGroup2Ref1.EngMax = 5;
Adc1ScanGroup2Ref1.TestTolerance = 0.001221001221;
Adc1ScanGroup2Ref1.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
Adc1ScanGroup2Ref1.WriteType = 'Rte';


Adc1ScanGroup3Ref0 = DataDict.OpSignal;
Adc1ScanGroup3Ref0.LongName = 'ADC 1 Scan Group 3 Reference 0';
Adc1ScanGroup3Ref0.Description = [...
  'ADC 1 reference voltage read at start of Scan Group 3'];
Adc1ScanGroup3Ref0.DocUnits = 'Volt';
Adc1ScanGroup3Ref0.SwcShoName = 'GmG2kcaMcuCfg';
Adc1ScanGroup3Ref0.EngDT = dt.float32;
Adc1ScanGroup3Ref0.EngInit = 0;
Adc1ScanGroup3Ref0.EngMin = 0;
Adc1ScanGroup3Ref0.EngMax = 5;
Adc1ScanGroup3Ref0.TestTolerance = 0.001221001221;
Adc1ScanGroup3Ref0.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
Adc1ScanGroup3Ref0.WriteType = 'Rte';


Adc1ScanGroup3Ref1 = DataDict.OpSignal;
Adc1ScanGroup3Ref1.LongName = 'ADC 1 Scan Group 3 Reference 1';
Adc1ScanGroup3Ref1.Description = [...
  'ADC 1 reference voltage read at end of Scan Group 3'];
Adc1ScanGroup3Ref1.DocUnits = 'Volt';
Adc1ScanGroup3Ref1.SwcShoName = 'GmG2kcaMcuCfg';
Adc1ScanGroup3Ref1.EngDT = dt.float32;
Adc1ScanGroup3Ref1.EngInit = 0;
Adc1ScanGroup3Ref1.EngMin = 0;
Adc1ScanGroup3Ref1.EngMax = 5;
Adc1ScanGroup3Ref1.TestTolerance = 0.001221001221;
Adc1ScanGroup3Ref1.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
Adc1ScanGroup3Ref1.WriteType = 'Rte';


Adc1SelfDiag0 = DataDict.OpSignal;
Adc1SelfDiag0.LongName = 'Adc1 Self Diagnosis 0';
Adc1SelfDiag0.Description = 'Adc1 Self Diagnosis 0';
Adc1SelfDiag0.DocUnits = 'Volt';
Adc1SelfDiag0.SwcShoName = 'GmG2kcaMcuCfg';
Adc1SelfDiag0.EngDT = dt.float32;
Adc1SelfDiag0.EngInit = 0;
Adc1SelfDiag0.EngMin = 0;
Adc1SelfDiag0.EngMax = 5;
Adc1SelfDiag0.TestTolerance = 0.001221001221;
Adc1SelfDiag0.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
Adc1SelfDiag0.WriteType = 'Rte';


Adc1SelfDiag2 = DataDict.OpSignal;
Adc1SelfDiag2.LongName = 'Adc1 Self Diagnosis 2';
Adc1SelfDiag2.Description = 'Adc1 Self Diagnosis 2';
Adc1SelfDiag2.DocUnits = 'Volt';
Adc1SelfDiag2.SwcShoName = 'GmG2kcaMcuCfg';
Adc1SelfDiag2.EngDT = dt.float32;
Adc1SelfDiag2.EngInit = 0;
Adc1SelfDiag2.EngMin = 0;
Adc1SelfDiag2.EngMax = 5;
Adc1SelfDiag2.TestTolerance = 0.001221001221;
Adc1SelfDiag2.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
Adc1SelfDiag2.WriteType = 'Rte';


Adc1SelfDiag4 = DataDict.OpSignal;
Adc1SelfDiag4.LongName = 'Adc1 Self Diagnosis 4';
Adc1SelfDiag4.Description = 'Adc1 Self Diagnosis 4';
Adc1SelfDiag4.DocUnits = 'Volt';
Adc1SelfDiag4.SwcShoName = 'GmG2kcaMcuCfg';
Adc1SelfDiag4.EngDT = dt.float32;
Adc1SelfDiag4.EngInit = 0;
Adc1SelfDiag4.EngMin = 0;
Adc1SelfDiag4.EngMax = 5;
Adc1SelfDiag4.TestTolerance = 0.001221001221;
Adc1SelfDiag4.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
Adc1SelfDiag4.WriteType = 'Rte';


BattVltg = DataDict.OpSignal;
BattVltg.LongName = 'Battery Voltage';
BattVltg.Description = 'Filtered Battery Voltage';
BattVltg.DocUnits = 'Volt';
BattVltg.SwcShoName = 'GmG2kcaMcuCfg';
BattVltg.EngDT = dt.float32;
BattVltg.EngInit = 0;
BattVltg.EngMin = 0;
BattVltg.EngMax = 40;
BattVltg.TestTolerance = 0.001221001221;
BattVltg.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
BattVltg.WriteType = 'Rte';


BattVltgAdcFaild = DataDict.OpSignal;
BattVltgAdcFaild.LongName = 'Battery Voltage  ADC Failed';
BattVltgAdcFaild.Description = [...
  'The Adc that converts BattVltg has failed'];
BattVltgAdcFaild.DocUnits = 'Cnt';
BattVltgAdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
BattVltgAdcFaild.EngDT = dt.lgc;
BattVltgAdcFaild.EngInit = 0;
BattVltgAdcFaild.EngMin = 0;
BattVltgAdcFaild.EngMax = 1;
BattVltgAdcFaild.TestTolerance = 0;
BattVltgAdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
BattVltgAdcFaild.WriteType = 'Rte';


BattVltgSwd1 = DataDict.OpSignal;
BattVltgSwd1.LongName = 'Switched Battery Voltage 1';
BattVltgSwd1.Description = 'Switched Battery Voltage 1';
BattVltgSwd1.DocUnits = 'Volt';
BattVltgSwd1.SwcShoName = 'GmG2kcaMcuCfg';
BattVltgSwd1.EngDT = dt.float32;
BattVltgSwd1.EngInit = 0;
BattVltgSwd1.EngMin = 0;
BattVltgSwd1.EngMax = 40;
BattVltgSwd1.TestTolerance = 0.001221001221;
BattVltgSwd1.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
BattVltgSwd1.WriteType = 'Rte';


BattVltgSwd1AdcFaild = DataDict.OpSignal;
BattVltgSwd1AdcFaild.LongName = 'Battery Voltage  Switched 1 ADC Failed';
BattVltgSwd1AdcFaild.Description = [...
  'The Adc that converts BattVltgSwd1 has failed'];
BattVltgSwd1AdcFaild.DocUnits = 'Cnt';
BattVltgSwd1AdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
BattVltgSwd1AdcFaild.EngDT = dt.lgc;
BattVltgSwd1AdcFaild.EngInit = 0;
BattVltgSwd1AdcFaild.EngMin = 0;
BattVltgSwd1AdcFaild.EngMax = 1;
BattVltgSwd1AdcFaild.TestTolerance = 0;
BattVltgSwd1AdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
BattVltgSwd1AdcFaild.WriteType = 'Rte';


EcuT = DataDict.OpSignal;
EcuT.LongName = 'Ecu Temperature';
EcuT.Description = [...
  'Voltage representation of Ecu Temperature, convertered to degC in a di' ...
  'fferent module'];
EcuT.DocUnits = 'Volt';
EcuT.SwcShoName = 'GmG2kcaMcuCfg';
EcuT.EngDT = dt.float32;
EcuT.EngInit = 0;
EcuT.EngMin = 0;
EcuT.EngMax = 5;
EcuT.TestTolerance = 0.001221001221;
EcuT.WrittenIn = {'GmG2kcaMcuCfgInit3','GmG2kcaMcuCfgPer2'};
EcuT.WriteType = 'Rte';


EcuTAdcFaild = DataDict.OpSignal;
EcuTAdcFaild.LongName = 'ECU Temperature ADC Failed';
EcuTAdcFaild.Description = [...
  'The Adc that converts EcuT has failed'];
EcuTAdcFaild.DocUnits = 'Cnt';
EcuTAdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
EcuTAdcFaild.EngDT = dt.lgc;
EcuTAdcFaild.EngInit = 0;
EcuTAdcFaild.EngMin = 0;
EcuTAdcFaild.EngMax = 1;
EcuTAdcFaild.TestTolerance = 0;
EcuTAdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
EcuTAdcFaild.WriteType = 'Rte';


MotCtrlAdc0ScanGroup2Ref0 = DataDict.OpSignal;
MotCtrlAdc0ScanGroup2Ref0.LongName = 'ADC 0 Scan Group 2 Reference 0';
MotCtrlAdc0ScanGroup2Ref0.Description = [...
  'ADC 0 reference voltage read at start of Scan Group 2'];
MotCtrlAdc0ScanGroup2Ref0.DocUnits = 'Volt';
MotCtrlAdc0ScanGroup2Ref0.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlAdc0ScanGroup2Ref0.EngDT = dt.float32;
MotCtrlAdc0ScanGroup2Ref0.EngInit = 0;
MotCtrlAdc0ScanGroup2Ref0.EngMin = 0;
MotCtrlAdc0ScanGroup2Ref0.EngMax = 5;
MotCtrlAdc0ScanGroup2Ref0.TestTolerance = 0.001221001221;
MotCtrlAdc0ScanGroup2Ref0.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlAdc0ScanGroup2Ref0.WriteType = 'NonRte';


MotCtrlAdc0ScanGroup2Ref1 = DataDict.OpSignal;
MotCtrlAdc0ScanGroup2Ref1.LongName = 'ADC 0 Scan Group 2 Reference 1';
MotCtrlAdc0ScanGroup2Ref1.Description = [...
  'ADC 0 reference voltage read at end of Scan Group 2'];
MotCtrlAdc0ScanGroup2Ref1.DocUnits = 'Volt';
MotCtrlAdc0ScanGroup2Ref1.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlAdc0ScanGroup2Ref1.EngDT = dt.float32;
MotCtrlAdc0ScanGroup2Ref1.EngInit = 0;
MotCtrlAdc0ScanGroup2Ref1.EngMin = 0;
MotCtrlAdc0ScanGroup2Ref1.EngMax = 5;
MotCtrlAdc0ScanGroup2Ref1.TestTolerance = 0.001221001221;
MotCtrlAdc0ScanGroup2Ref1.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlAdc0ScanGroup2Ref1.WriteType = 'NonRte';


MotCtrlAdc0ScanGroup3Ref0 = DataDict.OpSignal;
MotCtrlAdc0ScanGroup3Ref0.LongName = 'ADC 0 Scan Group 3 Reference 0';
MotCtrlAdc0ScanGroup3Ref0.Description = [...
  'ADC 0 reference voltage read at start of Scan Group 3'];
MotCtrlAdc0ScanGroup3Ref0.DocUnits = 'Volt';
MotCtrlAdc0ScanGroup3Ref0.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlAdc0ScanGroup3Ref0.EngDT = dt.float32;
MotCtrlAdc0ScanGroup3Ref0.EngInit = 0;
MotCtrlAdc0ScanGroup3Ref0.EngMin = 0;
MotCtrlAdc0ScanGroup3Ref0.EngMax = 5;
MotCtrlAdc0ScanGroup3Ref0.TestTolerance = 0.001221001221;
MotCtrlAdc0ScanGroup3Ref0.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlAdc0ScanGroup3Ref0.WriteType = 'NonRte';


MotCtrlAdc0ScanGroup3Ref1 = DataDict.OpSignal;
MotCtrlAdc0ScanGroup3Ref1.LongName = 'ADC 0 Scan Group 3 Reference 1';
MotCtrlAdc0ScanGroup3Ref1.Description = [...
  'ADC 0 reference voltage read at end of Scan Group 3'];
MotCtrlAdc0ScanGroup3Ref1.DocUnits = 'Volt';
MotCtrlAdc0ScanGroup3Ref1.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlAdc0ScanGroup3Ref1.EngDT = dt.float32;
MotCtrlAdc0ScanGroup3Ref1.EngInit = 0;
MotCtrlAdc0ScanGroup3Ref1.EngMin = 0;
MotCtrlAdc0ScanGroup3Ref1.EngMax = 5;
MotCtrlAdc0ScanGroup3Ref1.TestTolerance = 0.001221001221;
MotCtrlAdc0ScanGroup3Ref1.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlAdc0ScanGroup3Ref1.WriteType = 'NonRte';


MotCtrlAdc0SelfDiag0 = DataDict.OpSignal;
MotCtrlAdc0SelfDiag0.LongName = 'Adc0 Self Diagnostic 0';
MotCtrlAdc0SelfDiag0.Description = 'Adc0 Self Diagnostic 0';
MotCtrlAdc0SelfDiag0.DocUnits = 'Volt';
MotCtrlAdc0SelfDiag0.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlAdc0SelfDiag0.EngDT = dt.float32;
MotCtrlAdc0SelfDiag0.EngInit = 0;
MotCtrlAdc0SelfDiag0.EngMin = 0;
MotCtrlAdc0SelfDiag0.EngMax = 5;
MotCtrlAdc0SelfDiag0.TestTolerance = 0.001221001221;
MotCtrlAdc0SelfDiag0.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlAdc0SelfDiag0.WriteType = 'NonRte';


MotCtrlAdc0SelfDiag2 = DataDict.OpSignal;
MotCtrlAdc0SelfDiag2.LongName = 'Adc0 Self Diagnostic 2';
MotCtrlAdc0SelfDiag2.Description = 'Adc0 Self Diagnostic 2';
MotCtrlAdc0SelfDiag2.DocUnits = 'Volt';
MotCtrlAdc0SelfDiag2.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlAdc0SelfDiag2.EngDT = dt.float32;
MotCtrlAdc0SelfDiag2.EngInit = 0;
MotCtrlAdc0SelfDiag2.EngMin = 0;
MotCtrlAdc0SelfDiag2.EngMax = 5;
MotCtrlAdc0SelfDiag2.TestTolerance = 0.001221001221;
MotCtrlAdc0SelfDiag2.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlAdc0SelfDiag2.WriteType = 'NonRte';


MotCtrlAdc0SelfDiag4 = DataDict.OpSignal;
MotCtrlAdc0SelfDiag4.LongName = 'Adc0 Self Diagnostic 4';
MotCtrlAdc0SelfDiag4.Description = 'Adc0 Self Diagnostic 4';
MotCtrlAdc0SelfDiag4.DocUnits = 'Volt';
MotCtrlAdc0SelfDiag4.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlAdc0SelfDiag4.EngDT = dt.float32;
MotCtrlAdc0SelfDiag4.EngInit = 0;
MotCtrlAdc0SelfDiag4.EngMin = 0;
MotCtrlAdc0SelfDiag4.EngMax = 5;
MotCtrlAdc0SelfDiag4.TestTolerance = 0.001221001221;
MotCtrlAdc0SelfDiag4.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlAdc0SelfDiag4.WriteType = 'NonRte';


MotCtrlMotCurrAdcPeakA = DataDict.OpSignal;
MotCtrlMotCurrAdcPeakA.LongName = 'Motor Current A Sampled at Peak';
MotCtrlMotCurrAdcPeakA.Description = 'Motor Current A Sampled at Peak';
MotCtrlMotCurrAdcPeakA.DocUnits = 'Volt';
MotCtrlMotCurrAdcPeakA.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlMotCurrAdcPeakA.EngDT = dt.float32;
MotCtrlMotCurrAdcPeakA.EngInit = 0;
MotCtrlMotCurrAdcPeakA.EngMin = 0;
MotCtrlMotCurrAdcPeakA.EngMax = 5;
MotCtrlMotCurrAdcPeakA.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcPeakA.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlMotCurrAdcPeakA.WriteType = 'NonRte';


MotCtrlMotCurrAdcPeakB = DataDict.OpSignal;
MotCtrlMotCurrAdcPeakB.LongName = 'Motor Current B Sampled at Peak';
MotCtrlMotCurrAdcPeakB.Description = 'Motor Current B Sampled at Peak';
MotCtrlMotCurrAdcPeakB.DocUnits = 'Volt';
MotCtrlMotCurrAdcPeakB.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlMotCurrAdcPeakB.EngDT = dt.float32;
MotCtrlMotCurrAdcPeakB.EngInit = 0;
MotCtrlMotCurrAdcPeakB.EngMin = 0;
MotCtrlMotCurrAdcPeakB.EngMax = 5;
MotCtrlMotCurrAdcPeakB.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcPeakB.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlMotCurrAdcPeakB.WriteType = 'NonRte';


MotCtrlMotCurrAdcPeakC = DataDict.OpSignal;
MotCtrlMotCurrAdcPeakC.LongName = 'Motor Current C Sampled at Peak';
MotCtrlMotCurrAdcPeakC.Description = 'Motor Current C Sampled at Peak';
MotCtrlMotCurrAdcPeakC.DocUnits = 'Volt';
MotCtrlMotCurrAdcPeakC.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlMotCurrAdcPeakC.EngDT = dt.float32;
MotCtrlMotCurrAdcPeakC.EngInit = 0;
MotCtrlMotCurrAdcPeakC.EngMin = 0;
MotCtrlMotCurrAdcPeakC.EngMax = 5;
MotCtrlMotCurrAdcPeakC.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcPeakC.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlMotCurrAdcPeakC.WriteType = 'NonRte';


MotCtrlMotCurrAdcVlyA = DataDict.OpSignal;
MotCtrlMotCurrAdcVlyA.LongName = 'Motor Current A Sampled at Valley';
MotCtrlMotCurrAdcVlyA.Description = 'Motor Current A Sampled at Valley';
MotCtrlMotCurrAdcVlyA.DocUnits = 'Volt';
MotCtrlMotCurrAdcVlyA.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlMotCurrAdcVlyA.EngDT = dt.float32;
MotCtrlMotCurrAdcVlyA.EngInit = 0;
MotCtrlMotCurrAdcVlyA.EngMin = 0;
MotCtrlMotCurrAdcVlyA.EngMax = 5;
MotCtrlMotCurrAdcVlyA.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcVlyA.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlMotCurrAdcVlyA.WriteType = 'NonRte';


MotCtrlMotCurrAdcVlyB = DataDict.OpSignal;
MotCtrlMotCurrAdcVlyB.LongName = 'Motor Current B Sampled at Valley';
MotCtrlMotCurrAdcVlyB.Description = 'Motor Current B Sampled at Valley';
MotCtrlMotCurrAdcVlyB.DocUnits = 'Volt';
MotCtrlMotCurrAdcVlyB.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlMotCurrAdcVlyB.EngDT = dt.float32;
MotCtrlMotCurrAdcVlyB.EngInit = 0;
MotCtrlMotCurrAdcVlyB.EngMin = 0;
MotCtrlMotCurrAdcVlyB.EngMax = 5;
MotCtrlMotCurrAdcVlyB.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcVlyB.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlMotCurrAdcVlyB.WriteType = 'NonRte';


MotCtrlMotCurrAdcVlyC = DataDict.OpSignal;
MotCtrlMotCurrAdcVlyC.LongName = 'Motor Current C Sampled at Valley';
MotCtrlMotCurrAdcVlyC.Description = 'Motor Current C Sampled at Valley';
MotCtrlMotCurrAdcVlyC.DocUnits = 'Volt';
MotCtrlMotCurrAdcVlyC.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlMotCurrAdcVlyC.EngDT = dt.float32;
MotCtrlMotCurrAdcVlyC.EngInit = 0;
MotCtrlMotCurrAdcVlyC.EngMin = 0;
MotCtrlMotCurrAdcVlyC.EngMax = 5;
MotCtrlMotCurrAdcVlyC.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcVlyC.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlMotCurrAdcVlyC.WriteType = 'NonRte';


MotCtrlMotCurrSnsrOffs1 = DataDict.OpSignal;
MotCtrlMotCurrSnsrOffs1.LongName = 'Motor Current 1 Offset';
MotCtrlMotCurrSnsrOffs1.Description = 'Motor Current 1 Offset';
MotCtrlMotCurrSnsrOffs1.DocUnits = 'Volt';
MotCtrlMotCurrSnsrOffs1.SwcShoName = 'GmG2kcaMcuCfg';
MotCtrlMotCurrSnsrOffs1.EngDT = dt.float32;
MotCtrlMotCurrSnsrOffs1.EngInit = 0;
MotCtrlMotCurrSnsrOffs1.EngMin = 0;
MotCtrlMotCurrSnsrOffs1.EngMax = 5;
MotCtrlMotCurrSnsrOffs1.TestTolerance = 0.001221001221;
MotCtrlMotCurrSnsrOffs1.WrittenIn = {'GmG2kcaMcuCfgInit2','GmG2kcaMcuCfgPer1'};
MotCtrlMotCurrSnsrOffs1.WriteType = 'NonRte';


MotCurrAdcPeakAAdcFaild = DataDict.OpSignal;
MotCurrAdcPeakAAdcFaild.LongName = 'Motor Control Motor Current/I ADC Peak A/Acceleration ADC Failed';
MotCurrAdcPeakAAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcPeakA has failed'];
MotCurrAdcPeakAAdcFaild.DocUnits = 'Cnt';
MotCurrAdcPeakAAdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
MotCurrAdcPeakAAdcFaild.EngDT = dt.lgc;
MotCurrAdcPeakAAdcFaild.EngInit = 0;
MotCurrAdcPeakAAdcFaild.EngMin = 0;
MotCurrAdcPeakAAdcFaild.EngMax = 1;
MotCurrAdcPeakAAdcFaild.TestTolerance = 0;
MotCurrAdcPeakAAdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
MotCurrAdcPeakAAdcFaild.WriteType = 'Rte';


MotCurrAdcPeakBAdcFaild = DataDict.OpSignal;
MotCurrAdcPeakBAdcFaild.LongName = 'Motor Control Motor Current/I ADC Peak B ADC Failed';
MotCurrAdcPeakBAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcPeakB has failed'];
MotCurrAdcPeakBAdcFaild.DocUnits = 'Cnt';
MotCurrAdcPeakBAdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
MotCurrAdcPeakBAdcFaild.EngDT = dt.lgc;
MotCurrAdcPeakBAdcFaild.EngInit = 0;
MotCurrAdcPeakBAdcFaild.EngMin = 0;
MotCurrAdcPeakBAdcFaild.EngMax = 1;
MotCurrAdcPeakBAdcFaild.TestTolerance = 0;
MotCurrAdcPeakBAdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
MotCurrAdcPeakBAdcFaild.WriteType = 'Rte';


MotCurrAdcPeakCAdcFaild = DataDict.OpSignal;
MotCurrAdcPeakCAdcFaild.LongName = 'Motor Control Motor Current/I ADC Peak C ADC Failed';
MotCurrAdcPeakCAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcPeakC has failed'];
MotCurrAdcPeakCAdcFaild.DocUnits = 'Cnt';
MotCurrAdcPeakCAdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
MotCurrAdcPeakCAdcFaild.EngDT = dt.lgc;
MotCurrAdcPeakCAdcFaild.EngInit = 0;
MotCurrAdcPeakCAdcFaild.EngMin = 0;
MotCurrAdcPeakCAdcFaild.EngMax = 1;
MotCurrAdcPeakCAdcFaild.TestTolerance = 0;
MotCurrAdcPeakCAdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
MotCurrAdcPeakCAdcFaild.WriteType = 'Rte';


MotCurrAdcVlyAAdcFaild = DataDict.OpSignal;
MotCurrAdcVlyAAdcFaild.LongName = 'Motor Control Motor Current/I ADC Valley A/Acceleration ADC Failed';
MotCurrAdcVlyAAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcVlyA has failed'];
MotCurrAdcVlyAAdcFaild.DocUnits = 'Cnt';
MotCurrAdcVlyAAdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
MotCurrAdcVlyAAdcFaild.EngDT = dt.lgc;
MotCurrAdcVlyAAdcFaild.EngInit = 0;
MotCurrAdcVlyAAdcFaild.EngMin = 0;
MotCurrAdcVlyAAdcFaild.EngMax = 1;
MotCurrAdcVlyAAdcFaild.TestTolerance = 0;
MotCurrAdcVlyAAdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
MotCurrAdcVlyAAdcFaild.WriteType = 'Rte';


MotCurrAdcVlyBAdcFaild = DataDict.OpSignal;
MotCurrAdcVlyBAdcFaild.LongName = 'Motor Control Motor Current/I ADC Valley B ADC Failed';
MotCurrAdcVlyBAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcVlyB has failed'];
MotCurrAdcVlyBAdcFaild.DocUnits = 'Cnt';
MotCurrAdcVlyBAdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
MotCurrAdcVlyBAdcFaild.EngDT = dt.lgc;
MotCurrAdcVlyBAdcFaild.EngInit = 0;
MotCurrAdcVlyBAdcFaild.EngMin = 0;
MotCurrAdcVlyBAdcFaild.EngMax = 1;
MotCurrAdcVlyBAdcFaild.TestTolerance = 0;
MotCurrAdcVlyBAdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
MotCurrAdcVlyBAdcFaild.WriteType = 'Rte';


MotCurrAdcVlyCAdcFaild = DataDict.OpSignal;
MotCurrAdcVlyCAdcFaild.LongName = 'Motor Control Motor Current/I ADC Valley C ADC Failed';
MotCurrAdcVlyCAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcVlyC has failed'];
MotCurrAdcVlyCAdcFaild.DocUnits = 'Cnt';
MotCurrAdcVlyCAdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
MotCurrAdcVlyCAdcFaild.EngDT = dt.lgc;
MotCurrAdcVlyCAdcFaild.EngInit = 0;
MotCurrAdcVlyCAdcFaild.EngMin = 0;
MotCurrAdcVlyCAdcFaild.EngMax = 1;
MotCurrAdcVlyCAdcFaild.TestTolerance = 0;
MotCurrAdcVlyCAdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
MotCurrAdcVlyCAdcFaild.WriteType = 'Rte';


MotCurrSnsrOffs1AdcFaild = DataDict.OpSignal;
MotCurrSnsrOffs1AdcFaild.LongName = 'Motor Control Motor Current/I Sensor Offset 1 ADC Failed';
MotCurrSnsrOffs1AdcFaild.Description = [...
  'The Adc that converts MotCurrSnsrOffs1 has failed'];
MotCurrSnsrOffs1AdcFaild.DocUnits = 'Cnt';
MotCurrSnsrOffs1AdcFaild.SwcShoName = 'GmG2kcaMcuCfg';
MotCurrSnsrOffs1AdcFaild.EngDT = dt.lgc;
MotCurrSnsrOffs1AdcFaild.EngInit = 0;
MotCurrSnsrOffs1AdcFaild.EngMin = 0;
MotCurrSnsrOffs1AdcFaild.EngMax = 1;
MotCurrSnsrOffs1AdcFaild.TestTolerance = 0;
MotCurrSnsrOffs1AdcFaild.WrittenIn = {'GmG2kcaMcuCfgPer3'};
MotCurrSnsrOffs1AdcFaild.WriteType = 'Rte';



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

%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------

%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.LongName = 'ADCD0SGVCEP2 Register';
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.Description = 'ADC0 Scan Group 2 end pointer';
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.EngDT = dt.u08;
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.EngVal = 10;
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.Define = 'Local';


ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.LongName = 'ADCD0SGVCEP3 Register';
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.Description = 'ADC0 Scan Group 3 end pointer';
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.EngDT = dt.u08;
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.EngVal = 4;
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.Define = 'Local';


ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.LongName = 'ADCD0SGVCSP2 Register';
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.Description = 'ADC0 Scan Group 2 start pointer';
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.EngDT = dt.u08;
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.EngVal = 5;
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.Define = 'Local';


ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.LongName = 'ADCD0SGVCSP3 Register';
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.Description = 'ADC0 Scan Group 3 start pointer';
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.EngDT = dt.u08;
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.EngVal = 0;
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR00_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.LongName = 'ADCD0VCR00 Register';
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.Description = 'Value of the VCR00 Register';
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.EngVal = 24580;
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR01_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.LongName = 'ADCD0VCR01 Register';
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.Description = 'Value of the VCR01 Register';
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.EngVal = 2;
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR02_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.LongName = 'ADCD0VCR02 Register';
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.Description = 'Value of the VCR00 Register';
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.EngVal = 3;
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR03_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.LongName = 'ADCD0VCR03 Register';
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.Description = 'Value of the VCR03 Register';
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.EngVal = 4;
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR04_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.LongName = 'ADCD0VCR04 Register';
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.Description = 'Value of the VCR04 Register';
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.EngVal = 24588;
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR05_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.LongName = 'ADCD0VCR05 Register';
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.Description = 'Value of the VCR05 Register';
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.EngVal = 24580;
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR06_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.LongName = 'ADCD0VCR06 Register';
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.Description = 'Value of the VCR06 Register';
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.EngVal = 2;
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR07_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.LongName = 'ADCD0VCR07 Register';
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.Description = 'Value of the VCR07 Register';
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.EngVal = 3;
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR08_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.LongName = 'ADCD0VCR08 Register';
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.Description = 'Value of the VCR08 Register';
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.EngVal = 4;
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR09_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.LongName = 'ADCD0VCR09 Register';
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.Description = 'Value of the VCR09 Register';
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.EngVal = 1;
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR10_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.LongName = 'ADCD0VCR10 Register';
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.Description = 'Value of the VCR10 Register';
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.EngVal = 24588;
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR11_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.LongName = 'ADCD0VCR11 Register';
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.Description = 'Value of the VCR11 Register';
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR12_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.LongName = 'ADCD0VCR12 Register';
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.Description = 'Value of the VCR12 Register';
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR13_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.LongName = 'ADCD0VCR13 Register';
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.Description = 'Value of the VCR13 Register';
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR14_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.LongName = 'ADCD0VCR14 Register';
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.Description = 'Value of the VCR14 Register';
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR15_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.LongName = 'ADCD0VCR15 Register';
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.Description = 'Value of the VCR15 Register';
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR16_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.LongName = 'ADCD0VCR16 Register';
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.Description = 'Value of the VCR16 Register';
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR17_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.LongName = 'ADCD0VCR17 Register';
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.Description = 'Value of the VCR17 Register';
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR18_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.LongName = 'ADCD0VCR18 Register';
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.Description = 'Value of the VCR18 Register';
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR19_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.LongName = 'ADCD0VCR19 Register';
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.Description = 'Value of the VCR19 Register';
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR20_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.LongName = 'ADCD0VCR20 Register';
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.Description = 'Value of the VCR20 Register';
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32 = DataDict.Constant;
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.LongName = 'ADC Scaling Factor';
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.Description = [...
  'ADC scaling factor to convert converted counts to volts'];
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.DocUnits = 'VoltPerCnt';
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.EngDT = dt.float32;
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.EngVal = 0.001221001221;
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.Define = 'Local';


ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.LongName = 'ADCD1SGVCEP2 Register';
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.Description = 'ADC1 Scan Group 2 end pointer';
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.EngDT = dt.u08;
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.EngVal = 6;
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.Define = 'Local';


ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.LongName = 'ADCD1SGVCEP3 Register';
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.Description = 'ADC1 Scan Group 3 end pointer';
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.EngDT = dt.u08;
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.EngVal = 3;
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.Define = 'Local';


ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.LongName = 'ADCD1SGVCSP2 Register';
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.Description = 'ADC1 Scan Group 2 start pointer';
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.EngDT = dt.u08;
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.EngVal = 4;
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.Define = 'Local';


ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.LongName = 'ADCD1SGVCSP3 Register';
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.Description = 'ADC1 Scan Group 3 start pointer';
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.EngDT = dt.u08;
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.EngVal = 0;
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR00_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.LongName = 'ADCD1VCR00 Register';
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.Description = 'Value of the VCR00 Register';
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.EngVal = 24580;
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR01_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.LongName = 'ADCD1VCR01 Register';
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.Description = 'Value of the VCR01 Register';
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.EngVal = 2;
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR02_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.LongName = 'ADCD1VCR02 Register';
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.Description = 'Value of the VCR02 Register';
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.EngVal = 9;
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR03_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.LongName = 'ADCD1VCR03 Register';
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.Description = 'Value of the VCR03 Register';
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.EngVal = 24588;
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR04_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.LongName = 'ADCD1VCR04 Register';
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.Description = 'Value of the VCR04 Register';
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.EngVal = 24580;
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR05_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.LongName = 'ADCD1VCR05 Register';
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.Description = 'Value of the VCR05 Register';
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.EngVal = 1;
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR06_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.LongName = 'ADCD1VCR06 Register';
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.Description = 'Value of the VCR06 Register';
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.EngVal = 24588;
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR07_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.LongName = 'ADCD1VCR07 Register';
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.Description = 'Value of the VCR07 Register';
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR08_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.LongName = 'ADCD1VCR08 Register';
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.Description = 'Value of the VCR08 Register';
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR09_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.LongName = 'ADCD1VCR09 Register';
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.Description = 'Value of the VCR09 Register';
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR10_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.LongName = 'ADCD1VCR10 Register';
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.Description = 'Value of the VCR10 Register';
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR11_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.LongName = 'ADCD1VCR11 Register';
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.Description = 'Value of the VCR11 Register';
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR12_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.LongName = 'ADCD1VCR12 Register';
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.Description = 'Value of the VCR12 Register';
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR13_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.LongName = 'ADCD1VCR13 Register';
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.Description = 'Value of the VCR13 Register';
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR14_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.LongName = 'ADCD1VCR14 Register';
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.Description = 'Value of the VCR14 Register';
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR15_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.LongName = 'ADCD1VCR15 Register';
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.Description = 'Value of the VCR15 Register';
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR16_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.LongName = 'ADCD1VCR16 Register';
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.Description = 'Value of the VCR16 Register';
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR17_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.LongName = 'ADCD1VCR17 Register';
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.Description = 'Value of the VCR17 Register';
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR18_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.LongName = 'ADCD1VCR18 Register';
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.Description = 'Value of the VCR18 Register';
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR19_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.LongName = 'ADCD1VCR19 Register';
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.Description = 'Value of the VCR19 Register';
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR20_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.LongName = 'ADCD1VCR20 Register';
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.Description = 'Value of the VCR20 Register';
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.Define = 'Local';


BATTVLTGSCAGFAC_ULS_F32 = DataDict.Constant;
BATTVLTGSCAGFAC_ULS_F32.LongName = 'Battery Voltage';
BATTVLTGSCAGFAC_ULS_F32.Description = [...
  'Inverse hardware scaling factor of battery voltage.  .EngVal = (20.0+3' ...
  '.48)/3.48;'];
BATTVLTGSCAGFAC_ULS_F32.DocUnits = 'Uls';
BATTVLTGSCAGFAC_ULS_F32.EngDT = dt.float32;
BATTVLTGSCAGFAC_ULS_F32.EngVal = 6.747126437;
BATTVLTGSCAGFAC_ULS_F32.Define = 'Local';


BATTVLTGSWD1SCAGFAC_ULS_F32 = DataDict.Constant;
BATTVLTGSWD1SCAGFAC_ULS_F32.LongName = 'Battery Voltage Switched 1 Scaling Factor';
BATTVLTGSWD1SCAGFAC_ULS_F32.Description = [...
  'Inverse hardware scaling factor of battery voltage switched 1.  .EngVa' ...
  'l = (100.0+42.2)/42.2;'];
BATTVLTGSWD1SCAGFAC_ULS_F32.DocUnits = 'Uls';
BATTVLTGSWD1SCAGFAC_ULS_F32.EngDT = dt.float32;
BATTVLTGSWD1SCAGFAC_ULS_F32.EngVal = 3.369668246;
BATTVLTGSWD1SCAGFAC_ULS_F32.Define = 'Local';


ELECGLBPRM_IVTRCNT_CNT_U08 = DataDict.Constant;
ELECGLBPRM_IVTRCNT_CNT_U08.LongName = 'Inverter Count';
ELECGLBPRM_IVTRCNT_CNT_U08.Description = 'Number of Inverters';
ELECGLBPRM_IVTRCNT_CNT_U08.DocUnits = 'Cnt';
ELECGLBPRM_IVTRCNT_CNT_U08.EngDT = dt.u08;
ELECGLBPRM_IVTRCNT_CNT_U08.EngVal = 1;
ELECGLBPRM_IVTRCNT_CNT_U08.Define = 'Global';


ELECGLBPRM_PWMFRQMAX_HZ_U32 = DataDict.Constant;
ELECGLBPRM_PWMFRQMAX_HZ_U32.LongName = 'Maximum PWM Frequency';
ELECGLBPRM_PWMFRQMAX_HZ_U32.Description = [...
  'High end of PWM frequency dither range'];
ELECGLBPRM_PWMFRQMAX_HZ_U32.DocUnits = 'Hz';
ELECGLBPRM_PWMFRQMAX_HZ_U32.EngDT = dt.u32;
ELECGLBPRM_PWMFRQMAX_HZ_U32.EngVal = 20000;
ELECGLBPRM_PWMFRQMAX_HZ_U32.Define = 'Global';


ELECGLBPRM_PWMFRQMIN_HZ_U32 = DataDict.Constant;
ELECGLBPRM_PWMFRQMIN_HZ_U32.LongName = 'Minimum PWM Frequency';
ELECGLBPRM_PWMFRQMIN_HZ_U32.Description = [...
  'High end of PWM frequency dither range'];
ELECGLBPRM_PWMFRQMIN_HZ_U32.DocUnits = 'Hz';
ELECGLBPRM_PWMFRQMIN_HZ_U32.EngDT = dt.u32;
ELECGLBPRM_PWMFRQMIN_HZ_U32.EngVal = 16000;
ELECGLBPRM_PWMFRQMIN_HZ_U32.Define = 'Global';


ELECGLBPRM_PWMPERDMAX_NANOSEC_U32 = DataDict.Constant;
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.LongName = 'Maximum PWM Period';
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.Description = [...
  'Maximum PWM period in units of NanoSec.  ELECGLBPRM_PWMPERDMAX_NANOSEC' ...
  '_U32.EngVal = 1e9/ELECGLBPRM_PWMFRQMIN_HZ_U32.EngVal.  EngMin = 1e9/22' ...
  'e3, EngMax = 1e9/14e3'];
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.DocUnits = 'NanoSec';
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.EngDT = dt.u32;
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.EngVal = 62500;
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.Define = 'Global';


ELECGLBPRM_PWMPERDMIN_NANOSEC_U32 = DataDict.Constant;
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.LongName = 'Minimum PWM Period';
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.Description = [...
  'Minimum PWM period in units of NanoSec.  ELECGLBPRM_PWMPERDMIN_NANOSEC' ...
  '_U32.EngVal = 1e9/ELECGLBPRM_PWMFRQMAX_HZ_U32.EngVal.  EngMin = 1e9/22' ...
  'e3, EngMax = 1e9/14e3'];
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.DocUnits = 'NanoSec';
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.EngDT = dt.u32;
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.EngVal = 50000;
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.Define = 'Global';


ELECGLBPRM_PWMPERDNOMX2_SEC_F32 = DataDict.Constant;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.LongName = 'PWM Period Nominal Times 2';
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.Description = [...
  'This constant is 2 times ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9 in second' ...
  's.'];
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.DocUnits = 'Sec';
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.EngDT = dt.float32;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.EngVal = 0.000125;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.Define = 'Global';


ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9 = DataDict.Constant;
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.LongName = 'Nominal PWM Period';
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.Description = [...
  'Nominal PWM Period in units of MicroSec.  ELECGLBPRM_PWMPERDNOM_MICROS' ...
  'EC_U7P9 = (2 * 1e6)/(ELECGLBPRM_PWMFRQMAX_HZ_U32.EngVal + ELECGLBPRM_P' ...
  'WMFRQMIN_HZ_U32.EngVal).  EngMin = 1e6/22e3, EngMax = 1e6/14e3'];
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.DocUnits = 'MicroSec';
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.EngDT = dt.u7p9;
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.EngVal = 55.55555;
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.Define = 'Global';


HWAG0IFNTCNR_ULS_U16 = DataDict.Constant;
HWAG0IFNTCNR_ULS_U16.LongName = 'Handwheel Angle 0 Interface Ntc Number';
HWAG0IFNTCNR_ULS_U16.Description = 'HwAg0 Interface Ntc Number';
HWAG0IFNTCNR_ULS_U16.DocUnits = 'Uls';
HWAG0IFNTCNR_ULS_U16.EngDT = enum.NtcNr1;
HWAG0IFNTCNR_ULS_U16.EngVal = NtcNr1.NTCNR_0X094;
HWAG0IFNTCNR_ULS_U16.Define = 'Local';


HWAG0MFGNTCNR_ULS_U16 = DataDict.Constant;
HWAG0MFGNTCNR_ULS_U16.LongName = 'Handwheel Angle 0 Manufacturing Ntc Number';
HWAG0MFGNTCNR_ULS_U16.Description = 'HwAg0 Manufacturing Ntc Number';
HWAG0MFGNTCNR_ULS_U16.DocUnits = 'Uls';
HWAG0MFGNTCNR_ULS_U16.EngDT = enum.NtcNr1;
HWAG0MFGNTCNR_ULS_U16.EngVal = NtcNr1.NTCNR_0X1F9;
HWAG0MFGNTCNR_ULS_U16.Define = 'Local';


HWAG0SNSR0PRTCLNTCNR_ULS_U16 = DataDict.Constant;
HWAG0SNSR0PRTCLNTCNR_ULS_U16.LongName = 'Handwheel Angle 0 Sensor 0 Ntc Number';
HWAG0SNSR0PRTCLNTCNR_ULS_U16.Description = 'HwAg0 Sensor 0 Ntc Number';
HWAG0SNSR0PRTCLNTCNR_ULS_U16.DocUnits = 'Uls';
HWAG0SNSR0PRTCLNTCNR_ULS_U16.EngDT = enum.NtcNr1;
HWAG0SNSR0PRTCLNTCNR_ULS_U16.EngVal = NtcNr1.NTCNR_0X093;
HWAG0SNSR0PRTCLNTCNR_ULS_U16.Define = 'Local';


HWAG0SNSR1PRTCLNTCNR_ULS_U16 = DataDict.Constant;
HWAG0SNSR1PRTCLNTCNR_ULS_U16.LongName = 'Handwheel Angle 0 Sensor 1 Ntc Number';
HWAG0SNSR1PRTCLNTCNR_ULS_U16.Description = 'HwAg0 Sensor 1 Ntc Number';
HWAG0SNSR1PRTCLNTCNR_ULS_U16.DocUnits = 'Uls';
HWAG0SNSR1PRTCLNTCNR_ULS_U16.EngDT = enum.NtcNr1;
HWAG0SNSR1PRTCLNTCNR_ULS_U16.EngVal = NtcNr1.NTCNR_0X095;
HWAG0SNSR1PRTCLNTCNR_ULS_U16.Define = 'Local';


HWTQ0MEAS_HWTQ0MFGNTCNR_ULS_U16 = DataDict.Constant;
HWTQ0MEAS_HWTQ0MFGNTCNR_ULS_U16.LongName = 'Handwheel Torque 0 Manufacturing Ntc Number';
HWTQ0MEAS_HWTQ0MFGNTCNR_ULS_U16.Description = 'HwTq0 Manufacturing Ntc Number';
HWTQ0MEAS_HWTQ0MFGNTCNR_ULS_U16.DocUnits = 'Uls';
HWTQ0MEAS_HWTQ0MFGNTCNR_ULS_U16.EngDT = enum.NtcNr1;
HWTQ0MEAS_HWTQ0MFGNTCNR_ULS_U16.EngVal = NtcNr1.NTCNR_0X1E0;
HWTQ0MEAS_HWTQ0MFGNTCNR_ULS_U16.Define = 'Global';


HWTQ0MEAS_HWTQ0PRTCLNTCNR_ULS_U16 = DataDict.Constant;
HWTQ0MEAS_HWTQ0PRTCLNTCNR_ULS_U16.LongName = 'Handwheel Torque 0 Ntc Number';
HWTQ0MEAS_HWTQ0PRTCLNTCNR_ULS_U16.Description = 'HwTq0 Ntc Number';
HWTQ0MEAS_HWTQ0PRTCLNTCNR_ULS_U16.DocUnits = 'Uls';
HWTQ0MEAS_HWTQ0PRTCLNTCNR_ULS_U16.EngDT = enum.NtcNr1;
HWTQ0MEAS_HWTQ0PRTCLNTCNR_ULS_U16.EngVal = NtcNr1.NTCNR_0X073;
HWTQ0MEAS_HWTQ0PRTCLNTCNR_ULS_U16.Define = 'Global';


HWTQ1MEAS_HWTQ1MFGNTCNR_ULS_U16 = DataDict.Constant;
HWTQ1MEAS_HWTQ1MFGNTCNR_ULS_U16.LongName = 'Handwheel Torque 1 Manufacturing Ntc Number';
HWTQ1MEAS_HWTQ1MFGNTCNR_ULS_U16.Description = 'HwTq1 Manufacturing Ntc Number';
HWTQ1MEAS_HWTQ1MFGNTCNR_ULS_U16.DocUnits = 'Uls';
HWTQ1MEAS_HWTQ1MFGNTCNR_ULS_U16.EngDT = enum.NtcNr1;
HWTQ1MEAS_HWTQ1MFGNTCNR_ULS_U16.EngVal = NtcNr1.NTCNR_0X1E1;
HWTQ1MEAS_HWTQ1MFGNTCNR_ULS_U16.Define = 'Global';


HWTQ1MEAS_HWTQ1PRTCLNTCNR_ULS_U16 = DataDict.Constant;
HWTQ1MEAS_HWTQ1PRTCLNTCNR_ULS_U16.LongName = 'Handwheel Torque 1 Ntc Number';
HWTQ1MEAS_HWTQ1PRTCLNTCNR_ULS_U16.Description = 'HwTq1 Ntc Number';
HWTQ1MEAS_HWTQ1PRTCLNTCNR_ULS_U16.DocUnits = 'Uls';
HWTQ1MEAS_HWTQ1PRTCLNTCNR_ULS_U16.EngDT = enum.NtcNr1;
HWTQ1MEAS_HWTQ1PRTCLNTCNR_ULS_U16.EngVal = NtcNr1.NTCNR_0X075;
HWTQ1MEAS_HWTQ1PRTCLNTCNR_ULS_U16.Define = 'Global';


MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM = DataDict.Constant;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.LongName = 'Motor Angle 0 Protocol Fault NTC Number';
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.Description = [...
  'Motor Angle 0 Protocol Fault NTC Number'];
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.DocUnits = 'Cnt';
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X083;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.Define = 'Global';


MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM = DataDict.Constant;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.LongName = 'Motor Angle 1 Protocol Fault NTC Number';
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.Description = [...
  'Motor Angle 1 Protocol Fault NTC Number'];
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.DocUnits = 'Cnt';
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X085;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.Define = 'Global';


TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32 = DataDict.Constant;
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.LongName = 'XCP Vehicle Speed Threshold';
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.Description = [...
  'Vehicle Speed is compared with XCP Vehicle speed threshold to determin' ...
  'e whether to grant or deny requested change in corresponding RAM value' ...
  's.'];
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.DocUnits = 'Kph';
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.EngDT = dt.float32;
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.EngVal = 1;
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.Define = 'Global';



%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
%end of Data Dictionary
