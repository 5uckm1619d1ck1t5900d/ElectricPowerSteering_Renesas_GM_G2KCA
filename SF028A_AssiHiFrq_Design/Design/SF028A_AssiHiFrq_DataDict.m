%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 29-Jun-2015 10:42:49       %
%                                  Created with tool release: 2.14.0     %
%%-----------------------------------------------------------------------%

SF028A = DataDict.FDD;
SF028A.Version = '1.0.X';
SF028A.LongName = 'High Frequency Assist';
SF028A.ShoName  = 'AssiHiFrq';
SF028A.DesignASIL = 'D';
SF028A.Description = [...
  'This function provides a means of compensating for system inertia and ' ...
  'road feedback. It is tunable over both vehicle speed and handwheel tor' ...
  'que to obtain the desired level of disturbance rejection under various' ...
  ' operating conditions. It passes handwheel torque through a high-pass ' ...
  'filter and multiplies the resulting signal by a tunable gain factor. T' ...
  'he output is known as high-frequency assist and is simply added to the' ...
  ' usual assist calculated elsewhere'];
SF028A.Ntc = ...
	{};
SF028A.Dependencies = ...
	{'SysGlbPrm', };


%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
AssiHiFrqInit1 = DataDict.Runnable;
AssiHiFrqInit1.TimeStep = 0;

AssiHiFrqPer1 = DataDict.Runnable;
AssiHiFrqPer1.TimeStep = 0.002;


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------

%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
HwTq = DataDict.IpSignal;
HwTq.LongName = 'Handwheel Torque';
HwTq.DocUnits = 'HwNwtMtr';
HwTq.EngDT = dt.float32;
HwTq.EngInit = 0;
HwTq.EngMin = -10;
HwTq.EngMax = 10;
HwTq.ReadIn = {'AssiHiFrqPer1'};
HwTq.ReadType = 'Rte';


VehSpd = DataDict.IpSignal;
VehSpd.LongName = 'Vehicle Speed';
VehSpd.DocUnits = 'Kph';
VehSpd.EngDT = dt.float32;
VehSpd.EngInit = 0;
VehSpd.EngMin = 0;
VehSpd.EngMax = 511;
VehSpd.ReadIn = {'AssiHiFrqPer1'};
VehSpd.ReadType = 'Rte';


WhlImbRejctnAmp = DataDict.IpSignal;
WhlImbRejctnAmp.LongName = 'Wheel Imbalance Rejection Amplitude';
WhlImbRejctnAmp.DocUnits = 'MotNwtMtr';
WhlImbRejctnAmp.EngDT = dt.float32;
WhlImbRejctnAmp.EngInit = 0;
WhlImbRejctnAmp.EngMin = 0;
WhlImbRejctnAmp.EngMax = 8.8;
WhlImbRejctnAmp.ReadIn = {'AssiHiFrqPer1'};
WhlImbRejctnAmp.ReadType = 'Rte';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
AssiHiFrqCmd = DataDict.OpSignal;
AssiHiFrqCmd.LongName = 'High Frequency Assist Command';
AssiHiFrqCmd.Description = 'High frequency assist component';
AssiHiFrqCmd.DocUnits = 'MotNwtMtr';
AssiHiFrqCmd.SwcShoName = 'AssiHiFrq';
AssiHiFrqCmd.EngDT = dt.float32;
AssiHiFrqCmd.EngInit = 0;
AssiHiFrqCmd.EngMin = -8.8;
AssiHiFrqCmd.EngMax = 8.8;
AssiHiFrqCmd.TestTolerance = 0.000488281;
AssiHiFrqCmd.WrittenIn = {'AssiHiFrqPer1'};
AssiHiFrqCmd.WriteType = 'Rte';



%%-------------------------------------------
%% Inter-Runnable Variable Definition        
%%-------------------------------------------

%%-------------------------------------------
%% Calibrations Definition                   
%%-------------------------------------------
AssiHiFrqGainY = DataDict.Calibration;
AssiHiFrqGainY.LongName = 'Gain Y';
AssiHiFrqGainY.Description = [...
  'Normal tuning high frequency gain table y-variable'];
