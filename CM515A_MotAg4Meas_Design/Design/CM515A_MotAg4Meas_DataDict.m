%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 19-Sep-2016 14:45:59       %
%                                  Created with tool release: 2.46.0     %
%                                  Synergy file: %version: 2 %           %
%                                  Derived by: %derived_by: tz8cy0 %          %
%%-----------------------------------------------------------------------%

CM515A = DataDict.FDD;
CM515A.Version = '1.2.X';
CM515A.LongName = 'Motor Angle 4 Measurement';
CM515A.ShoName  = 'MotAg4Meas';
CM515A.DesignASIL = 'D';
CM515A.Description = [...
  'Measurement function of motor angle 4.  This function includes configu' ...
  'ration and use of the ENCA peripheral'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
MotAg4MeasInit1 = DataDict.Runnable;
MotAg4MeasInit1.Context = 'Rte';
MotAg4MeasInit1.TimeStep = 0;
MotAg4MeasInit1.Description = [...
  'Intial Function for Motor Angle 4 Measurement'];

GetMotAg4Mecl = DataDict.SrvRunnable;
GetMotAg4Mecl.Context = 'Both';
GetMotAg4Mecl.Description = [...
  'used to get the data from motor angle 4'];
GetMotAg4Mecl.Return = DataDict.CSReturn;
GetMotAg4Mecl.Return.Type = 'None';
GetMotAg4Mecl.Return.Min = [];
GetMotAg4Mecl.Return.Max = [];
GetMotAg4Mecl.Return.TestTolerance = [];
GetMotAg4Mecl.Arguments(1) = DataDict.CSArguments;
GetMotAg4Mecl.Arguments(1).Name = 'MotAgMecl';
GetMotAg4Mecl.Arguments(1).EngDT = dt.u0p16;
GetMotAg4Mecl.Arguments(1).EngMin = 0;
GetMotAg4Mecl.Arguments(1).EngMax = 0.9999847412;
GetMotAg4Mecl.Arguments(1).TestTolerance = 0;
GetMotAg4Mecl.Arguments(1).Units = 'MotRev';
GetMotAg4Mecl.Arguments(1).Direction = 'Out';
GetMotAg4Mecl.Arguments(1).InitRowCol = [1  1];
GetMotAg4Mecl.Arguments(1).Description = [...
  'Motor Angle 4 value in mechanical units'];


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------

%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
MotAgMecl4Polarity = DataDict.IpSignal;
MotAgMecl4Polarity.LongName = 'Motor Angle Mechanical 4 Polarity';
MotAgMecl4Polarity.Description = 'Polarity value of Motor Angle 4';
MotAgMecl4Polarity.DocUnits = 'Uls';
MotAgMecl4Polarity.EngDT = dt.s08;
MotAgMecl4Polarity.EngInit = 1;
MotAgMecl4Polarity.EngMin = -1;
MotAgMecl4Polarity.EngMax = 1;
MotAgMecl4Polarity.ReadIn = {'GetMotAg4Mecl'};
MotAgMecl4Polarity.ReadType = 'Rte';


RegInpENCA1CNT = DataDict.IpSignal;
RegInpENCA1CNT.LongName = 'Register Input ENCA1CNT';
RegInpENCA1CNT.Description = 'Register ENCA1CNT Value';
RegInpENCA1CNT.DocUnits = 'Cnt';
RegInpENCA1CNT.EngDT = dt.u16;
RegInpENCA1CNT.EngInit = 0;
RegInpENCA1CNT.EngMin = 0;
RegInpENCA1CNT.EngMax = 65535;
RegInpENCA1CNT.ReadIn = {'GetMotAg4Mecl'};
RegInpENCA1CNT.ReadType = 'Phy';



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
