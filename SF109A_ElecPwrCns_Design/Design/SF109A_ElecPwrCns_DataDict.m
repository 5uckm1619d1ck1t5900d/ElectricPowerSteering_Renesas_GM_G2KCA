%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 16-May-2016 17:09:38       %
%                                  Created with tool release: 2.39.0     %
%                                  Synergy file: %version: X %           %
%                                  Derived by: %derived_by: X %          %
%%-----------------------------------------------------------------------%

SF109A = DataDict.FDD;
SF109A.Version = '1.1.X';
SF109A.LongName = 'Electric Power Consumption';
SF109A.ShoName  = 'ElecPwrCns';
SF109A.DesignASIL = 'QM';
SF109A.Description = [...
  'This function estimates the instantaneous electric power and supply cu' ...
  'rrent at the input of the control module for the purpose of transmitti' ...
  'ng this information over the serial communication bus'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
ElecPwrCnsPer1 = DataDict.Runnable;
ElecPwrCnsPer1.Context = 'Rte';
ElecPwrCnsPer1.TimeStep = 0.01;
ElecPwrCnsPer1.Description = [...
  '10 Millisecond periodic for Electric Power Consumption'];


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------

%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
BrdgVltg = DataDict.IpSignal;
BrdgVltg.LongName = 'Bridge Voltage';
BrdgVltg.Description = 'Output Bridge Voltage';
BrdgVltg.DocUnits = 'Volt';
BrdgVltg.EngDT = dt.float32;
BrdgVltg.EngInit = 6;
BrdgVltg.EngMin = 6;
BrdgVltg.EngMax = 26.5;
BrdgVltg.ReadIn = {};
BrdgVltg.ReadType = 'Rte';


CurrMeasLoaMtgtnEna = DataDict.IpSignal;
CurrMeasLoaMtgtnEna.LongName = 'Motor Current LOA Mitigation Enable';
CurrMeasLoaMtgtnEna.Description = [...
  'Flag from LoaMgr that, when true, tells other functions to enable loss' ...
  ' of assist mitigation.'];
CurrMeasLoaMtgtnEna.DocUnits = 'Cnt';
CurrMeasLoaMtgtnEna.EngDT = dt.lgc;
CurrMeasLoaMtgtnEna.EngInit = 0;
CurrMeasLoaMtgtnEna.EngMin = 0;
CurrMeasLoaMtgtnEna.EngMax = 1;
CurrMeasLoaMtgtnEna.ReadIn = {};
CurrMeasLoaMtgtnEna.ReadType = 'Rte';


IvtrLoaMtgtnEna = DataDict.IpSignal;
IvtrLoaMtgtnEna.LongName = 'Inverter LOA Mitigation Enable';
IvtrLoaMtgtnEna.Description = [...
  'Flag from LoaMgr that, when true, tells other functions to enable loss' ...
  ' of assist mitigation.'];
IvtrLoaMtgtnEna.DocUnits = 'Cnt';
IvtrLoaMtgtnEna.EngDT = dt.lgc;
IvtrLoaMtgtnEna.EngInit = 0;
IvtrLoaMtgtnEna.EngMin = 0;
IvtrLoaMtgtnEna.EngMax = 1;
IvtrLoaMtgtnEna.ReadIn = {};
IvtrLoaMtgtnEna.ReadType = 'Rte';


MotCtrlMotCurrDax = DataDict.IpSignal;
MotCtrlMotCurrDax.LongName = 'Motor D-Axis Measured Current';
MotCtrlMotCurrDax.Description = 'Motor Current D-Axis Current';
MotCtrlMotCurrDax.DocUnits = 'Ampr';
MotCtrlMotCurrDax.EngDT = dt.float32;
MotCtrlMotCurrDax.EngInit = 0;
MotCtrlMotCurrDax.EngMin = -200;
MotCtrlMotCurrDax.EngMax = 200;
MotCtrlMotCurrDax.ReadIn = {};
MotCtrlMotCurrDax.ReadType = 'Rte';


MotCtrlMotCurrQax = DataDict.IpSignal;
MotCtrlMotCurrQax.LongName = 'Motor Q-Axis Measured Current';
MotCtrlMotCurrQax.Description = 'Motor Current Q-Axis Current';
MotCtrlMotCurrQax.DocUnits = 'Ampr';
MotCtrlMotCurrQax.EngDT = dt.float32;
MotCtrlMotCurrQax.EngInit = 0;
MotCtrlMotCurrQax.EngMin = -200;
MotCtrlMotCurrQax.EngMax = 200;
MotCtrlMotCurrQax.ReadIn = {};
MotCtrlMotCurrQax.ReadType = 'Rte';


MotCtrlMotVltgDax = DataDict.IpSignal;
MotCtrlMotVltgDax.LongName = 'Motor D-Axis Voltage';
MotCtrlMotVltgDax.Description = 'D Axis Motor Voltage';
MotCtrlMotVltgDax.DocUnits = 'Volt';
MotCtrlMotVltgDax.EngDT = dt.float32;
MotCtrlMotVltgDax.EngInit = 0;
MotCtrlMotVltgDax.EngMin = -26.5;
MotCtrlMotVltgDax.EngMax = 26.5;
MotCtrlMotVltgDax.ReadIn = {};
MotCtrlMotVltgDax.ReadType = 'Rte';


MotCtrlMotVltgQax = DataDict.IpSignal;
MotCtrlMotVltgQax.LongName = 'Motor Q-Axis Voltage';
MotCtrlMotVltgQax.Description = 'Q Axis Motor Voltage';
MotCtrlMotVltgQax.DocUnits = 'Volt';
MotCtrlMotVltgQax.EngDT = dt.float32;
MotCtrlMotVltgQax.EngInit = 0;
MotCtrlMotVltgQax.EngMin = -26.5;
MotCtrlMotVltgQax.EngMax = 26.5;
MotCtrlMotVltgQax.ReadIn = {};
MotCtrlMotVltgQax.ReadType = 'Rte';


MotCurrDaxCmd = DataDict.IpSignal;
MotCurrDaxCmd.LongName = 'Motor Current D-Axis Reference';
MotCurrDaxCmd.Description = [...
  'D-Axis Reference (commanded or expected value)'];
MotCurrDaxCmd.DocUnits = 'Ampr';
MotCurrDaxCmd.EngDT = dt.float32;
MotCurrDaxCmd.EngInit = 0;
MotCurrDaxCmd.EngMin = 0;
MotCurrDaxCmd.EngMax = 200;
MotCurrDaxCmd.ReadIn = {};
MotCurrDaxCmd.ReadType = 'Rte';


MotCurrQaxCmd = DataDict.IpSignal;
MotCurrQaxCmd.LongName = 'Motor Current Q-Axis Reference';
MotCurrQaxCmd.Description = 'Motor Current Q-Axis Reference';
MotCurrQaxCmd.DocUnits = 'Ampr';
MotCurrQaxCmd.EngDT = dt.float32;
MotCurrQaxCmd.EngInit = 0;
MotCurrQaxCmd.EngMin = -200;
MotCurrQaxCmd.EngMax = 200;
MotCurrQaxCmd.ReadIn = {};
MotCurrQaxCmd.ReadType = 'Rte';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
ElecInpPwrEstim = DataDict.OpSignal;
ElecInpPwrEstim.LongName = 'Electric Input Power Estimate';
ElecInpPwrEstim.Description = [...
  'Final value of Electrical Input Power in Watts'];
ElecInpPwrEstim.DocUnits = 'Watt';
ElecInpPwrEstim.SwcShoName = 'ElecPwrCns';
ElecInpPwrEstim.EngDT = dt.float32;
ElecInpPwrEstim.EngInit = 0;
ElecInpPwrEstim.EngMin = -2000;
ElecInpPwrEstim.EngMax = 2000;
ElecInpPwrEstim.TestTolerance = 0;
ElecInpPwrEstim.WrittenIn = {};
ElecInpPwrEstim.WriteType = 'Rte';


SplyCurrEstim = DataDict.OpSignal;
SplyCurrEstim.LongName = 'Supply Current Estimate';
SplyCurrEstim.Description = [...
  'Supply current estimate calculated from  value of electrical input pow' ...
  'er'];
SplyCurrEstim.DocUnits = 'Ampr';
SplyCurrEstim.SwcShoName = 'ElecPwrCns';
SplyCurrEstim.EngDT = dt.float32;
SplyCurrEstim.EngInit = 0;
SplyCurrEstim.EngMin = -200;
SplyCurrEstim.EngMax = 200;
SplyCurrEstim.TestTolerance = 0;
SplyCurrEstim.WrittenIn = {};
SplyCurrEstim.WriteType = 'Rte';



%%-------------------------------------------
%% Inter-Runnable Variable Definition        
%%-------------------------------------------

%%-------------------------------------------
%% Calibrations Definition                   
%%-------------------------------------------
ElecPwrCnsCtrlrInpR = DataDict.Calibration;
ElecPwrCnsCtrlrInpR.LongName = 'Controller Input Resistance';
ElecPwrCnsCtrlrInpR.Description = [...
  'Control Module Input Resistance Value'];
ElecPwrCnsCtrlrInpR.DocUnits = 'Ohm';
ElecPwrCnsCtrlrInpR.EngDT = dt.float32;
ElecPwrCnsCtrlrInpR.EngVal = 0.0005;
ElecPwrCnsCtrlrInpR.EngMin = 0;
ElecPwrCnsCtrlrInpR.EngMax = 0.02;
ElecPwrCnsCtrlrInpR.Cardinality = 'Cmn';
ElecPwrCnsCtrlrInpR.CustomerVisible = false;
ElecPwrCnsCtrlrInpR.Online = false;
ElecPwrCnsCtrlrInpR.Impact = 'H';
ElecPwrCnsCtrlrInpR.TuningOwner = 'TqCtrl';
ElecPwrCnsCtrlrInpR.GraphLink = {''};
ElecPwrCnsCtrlrInpR.Monotony = 'None';
ElecPwrCnsCtrlrInpR.MaxGrad = 998;
ElecPwrCnsCtrlrInpR.PortName = 'ElecPwrCnsCtrlrInpR';


ElecPwrCnsPrstcPwrLoss = DataDict.Calibration;
ElecPwrCnsPrstcPwrLoss.LongName = 'Parasitic Power Loss';
ElecPwrCnsPrstcPwrLoss.Description = 'Parasitic power loss of controller';
ElecPwrCnsPrstcPwrLoss.DocUnits = 'Watt';
ElecPwrCnsPrstcPwrLoss.EngDT = dt.float32;
ElecPwrCnsPrstcPwrLoss.EngVal = 10;
ElecPwrCnsPrstcPwrLoss.EngMin = 0;
ElecPwrCnsPrstcPwrLoss.EngMax = 25;
ElecPwrCnsPrstcPwrLoss.Cardinality = 'Cmn';
ElecPwrCnsPrstcPwrLoss.CustomerVisible = false;
ElecPwrCnsPrstcPwrLoss.Online = true;
ElecPwrCnsPrstcPwrLoss.Impact = 'H';
ElecPwrCnsPrstcPwrLoss.TuningOwner = 'TqCtrl';
ElecPwrCnsPrstcPwrLoss.GraphLink = {''};
ElecPwrCnsPrstcPwrLoss.Monotony = 'None';
ElecPwrCnsPrstcPwrLoss.MaxGrad = 998;
ElecPwrCnsPrstcPwrLoss.PortName = 'ElecPwrCnsPrstcPwrLoss';



%%-------------------------------------------
%% Imported Calibrations Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Non-Volatile Memory Definition            
%%-------------------------------------------

%%-------------------------------------------
%% Display Variable Definition               
%%-------------------------------------------
dElecPwrCnsDrpInpPwr = DataDict.Display;
dElecPwrCnsDrpInpPwr.LongName = 'Power Drop';
dElecPwrCnsDrpInpPwr.Description = [...
  'Represents Power Drop across Input Resistance'];
dElecPwrCnsDrpInpPwr.DocUnits = 'Watt';
dElecPwrCnsDrpInpPwr.EngDT = dt.float32;
dElecPwrCnsDrpInpPwr.EngMin = -2000;
dElecPwrCnsDrpInpPwr.EngMax = 2000;
dElecPwrCnsDrpInpPwr.InitRowCol = [1  1];


dElecPwrCnsModInpPwr = DataDict.Display;
dElecPwrCnsModInpPwr.LongName = 'Modulator Input Power';
dElecPwrCnsModInpPwr.Description = 'Modulator Input Power';
dElecPwrCnsModInpPwr.DocUnits = 'Watt';
dElecPwrCnsModInpPwr.EngDT = dt.float32;
dElecPwrCnsModInpPwr.EngMin = -2000;
dElecPwrCnsModInpPwr.EngMax = 2000;
dElecPwrCnsModInpPwr.InitRowCol = [1  1];


dElecPwrCnsMotCurrDaxEstim = DataDict.Display;
dElecPwrCnsMotCurrDaxEstim.LongName = 'Motor Dax Current Estimate';
dElecPwrCnsMotCurrDaxEstim.Description = 'Estimate Of Motor Dax Current';
dElecPwrCnsMotCurrDaxEstim.DocUnits = 'Ampr';
dElecPwrCnsMotCurrDaxEstim.EngDT = dt.float32;
dElecPwrCnsMotCurrDaxEstim.EngMin = -200;
dElecPwrCnsMotCurrDaxEstim.EngMax = 200;
dElecPwrCnsMotCurrDaxEstim.InitRowCol = [1  1];


dElecPwrCnsMotCurrQaxEstim = DataDict.Display;
dElecPwrCnsMotCurrQaxEstim.LongName = 'Motor Qax Current Estimate';
dElecPwrCnsMotCurrQaxEstim.Description = 'Estimate Of Motor Qax Current';
dElecPwrCnsMotCurrQaxEstim.DocUnits = 'Ampr';
dElecPwrCnsMotCurrQaxEstim.EngDT = dt.float32;
dElecPwrCnsMotCurrQaxEstim.EngMin = -200;
dElecPwrCnsMotCurrQaxEstim.EngMax = 200;
dElecPwrCnsMotCurrQaxEstim.InitRowCol = [1  1];



%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------

%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
ARCHGLBPRM_HALFSQRT3_ULS_F32 = DataDict.Constant;
ARCHGLBPRM_HALFSQRT3_ULS_F32.LongName = 'Half Square Root of 3';
ARCHGLBPRM_HALFSQRT3_ULS_F32.Description = '(Square root of 3) divided by 2';
ARCHGLBPRM_HALFSQRT3_ULS_F32.DocUnits = 'Uls';
ARCHGLBPRM_HALFSQRT3_ULS_F32.EngDT = dt.float32;
ARCHGLBPRM_HALFSQRT3_ULS_F32.EngVal = 0.8660254;
ARCHGLBPRM_HALFSQRT3_ULS_F32.Define = 'Global';


ELECINPPWRESTIMHILIM_WATT_F32 = DataDict.Constant;
ELECINPPWRESTIMHILIM_WATT_F32.LongName = 'Electric Power High Limit';
ELECINPPWRESTIMHILIM_WATT_F32.Description = [...
  'Maximum Value of the Electric Power at the output limiter'];
ELECINPPWRESTIMHILIM_WATT_F32.DocUnits = 'Watt';
ELECINPPWRESTIMHILIM_WATT_F32.EngDT = dt.float32;
ELECINPPWRESTIMHILIM_WATT_F32.EngVal = 2000;
ELECINPPWRESTIMHILIM_WATT_F32.Define = 'Local';


ELECINPPWRESTIMLOLIM_WATT_F32 = DataDict.Constant;
ELECINPPWRESTIMLOLIM_WATT_F32.LongName = 'Electric Power Low Limit';
ELECINPPWRESTIMLOLIM_WATT_F32.Description = [...
  'Minimum Value of the Electric Power at the output limiter'];
ELECINPPWRESTIMLOLIM_WATT_F32.DocUnits = 'Watt';
ELECINPPWRESTIMLOLIM_WATT_F32.EngDT = dt.float32;
ELECINPPWRESTIMLOLIM_WATT_F32.EngVal = -2000;
ELECINPPWRESTIMLOLIM_WATT_F32.Define = 'Local';


SPLYCURRESTIMHILIM_AMPR_F32 = DataDict.Constant;
SPLYCURRESTIMHILIM_AMPR_F32.LongName = 'Supply Current High Limit';
SPLYCURRESTIMHILIM_AMPR_F32.Description = [...
  'Maximum Value of the supply current at the output limiter'];
SPLYCURRESTIMHILIM_AMPR_F32.DocUnits = 'Ampr';
SPLYCURRESTIMHILIM_AMPR_F32.EngDT = dt.float32;
SPLYCURRESTIMHILIM_AMPR_F32.EngVal = 200;
SPLYCURRESTIMHILIM_AMPR_F32.Define = 'Local';


SPLYCURRESTIMLOLIM_AMPR_F32 = DataDict.Constant;
SPLYCURRESTIMLOLIM_AMPR_F32.LongName = 'Supply Current Low Limit';
SPLYCURRESTIMLOLIM_AMPR_F32.Description = [...
  'Minimum Value of the supply current at the output limiter'];
SPLYCURRESTIMLOLIM_AMPR_F32.DocUnits = 'Ampr';
SPLYCURRESTIMLOLIM_AMPR_F32.EngDT = dt.float32;
SPLYCURRESTIMLOLIM_AMPR_F32.EngVal = -200;
SPLYCURRESTIMLOLIM_AMPR_F32.Define = 'Local';



%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
%end of Data Dictionary
