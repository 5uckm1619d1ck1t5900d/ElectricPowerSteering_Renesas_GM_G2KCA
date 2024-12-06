%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 30-Jan-2017 17:58:45       %
%                                  Created with tool release: 2.48.0     %
%                                  Synergy file: %version: 4 %           %
%                                  Derived by: %derived_by: fz41t8 %          %
%%-----------------------------------------------------------------------%

CM745A = DataDict.FDD;
CM745A.Version = '1.3.X';
CM745A.LongName = 'Sci30ConfigAndUse';
CM745A.ShoName  = 'Sci30CfgAndUse';
CM745A.DesignASIL = 'D';
CM745A.Description = [...
  'SCI30 Configuration And Use Function'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
Sci30CfgAndUseInit1 = DataDict.Runnable;
Sci30CfgAndUseInit1.Context = 'Rte';
Sci30CfgAndUseInit1.TimeStep = 0;
Sci30CfgAndUseInit1.Description = 'Sci30 Initialization';

Sci30CfgAndUsePer1 = DataDict.Runnable;
Sci30CfgAndUsePer1.Context = 'Rte';
Sci30CfgAndUsePer1.TimeStep = 0.002;
Sci30CfgAndUsePer1.Description = 'Sci30 Periodic 1';

Sci30CfgAndUsePer2 = DataDict.Runnable;
Sci30CfgAndUsePer2.Context = 'Rte';
Sci30CfgAndUsePer2.TimeStep = 0.002;
Sci30CfgAndUsePer2.Description = 'Sci30 Periodic 2';

Sci30CfgAndUsePer3 = DataDict.Runnable;
Sci30CfgAndUsePer3.Context = 'Rte';
Sci30CfgAndUsePer3.TimeStep = 0.01;
Sci30CfgAndUsePer3.Description = 'Sci30 Periodic 3';

Sci30CfgAndUsePer4 = DataDict.Runnable;
Sci30CfgAndUsePer4.Context = 'Rte';
Sci30CfgAndUsePer4.TimeStep = 0.1;
Sci30CfgAndUsePer4.Description = 'Sci30 Periodic 4';


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------
GetTxRateGroup = DataDict.Client;
GetTxRateGroup.CallLocation = {'Sci30CfgAndUsePer2','Sci30CfgAndUsePer3','Sci30CfgAndUsePer4'};
GetTxRateGroup.Description = [...
  'Get data for all Signal Groups that are configured under given Rate Gr' ...
  'oup'];
GetTxRateGroup.Return = DataDict.CSReturn;
GetTxRateGroup.Return.Type = 'Standard';
GetTxRateGroup.Return.Min = 0;
GetTxRateGroup.Return.Max = 1;
GetTxRateGroup.Return.TestTolerance = 0;
GetTxRateGroup.Return.Description = '';
GetTxRateGroup.Arguments(1) = DataDict.CSArguments;
GetTxRateGroup.Arguments(1).Name = 'RateGroup';
GetTxRateGroup.Arguments(1).EngDT = dt.u08;
GetTxRateGroup.Arguments(1).EngMin = 0;
GetTxRateGroup.Arguments(1).EngMax = 255;
GetTxRateGroup.Arguments(1).Units = 'Cnt';
GetTxRateGroup.Arguments(1).Direction = 'In';
GetTxRateGroup.Arguments(1).InitRowCol = [1  1];
GetTxRateGroup.Arguments(1).Description = [...
  'Rate Group ID provided by IMC Arbitration component'];
GetTxRateGroup.Arguments(2) = DataDict.CSArguments;
GetTxRateGroup.Arguments(2).Name = 'Buf';
GetTxRateGroup.Arguments(2).EngDT = dt.u08;
GetTxRateGroup.Arguments(2).EngMin = 0;
GetTxRateGroup.Arguments(2).EngMax = 255;
GetTxRateGroup.Arguments(2).TestTolerance = 1;
GetTxRateGroup.Arguments(2).Units = 'Uls';
GetTxRateGroup.Arguments(2).Direction = 'Out';
GetTxRateGroup.Arguments(2).InitRowCol = [1  2048];
GetTxRateGroup.Arguments(2).Description = [...
  'Pointer to the configurable buffer.Size of this buffer will be based o' ...
  'ut of number of Signal Groups configured under Rate Group.Refer MDD fo' ...
  'r more details'];


SetRxSigGroup = DataDict.Client;
SetRxSigGroup.CallLocation = {'Sci30CfgAndUsePer1'};
SetRxSigGroup.Description = [...
  'Copies Signal Group data received by a serial comm channel to Imc Arbi' ...
  'tration'];
SetRxSigGroup.Return = DataDict.CSReturn;
SetRxSigGroup.Return.Type = 'Standard';
SetRxSigGroup.Return.Min = 0;
SetRxSigGroup.Return.Max = 1;
SetRxSigGroup.Return.TestTolerance = 0;
SetRxSigGroup.Return.Description = '';
SetRxSigGroup.Arguments(1) = DataDict.CSArguments;
SetRxSigGroup.Arguments(1).Name = 'SigGroup';
SetRxSigGroup.Arguments(1).EngDT = dt.u08;
SetRxSigGroup.Arguments(1).EngMin = 0;
SetRxSigGroup.Arguments(1).EngMax = 255;
SetRxSigGroup.Arguments(1).Units = 'Cnt';
SetRxSigGroup.Arguments(1).Direction = 'In';
SetRxSigGroup.Arguments(1).InitRowCol = [1  1];
SetRxSigGroup.Arguments(1).Description = [...
  'Signal Group Id provided by IMC Arbitration component'];
SetRxSigGroup.Arguments(2) = DataDict.CSArguments;
SetRxSigGroup.Arguments(2).Name = 'DataSrc';
SetRxSigGroup.Arguments(2).EngDT = enum.ImcArbnRxDataSrc1;
SetRxSigGroup.Arguments(2).EngMin = ImcArbnRxDataSrc1.IMCARBNRXDATASRC_NOSRC;
SetRxSigGroup.Arguments(2).EngMax = ImcArbnRxDataSrc1.IMCARBNRXDATASRC_SECDRY;
SetRxSigGroup.Arguments(2).Units = 'Cnt';
SetRxSigGroup.Arguments(2).Direction = 'In';
SetRxSigGroup.Arguments(2).InitRowCol = [1  1];
SetRxSigGroup.Arguments(2).Description = 'Signal Source';
SetRxSigGroup.Arguments(3) = DataDict.CSArguments;
SetRxSigGroup.Arguments(3).Name = 'Buf';
SetRxSigGroup.Arguments(3).EngDT = dt.u08;
SetRxSigGroup.Arguments(3).EngMin = 0;
SetRxSigGroup.Arguments(3).EngMax = 255;
SetRxSigGroup.Arguments(3).TestTolerance = 1;
SetRxSigGroup.Arguments(3).Units = 'Uls';
SetRxSigGroup.Arguments(3).Direction = 'Out';
SetRxSigGroup.Arguments(3).InitRowCol = [1  8];
SetRxSigGroup.Arguments(3).Description = [...
  'Pointer to the received Signal Group data buffer. Imc Arbitration comp' ...
  'onent assumes that minimum 8 bytes can be read starting from given poi' ...
  'nter.0Refer MDD for more details'];



%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------

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
Sci100MilliSecBufCnt = DataDict.PIM;
Sci100MilliSecBufCnt.LongName = 'Sci30 100 Milli Second/Second Buffer Count';
Sci100MilliSecBufCnt.Description = [...
  'Sci30 100 Milli Second Buffer Count. This size of this array is config' ...
  'urable'];
Sci100MilliSecBufCnt.DocUnits = 'Cnt';
Sci100MilliSecBufCnt.EngDT = dt.u08;
Sci100MilliSecBufCnt.EngMin = 0;
Sci100MilliSecBufCnt.EngMax = 255;
Sci100MilliSecBufCnt.InitRowCol = [2047     1];


Sci100MilliSecReadCmpl = DataDict.PIM;
Sci100MilliSecReadCmpl.LongName = 'Sci30 100 Milli Read Complete';
Sci100MilliSecReadCmpl.Description = 'Sci30 100 Milli Read Complete';
Sci100MilliSecReadCmpl.DocUnits = 'Cnt';
Sci100MilliSecReadCmpl.EngDT = dt.lgc;
Sci100MilliSecReadCmpl.EngMin = 0;
Sci100MilliSecReadCmpl.EngMax = 1;
Sci100MilliSecReadCmpl.InitRowCol = [1  1];


Sci10MilliSecBufCnt = DataDict.PIM;
Sci10MilliSecBufCnt.LongName = 'Sci30 10 Milli Second/Second Buffer Count';
Sci10MilliSecBufCnt.Description = [...
  'Sci30 10 Milli Second Buffer Count. This size of this array is configu' ...
  'rable'];
Sci10MilliSecBufCnt.DocUnits = 'Cnt';
Sci10MilliSecBufCnt.EngDT = dt.u08;
Sci10MilliSecBufCnt.EngMin = 0;
Sci10MilliSecBufCnt.EngMax = 255;
Sci10MilliSecBufCnt.InitRowCol = [2047     1];


Sci10MilliSecReadCmpl = DataDict.PIM;
Sci10MilliSecReadCmpl.LongName = 'Sci30 10 Milli Read Complete';
Sci10MilliSecReadCmpl.Description = 'Sci30 10 Milli Read Complete';
Sci10MilliSecReadCmpl.DocUnits = 'Cnt';
Sci10MilliSecReadCmpl.EngDT = dt.lgc;
Sci10MilliSecReadCmpl.EngMin = 0;
Sci10MilliSecReadCmpl.EngMax = 1;
Sci10MilliSecReadCmpl.InitRowCol = [1  1];


Sci2MilliSecBufCnt = DataDict.PIM;
Sci2MilliSecBufCnt.LongName = 'Sci30 2 Milli Second/Second Buffer Count';
Sci2MilliSecBufCnt.Description = [...
  'Sci30 2 Milli Second Buffer Count. This size of this array is configur' ...
  'able'];
Sci2MilliSecBufCnt.DocUnits = 'Cnt';
Sci2MilliSecBufCnt.EngDT = dt.u08;
Sci2MilliSecBufCnt.EngMin = 0;
Sci2MilliSecBufCnt.EngMax = 255;
Sci2MilliSecBufCnt.InitRowCol = [2047     1];


SciDiagcFrmErrCntr = DataDict.PIM;
SciDiagcFrmErrCntr.LongName = 'Sci30 Diagnostic Frame Error Counter';
SciDiagcFrmErrCntr.Description = [...
  'Sci30 Diagnostic Frame Error Counter'];
SciDiagcFrmErrCntr.DocUnits = 'Cnt';
SciDiagcFrmErrCntr.EngDT = dt.u32;
SciDiagcFrmErrCntr.EngMin = 0;
SciDiagcFrmErrCntr.EngMax = 4294967295;
SciDiagcFrmErrCntr.InitRowCol = [1  1];


SciDiagcOvrrunErrCntr = DataDict.PIM;
SciDiagcOvrrunErrCntr.LongName = 'Sci30 Diagnostic Overrun Error Counter';
SciDiagcOvrrunErrCntr.Description = [...
  'Sci30 Diagnostic Overrun Error Counter'];
SciDiagcOvrrunErrCntr.DocUnits = 'Cnt';
SciDiagcOvrrunErrCntr.EngDT = dt.u32;
SciDiagcOvrrunErrCntr.EngMin = 0;
SciDiagcOvrrunErrCntr.EngMax = 4294967295;
SciDiagcOvrrunErrCntr.InitRowCol = [1  1];


SciDiagcParErrCntr = DataDict.PIM;
SciDiagcParErrCntr.LongName = 'Sci30 Diagnostic Parity Error Counter';
SciDiagcParErrCntr.Description = [...
  'Sci30 Diagnostic Parity Error Counter'];
SciDiagcParErrCntr.DocUnits = 'Cnt';
SciDiagcParErrCntr.EngDT = dt.u32;
SciDiagcParErrCntr.EngMin = 0;
SciDiagcParErrCntr.EngMax = 4294967295;
SciDiagcParErrCntr.InitRowCol = [1  1];


SciDiagcRxMaxDataErrCntr = DataDict.PIM;
SciDiagcRxMaxDataErrCntr.LongName = 'Sci30 Diagnostic Maximum Data Received error counter';
SciDiagcRxMaxDataErrCntr.Description = [...
  'Sci30 Diagnostic Maximum Data Received error counter'];
SciDiagcRxMaxDataErrCntr.DocUnits = 'Cnt';
SciDiagcRxMaxDataErrCntr.EngDT = dt.u32;
SciDiagcRxMaxDataErrCntr.EngMin = 0;
SciDiagcRxMaxDataErrCntr.EngMax = 4294967295;
SciDiagcRxMaxDataErrCntr.InitRowCol = [1  1];


SciNrOfPnd100MilliSecFrmCnt = DataDict.PIM;
SciNrOfPnd100MilliSecFrmCnt.LongName = 'Sci30 Number Of Pending 100 Milli Second/Second Frame Count';
SciNrOfPnd100MilliSecFrmCnt.Description = [...
  'Sci30 Number Of Pending 100 Milli Second Frame Count'];
SciNrOfPnd100MilliSecFrmCnt.DocUnits = 'Cnt';
SciNrOfPnd100MilliSecFrmCnt.EngDT = dt.u08;
SciNrOfPnd100MilliSecFrmCnt.EngMin = 0;
SciNrOfPnd100MilliSecFrmCnt.EngMax = 255;
SciNrOfPnd100MilliSecFrmCnt.InitRowCol = [1  1];


SciNrOfPnd10MilliSecFrmCnt = DataDict.PIM;
SciNrOfPnd10MilliSecFrmCnt.LongName = 'Sci30 Number Of Pending 10 Milli Second/Second Frame Count';
SciNrOfPnd10MilliSecFrmCnt.Description = [...
  'Sci30 Number Of Pending 10 Milli Second Frame Count'];
SciNrOfPnd10MilliSecFrmCnt.DocUnits = 'Cnt';
SciNrOfPnd10MilliSecFrmCnt.EngDT = dt.u08;
SciNrOfPnd10MilliSecFrmCnt.EngMin = 0;
SciNrOfPnd10MilliSecFrmCnt.EngMax = 255;
SciNrOfPnd10MilliSecFrmCnt.InitRowCol = [1  1];


SciRxPrevFrmCntr = DataDict.PIM;
SciRxPrevFrmCntr.LongName = 'Sci30 Receive Previous Frame Counter';
SciRxPrevFrmCntr.Description = [...
  'Sci30 Receive Previous Frame Counter'];
SciRxPrevFrmCntr.DocUnits = 'Cnt';
SciRxPrevFrmCntr.EngDT = dt.u08;
SciRxPrevFrmCntr.EngMin = 0;
SciRxPrevFrmCntr.EngMax = 255;
SciRxPrevFrmCntr.InitRowCol = [1  1];


SciRxPrevLoopDataUnread = DataDict.PIM;
SciRxPrevLoopDataUnread.LongName = 'Sci30 Receive Previous Loop Data Unused';
SciRxPrevLoopDataUnread.Description = [...
  'Sci30 Receive Previous Loop Data Unused'];
SciRxPrevLoopDataUnread.DocUnits = 'Cnt';
SciRxPrevLoopDataUnread.EngDT = dt.u08;
SciRxPrevLoopDataUnread.EngMin = 0;
SciRxPrevLoopDataUnread.EngMax = 255;
SciRxPrevLoopDataUnread.InitRowCol = [1  1];


SciRxProcIdx = DataDict.PIM;
SciRxProcIdx.LongName = 'Sci30 Receive Process Index';
SciRxProcIdx.Description = 'Sci30 Receive Process Index';
SciRxProcIdx.DocUnits = 'Cnt';
SciRxProcIdx.EngDT = dt.u08;
SciRxProcIdx.EngMin = 0;
SciRxProcIdx.EngMax = 255;
SciRxProcIdx.InitRowCol = [1  1];



%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
BYTE_CNT_U08 = DataDict.Constant;
BYTE_CNT_U08.LongName = 'Byte Count';
BYTE_CNT_U08.Description = 'Byte Count';
BYTE_CNT_U08.DocUnits = 'Cnt';
BYTE_CNT_U08.EngDT = dt.u08;
BYTE_CNT_U08.EngVal = 8;
BYTE_CNT_U08.Define = 'Local';


DATABYTE0_CNT_U08 = DataDict.Constant;
DATABYTE0_CNT_U08.LongName = 'Data Byte 0';
DATABYTE0_CNT_U08.Description = 'Data Byte 0';
DATABYTE0_CNT_U08.DocUnits = 'Cnt';
DATABYTE0_CNT_U08.EngDT = dt.u08;
DATABYTE0_CNT_U08.EngVal = 0;
DATABYTE0_CNT_U08.Define = 'Local';


DATABYTE1_CNT_U08 = DataDict.Constant;
DATABYTE1_CNT_U08.LongName = 'Data Byte 1';
DATABYTE1_CNT_U08.Description = 'Data Byte 1';
DATABYTE1_CNT_U08.DocUnits = 'Cnt';
DATABYTE1_CNT_U08.EngDT = dt.u08;
DATABYTE1_CNT_U08.EngVal = 1;
DATABYTE1_CNT_U08.Define = 'Local';


DATABYTE2_CNT_U08 = DataDict.Constant;
DATABYTE2_CNT_U08.LongName = 'Data Byte 2';
DATABYTE2_CNT_U08.Description = 'Data Byte 2';
DATABYTE2_CNT_U08.DocUnits = 'Cnt';
DATABYTE2_CNT_U08.EngDT = dt.u08;
DATABYTE2_CNT_U08.EngVal = 2;
DATABYTE2_CNT_U08.Define = 'Local';


DATABYTE3_CNT_U08 = DataDict.Constant;
DATABYTE3_CNT_U08.LongName = 'Data Byte 3';
DATABYTE3_CNT_U08.Description = 'Data Byte 3';
DATABYTE3_CNT_U08.DocUnits = 'Cnt';
DATABYTE3_CNT_U08.EngDT = dt.u08;
DATABYTE3_CNT_U08.EngVal = 3;
DATABYTE3_CNT_U08.Define = 'Local';


DATABYTE4_CNT_U08 = DataDict.Constant;
DATABYTE4_CNT_U08.LongName = 'Data Byte 4';
DATABYTE4_CNT_U08.Description = 'Data Byte 4';
DATABYTE4_CNT_U08.DocUnits = 'Cnt';
DATABYTE4_CNT_U08.EngDT = dt.u08;
DATABYTE4_CNT_U08.EngVal = 4;
DATABYTE4_CNT_U08.Define = 'Local';


DATABYTE5_CNT_U08 = DataDict.Constant;
DATABYTE5_CNT_U08.LongName = 'Data Byte 5';
DATABYTE5_CNT_U08.Description = 'Data Byte 5';
DATABYTE5_CNT_U08.DocUnits = 'Cnt';
DATABYTE5_CNT_U08.EngDT = dt.u08;
DATABYTE5_CNT_U08.EngVal = 5;
DATABYTE5_CNT_U08.Define = 'Local';


DATABYTE6_CNT_U08 = DataDict.Constant;
DATABYTE6_CNT_U08.LongName = 'Data Byte 6';
DATABYTE6_CNT_U08.Description = 'Data Byte 6';
DATABYTE6_CNT_U08.DocUnits = 'Cnt';
DATABYTE6_CNT_U08.EngDT = dt.u08;
DATABYTE6_CNT_U08.EngVal = 6;
DATABYTE6_CNT_U08.Define = 'Local';


DATABYTE7_CNT_U08 = DataDict.Constant;
DATABYTE7_CNT_U08.LongName = 'Data Byte 7';
DATABYTE7_CNT_U08.Description = 'Data Byte 7';
DATABYTE7_CNT_U08.DocUnits = 'Cnt';
DATABYTE7_CNT_U08.EngDT = dt.u08;
DATABYTE7_CNT_U08.EngVal = 7;
DATABYTE7_CNT_U08.Define = 'Local';


DATABYTE8_CNT_U08 = DataDict.Constant;
DATABYTE8_CNT_U08.LongName = 'Data Byte 8';
DATABYTE8_CNT_U08.Description = 'Data Byte 8';
DATABYTE8_CNT_U08.DocUnits = 'Cnt';
DATABYTE8_CNT_U08.EngDT = dt.u08;
DATABYTE8_CNT_U08.EngVal = 8;
DATABYTE8_CNT_U08.Define = 'Local';


IMCARBN_FRMSIZE_CNT_U08 = DataDict.Constant;
IMCARBN_FRMSIZE_CNT_U08.LongName = 'Sci30 Frame Size';
IMCARBN_FRMSIZE_CNT_U08.Description = 'Sci30 Frame Size';
IMCARBN_FRMSIZE_CNT_U08.DocUnits = 'Cnt';
IMCARBN_FRMSIZE_CNT_U08.EngDT = dt.u08;
IMCARBN_FRMSIZE_CNT_U08.EngVal = 8;
IMCARBN_FRMSIZE_CNT_U08.Define = 'Global';


IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08 = DataDict.Constant;
IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08.LongName = 'Inter Micro Communication Arbitration Number of 100 MilliSecond Rate Group';
IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08.Description = [...
  'Inter Micro Communication Arbitration Number of 100 MilliSecond Rate G' ...
  'roup'];
IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08.DocUnits = 'Cnt';
IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08.EngDT = dt.u08;
IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08.EngVal = 0;
IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08.Define = 'Global';


IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08 = DataDict.Constant;
IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08.LongName = 'Inter Micro Communication Arbitration Number of 10 MilliSecond Rate Group';
IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08.Description = [...
  'Inter Micro Communication Arbitration Number of 10 MilliSecond Rate Gr' ...
  'oup'];
IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08.DocUnits = 'Cnt';
IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08.EngDT = dt.u08;
IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08.EngVal = 0;
IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08.Define = 'Global';


IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08 = DataDict.Constant;
IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08.LongName = 'Inter Micro Communication Arbitration Number of 2 MilliSecond Rate Group';
IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08.Description = [...
  'Inter Micro Communication Arbitration Number of 2 MilliSecond Rate Gro' ...
  'up'];
IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08.DocUnits = 'Cnt';
IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08.EngDT = dt.u08;
IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08.EngVal = 0;
IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08.Define = 'Global';


IMCARBN_PATIDMASKVAL_CNT_U08 = DataDict.Constant;
IMCARBN_PATIDMASKVAL_CNT_U08.LongName = 'Sci30 Pattern Identification Mask';
IMCARBN_PATIDMASKVAL_CNT_U08.Description = 'Sci30 Pattern Identification Mask';
IMCARBN_PATIDMASKVAL_CNT_U08.DocUnits = 'Cnt';
IMCARBN_PATIDMASKVAL_CNT_U08.EngDT = dt.u08;
IMCARBN_PATIDMASKVAL_CNT_U08.EngVal = 224;
IMCARBN_PATIDMASKVAL_CNT_U08.Define = 'Global';


IMCARBN_PATIDN_CNT_U08 = DataDict.Constant;
IMCARBN_PATIDN_CNT_U08.LongName = 'Sci30 Pattern Identification';
IMCARBN_PATIDN_CNT_U08.Description = 'Sci30 Pattern Identification';
IMCARBN_PATIDN_CNT_U08.DocUnits = 'Cnt';
IMCARBN_PATIDN_CNT_U08.EngDT = dt.u08;
IMCARBN_PATIDN_CNT_U08.EngVal = 160;
IMCARBN_PATIDN_CNT_U08.Define = 'Global';


IMCARBN_RATEGROUPID100MILLISEC_CNT_U08 = DataDict.Constant;
IMCARBN_RATEGROUPID100MILLISEC_CNT_U08.LongName = 'Inter Micro Communication Arbitration of 100 MilliSecond';
IMCARBN_RATEGROUPID100MILLISEC_CNT_U08.Description = [...
  'Inter Micro Communication Arbitration of 100 MilliSecond'];
IMCARBN_RATEGROUPID100MILLISEC_CNT_U08.DocUnits = 'Cnt';
IMCARBN_RATEGROUPID100MILLISEC_CNT_U08.EngDT = dt.u08;
IMCARBN_RATEGROUPID100MILLISEC_CNT_U08.EngVal = 0;
IMCARBN_RATEGROUPID100MILLISEC_CNT_U08.Define = 'Global';


IMCARBN_RATEGROUPID10MILLISEC_CNT_U08 = DataDict.Constant;
IMCARBN_RATEGROUPID10MILLISEC_CNT_U08.LongName = 'Inter Micro Communication Arbitration of 10 MilliSecond';
IMCARBN_RATEGROUPID10MILLISEC_CNT_U08.Description = [...
  'Inter Micro Communication Arbitration of 10 MilliSecond'];
IMCARBN_RATEGROUPID10MILLISEC_CNT_U08.DocUnits = 'Cnt';
IMCARBN_RATEGROUPID10MILLISEC_CNT_U08.EngDT = dt.u08;
IMCARBN_RATEGROUPID10MILLISEC_CNT_U08.EngVal = 0;
IMCARBN_RATEGROUPID10MILLISEC_CNT_U08.Define = 'Global';


IMCARBN_RATEGROUPID2MILLISEC_CNT_U08 = DataDict.Constant;
IMCARBN_RATEGROUPID2MILLISEC_CNT_U08.LongName = 'Inter Micro Communication Arbitration of 2 MilliSecond';
IMCARBN_RATEGROUPID2MILLISEC_CNT_U08.Description = [...
  'Inter Micro Communication Arbitration of 2 MilliSecond'];
IMCARBN_RATEGROUPID2MILLISEC_CNT_U08.DocUnits = 'Cnt';
IMCARBN_RATEGROUPID2MILLISEC_CNT_U08.EngDT = dt.u08;
IMCARBN_RATEGROUPID2MILLISEC_CNT_U08.EngVal = 0;
IMCARBN_RATEGROUPID2MILLISEC_CNT_U08.Define = 'Global';


IMCARBN_RXDATASRC_CNT_U08 = DataDict.Constant;
IMCARBN_RXDATASRC_CNT_U08.LongName = 'Inter Micro Communication Arbitration Data Source';
IMCARBN_RXDATASRC_CNT_U08.Description = [...
  'Inter Micro Communication Arbitration Data Source'];
IMCARBN_RXDATASRC_CNT_U08.DocUnits = 'Cnt';
IMCARBN_RXDATASRC_CNT_U08.EngDT = enum.ImcArbnRxDataSrc1;
IMCARBN_RXDATASRC_CNT_U08.EngVal = ImcArbnRxDataSrc1.IMCARBNRXDATASRC_PRIM;
IMCARBN_RXDATASRC_CNT_U08.Define = 'Global';


MASKLOWR16BITOFUINT32_CNT_U16 = DataDict.Constant;
MASKLOWR16BITOFUINT32_CNT_U16.LongName = 'Mask Lower 16 bits of a Uint32';
MASKLOWR16BITOFUINT32_CNT_U16.Description = 'Mask Lower 16 bits of a Uint32';
MASKLOWR16BITOFUINT32_CNT_U16.DocUnits = 'Cnt';
MASKLOWR16BITOFUINT32_CNT_U16.EngDT = dt.u16;
MASKLOWR16BITOFUINT32_CNT_U16.EngVal = 65535;
MASKLOWR16BITOFUINT32_CNT_U16.Define = 'Local';


MASKUPPR16BITOFUINT32_CNT_U32 = DataDict.Constant;
MASKUPPR16BITOFUINT32_CNT_U32.LongName = 'Mask Upper 16 bits of a Uint32';
MASKUPPR16BITOFUINT32_CNT_U32.Description = 'Mask Upper 16 bits of a Uint32';
MASKUPPR16BITOFUINT32_CNT_U32.DocUnits = 'Cnt';
MASKUPPR16BITOFUINT32_CNT_U32.EngDT = dt.u32;
MASKUPPR16BITOFUINT32_CNT_U32.EngVal = 4294901760;
MASKUPPR16BITOFUINT32_CNT_U32.Define = 'Local';


MAXSIGGROUPFORTX_CNT_U08 = DataDict.Constant;
MAXSIGGROUPFORTX_CNT_U08.LongName = 'Maximum Signal Group For Transmit';
MAXSIGGROUPFORTX_CNT_U08.Description = 'Maximum Signal Group For Transmit';
MAXSIGGROUPFORTX_CNT_U08.DocUnits = 'Cnt';
MAXSIGGROUPFORTX_CNT_U08.EngDT = dt.u08;
MAXSIGGROUPFORTX_CNT_U08.EngVal = 9;
MAXSIGGROUPFORTX_CNT_U08.Define = 'Local';


SCIRXMAXBUFSIZE_CNT_U08 = DataDict.Constant;
SCIRXMAXBUFSIZE_CNT_U08.LongName = 'Dma Receive Channel Transfer Count';
SCIRXMAXBUFSIZE_CNT_U08.Description = 'Dma Receive Channel Transfer Count';
SCIRXMAXBUFSIZE_CNT_U08.DocUnits = 'Cnt';
SCIRXMAXBUFSIZE_CNT_U08.EngDT = dt.u08;
SCIRXMAXBUFSIZE_CNT_U08.EngVal = 144;
SCIRXMAXBUFSIZE_CNT_U08.Define = 'Local';



%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
%end of Data Dictionary