AssiHiFrqGainY.DocUnits = 'MotNwtMtrPerHwNwtMtr';
AssiHiFrqGainY.EngDT = dt.u3p13;
AssiHiFrqGainY.EngVal =  ...
   [0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25
    0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2
    0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13
    0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08
    0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04
    0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0];
AssiHiFrqGainY.EngMin = 0;
AssiHiFrqGainY.EngMax = 5;
AssiHiFrqGainY.ProgrammedBy = 'Nexteer';
AssiHiFrqGainY.Cardinality = 'R';
AssiHiFrqGainY.CustomerVisible = true;
AssiHiFrqGainY.Online = true;
AssiHiFrqGainY.Impact = 'H';
AssiHiFrqGainY.TuningOwner = 'CSE';
AssiHiFrqGainY.GraphLink = 'AssiHiFrqTqX, SysGlbPrmVehSpdBilnrSeln';
AssiHiFrqGainY.Monotony = 'None';
AssiHiFrqGainY.MaxGrad = 998;
AssiHiFrqGainY.CoderInfo.CustomAttributes.PortName = 'AssiHiFrqGainY';


AssiHiFrqHpFilFrqY = DataDict.Calibration;
AssiHiFrqHpFilFrqY.LongName = 'High Pass Filter Frequency Y';
AssiHiFrqHpFilFrqY.Description = [...
  'Table of filter cutoff frequencies, dependent on vehicle speed.'];
AssiHiFrqHpFilFrqY.DocUnits = 'Hz';
AssiHiFrqHpFilFrqY.EngDT = dt.u7p9;
AssiHiFrqHpFilFrqY.EngVal =  ...
   [8                8                8                8                8                8                8                8                8                8                8                8];
AssiHiFrqHpFilFrqY.EngMin = 5;
AssiHiFrqHpFilFrqY.EngMax = 100;
AssiHiFrqHpFilFrqY.ProgrammedBy = 'Nexteer';
AssiHiFrqHpFilFrqY.Cardinality = 'R';
AssiHiFrqHpFilFrqY.CustomerVisible = false;
AssiHiFrqHpFilFrqY.Online = false;
AssiHiFrqHpFilFrqY.Impact = 'H';
AssiHiFrqHpFilFrqY.TuningOwner = 'CSE';
AssiHiFrqHpFilFrqY.GraphLink = 'SysGlbPrmVehSpdBilnrSeln';
AssiHiFrqHpFilFrqY.Monotony = 'None';
AssiHiFrqHpFilFrqY.MaxGrad = 998;
AssiHiFrqHpFilFrqY.CoderInfo.CustomAttributes.PortName = 'AssiHiFrqHpFilFrqY';


AssiHiFrqTqWhlImbRejctnTqX = DataDict.Calibration;
AssiHiFrqTqWhlImbRejctnTqX.LongName = 'Wheel Imbalance Rejection Torque X';
AssiHiFrqTqWhlImbRejctnTqX.Description = [...
  'WIR Active tuning high frequency gain table x-variable'];
AssiHiFrqTqWhlImbRejctnTqX.DocUnits = 'HwNwtMtr';
AssiHiFrqTqWhlImbRejctnTqX.EngDT = dt.u5p11;
AssiHiFrqTqWhlImbRejctnTqX.EngVal =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0
    0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25
    0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5
    0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75
    1                1                1                1                1                1                1                1                1                1                1                1
    1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25
    1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5
    2                2                2                2                2                2                2                2                2                2                2                2
    4                4                4                4                4                4                4                4                4                4                4                4
    6                6                6                6                6                6                6                6                6                6                6                6
    7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5
    7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75
    8                8                8                8                8                8                8                8                8                8                8                8];
