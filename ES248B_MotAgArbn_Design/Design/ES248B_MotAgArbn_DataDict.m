%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 10-Aug-2016 12:58:39       %
%                                  Created with tool release: 2.44.0     %
%                                  Synergy file: %version: 1 %           %
%                                  Derived by: %derived_by: tzbsjd %          %
%%-----------------------------------------------------------------------%

ES248B = DataDict.FDD;
ES248B.Version = '1.0.X';
ES248B.LongName = 'Motor Angle Arbitration';
ES248B.ShoName  = 'MotAgArbn';
ES248B.DesignASIL = 'D';
ES248B.Description = [...
  'Perform arbitration on available signals in motor control loop.This de' ...
  'sign assumes that motor angle A is the primary sensor and will use it ' ...
  'when possible otherwise holds the last good value.'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
MotAgArbnInit1 = DataDict.Runnable;
MotAgArbnInit1.Context = 'Rte';
MotAgArbnInit1.TimeStep = 0;
MotAgArbnInit1.Description = 'Initial Function for Arbitration';

MotAgArbnPer1 = DataDict.Runnable;
MotAgArbnPer1.Context = 'NonRte';
MotAgArbnPer1.TimeStep = 'MotorControl';
MotAgArbnPer1.Description = [...
  'Periodic function for Arbitration runs at motorcontrol ISR'];


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------

%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
MotCtrlMotAgAMecl = DataDict.IpSignal;
MotCtrlMotAgAMecl.LongName = 'Motor Control Motor Angle A Mechanical';
MotCtrlMotAgAMecl.Description = [...
  'caliculated Motor Angle in Mechanical degrees from Die1'];
MotCtrlMotAgAMecl.DocUnits = 'MotRev';
MotCtrlMotAgAMecl.EngDT = dt.u0p16;
MotCtrlMotAgAMecl.EngInit = 0;
MotCtrlMotAgAMecl.EngMin = 0;
MotCtrlMotAgAMecl.EngMax = 0.9999847412;
MotCtrlMotAgAMecl.ReadIn = {'MotAgArbnPer1'};
MotCtrlMotAgAMecl.ReadType = 'NonRte';


MotCtrlMotAgAMeclQlfr = DataDict.IpSignal;
MotCtrlMotAgAMeclQlfr.LongName = 'Motor Control Motor Angle A Qualifier';
MotCtrlMotAgAMeclQlfr.Description = [...
  'The Signal provide the qualifing information(Protocol Pass/Fail) about' ...
  'the MotPosnAMecl signal'];
MotCtrlMotAgAMeclQlfr.DocUnits = 'Cnt';
MotCtrlMotAgAMeclQlfr.EngDT = enum.SigQlfr1;
MotCtrlMotAgAMeclQlfr.EngInit = SigQlfr1.SIGQLFR_NORES;
MotCtrlMotAgAMeclQlfr.EngMin = SigQlfr1.SIGQLFR_NORES;
MotCtrlMotAgAMeclQlfr.EngMax = SigQlfr1.SIGQLFR_FAILD;
MotCtrlMotAgAMeclQlfr.ReadIn = {'MotAgArbnPer1'};
MotCtrlMotAgAMeclQlfr.ReadType = 'NonRte';


MotCtrlMotAgAMeclRollgCntr = DataDict.IpSignal;
MotCtrlMotAgAMeclRollgCntr.LongName = 'Motor Control Motor Angle A Rolling Counter';
MotCtrlMotAgAMeclRollgCntr.Description = [...
  'Rolling counter will be incremented when MotPosnAMecl value is updated' ...
  ' with a new valid value.'];
MotCtrlMotAgAMeclRollgCntr.DocUnits = 'Cnt';
MotCtrlMotAgAMeclRollgCntr.EngDT = dt.u08;
MotCtrlMotAgAMeclRollgCntr.EngInit = 0;
MotCtrlMotAgAMeclRollgCntr.EngMin = 0;
MotCtrlMotAgAMeclRollgCntr.EngMax = 255;
MotCtrlMotAgAMeclRollgCntr.ReadIn = {'MotAgArbnPer1'};
MotCtrlMotAgAMeclRollgCntr.ReadType = 'NonRte';


MotCtrlMotAgMeclCorrlnSts = DataDict.IpSignal;
MotCtrlMotAgMeclCorrlnSts.LongName = 'Motor Control Motor Angle Correlation Status';
MotCtrlMotAgMeclCorrlnSts.Description = [...
  'Signal that indicates the Correlation status of input signal to the ar' ...
  'bitration function'];
MotCtrlMotAgMeclCorrlnSts.DocUnits = 'Cnt';
MotCtrlMotAgMeclCorrlnSts.EngDT = dt.b08;
MotCtrlMotAgMeclCorrlnSts.EngInit = 3;
MotCtrlMotAgMeclCorrlnSts.EngMin = 0;
MotCtrlMotAgMeclCorrlnSts.EngMax = 3;
MotCtrlMotAgMeclCorrlnSts.ReadIn = {'MotAgArbnPer1'};
MotCtrlMotAgMeclCorrlnSts.ReadType = 'NonRte';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
MotCtrlMotAgMecl = DataDict.OpSignal;
MotCtrlMotAgMecl.LongName = 'Motor Control Motor Angle Mechanical';
MotCtrlMotAgMecl.Description = [...
  'Arbitrated motor angle in mechanical degrees'];
MotCtrlMotAgMecl.DocUnits = 'MotRev';
MotCtrlMotAgMecl.SwcShoName = 'MotAgArbn';
MotCtrlMotAgMecl.EngDT = dt.u0p16;
MotCtrlMotAgMecl.EngInit = 0;
MotCtrlMotAgMecl.EngMin = 0;
MotCtrlMotAgMecl.EngMax = 0.9999847412;
MotCtrlMotAgMecl.TestTolerance = 0.0001220703125;
MotCtrlMotAgMecl.WrittenIn = {'MotAgArbnPer1'};
MotCtrlMotAgMecl.WriteType = 'NonRte';



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
MotAgARollgCntPrev = DataDict.PIM;
MotAgARollgCntPrev.LongName = 'Motor Angle A Rolling Counter Previous';
MotAgARollgCntPrev.Description = [...
  'Previous instance of motor angle 0 rolling count'];
MotAgARollgCntPrev.DocUnits = 'Cnt';
MotAgARollgCntPrev.EngDT = dt.u08;
MotAgARollgCntPrev.EngMin = 0;
MotAgARollgCntPrev.EngMax = 255;
MotAgARollgCntPrev.InitRowCol = [1  1];


MotAgAStallCntPrev = DataDict.PIM;
MotAgAStallCntPrev.LongName = 'Motor Angle A Stall Counter Previous';
MotAgAStallCntPrev.Description = [...
  'Previous instance of motor angle 0 stall count'];
MotAgAStallCntPrev.DocUnits = 'Cnt';
MotAgAStallCntPrev.EngDT = dt.u08;
MotAgAStallCntPrev.EngMin = 0;
MotAgAStallCntPrev.EngMax = 255;
MotAgAStallCntPrev.InitRowCol = [1  1];


MotAgMeclPrev = DataDict.PIM;
MotAgMeclPrev.LongName = 'Motor Angle Mechanical Previous';
MotAgMeclPrev.Description = [...
  'Previous instance of motor angle mechanical'];
MotAgMeclPrev.DocUnits = 'Cnt';
MotAgMeclPrev.EngDT = dt.u0p16;
MotAgMeclPrev.EngMin = 0;
MotAgMeclPrev.EngMax = 0.9999847412;
MotAgMeclPrev.InitRowCol = [1  1];



%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
MAXSTALL_CNT_U08 = DataDict.Constant;
MAXSTALL_CNT_U08.LongName = 'Maximum Stall Count';
MAXSTALL_CNT_U08.Description = [...
  'Maximum stall count before deemed not available'];
MAXSTALL_CNT_U08.DocUnits = 'Cnt';
MAXSTALL_CNT_U08.EngDT = dt.u08;
MAXSTALL_CNT_U08.EngVal = 200;
MAXSTALL_CNT_U08.Define = 'Local';



%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
%end of Data Dictionary
