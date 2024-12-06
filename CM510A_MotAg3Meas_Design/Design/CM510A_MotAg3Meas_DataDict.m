%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 13-Sep-2016 13:01:29       %
%                                  Created with tool release: 2.46.0     %
%                                  Synergy file: %version: X %           %
%                                  Derived by: %derived_by: X %          %
%%-----------------------------------------------------------------------%

CM510A = DataDict.FDD;
CM510A.Version = '1.2.1';
CM510A.LongName = 'Motor Angle 3 Measurement';
CM510A.ShoName  = 'MotAg3Meas';
CM510A.DesignASIL = 'D';
CM510A.Description = [...
  'Measurement function of Motor Angle 0.  This function includes configu' ...
  'ration and use of the ENCA peripheral'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
MotAg3MeasInit1 = DataDict.Runnable;
MotAg3MeasInit1.Context = 'Rte';
MotAg3MeasInit1.TimeStep = 0;
MotAg3MeasInit1.Description = [...
  'Intial Function for Motor Angle 3 Measurement'];


GetMotAg3Mecl = DataDict.SrvRunnable;
GetMotAg3Mecl.Context = 'Both';
GetMotAg3Mecl.Description = [...
  'used to get the data from motor angle 0 coefficient table'];
GetMotAg3Mecl.Return = DataDict.CSReturn;
GetMotAg3Mecl.Return.Type = 'None';
GetMotAg3Mecl.Return.Min = [];
GetMotAg3Mecl.Return.Max = [];
GetMotAg3Mecl.Return.TestTolerance = [];
GetMotAg3Mecl.Arguments(1) = DataDict.CSArguments;
GetMotAg3Mecl.Arguments(1).Name = 'MotAgMecl';
GetMotAg3Mecl.Arguments(1).EngDT = dt.u0p16;
GetMotAg3Mecl.Arguments(1).EngMin = 0;
GetMotAg3Mecl.Arguments(1).EngMax = 0.9999847412;
GetMotAg3Mecl.Arguments(1).TestTolerance = 0;
GetMotAg3Mecl.Arguments(1).Units = 'MotRev';
GetMotAg3Mecl.Arguments(1).Direction = 'Out';
GetMotAg3Mecl.Arguments(1).InitRowCol = [1  1];
GetMotAg3Mecl.Arguments(1).Description = [...
  'Motor Angle 3 value in mechanical units'];


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------

%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
MotAgMecl3Polarity = DataDict.IpSignal;
MotAgMecl3Polarity.LongName = 'Motor Angle Mechanical 3 Polarity';
MotAgMecl3Polarity.Description = 'Polarity value of Motor Angle 3';
MotAgMecl3Polarity.DocUnits = 'Uls';
MotAgMecl3Polarity.EngDT = dt.s08;
MotAgMecl3Polarity.EngInit = 1;
MotAgMecl3Polarity.EngMin = -1;
MotAgMecl3Polarity.EngMax = 1;
MotAgMecl3Polarity.ReadIn = {'GetMotAg3Mecl'};
MotAgMecl3Polarity.ReadType = 'Rte';


RegInpENCA0CNT = DataDict.IpSignal;
RegInpENCA0CNT.LongName = 'Register Input ENCA0CNT';
RegInpENCA0CNT.Description = 'Register ENCA0CNT Value';
RegInpENCA0CNT.DocUnits = 'Cnt';
RegInpENCA0CNT.EngDT = dt.u16;
RegInpENCA0CNT.EngInit = 0;
RegInpENCA0CNT.EngMin = 0;
RegInpENCA0CNT.EngMax = 65535;
RegInpENCA0CNT.ReadIn = {'GetMotAg3Mecl'};
RegInpENCA0CNT.ReadType = 'Phy';

%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------

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
MOTAGCNTRREGMASK_CNT_U16 = DataDict.Constant;
MOTAGCNTRREGMASK_CNT_U16.LongName = 'Motor Angle Counter Register Mask';
MOTAGCNTRREGMASK_CNT_U16.Description = [...
  'Value used to mask 14 bit counts from the ENCA register'];
MOTAGCNTRREGMASK_CNT_U16.DocUnits = 'Cnt';
MOTAGCNTRREGMASK_CNT_U16.EngDT = dt.u16;
MOTAGCNTRREGMASK_CNT_U16.EngVal = 16383;
MOTAGCNTRREGMASK_CNT_U16.Define = 'Local';


MOTAGLIM_CNT_U16 = DataDict.Constant;
MOTAGLIM_CNT_U16.LongName = 'Motor Angle Limit Mask';
MOTAGLIM_CNT_U16.Description = [...
  'Mask to limit Motor Angle to 16-bit value'];
MOTAGLIM_CNT_U16.DocUnits = 'Cnt';
MOTAGLIM_CNT_U16.EngDT = dt.u16;
MOTAGLIM_CNT_U16.EngVal = 65535;
MOTAGLIM_CNT_U16.Define = 'Local';



%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
%end of Data Dictionary