AssiHiFrqTqWhlImbRejctnTqX.EngMin = 0;
AssiHiFrqTqWhlImbRejctnTqX.EngMax = 10;
AssiHiFrqTqWhlImbRejctnTqX.ProgrammedBy = 'Nexteer';
AssiHiFrqTqWhlImbRejctnTqX.Cardinality = 'R';
AssiHiFrqTqWhlImbRejctnTqX.CustomerVisible = false;
AssiHiFrqTqWhlImbRejctnTqX.Online = true;
AssiHiFrqTqWhlImbRejctnTqX.Impact = 'H';
AssiHiFrqTqWhlImbRejctnTqX.TuningOwner = 'CSE';
AssiHiFrqTqWhlImbRejctnTqX.GraphLink = '';
AssiHiFrqTqWhlImbRejctnTqX.Monotony = 'Strictly_Increasing';
AssiHiFrqTqWhlImbRejctnTqX.MaxGrad = 998;
AssiHiFrqTqWhlImbRejctnTqX.CoderInfo.CustomAttributes.PortName = 'AssiHiFrqTqWhlImbRejctnTqX';


AssiHiFrqTqX = DataDict.Calibration;
AssiHiFrqTqX.LongName = 'Torque X';
AssiHiFrqTqX.Description = [...
  'Normal tuning high frequency gain table x-variable'];
AssiHiFrqTqX.DocUnits = 'HwNwtMtr';
AssiHiFrqTqX.EngDT = dt.u5p11;
AssiHiFrqTqX.EngVal =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0
    0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25
    0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5
    0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75
    1                1                1                1                1                1                1                1                1                1                1                1
    1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25             1.25
    1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5              1.5
    2                2                2                2                2                2                2                2                2                2                2                2
    4                4                4                4                4                4                4                4                4                4                4                4
    6                6                6                6                6                6                6                6                6                6                6                6
    7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5              7.5
    7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75             7.75
    8                8                8                8                8                8                8                8                8                8                8                8];
AssiHiFrqTqX.EngMin = 0;
AssiHiFrqTqX.EngMax = 10;
AssiHiFrqTqX.ProgrammedBy = 'Nexteer';
AssiHiFrqTqX.Cardinality = 'R';
AssiHiFrqTqX.CustomerVisible = true;
AssiHiFrqTqX.Online = true;
AssiHiFrqTqX.Impact = 'H';
AssiHiFrqTqX.TuningOwner = 'CSE';
AssiHiFrqTqX.GraphLink = '';
AssiHiFrqTqX.Monotony = 'Strictly_Increasing';
AssiHiFrqTqX.MaxGrad = 998;
AssiHiFrqTqX.CoderInfo.CustomAttributes.PortName = 'AssiHiFrqTqX';


AssiHiFrqWhlImbRejctnGainY = DataDict.Calibration;
AssiHiFrqWhlImbRejctnGainY.LongName = 'Wheel Imbalance Rejection Gain Y';
AssiHiFrqWhlImbRejctnGainY.Description = [...
  'WIR Active tuning high frequency gain table y-variable'];
AssiHiFrqWhlImbRejctnGainY.DocUnits = 'MotNwtMtrPerHwNwtMtr';
AssiHiFrqWhlImbRejctnGainY.EngDT = dt.u3p13;
AssiHiFrqWhlImbRejctnGainY.EngVal =  ...
   [0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25
    0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2              0.2
    0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13             0.13
    0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08             0.08
    0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04             0.04
    0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01             0.01
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0];
AssiHiFrqWhlImbRejctnGainY.EngMin = 0;
AssiHiFrqWhlImbRejctnGainY.EngMax = 5;
AssiHiFrqWhlImbRejctnGainY.ProgrammedBy = 'Nexteer';
AssiHiFrqWhlImbRejctnGainY.Cardinality = 'R';
AssiHiFrqWhlImbRejctnGainY.CustomerVisible = false;
AssiHiFrqWhlImbRejctnGainY.Online = true;
AssiHiFrqWhlImbRejctnGainY.Impact = 'H';
AssiHiFrqWhlImbRejctnGainY.TuningOwner = 'CSE';
AssiHiFrqWhlImbRejctnGainY.GraphLink = 'AssiHiFrqTqWhlImbRejctnTqX, SysGlbPrmVehSpdBilnrSeln';
AssiHiFrqWhlImbRejctnGainY.Monotony = 'None';
AssiHiFrqWhlImbRejctnGainY.MaxGrad = 998;
AssiHiFrqWhlImbRejctnGainY.CoderInfo.CustomAttributes.PortName = 'AssiHiFrqWhlImbRejctnGainY';


