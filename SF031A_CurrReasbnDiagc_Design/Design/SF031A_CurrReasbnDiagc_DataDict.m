%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 19-Dec-2016 11:07:57       %
%                                  Created with tool release: 2.51.0     %
%                                  Synergy file: %version: X %           %
%                                  Derived by: %derived_by: X %          %
%%-----------------------------------------------------------------------%

SF031A = DataDict.FDD;
SF031A.Version = '1.1.X';
SF031A.LongName = 'Current Reasonableness Diagnostic';
SF031A.ShoName  = 'CurrReasbnDiagc';
SF031A.DesignASIL = 'D';
SF031A.Description = [...
  'Current Reasonableness Diagnostic is intended to detect offset errors ' ...
  'in current feedback'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
CurrReasbnDiagcInit1 = DataDict.Runnable;
CurrReasbnDiagcInit1.Context = 'NonRte';
CurrReasbnDiagcInit1.TimeStep = 'MotorControlx2';
CurrReasbnDiagcInit1.Description = [...
  'Initialization periodic for Current Reasonableness Diagnostic'];

CurrReasbnDiagcInit2 = DataDict.Runnable;
CurrReasbnDiagcInit2.Context = 'Rte';
CurrReasbnDiagcInit2.TimeStep = 0;
CurrReasbnDiagcInit2.Description = [...
  'Initialization periodic for Current Reasonableness Diagnostic'];

CurrReasbnDiagcPer1 = DataDict.Runnable;
CurrReasbnDiagcPer1.Context = 'NonRte';
CurrReasbnDiagcPer1.TimeStep = 'MotorControlx2';
CurrReasbnDiagcPer1.Description = [...
  'Twice of Motor Control ISR Periodic for Current Reasonableness Diagnos' ...
  'tic'];

CurrReasbnDiagcPer2 = DataDict.Runnable;
CurrReasbnDiagcPer2.Context = 'Rte';
CurrReasbnDiagcPer2.TimeStep = 0.002;
CurrReasbnDiagcPer2.Description = [...
  'Runs every 2mSec for Current Reasonableness Diagnostic'];


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------

%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
MotAgElec = DataDict.IpSignal;
MotAgElec.LongName = 'Motor Control Motor Angle Electric';
MotAgElec.Description = [...
  'Motor angle corrected for Back EMF.'];
MotAgElec.DocUnits = 'MotRevElec';
MotAgElec.EngDT = dt.u0p16;
MotAgElec.EngInit = 0;
MotAgElec.EngMin = 0;
MotAgElec.EngMax = 0.9999847412;
MotAgElec.ReadIn = {'CurrReasbnDiagcPer2'};
MotAgElec.ReadType = 'Rte';


MotCtrlMotVltgDax = DataDict.IpSignal;
MotCtrlMotVltgDax.LongName = 'Motor Control Motor Voltage Dax';
MotCtrlMotVltgDax.Description = 'D Axis Motor Voltage';
MotCtrlMotVltgDax.DocUnits = 'Volt';
MotCtrlMotVltgDax.EngDT = dt.float32;
MotCtrlMotVltgDax.EngInit = 0;
MotCtrlMotVltgDax.EngMin = -26.5;
MotCtrlMotVltgDax.EngMax = 26.5;
MotCtrlMotVltgDax.ReadIn = {'CurrReasbnDiagcPer1'};
MotCtrlMotVltgDax.ReadType = 'NonRte';


MotCtrlMotVltgQax = DataDict.IpSignal;
MotCtrlMotVltgQax.LongName = 'Motor Control Motor Voltage Qax';
MotCtrlMotVltgQax.Description = 'Q Axis Motor Voltage';
MotCtrlMotVltgQax.DocUnits = 'Volt';
MotCtrlMotVltgQax.EngDT = dt.float32;
MotCtrlMotVltgQax.EngInit = 0;
MotCtrlMotVltgQax.EngMin = -26.5;
MotCtrlMotVltgQax.EngMax = 26.5;
MotCtrlMotVltgQax.ReadIn = {'CurrReasbnDiagcPer1'};
MotCtrlMotVltgQax.ReadType = 'NonRte';


MotTqCmdLimrMin = DataDict.IpSignal;
MotTqCmdLimrMin.LongName = 'Motor Torque Command Limiter Minimum';
MotTqCmdLimrMin.Description = [...
  'The overall minimum of limits applied by EOT Limit, Veh Spd Limit, Sta' ...
  'll Limit and Thermal Limit'];
MotTqCmdLimrMin.DocUnits = 'MotNwtMtr';
MotTqCmdLimrMin.EngDT = dt.float32;
MotTqCmdLimrMin.EngInit = 0;
MotTqCmdLimrMin.EngMin = 0;
MotTqCmdLimrMin.EngMax = 8.8;
MotTqCmdLimrMin.ReadIn = {'CurrReasbnDiagcPer2'};
MotTqCmdLimrMin.ReadType = 'Rte';


MotVelMrf = DataDict.IpSignal;
MotVelMrf.LongName = 'Motor Velocity in Motor Reference Frame';
MotVelMrf.Description = [...
  'Motor velocity with polarity as seen by motor shaft.'];
MotVelMrf.DocUnits = 'MotRadPerSec';
MotVelMrf.EngDT = dt.float32;
MotVelMrf.EngInit = 0;
MotVelMrf.EngMin = -1350;
MotVelMrf.EngMax = 1350;
MotVelMrf.ReadIn = {'CurrReasbnDiagcPer2'};
MotVelMrf.ReadType = 'Rte';


MotVltgDaxFfStat = DataDict.IpSignal;
MotVltgDaxFfStat.LongName = 'Motor D-Axis Static Feedforward Voltage';
MotVltgDaxFfStat.Description = [...
  'Motor D-Axis Static Feedforward Voltage'];
MotVltgDaxFfStat.DocUnits = 'Volt';
MotVltgDaxFfStat.EngDT = dt.float32;
MotVltgDaxFfStat.EngInit = 0;
MotVltgDaxFfStat.EngMin = -26.5;
MotVltgDaxFfStat.EngMax = 26.5;
MotVltgDaxFfStat.ReadIn = {'CurrReasbnDiagcPer2'};
MotVltgDaxFfStat.ReadType = 'Rte';


MotVltgDaxFild = DataDict.IpSignal;
MotVltgDaxFild.LongName = 'Motor Control Motor Voltage Dax';
MotVltgDaxFild.Description = 'D Axis Motor Voltage';
MotVltgDaxFild.DocUnits = 'Volt';
MotVltgDaxFild.EngDT = dt.float32;
MotVltgDaxFild.EngInit = 0;
MotVltgDaxFild.EngMin = -26.5;
MotVltgDaxFild.EngMax = 26.5;
MotVltgDaxFild.ReadIn = {'CurrReasbnDiagcPer2'};
MotVltgDaxFild.ReadType = 'Rte';


MotVltgQaxFfStat = DataDict.IpSignal;
MotVltgQaxFfStat.LongName = 'Motor Q-Axis Static Feedforward Voltage';
MotVltgQaxFfStat.Description = [...
  'Motor Q-Axis Static Feedforward Voltage'];
MotVltgQaxFfStat.DocUnits = 'Volt';
MotVltgQaxFfStat.EngDT = dt.float32;
MotVltgQaxFfStat.EngInit = 0;
MotVltgQaxFfStat.EngMin = -26.5;
MotVltgQaxFfStat.EngMax = 26.5;
MotVltgQaxFfStat.ReadIn = {'CurrReasbnDiagcPer2'};
MotVltgQaxFfStat.ReadType = 'Rte';


MotVltgQaxFild = DataDict.IpSignal;
MotVltgQaxFild.LongName = 'Motor Control Motor Voltage Dax';
MotVltgQaxFild.Description = 'D Axis Motor Voltage';
MotVltgQaxFild.DocUnits = 'Volt';
MotVltgQaxFild.EngDT = dt.float32;
MotVltgQaxFild.EngInit = 0;
MotVltgQaxFild.EngMin = -26.5;
MotVltgQaxFild.EngMax = 26.5;
MotVltgQaxFild.ReadIn = {'CurrReasbnDiagcPer2'};
MotVltgQaxFild.ReadType = 'Rte';


SysMotTqCmdSca = DataDict.IpSignal;
SysMotTqCmdSca.LongName = 'System Motor Torque Command Scale';
SysMotTqCmdSca.Description = 'System Motor Torque Command Scale';
SysMotTqCmdSca.DocUnits = 'Uls';
SysMotTqCmdSca.EngDT = dt.float32;
SysMotTqCmdSca.EngInit = 1;
SysMotTqCmdSca.EngMin = 0;
SysMotTqCmdSca.EngMax = 1;
SysMotTqCmdSca.ReadIn = {'CurrReasbnDiagcPer2'};
SysMotTqCmdSca.ReadType = 'Rte';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
MotCtrlMotVltgDaxFild = DataDict.OpSignal;
MotCtrlMotVltgDaxFild.LongName = 'Motor Control Motor Voltage Dax Filtered';
MotCtrlMotVltgDaxFild.Description = 'Filtered Dax Voltage';
MotCtrlMotVltgDaxFild.DocUnits = 'Volt';
MotCtrlMotVltgDaxFild.SwcShoName = 'CurrReasbnDiagc';
MotCtrlMotVltgDaxFild.EngDT = dt.float32;
MotCtrlMotVltgDaxFild.EngInit = 0;
MotCtrlMotVltgDaxFild.EngMin = -26.5;
MotCtrlMotVltgDaxFild.EngMax = 26.5;
MotCtrlMotVltgDaxFild.TestTolerance = 0;
MotCtrlMotVltgDaxFild.WrittenIn = {'CurrReasbnDiagcPer1'};
MotCtrlMotVltgDaxFild.WriteType = 'NonRte';


MotCtrlMotVltgQaxFild = DataDict.OpSignal;
MotCtrlMotVltgQaxFild.LongName = 'Motor Control Motor Voltage Qax Filtered';
MotCtrlMotVltgQaxFild.Description = 'Filtered Qax Voltage';
MotCtrlMotVltgQaxFild.DocUnits = 'Volt';
MotCtrlMotVltgQaxFild.SwcShoName = 'CurrReasbnDiagc';
MotCtrlMotVltgQaxFild.EngDT = dt.float32;
MotCtrlMotVltgQaxFild.EngInit = 0;
MotCtrlMotVltgQaxFild.EngMin = -26.5;
MotCtrlMotVltgQaxFild.EngMax = 26.5;
MotCtrlMotVltgQaxFild.TestTolerance = 0;
MotCtrlMotVltgQaxFild.WrittenIn = {'CurrReasbnDiagcPer1'};
MotCtrlMotVltgQaxFild.WriteType = 'NonRte';



%%-------------------------------------------
%% Inter-Runnable Variable Definition        
%%-------------------------------------------

%%-------------------------------------------
%% Calibrations Definition                   
%%-------------------------------------------
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax = DataDict.Calibration;
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.LongName = 'Current Diagnostic Motor Envelope Table Maximum';
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.Description = 'Maximum of Motor Envelope Table';
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.DocUnits = 'MotNwtMtr';
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.EngDT = dt.float32;
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.EngVal = 4.6;
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.EngMin = 1;
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.EngMax = 8.8;
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.Cardinality = 'Cmn';
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.CustomerVisible = false;
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.Online = false;
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.Impact = 'H';
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.TuningOwner = 'Safety';
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.GraphLink = {''};
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.Monotony = 'None';
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.MaxGrad = Inf;
CurrReasbnDiagcCurrDiagcMotEnvlpTblMax.PortName = 'CurrReasbnDiagcCurrDiagcMotEnvlpTblMax';


CurrReasbnDiagcCurrDiagcPrimErrThd = DataDict.Calibration;
CurrReasbnDiagcCurrDiagcPrimErrThd.LongName = 'Cuurent Diagnostic Primary Error Threshold';
CurrReasbnDiagcCurrDiagcPrimErrThd.Description = [...
  'Threshold value to which Alpha and Beta voltages are compared'];
CurrReasbnDiagcCurrDiagcPrimErrThd.DocUnits = 'Volt';
CurrReasbnDiagcCurrDiagcPrimErrThd.EngDT = dt.float32;
CurrReasbnDiagcCurrDiagcPrimErrThd.EngVal = 20;
CurrReasbnDiagcCurrDiagcPrimErrThd.EngMin = 0;
CurrReasbnDiagcCurrDiagcPrimErrThd.EngMax = 250;
CurrReasbnDiagcCurrDiagcPrimErrThd.Cardinality = 'Cmn';
CurrReasbnDiagcCurrDiagcPrimErrThd.CustomerVisible = false;
CurrReasbnDiagcCurrDiagcPrimErrThd.Online = false;
CurrReasbnDiagcCurrDiagcPrimErrThd.Impact = 'H';
CurrReasbnDiagcCurrDiagcPrimErrThd.TuningOwner = 'Safety';
CurrReasbnDiagcCurrDiagcPrimErrThd.GraphLink = {''};
CurrReasbnDiagcCurrDiagcPrimErrThd.Monotony = 'None';
CurrReasbnDiagcCurrDiagcPrimErrThd.MaxGrad = Inf;
CurrReasbnDiagcCurrDiagcPrimErrThd.PortName = 'CurrReasbnDiagcCurrDiagcPrimErrThd';


CurrReasbnDiagcCurrDiagcSecdryErrThd = DataDict.Calibration;
CurrReasbnDiagcCurrDiagcSecdryErrThd.LongName = 'Current Diagnostic Secondary Error Threshold';
CurrReasbnDiagcCurrDiagcSecdryErrThd.Description = [...
  'Threshold value to which Alpha and Beta voltages are compared'];
CurrReasbnDiagcCurrDiagcSecdryErrThd.DocUnits = 'Volt';
CurrReasbnDiagcCurrDiagcSecdryErrThd.EngDT = dt.float32;
CurrReasbnDiagcCurrDiagcSecdryErrThd.EngVal = 20;
CurrReasbnDiagcCurrDiagcSecdryErrThd.EngMin = 0;
CurrReasbnDiagcCurrDiagcSecdryErrThd.EngMax = 250;
CurrReasbnDiagcCurrDiagcSecdryErrThd.Cardinality = 'Cmn';
CurrReasbnDiagcCurrDiagcSecdryErrThd.CustomerVisible = false;
CurrReasbnDiagcCurrDiagcSecdryErrThd.Online = false;
CurrReasbnDiagcCurrDiagcSecdryErrThd.Impact = 'H';
CurrReasbnDiagcCurrDiagcSecdryErrThd.TuningOwner = 'Safety';
CurrReasbnDiagcCurrDiagcSecdryErrThd.GraphLink = {''};
CurrReasbnDiagcCurrDiagcSecdryErrThd.Monotony = 'None';
CurrReasbnDiagcCurrDiagcSecdryErrThd.MaxGrad = Inf;
CurrReasbnDiagcCurrDiagcSecdryErrThd.PortName = 'CurrReasbnDiagcCurrDiagcSecdryErrThd';


CurrReasbnDiagcCurrDiagcSecdryTqLimThd = DataDict.Calibration;
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.LongName = 'Current Diagnostic Secondary Torque Limited Threshold';
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.Description = [...
  'Threshold value for which the secondary portion of the diagnostic is a' ...
  'ctive compared to scaled output limits'];
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.DocUnits = 'Uls';
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.EngDT = dt.float32;
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.EngVal = 0;
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.EngMin = 0;
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.EngMax = 1;
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.Cardinality = 'Cmn';
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.CustomerVisible = false;
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.Online = false;
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.Impact = 'H';
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.TuningOwner = 'Safety';
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.GraphLink = {''};
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.Monotony = 'None';
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.MaxGrad = Inf;
CurrReasbnDiagcCurrDiagcSecdryTqLimThd.PortName = 'CurrReasbnDiagcCurrDiagcSecdryTqLimThd';


CurrReasbnDiagcDiagFildLim = DataDict.Calibration;
CurrReasbnDiagcDiagFildLim.LongName = 'Current Reasonableness Diagnostic Filtered Limit';
CurrReasbnDiagcDiagFildLim.Description = [...
  'Saturation Limits For Motor Voltage Diagnostic Filtered Input'];
CurrReasbnDiagcDiagFildLim.DocUnits = 'Volt';
CurrReasbnDiagcDiagFildLim.EngDT = dt.float32;
CurrReasbnDiagcDiagFildLim.EngVal = 10;
CurrReasbnDiagcDiagFildLim.EngMin = 0;
CurrReasbnDiagcDiagFildLim.EngMax = 20;
CurrReasbnDiagcDiagFildLim.Cardinality = 'Cmn';
CurrReasbnDiagcDiagFildLim.CustomerVisible = false;
CurrReasbnDiagcDiagFildLim.Online = false;
CurrReasbnDiagcDiagFildLim.Impact = 'H';
CurrReasbnDiagcDiagFildLim.TuningOwner = 'Safety';
CurrReasbnDiagcDiagFildLim.GraphLink = {''};
CurrReasbnDiagcDiagFildLim.Monotony = 'None';
CurrReasbnDiagcDiagFildLim.MaxGrad = Inf;
CurrReasbnDiagcDiagFildLim.PortName = 'CurrReasbnDiagcDiagFildLim';


CurrReasbnDiagcDiagVltgLpFilEna = DataDict.Calibration;
CurrReasbnDiagcDiagVltgLpFilEna.LongName = 'Cuurent Reaonableness Diagnostic Voltage Filter Enable';
CurrReasbnDiagcDiagVltgLpFilEna.Description = 'Diagnostic Voltage Filter Enable';
CurrReasbnDiagcDiagVltgLpFilEna.DocUnits = 'Cnt';
CurrReasbnDiagcDiagVltgLpFilEna.EngDT = dt.lgc;
CurrReasbnDiagcDiagVltgLpFilEna.EngVal = 1;
CurrReasbnDiagcDiagVltgLpFilEna.EngMin = 0;
CurrReasbnDiagcDiagVltgLpFilEna.EngMax = 1;
CurrReasbnDiagcDiagVltgLpFilEna.Cardinality = 'Cmn';
CurrReasbnDiagcDiagVltgLpFilEna.CustomerVisible = false;
CurrReasbnDiagcDiagVltgLpFilEna.Online = false;
CurrReasbnDiagcDiagVltgLpFilEna.Impact = 'H';
CurrReasbnDiagcDiagVltgLpFilEna.TuningOwner = 'Safety';
CurrReasbnDiagcDiagVltgLpFilEna.GraphLink = {''};
CurrReasbnDiagcDiagVltgLpFilEna.Monotony = 'None';
CurrReasbnDiagcDiagVltgLpFilEna.MaxGrad = Inf;
CurrReasbnDiagcDiagVltgLpFilEna.PortName = 'CurrReasbnDiagcDiagVltgLpFilEna';


CurrReasbnDiagcDiagVltgLpFilFrq = DataDict.Calibration;
CurrReasbnDiagcDiagVltgLpFilFrq.LongName = 'Current Reasonableness Diagnostic Voltage Filter Cut off Frequency';
CurrReasbnDiagcDiagVltgLpFilFrq.Description = [...
  'Cutoff frequency for Diagnostic Voltage Filter.'];
CurrReasbnDiagcDiagVltgLpFilFrq.DocUnits = 'Hz';
CurrReasbnDiagcDiagVltgLpFilFrq.EngDT = dt.float32;
CurrReasbnDiagcDiagVltgLpFilFrq.EngVal = 5;
CurrReasbnDiagcDiagVltgLpFilFrq.EngMin = 0;
CurrReasbnDiagcDiagVltgLpFilFrq.EngMax = 250;
CurrReasbnDiagcDiagVltgLpFilFrq.Cardinality = 'Cmn';
CurrReasbnDiagcDiagVltgLpFilFrq.CustomerVisible = false;
CurrReasbnDiagcDiagVltgLpFilFrq.Online = false;
CurrReasbnDiagcDiagVltgLpFilFrq.Impact = 'H';
CurrReasbnDiagcDiagVltgLpFilFrq.TuningOwner = 'Safety';
CurrReasbnDiagcDiagVltgLpFilFrq.GraphLink = {''};
CurrReasbnDiagcDiagVltgLpFilFrq.Monotony = 'None';
CurrReasbnDiagcDiagVltgLpFilFrq.MaxGrad = 0;
CurrReasbnDiagcDiagVltgLpFilFrq.PortName = 'CurrReasbnDiagcDiagVltgLpFilFrq';


CurrReasbnDiagcLpFilSca = DataDict.Calibration;
CurrReasbnDiagcLpFilSca.LongName = 'Current Reasonableness Low pass Filter Scaled';
CurrReasbnDiagcLpFilSca.Description = 'Scaling Factor of Input';
CurrReasbnDiagcLpFilSca.DocUnits = 'Uls';
CurrReasbnDiagcLpFilSca.EngDT = dt.float32;
CurrReasbnDiagcLpFilSca.EngVal = 0.5;
CurrReasbnDiagcLpFilSca.EngMin = 0.001953125;
CurrReasbnDiagcLpFilSca.EngMax = 100;
CurrReasbnDiagcLpFilSca.Cardinality = 'Cmn';
CurrReasbnDiagcLpFilSca.CustomerVisible = false;
CurrReasbnDiagcLpFilSca.Online = false;
CurrReasbnDiagcLpFilSca.Impact = 'H';
CurrReasbnDiagcLpFilSca.TuningOwner = 'Safety';
CurrReasbnDiagcLpFilSca.GraphLink = {''};
CurrReasbnDiagcLpFilSca.Monotony = 'None';
CurrReasbnDiagcLpFilSca.MaxGrad = Inf;
CurrReasbnDiagcLpFilSca.PortName = 'CurrReasbnDiagcLpFilSca';


CurrReasbnDiagcMotVelHiLim = DataDict.Calibration;
CurrReasbnDiagcMotVelHiLim.LongName = 'Current Reasonableness Motor Velocity High Limit';
CurrReasbnDiagcMotVelHiLim.Description = 'Upper Limit of Motor Velocity';
CurrReasbnDiagcMotVelHiLim.DocUnits = 'MotRadPerSec';
CurrReasbnDiagcMotVelHiLim.EngDT = dt.float32;
CurrReasbnDiagcMotVelHiLim.EngVal = 1350;
CurrReasbnDiagcMotVelHiLim.EngMin = 0.03125;
CurrReasbnDiagcMotVelHiLim.EngMax = 1350;
CurrReasbnDiagcMotVelHiLim.Cardinality = 'Cmn';
CurrReasbnDiagcMotVelHiLim.CustomerVisible = false;
CurrReasbnDiagcMotVelHiLim.Online = false;
CurrReasbnDiagcMotVelHiLim.Impact = 'H';
CurrReasbnDiagcMotVelHiLim.TuningOwner = 'Safety';
CurrReasbnDiagcMotVelHiLim.GraphLink = {''};
CurrReasbnDiagcMotVelHiLim.Monotony = 'None';
CurrReasbnDiagcMotVelHiLim.MaxGrad = Inf;
CurrReasbnDiagcMotVelHiLim.PortName = 'CurrReasbnDiagcMotVelHiLim';


CurrReasbnDiagcMotVelLoLim = DataDict.Calibration;
CurrReasbnDiagcMotVelLoLim.LongName = 'Current Reasonableness Motor Velocity Low Limit';
CurrReasbnDiagcMotVelLoLim.Description = 'Lower Limit of Motor Velocity';
CurrReasbnDiagcMotVelLoLim.DocUnits = 'MotRadPerSec';
CurrReasbnDiagcMotVelLoLim.EngDT = dt.float32;
CurrReasbnDiagcMotVelLoLim.EngVal = 1;
CurrReasbnDiagcMotVelLoLim.EngMin = 0.03125;
CurrReasbnDiagcMotVelLoLim.EngMax = 1350;
CurrReasbnDiagcMotVelLoLim.Cardinality = 'Cmn';
CurrReasbnDiagcMotVelLoLim.CustomerVisible = false;
CurrReasbnDiagcMotVelLoLim.Online = false;
CurrReasbnDiagcMotVelLoLim.Impact = 'H';
CurrReasbnDiagcMotVelLoLim.TuningOwner = 'Safety';
CurrReasbnDiagcMotVelLoLim.GraphLink = {''};
CurrReasbnDiagcMotVelLoLim.Monotony = 'None';
CurrReasbnDiagcMotVelLoLim.MaxGrad = 0;
CurrReasbnDiagcMotVelLoLim.PortName = 'CurrReasbnDiagcMotVelLoLim';


CurrReasbnDiagcMotVltgDaxLpFilFrq = DataDict.Calibration;
CurrReasbnDiagcMotVltgDaxLpFilFrq.LongName = 'Motor Voltage Dax Lowpass Filter Frequency';
CurrReasbnDiagcMotVltgDaxLpFilFrq.Description = [...
  'Cutoff frequency for Dax voltage filter'];
CurrReasbnDiagcMotVltgDaxLpFilFrq.DocUnits = 'Hz';
CurrReasbnDiagcMotVltgDaxLpFilFrq.EngDT = dt.float32;
CurrReasbnDiagcMotVltgDaxLpFilFrq.EngVal = 250;
CurrReasbnDiagcMotVltgDaxLpFilFrq.EngMin = 0;
CurrReasbnDiagcMotVltgDaxLpFilFrq.EngMax = 250;
CurrReasbnDiagcMotVltgDaxLpFilFrq.Cardinality = 'Cmn';
CurrReasbnDiagcMotVltgDaxLpFilFrq.CustomerVisible = false;
CurrReasbnDiagcMotVltgDaxLpFilFrq.Online = false;
CurrReasbnDiagcMotVltgDaxLpFilFrq.Impact = 'H';
CurrReasbnDiagcMotVltgDaxLpFilFrq.TuningOwner = 'Safety';
CurrReasbnDiagcMotVltgDaxLpFilFrq.GraphLink = {''};
CurrReasbnDiagcMotVltgDaxLpFilFrq.Monotony = 'None';
CurrReasbnDiagcMotVltgDaxLpFilFrq.MaxGrad = 0;
CurrReasbnDiagcMotVltgDaxLpFilFrq.PortName = 'CurrReasbnDiagcMotVltgDaxLpFilFrq';


CurrReasbnDiagcMotVltgQaxDaxFilEna = DataDict.Calibration;
CurrReasbnDiagcMotVltgQaxDaxFilEna.LongName = 'Motor Voltage Qax and Motor Voltage Dax Filter Enable';
CurrReasbnDiagcMotVltgQaxDaxFilEna.Description = [...
  'Calibration to enable anti-aliasing filter.'];
CurrReasbnDiagcMotVltgQaxDaxFilEna.DocUnits = 'Cnt';
CurrReasbnDiagcMotVltgQaxDaxFilEna.EngDT = dt.lgc;
CurrReasbnDiagcMotVltgQaxDaxFilEna.EngVal = 1;
CurrReasbnDiagcMotVltgQaxDaxFilEna.EngMin = 0;
CurrReasbnDiagcMotVltgQaxDaxFilEna.EngMax = 1;
CurrReasbnDiagcMotVltgQaxDaxFilEna.Cardinality = 'Cmn';
CurrReasbnDiagcMotVltgQaxDaxFilEna.CustomerVisible = false;
CurrReasbnDiagcMotVltgQaxDaxFilEna.Online = false;
CurrReasbnDiagcMotVltgQaxDaxFilEna.Impact = 'H';
CurrReasbnDiagcMotVltgQaxDaxFilEna.TuningOwner = 'Safety';
CurrReasbnDiagcMotVltgQaxDaxFilEna.GraphLink = {''};
CurrReasbnDiagcMotVltgQaxDaxFilEna.Monotony = 'None';
CurrReasbnDiagcMotVltgQaxDaxFilEna.MaxGrad = 0;
CurrReasbnDiagcMotVltgQaxDaxFilEna.PortName = 'CurrReasbnDiagcMotVltgQaxDaxFilEna';


CurrReasbnDiagcMotVltgQaxLpFilFrq = DataDict.Calibration;
CurrReasbnDiagcMotVltgQaxLpFilFrq.LongName = 'Motor Voltage Qax Lowpass Filter Frequency';
CurrReasbnDiagcMotVltgQaxLpFilFrq.Description = [...
  'Cutoff frequency for Qax voltage filter.'];
CurrReasbnDiagcMotVltgQaxLpFilFrq.DocUnits = 'Hz';
CurrReasbnDiagcMotVltgQaxLpFilFrq.EngDT = dt.float32;
CurrReasbnDiagcMotVltgQaxLpFilFrq.EngVal = 250;
CurrReasbnDiagcMotVltgQaxLpFilFrq.EngMin = 0;
CurrReasbnDiagcMotVltgQaxLpFilFrq.EngMax = 250;
CurrReasbnDiagcMotVltgQaxLpFilFrq.Cardinality = 'Cmn';
CurrReasbnDiagcMotVltgQaxLpFilFrq.CustomerVisible = false;
CurrReasbnDiagcMotVltgQaxLpFilFrq.Online = false;
CurrReasbnDiagcMotVltgQaxLpFilFrq.Impact = 'H';
CurrReasbnDiagcMotVltgQaxLpFilFrq.TuningOwner = 'Safety';
CurrReasbnDiagcMotVltgQaxLpFilFrq.GraphLink = {''};
CurrReasbnDiagcMotVltgQaxLpFilFrq.Monotony = 'None';
CurrReasbnDiagcMotVltgQaxLpFilFrq.MaxGrad = 0;
CurrReasbnDiagcMotVltgQaxLpFilFrq.PortName = 'CurrReasbnDiagcMotVltgQaxLpFilFrq';


CurrReasbnDiagcVelLpFilEna = DataDict.Calibration;
CurrReasbnDiagcVelLpFilEna.LongName = 'Current Reasonableness Velocity Filter Enable';
CurrReasbnDiagcVelLpFilEna.Description = [...
  'Calibration to enable velocity filter.'];
CurrReasbnDiagcVelLpFilEna.DocUnits = 'Cnt';
CurrReasbnDiagcVelLpFilEna.EngDT = dt.lgc;
CurrReasbnDiagcVelLpFilEna.EngVal = 1;
CurrReasbnDiagcVelLpFilEna.EngMin = 0;
CurrReasbnDiagcVelLpFilEna.EngMax = 1;
CurrReasbnDiagcVelLpFilEna.Cardinality = 'Cmn';
CurrReasbnDiagcVelLpFilEna.CustomerVisible = false;
CurrReasbnDiagcVelLpFilEna.Online = false;
CurrReasbnDiagcVelLpFilEna.Impact = 'H';
CurrReasbnDiagcVelLpFilEna.TuningOwner = 'Safety';
CurrReasbnDiagcVelLpFilEna.GraphLink = {''};
CurrReasbnDiagcVelLpFilEna.Monotony = 'None';
CurrReasbnDiagcVelLpFilEna.MaxGrad = 0;
CurrReasbnDiagcVelLpFilEna.PortName = 'CurrReasbnDiagcVelLpFilEna';


CurrReasbnDiagcVelLpFilFrq = DataDict.Calibration;
CurrReasbnDiagcVelLpFilFrq.LongName = 'Current Reasonableness Velocity Filter Cut off Frequency';
CurrReasbnDiagcVelLpFilFrq.Description = [...
  'Cutoff frequency for Velocity Filter.'];
CurrReasbnDiagcVelLpFilFrq.DocUnits = 'Hz';
CurrReasbnDiagcVelLpFilFrq.EngDT = dt.float32;
CurrReasbnDiagcVelLpFilFrq.EngVal = 125;
CurrReasbnDiagcVelLpFilFrq.EngMin = 0;
CurrReasbnDiagcVelLpFilFrq.EngMax = 250;
CurrReasbnDiagcVelLpFilFrq.Cardinality = 'Cmn';
CurrReasbnDiagcVelLpFilFrq.CustomerVisible = false;
CurrReasbnDiagcVelLpFilFrq.Online = false;
CurrReasbnDiagcVelLpFilFrq.Impact = 'H';
CurrReasbnDiagcVelLpFilFrq.TuningOwner = 'Safety';
CurrReasbnDiagcVelLpFilFrq.GraphLink = {''};
CurrReasbnDiagcVelLpFilFrq.Monotony = 'None';
CurrReasbnDiagcVelLpFilFrq.MaxGrad = 0;
CurrReasbnDiagcVelLpFilFrq.PortName = 'CurrReasbnDiagcVelLpFilFrq';



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
SysGlbPrmMotPoleCnt.Description = '';



%%-------------------------------------------
%% Non-Volatile Memory Definition            
%%-------------------------------------------

%%-------------------------------------------
%% Display Variable Definition               
%%-------------------------------------------
dCurrReasbnDiagcMotVltgAFild = DataDict.Display;
dCurrReasbnDiagcMotVltgAFild.LongName = 'Current Reasonableness Motor Voltage Alpha Filtered';
dCurrReasbnDiagcMotVltgAFild.Description = 'Motor Voltage Filtered Alpha';
dCurrReasbnDiagcMotVltgAFild.DocUnits = 'Volt';
dCurrReasbnDiagcMotVltgAFild.EngDT = dt.float32;
dCurrReasbnDiagcMotVltgAFild.EngMin = -26.5;
dCurrReasbnDiagcMotVltgAFild.EngMax = 26.5;
dCurrReasbnDiagcMotVltgAFild.InitRowCol = [1  1];


dCurrReasbnDiagcMotVltgBFild = DataDict.Display;
dCurrReasbnDiagcMotVltgBFild.LongName = 'Current Reasonableness Motor Voltage Beta Filtered';
dCurrReasbnDiagcMotVltgBFild.Description = 'Motor Voltage Filtered Beta';
dCurrReasbnDiagcMotVltgBFild.DocUnits = 'Volt';
dCurrReasbnDiagcMotVltgBFild.EngDT = dt.float32;
dCurrReasbnDiagcMotVltgBFild.EngMin = -26.5;
dCurrReasbnDiagcMotVltgBFild.EngMax = 26.5;
dCurrReasbnDiagcMotVltgBFild.InitRowCol = [1  1];


dCurrReasbnDiagcMotVltgDaxDif = DataDict.Display;
dCurrReasbnDiagcMotVltgDaxDif.LongName = 'Current Reasonableness Motor Voltage Dax Difference';
dCurrReasbnDiagcMotVltgDaxDif.Description = [...
  'Difference of Dax Filtered and Feedforward Voltages'];
dCurrReasbnDiagcMotVltgDaxDif.DocUnits = 'Volt';
dCurrReasbnDiagcMotVltgDaxDif.EngDT = dt.float32;
dCurrReasbnDiagcMotVltgDaxDif.EngMin = -26.5;
dCurrReasbnDiagcMotVltgDaxDif.EngMax = 26.5;
dCurrReasbnDiagcMotVltgDaxDif.InitRowCol = [1  1];


dCurrReasbnDiagcMotVltgDiagFild = DataDict.Display;
dCurrReasbnDiagcMotVltgDiagFild.LongName = 'Current Reasonableness Motor Voltage Daignostic Filtered';
dCurrReasbnDiagcMotVltgDiagFild.Description = 'Diagnostic Voltage';
dCurrReasbnDiagcMotVltgDiagFild.DocUnits = 'Volt';
dCurrReasbnDiagcMotVltgDiagFild.EngDT = dt.float32;
dCurrReasbnDiagcMotVltgDiagFild.EngMin = -26.5;
dCurrReasbnDiagcMotVltgDiagFild.EngMax = 26.5;
dCurrReasbnDiagcMotVltgDiagFild.InitRowCol = [1  1];


dCurrReasbnDiagcMotVltgDiagFildLimd = DataDict.Display;
dCurrReasbnDiagcMotVltgDiagFildLimd.LongName = 'Current Reasonableness Motor Voltage Daignostic Filtered Limited';
dCurrReasbnDiagcMotVltgDiagFildLimd.Description = 'Limited Diagnostic Voltage';
dCurrReasbnDiagcMotVltgDiagFildLimd.DocUnits = 'Volt';
dCurrReasbnDiagcMotVltgDiagFildLimd.EngDT = dt.float32;
dCurrReasbnDiagcMotVltgDiagFildLimd.EngMin = -26.5;
dCurrReasbnDiagcMotVltgDiagFildLimd.EngMax = 26.5;
dCurrReasbnDiagcMotVltgDiagFildLimd.InitRowCol = [1  1];


dCurrReasbnDiagcMotVltgDiagSecdryFild = DataDict.Display;
dCurrReasbnDiagcMotVltgDiagSecdryFild.LongName = 'Current Reasonableness Motor Voltage Daignostic Secondary Filtered';
dCurrReasbnDiagcMotVltgDiagSecdryFild.Description = [...
  'Conditional Filter Diagnositc Voltage.'];
dCurrReasbnDiagcMotVltgDiagSecdryFild.DocUnits = 'Volt';
dCurrReasbnDiagcMotVltgDiagSecdryFild.EngDT = dt.float32;
dCurrReasbnDiagcMotVltgDiagSecdryFild.EngMin = -26.5;
dCurrReasbnDiagcMotVltgDiagSecdryFild.EngMax = 26.5;
dCurrReasbnDiagcMotVltgDiagSecdryFild.InitRowCol = [1  1];


dCurrReasbnDiagcMotVltgQaxDif = DataDict.Display;
dCurrReasbnDiagcMotVltgQaxDif.LongName = 'Current Reasonableness Motor Voltage Qax Difference';
dCurrReasbnDiagcMotVltgQaxDif.Description = [...
  'Difference of Qax Filtered and Feedforward Voltages'];
dCurrReasbnDiagcMotVltgQaxDif.DocUnits = 'Volt';
dCurrReasbnDiagcMotVltgQaxDif.EngDT = dt.float32;
dCurrReasbnDiagcMotVltgQaxDif.EngMin = -26.5;
dCurrReasbnDiagcMotVltgQaxDif.EngMax = 26.5;
dCurrReasbnDiagcMotVltgQaxDif.InitRowCol = [1  1];


dCurrReasbnDiagcVelLpFild = DataDict.Display;
dCurrReasbnDiagcVelLpFild.LongName = 'Current Reasonableness Velocity Low Pass Filtered';
dCurrReasbnDiagcVelLpFild.Description = 'Motor Velocity Filtered';
dCurrReasbnDiagcVelLpFild.DocUnits = 'MotRadPerSec';
dCurrReasbnDiagcVelLpFild.EngDT = dt.float32;
dCurrReasbnDiagcVelLpFild.EngMin = 0;
dCurrReasbnDiagcVelLpFild.EngMax = 1350;
dCurrReasbnDiagcVelLpFild.InitRowCol = [1  1];



%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------
CurrReasbnMotVelLpFil = DataDict.PIM;
CurrReasbnMotVelLpFil.LongName = 'Current Reasonableness Diagnostic Motor Velocity Lowpass Filter';
CurrReasbnMotVelLpFil.Description = [...
  'Current Reasonableness Diagnostic Motor Velocity Lowpass Filter'];
CurrReasbnMotVelLpFil.DocUnits = 'Cnt';
CurrReasbnMotVelLpFil.EngDT = struct.FilLpRec1;
CurrReasbnMotVelLpFil.EngMin = [struct('FilSt',-3.402823466e+38,'FilGain',0)];
CurrReasbnMotVelLpFil.EngMax = [struct('FilSt',3.402823466e+38,'FilGain',3.402823466e+38)];
CurrReasbnMotVelLpFil.InitRowCol = [1  1];


DiagVltgLpFil = DataDict.PIM;
DiagVltgLpFil.LongName = 'Diagnostic Voltage Low Pass Filter';
DiagVltgLpFil.Description = [...
  'Filter structure for the Diagnostic Voltage.'];
DiagVltgLpFil.DocUnits = 'Cnt';
DiagVltgLpFil.EngDT = struct.FilLpRec1;
DiagVltgLpFil.EngMin = [struct('FilSt',-3.402823466e+38,'FilGain',0)];
DiagVltgLpFil.EngMax = [struct('FilSt',3.402823466e+38,'FilGain',3.402823466e+38)];
DiagVltgLpFil.InitRowCol = [1  1];


MotVltgDaxLpFil = DataDict.PIM;
MotVltgDaxLpFil.LongName = 'Motor Voltage Daxis Low Pass Filter';
MotVltgDaxLpFil.Description = [...
  'Filter structure for the Dax Motor Voltage'];
MotVltgDaxLpFil.DocUnits = 'Cnt';
MotVltgDaxLpFil.EngDT = struct.FilLpRec1;
MotVltgDaxLpFil.EngMin = [struct('FilSt',-3.402823466e+38,'FilGain',0)];
MotVltgDaxLpFil.EngMax = [struct('FilSt',3.402823466e+38,'FilGain',3.402823466e+38)];
MotVltgDaxLpFil.InitRowCol = [1  1];


MotVltgDiagFildInp1Prev = DataDict.PIM;
MotVltgDiagFildInp1Prev.LongName = 'Previous Motor Diagnostic Filtered Input 1';
MotVltgDiagFildInp1Prev.Description = [...
  'Previous value of Input for Motor Diagnostic Voltage.'];
MotVltgDiagFildInp1Prev.DocUnits = 'Volt';
MotVltgDiagFildInp1Prev.EngDT = dt.float32;
MotVltgDiagFildInp1Prev.EngMin = -26.5;
MotVltgDiagFildInp1Prev.EngMax = 26.5;
MotVltgDiagFildInp1Prev.InitRowCol = [1  1];


MotVltgDiagFildInp2Prev = DataDict.PIM;
MotVltgDiagFildInp2Prev.LongName = 'Previous Motor Diagnostic Filtered Input 2';
MotVltgDiagFildInp2Prev.Description = [...
  'Previous value of Input for Motor Diagnostic Voltage.'];
MotVltgDiagFildInp2Prev.DocUnits = 'Volt';
MotVltgDiagFildInp2Prev.EngDT = dt.float32;
MotVltgDiagFildInp2Prev.EngMin = -26.5;
MotVltgDiagFildInp2Prev.EngMax = 26.5;
MotVltgDiagFildInp2Prev.InitRowCol = [1  1];


MotVltgDiagFildOutp1Prev = DataDict.PIM;
MotVltgDiagFildOutp1Prev.LongName = 'Previous Motor Diagnostic Filtered Output 1';
MotVltgDiagFildOutp1Prev.Description = [...
  'Previous value of Output for Motor Diagnostic Voltage.'];
MotVltgDiagFildOutp1Prev.DocUnits = 'Volt';
MotVltgDiagFildOutp1Prev.EngDT = dt.float32;
MotVltgDiagFildOutp1Prev.EngMin = -26.5;
MotVltgDiagFildOutp1Prev.EngMax = 26.5;
MotVltgDiagFildOutp1Prev.InitRowCol = [1  1];


MotVltgDiagFildOutp2Prev = DataDict.PIM;
MotVltgDiagFildOutp2Prev.LongName = 'Previous Motor Diagnostic Filtered Output 2';
MotVltgDiagFildOutp2Prev.Description = [...
  'Previous value of Output for Motor Diagnostic Voltage.'];
MotVltgDiagFildOutp2Prev.DocUnits = 'Volt';
MotVltgDiagFildOutp2Prev.EngDT = dt.float32;
MotVltgDiagFildOutp2Prev.EngMin = -26.5;
MotVltgDiagFildOutp2Prev.EngMax = 26.5;
MotVltgDiagFildOutp2Prev.InitRowCol = [1  1];


MotVltgQaxLpFil = DataDict.PIM;
MotVltgQaxLpFil.LongName = 'Motor Voltage Qaxis Low Pass Filter';
MotVltgQaxLpFil.Description = [...
  'Filter structure for the Dax Motor Voltage.'];
MotVltgQaxLpFil.DocUnits = 'Cnt';
MotVltgQaxLpFil.EngDT = struct.FilLpRec1;
MotVltgQaxLpFil.EngMin = [struct('FilSt',-3.402823466e+38,'FilGain',0)];
MotVltgQaxLpFil.EngMax = [struct('FilSt',3.402823466e+38,'FilGain',3.402823466e+38)];
MotVltgQaxLpFil.InitRowCol = [1  1];



%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
ARCHGLBPRM_2MILLISEC_SEC_F32 = DataDict.Constant;
ARCHGLBPRM_2MILLISEC_SEC_F32.LongName = '2 Milliseconds';
ARCHGLBPRM_2MILLISEC_SEC_F32.Description = '2ms periodic loop time step';
ARCHGLBPRM_2MILLISEC_SEC_F32.DocUnits = 'Sec';
ARCHGLBPRM_2MILLISEC_SEC_F32.EngDT = dt.float32;
ARCHGLBPRM_2MILLISEC_SEC_F32.EngVal = 0.002;
ARCHGLBPRM_2MILLISEC_SEC_F32.Define = 'Global';


ARCHGLBPRM_2PI_ULS_F32 = DataDict.Constant;
ARCHGLBPRM_2PI_ULS_F32.LongName = 'Two Times Pi';
ARCHGLBPRM_2PI_ULS_F32.Description = '2 times the value of Pi';
ARCHGLBPRM_2PI_ULS_F32.DocUnits = 'Uls';
ARCHGLBPRM_2PI_ULS_F32.EngDT = dt.float32;
ARCHGLBPRM_2PI_ULS_F32.EngVal = 6.2831853;
ARCHGLBPRM_2PI_ULS_F32.Define = 'Global';


ELECGLBPRM_PWMPERDNOMX2_SEC_F32 = DataDict.ConfigParam;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.LongName = 'Motor Control ISR Period Times 2';
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.Description = [...
  'This constant is 2 times ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9 in second' ...
  's.'];
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.IsBuildPrm = false;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.DocUnits = 'Sec';
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.EngDT = dt.float32;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.EngVal = 0.000125;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.EngMin = 9.09090909e-05;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.EngMax = 0.0001428571429;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.Define = 'Global';


MOTVLTGFILDDQAXHILIM_VOLT_F32 = DataDict.Constant;
MOTVLTGFILDDQAXHILIM_VOLT_F32.LongName = 'D-Axis & Q-Axis Motor Voltage High Limit';
MOTVLTGFILDDQAXHILIM_VOLT_F32.Description = [...
  'D-Axis & Q-Axis Motor Voltage High Limit'];
MOTVLTGFILDDQAXHILIM_VOLT_F32.DocUnits = 'Volt';
MOTVLTGFILDDQAXHILIM_VOLT_F32.EngDT = dt.float32;
MOTVLTGFILDDQAXHILIM_VOLT_F32.EngVal = 26.5;
MOTVLTGFILDDQAXHILIM_VOLT_F32.Define = 'Local';


MOTVLTGFILDDQAXLOLIM_VOLT_F32 = DataDict.Constant;
MOTVLTGFILDDQAXLOLIM_VOLT_F32.LongName = 'D-Axis & Q-Axis Motor Voltage Low Limit';
MOTVLTGFILDDQAXLOLIM_VOLT_F32.Description = [...
  'D-Axis & Q-Axis Motor Voltage Low Limit'];
MOTVLTGFILDDQAXLOLIM_VOLT_F32.DocUnits = 'Volt';
MOTVLTGFILDDQAXLOLIM_VOLT_F32.EngDT = dt.float32;
MOTVLTGFILDDQAXLOLIM_VOLT_F32.EngVal = -26.5;
MOTVLTGFILDDQAXLOLIM_VOLT_F32.Define = 'Local';


NODEBSTEP_CNT_U16 = DataDict.Constant;
NODEBSTEP_CNT_U16.LongName = 'No De-Bounce Step';
NODEBSTEP_CNT_U16.Description = [...
  'Step used when No debouncing is required'];
NODEBSTEP_CNT_U16.DocUnits = 'Cnt';
NODEBSTEP_CNT_U16.EngDT = dt.u16;
NODEBSTEP_CNT_U16.EngVal = 65535;
NODEBSTEP_CNT_U16.Define = 'Local';


ONEOVERTWO_ULS_F32 = DataDict.Constant;
ONEOVERTWO_ULS_F32.LongName = 'One Over Two';
ONEOVERTWO_ULS_F32.Description = 'One divided by two';
ONEOVERTWO_ULS_F32.DocUnits = 'Uls';
ONEOVERTWO_ULS_F32.EngDT = dt.float32;
ONEOVERTWO_ULS_F32.EngVal = 0.5;
ONEOVERTWO_ULS_F32.Define = 'Local';


ONE_ULS_F32 = DataDict.Constant;
ONE_ULS_F32.LongName = 'One';
ONE_ULS_F32.Description = 'One';
ONE_ULS_F32.DocUnits = 'Uls';
ONE_ULS_F32.EngDT = dt.float32;
ONE_ULS_F32.EngVal = 1;
ONE_ULS_F32.Define = 'Local';


TWO_ULS_F32 = DataDict.Constant;
TWO_ULS_F32.LongName = 'Two';
TWO_ULS_F32.Description = 'Two';
TWO_ULS_F32.DocUnits = 'Uls';
TWO_ULS_F32.EngDT = dt.float32;
TWO_ULS_F32.EngVal = 2;
TWO_ULS_F32.Define = 'Local';



%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
OffsErrExcdd = DataDict.NTC;
OffsErrExcdd.NtcNr = NtcNr1.NTCNR_0X0A9;
OffsErrExcdd.NtcTyp = 'Deb';
OffsErrExcdd.LongName = 'Offset Error in Phase A B C';
OffsErrExcdd.Description = 'Offset Error Phase A B C';
OffsErrExcdd.NtcStInfo = DataDict.NtcStInfoIdx;
OffsErrExcdd.NtcStInfo.Idx(1).EngVal = 0;
OffsErrExcdd.NtcStInfo.Idx(1).Descr = 'Offset Error Phase A B C';


%end of Data Dictionary