AssiHiFrqWhlImbRejtcnBlndX = DataDict.Calibration;
AssiHiFrqWhlImbRejtcnBlndX.LongName = 'Wheel Imbalance Rejection Blend X';
AssiHiFrqWhlImbRejtcnBlndX.Description = 'WIR Blend table x-variable';
AssiHiFrqWhlImbRejtcnBlndX.DocUnits = 'MotNwtMtr';
AssiHiFrqWhlImbRejtcnBlndX.EngDT = dt.u4p12;
AssiHiFrqWhlImbRejtcnBlndX.EngVal =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0
    0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25             0.25
    0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5              0.5
    0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75             0.75
    1.1              1.1              1.1              1.1              1.1              1.1              1.1              1.1              1.1              1.1              1.1              1.1];
AssiHiFrqWhlImbRejtcnBlndX.EngMin = 0;
AssiHiFrqWhlImbRejtcnBlndX.EngMax = 8;
AssiHiFrqWhlImbRejtcnBlndX.ProgrammedBy = 'Nexteer';
AssiHiFrqWhlImbRejtcnBlndX.Cardinality = 'R';
AssiHiFrqWhlImbRejtcnBlndX.CustomerVisible = false;
AssiHiFrqWhlImbRejtcnBlndX.Online = true;
AssiHiFrqWhlImbRejtcnBlndX.Impact = 'H';
AssiHiFrqWhlImbRejtcnBlndX.TuningOwner = 'CSE';
AssiHiFrqWhlImbRejtcnBlndX.GraphLink = '';
AssiHiFrqWhlImbRejtcnBlndX.Monotony = 'Strictly_Increasing';
AssiHiFrqWhlImbRejtcnBlndX.MaxGrad = 998;
AssiHiFrqWhlImbRejtcnBlndX.CoderInfo.CustomAttributes.PortName = 'AssiHiFrqWhlImbRejtcnBlndX';


AssiHiFrqWhlImbRejtcnBlndY = DataDict.Calibration;
AssiHiFrqWhlImbRejtcnBlndY.LongName = 'Wheel Imbalance Rejection Blend Y';
AssiHiFrqWhlImbRejtcnBlndY.Description = 'WIR Blend table y-variable';
AssiHiFrqWhlImbRejtcnBlndY.DocUnits = 'Uls';
AssiHiFrqWhlImbRejtcnBlndY.EngDT = dt.u1p15;
AssiHiFrqWhlImbRejtcnBlndY.EngVal =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0
    0                0                0                0                0                0                0                0                0                0                0                0];
AssiHiFrqWhlImbRejtcnBlndY.EngMin = 0;
AssiHiFrqWhlImbRejtcnBlndY.EngMax = 1;
AssiHiFrqWhlImbRejtcnBlndY.ProgrammedBy = 'Nexteer';
AssiHiFrqWhlImbRejtcnBlndY.Cardinality = 'R';
AssiHiFrqWhlImbRejtcnBlndY.CustomerVisible = false;
AssiHiFrqWhlImbRejtcnBlndY.Online = true;
AssiHiFrqWhlImbRejtcnBlndY.Impact = 'H';
AssiHiFrqWhlImbRejtcnBlndY.TuningOwner = 'CSE';
AssiHiFrqWhlImbRejtcnBlndY.GraphLink = 'AssiHiFrqWhlImbRejtcnBlndX, SysGlbPrmVehSpdBilnrSeln';
AssiHiFrqWhlImbRejtcnBlndY.Monotony = 'None';
AssiHiFrqWhlImbRejtcnBlndY.MaxGrad = 998;
AssiHiFrqWhlImbRejtcnBlndY.CoderInfo.CustomAttributes.PortName = 'AssiHiFrqWhlImbRejtcnBlndY';



%%-------------------------------------------
%% Imported Calibrations Definition                   
%%-------------------------------------------
SysGlbPrmVehSpdBilnrSeln = DataDict.ImprtdCal;
SysGlbPrmVehSpdBilnrSeln.DocUnits = 'Kph';
SysGlbPrmVehSpdBilnrSeln.EngDT = dt.u9p7;
SysGlbPrmVehSpdBilnrSeln.EngVal =  ...
   [0                5               15               30               60               80              100              120              150              180              200              220];
SysGlbPrmVehSpdBilnrSeln.EngMax = 511;
SysGlbPrmVehSpdBilnrSeln.EngMin = 0;
SysGlbPrmVehSpdBilnrSeln.CoderInfo.CustomAttributes.PortName = 'SysGlbPrmVehSpdBilnrSeln';



%%-------------------------------------------
%% Non-Volatile Memory Definition            
%%-------------------------------------------

%%-------------------------------------------
%% Display Variable Definition               
%%-------------------------------------------
dAssiHiFrqGain = DataDict.Display;
dAssiHiFrqGain.LongName = 'Gain';
dAssiHiFrqGain.Description = [...
  'Final gain value applied to high-frequency component of assist.'];
dAssiHiFrqGain.DocUnits = 'MotNwtMtrPerHwNwtMtr';
dAssiHiFrqGain.EngDT = dt.float32;
dAssiHiFrqGain.EngMin = 0;
dAssiHiFrqGain.EngMax = 5;
dAssiHiFrqGain.InitRowCol = [1  1];


dAssiHiFrqGainBlnd = DataDict.Display;
dAssiHiFrqGainBlnd.LongName = 'Gain Blend';
dAssiHiFrqGainBlnd.Description = [...
  'Zero-to-one fraction.  Zero means use entirely WIR-off tuning.  One me' ...
  'ans use entirely WIR-on tuning.'];
dAssiHiFrqGainBlnd.DocUnits = 'Uls';
dAssiHiFrqGainBlnd.EngDT = dt.float32;
dAssiHiFrqGainBlnd.EngMin = 0;
dAssiHiFrqGainBlnd.EngMax = 1;
dAssiHiFrqGainBlnd.InitRowCol = [1  1];


dAssiHiFrqGainWhlImbRejtcnZero = DataDict.Display;
dAssiHiFrqGainWhlImbRejtcnZero.LongName = 'Gain Wheel Imbalance Rejection Zero';
dAssiHiFrqGainWhlImbRejtcnZero.Description = [...
  'Gain value that is applied to high-frequency component of assist whene' ...
  'ver WIR amplitude is zero.'];
dAssiHiFrqGainWhlImbRejtcnZero.DocUnits = 'MotNwtMtrPerHwNwtMtr';
dAssiHiFrqGainWhlImbRejtcnZero.EngDT = dt.float32;
dAssiHiFrqGainWhlImbRejtcnZero.EngMin = 0;
dAssiHiFrqGainWhlImbRejtcnZero.EngMax = 5;
dAssiHiFrqGainWhlImbRejtcnZero.InitRowCol = [1  1];



%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------
HwTqHpFil = DataDict.PIM;
HwTqHpFil.LongName = 'Handwheel Torque High Pass Filter';
HwTqHpFil.Description = [...
  'Structure for a high pass filter on handhweel torque containing state ' ...
  'variables.'];
HwTqHpFil.DocUnits = 'HwNwtMtr';
HwTqHpFil.EngDT = struct.FilHpRec1;
HwTqHpFil.EngMin = [];
HwTqHpFil.EngMax = [];
HwTqHpFil.InitRowCol = [1  1];



%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32 = DataDict.Constant;
SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32.LongName = 'Motor Torque Command High Limit';
SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32.Description = [...
  'Limit on high value of motor torque command.'];
SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32.DocUnits = 'MotNwtMtr';
SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32.EngDT = dt.float32;
SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32.EngVal = 8.8;
SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32.Header = 'SysGlbPrm.h';
SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32.Define = 'Global';


SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32 = DataDict.Constant;
SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32.LongName = 'Motor Torque Command Low Limit';
SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32.Description = [...
  'Limit on lower value of motor torque command'];
SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32.DocUnits = 'MotNwtMtr';
SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32.EngDT = dt.float32;
SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32.EngVal = -8.8;
SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32.Header = 'SysGlbPrm.h';
SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32.Define = 'Global';


%end of Data Dictionary