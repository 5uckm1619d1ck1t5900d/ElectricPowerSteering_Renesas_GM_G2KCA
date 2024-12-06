%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 21-Dec-2015 09:43:12       %
%                                  Created with tool release: 2.22.0     %
%                                  Synergy file: %version: 1 %           %
%                                  Date Modified: %date_modified: X %    %
%                                  Derived by: %derived_by: cz68ds %          %
%%-----------------------------------------------------------------------%

CM200C = DataDict.FDD;
CM200C.Version = '1.0.X';
CM200C.LongName = 'DMA Configuration And Usage';
CM200C.ShoName  = 'DmaCfgAndUse';
CM200C.DesignASIL = '';
CM200C.Description = [...
  'DMA Configuration and Usage intent to trigger SPI, ADC, Motor Control ' ...
  'data and 2ms'];
CM200C.Dependencies = ...
	{'ArSuprt', 'MotAg0Meas', 'MotAg1Meas'};


%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
DmaCfgAndUseInit1 = DataDict.Runnable;
DmaCfgAndUseInit1.TimeStep = 0;

DmaCfgAndUsePer1 = DataDict.Runnable;
DmaCfgAndUsePer1.TimeStep = 0.002;

DmaEna2MilliSecToMotCtrlTrf = DataDict.SrvRunnable;
DmaEna2MilliSecToMotCtrlTrf.Context = 'Rte';
DmaEna2MilliSecToMotCtrlTrf.Return = DataDict.CSReturn;
DmaEna2MilliSecToMotCtrlTrf.Return.Type = 'None';
DmaEna2MilliSecToMotCtrlTrf.Return.Min = [];
DmaEna2MilliSecToMotCtrlTrf.Return.Max = [];
DmaEna2MilliSecToMotCtrlTrf.Return.TestTolerance = [];

DmaWaitForMotCtrlTo2MilliSecTrf = DataDict.SrvRunnable;
DmaWaitForMotCtrlTo2MilliSecTrf.Context = 'Rte';
DmaWaitForMotCtrlTo2MilliSecTrf.Return = DataDict.CSReturn;
DmaWaitForMotCtrlTo2MilliSecTrf.Return.Type = 'Standard';
DmaWaitForMotCtrlTo2MilliSecTrf.Return.Min = 0;
DmaWaitForMotCtrlTo2MilliSecTrf.Return.Max = 1;
DmaWaitForMotCtrlTo2MilliSecTrf.Return.TestTolerance = [];

InjDmaErr = DataDict.SrvRunnable;
InjDmaErr.Context = 'NonRte';
InjDmaErr.Return = DataDict.CSReturn;
InjDmaErr.Return.Type = 'None';
InjDmaErr.Return.Min = [];
InjDmaErr.Return.Max = [];
InjDmaErr.Return.TestTolerance = [];

InjMcuDiagcErr = DataDict.SrvRunnable;
InjMcuDiagcErr.Context = 'NonRte';
InjMcuDiagcErr.Return = DataDict.CSReturn;
InjMcuDiagcErr.Return.Type = 'None';
InjMcuDiagcErr.Return.Min = [];
InjMcuDiagcErr.Return.Max = [];
InjMcuDiagcErr.Return.TestTolerance = [];

%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------
Adc1CfgAndUseAdc1EnaCnvn = DataDict.Client;
Adc1CfgAndUseAdc1EnaCnvn.CallLocation = {'DmaCfgAndUsePer1'};
Adc1CfgAndUseAdc1EnaCnvn.Return = DataDict.CSReturn;
Adc1CfgAndUseAdc1EnaCnvn.Return.Type = 'None';
Adc1CfgAndUseAdc1EnaCnvn.Return.Min = [];
Adc1CfgAndUseAdc1EnaCnvn.Return.Max = [];
Adc1CfgAndUseAdc1EnaCnvn.Return.TestTolerance = [];


ClrErrInjReg = DataDict.Client;
ClrErrInjReg.CallLocation = {'DmaEna2MilliSecToMotCtrlTrf','InjDmaErr','InjMotCtrlTo2MilliSecTrfErr'};
ClrErrInjReg.Description = 'Clear BRAMDAT2';
ClrErrInjReg.Return = DataDict.CSReturn;
ClrErrInjReg.Return.Type = 'None';
ClrErrInjReg.Return.Min = [];
ClrErrInjReg.Return.Max = [];
ClrErrInjReg.Return.TestTolerance = [];


GetRefTmr1MicroSec32bit = DataDict.Client;
GetRefTmr1MicroSec32bit.CallLocation = {'DmaCfgAndUsePer1'};
GetRefTmr1MicroSec32bit.Return = DataDict.CSReturn;
GetRefTmr1MicroSec32bit.Return.Type = 'None';
GetRefTmr1MicroSec32bit.Return.Min = [];
GetRefTmr1MicroSec32bit.Return.Max = [];
GetRefTmr1MicroSec32bit.Return.TestTolerance = [];
GetRefTmr1MicroSec32bit.Arguments(1) = DataDict.CSArguments;
GetRefTmr1MicroSec32bit.Arguments(1).Name = 'RefTmr';
GetRefTmr1MicroSec32bit.Arguments(1).EngMin = 0;
GetRefTmr1MicroSec32bit.Arguments(1).EngMax = 4294967295;
GetRefTmr1MicroSec32bit.Arguments(1).EngDT = dt.u32;
GetRefTmr1MicroSec32bit.Arguments(1).Units = 'Cnt';
GetRefTmr1MicroSec32bit.Arguments(1).Direction = 'Out';
GetRefTmr1MicroSec32bit.Arguments(1).InitRowCol = [1  1];


GetTiSpan1MicroSec32bit = DataDict.Client;
GetTiSpan1MicroSec32bit.CallLocation = {'DmaWaitForMotCtrlTo2MilliSecTrf'};
GetTiSpan1MicroSec32bit.Return = DataDict.CSReturn;
GetTiSpan1MicroSec32bit.Return.Type = 'Standard';
GetTiSpan1MicroSec32bit.Return.Min = 0;
GetTiSpan1MicroSec32bit.Return.Max = 1;
GetTiSpan1MicroSec32bit.Return.TestTolerance = 0;
GetTiSpan1MicroSec32bit.Arguments(1) = DataDict.CSArguments;
GetTiSpan1MicroSec32bit.Arguments(1).Name = 'RefTmr';
GetTiSpan1MicroSec32bit.Arguments(1).EngMin = 0;
GetTiSpan1MicroSec32bit.Arguments(1).EngMax = 4294967295;
GetTiSpan1MicroSec32bit.Arguments(1).EngDT = dt.u32;
GetTiSpan1MicroSec32bit.Arguments(1).Units = 'Cnt';
GetTiSpan1MicroSec32bit.Arguments(1).Direction = 'In';
GetTiSpan1MicroSec32bit.Arguments(1).InitRowCol = [1  1];
GetTiSpan1MicroSec32bit.Arguments(2) = DataDict.CSArguments;
GetTiSpan1MicroSec32bit.Arguments(2).Name = 'TiSpan';
GetTiSpan1MicroSec32bit.Arguments(2).EngMin = 0;
GetTiSpan1MicroSec32bit.Arguments(2).EngMax = 4294967295;
GetTiSpan1MicroSec32bit.Arguments(2).EngDT = dt.u32;
GetTiSpan1MicroSec32bit.Arguments(2).Units = 'Cnt';
GetTiSpan1MicroSec32bit.Arguments(2).Direction = 'Out';
GetTiSpan1MicroSec32bit.Arguments(2).InitRowCol = [1  1];


ReadErrInjReg = DataDict.Client;
ReadErrInjReg.CallLocation = {'DmaEna2MilliSecToMotCtrlTrf','InjDmaErr','InjMotCtrlTo2MilliSecTrfErr'};
ReadErrInjReg.Description = 'Read BRAMDAT2';
ReadErrInjReg.Return = DataDict.CSReturn;
ReadErrInjReg.Return.Type = 'None';
ReadErrInjReg.Return.Min = [];
ReadErrInjReg.Return.Max = [];
ReadErrInjReg.Return.TestTolerance = [];
ReadErrInjReg.Arguments(1) = DataDict.CSArguments;
ReadErrInjReg.Arguments(1).Name = 'ErrId';
ReadErrInjReg.Arguments(1).EngDT = dt.u32;
ReadErrInjReg.Arguments(1).EngMin = 0;
ReadErrInjReg.Arguments(1).EngMax = 4294967295;
ReadErrInjReg.Arguments(1).TestTolerance = 999;
ReadErrInjReg.Arguments(1).Units = 'Cnt';
ReadErrInjReg.Arguments(1).Direction = 'Out';
ReadErrInjReg.Arguments(1).InitRowCol = [1  1];
ReadErrInjReg.Arguments(1).Description = 'None';
%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
DmaAdc0ResTrig = DataDict.IpSignal;
DmaAdc0ResTrig.LongName = 'DMA Adc0 Results Trigger';
DmaAdc0ResTrig.DocUnits = 'Cnt';
DmaAdc0ResTrig.EngDT = dt.lgc;
DmaAdc0ResTrig.EngInit = 0;
DmaAdc0ResTrig.EngMin = 0;
DmaAdc0ResTrig.EngMax = 1;
DmaAdc0ResTrig.ReadIn = {'DmaCfgAndUseInit1'};
DmaAdc0ResTrig.ReadType = 'Phy';


DmaAdc1ResTrig = DataDict.IpSignal;
DmaAdc1ResTrig.LongName = 'DMA Adc1 Results Trigger';
DmaAdc1ResTrig.DocUnits = 'Cnt';
DmaAdc1ResTrig.EngDT = dt.lgc;
DmaAdc1ResTrig.EngInit = 0;
DmaAdc1ResTrig.EngMin = 0;
DmaAdc1ResTrig.EngMax = 1;
DmaAdc1ResTrig.ReadIn = {'DmaCfgAndUseInit1'};
DmaAdc1ResTrig.ReadType = 'Phy';


DmaTSG31Upd = DataDict.IpSignal;
DmaTSG31Upd.LongName = 'DMA TSG 31 Update';
DmaTSG31Upd.DocUnits = 'Cnt';
DmaTSG31Upd.EngDT = dt.lgc;
DmaTSG31Upd.EngInit = 0;
DmaTSG31Upd.EngMin = 0;
DmaTSG31Upd.EngMax = 1;
DmaTSG31Upd.ReadIn = {'DmaCfgAndUseInit1'};
DmaTSG31Upd.ReadType = 'Phy';


DmaVlyTrig = DataDict.IpSignal;
DmaVlyTrig.LongName = 'DMA Valley Trigger';
DmaVlyTrig.DocUnits = 'Cnt';
DmaVlyTrig.EngDT = dt.lgc;
DmaVlyTrig.EngInit = 0;
DmaVlyTrig.EngMin = 0;
DmaVlyTrig.EngMax = 1;
DmaVlyTrig.ReadIn = {'DmaCfgAndUseInit1'};
DmaVlyTrig.ReadType = 'Phy';


MotCtrlMgr_MotCtrlToTwoMilliSec_Rec = DataDict.IpSignal;
MotCtrlMgr_MotCtrlToTwoMilliSec_Rec.LongName = 'Motor Control Manager 2ms to Motor Control Record';
MotCtrlMgr_MotCtrlToTwoMilliSec_Rec.DocUnits = 'Cnt';
MotCtrlMgr_MotCtrlToTwoMilliSec_Rec.EngDT = struct.MotCtrlToTwoMilliSecRec1;
MotCtrlMgr_MotCtrlToTwoMilliSec_Rec.EngInit = [];
MotCtrlMgr_MotCtrlToTwoMilliSec_Rec.EngMin = [];
MotCtrlMgr_MotCtrlToTwoMilliSec_Rec.EngMax = [];
MotCtrlMgr_MotCtrlToTwoMilliSec_Rec.ReadIn = {'DmaCfgAndUseInit1'};
MotCtrlMgr_MotCtrlToTwoMilliSec_Rec.ReadType = 'NonRte';


MotCtrlMgr_TwoMilliSecToMotCtrl_Rec = DataDict.IpSignal;
MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.LongName = 'Motor Control Manager 2ms to Motor Control Record';
MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.DocUnits = 'Cnt';
MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.EngDT = struct.TwoMilliSecToMotCtrlRec1;
MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.EngInit = [];
MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.EngMin = [];
MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.EngMax = [];
MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.ReadIn = {'DmaCfgAndUseInit1'};
MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.ReadType = 'NonRte';


MotCtrlTSG31CMPWE = DataDict.IpSignal;
MotCtrlTSG31CMPWE.LongName = 'Motor Control TSG31CMPWE';
MotCtrlTSG31CMPWE.DocUnits = 'Cnt';
MotCtrlTSG31CMPWE.EngDT = dt.u32;
MotCtrlTSG31CMPWE.EngInit = 0;
MotCtrlTSG31CMPWE.EngMin = 0;
MotCtrlTSG31CMPWE.EngMax = 4294967295;
MotCtrlTSG31CMPWE.ReadIn = {'DmaCfgAndUseInit1'};
MotCtrlTSG31CMPWE.ReadType = 'NonRte';


MotCtrlTSG31DCMP0E = DataDict.IpSignal;
MotCtrlTSG31DCMP0E.LongName = 'Motor Control TSG31DCMP0E';
MotCtrlTSG31DCMP0E.DocUnits = 'Cnt';
MotCtrlTSG31DCMP0E.EngDT = dt.u32;
MotCtrlTSG31DCMP0E.EngInit = 0;
MotCtrlTSG31DCMP0E.EngMin = 0;
MotCtrlTSG31DCMP0E.EngMax = 4294967295;
MotCtrlTSG31DCMP0E.ReadIn = {'DmaCfgAndUseInit1'};
MotCtrlTSG31DCMP0E.ReadType = 'NonRte';


RegInpADCD0DR00 = DataDict.IpSignal;
RegInpADCD0DR00.LongName = 'Register ADCD0DR00';
RegInpADCD0DR00.DocUnits = 'Cnt';
RegInpADCD0DR00.EngDT = dt.u32;
RegInpADCD0DR00.EngInit = 0;
RegInpADCD0DR00.EngMin = 0;
RegInpADCD0DR00.EngMax = 4294967295;
RegInpADCD0DR00.ReadIn = {'DmaCfgAndUseInit1'};
RegInpADCD0DR00.ReadType = 'Phy';


RegInpADCD1DR00 = DataDict.IpSignal;
RegInpADCD1DR00.LongName = 'Reg Input TSG31CMPWE';
RegInpADCD1DR00.DocUnits = 'Cnt';
RegInpADCD1DR00.EngDT = dt.u32;
RegInpADCD1DR00.EngInit = 0;
RegInpADCD1DR00.EngMin = 0;
RegInpADCD1DR00.EngMax = 4294967295;
RegInpADCD1DR00.ReadIn = {'DmaCfgAndUseInit1'};
RegInpADCD1DR00.ReadType = 'Phy';


RegInpDMASSTC15 = DataDict.IpSignal;
RegInpDMASSTC15.LongName = 'Register DMASSTC15';
RegInpDMASSTC15.DocUnits = 'Cnt';
RegInpDMASSTC15.EngDT = dt.u08;
RegInpDMASSTC15.EngInit = 0;
RegInpDMASSTC15.EngMin = 0;
RegInpDMASSTC15.EngMax = 1;
RegInpDMASSTC15.ReadIn = {'DmaWaitForMotCtrlTo2MilliSecTrf'};
RegInpDMASSTC15.ReadType = 'Phy';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
MotCtrlAdc0RawRes = DataDict.OpSignal;
MotCtrlAdc0RawRes.LongName = 'Motor Control ADC 0 Raw Result';
MotCtrlAdc0RawRes.Description = 'DMA ADC 0 Raw Destination Address';
MotCtrlAdc0RawRes.DocUnits = 'Cnt';
MotCtrlAdc0RawRes.SwcShoName = 'DmaCfgAndUse';
MotCtrlAdc0RawRes.EngDT = dt.u16;
MotCtrlAdc0RawRes.EngInit =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0];
MotCtrlAdc0RawRes.EngMin = 0;
MotCtrlAdc0RawRes.EngMax = 4095;
MotCtrlAdc0RawRes.TestTolerance = 0;
MotCtrlAdc0RawRes.WrittenIn = {'DmaCfgAndUseInit1'};
MotCtrlAdc0RawRes.WriteType = 'NonRte';


MotCtrlAdc1RawRes = DataDict.OpSignal;
MotCtrlAdc1RawRes.LongName = 'Motor Control ADC 1 Raw Result';
MotCtrlAdc1RawRes.Description = 'Motor Control ADC 1 Destination';
MotCtrlAdc1RawRes.DocUnits = 'Cnt';
MotCtrlAdc1RawRes.SwcShoName = 'DmaCfgAndUse';
MotCtrlAdc1RawRes.EngDT = dt.u16;
MotCtrlAdc1RawRes.EngInit =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0];
MotCtrlAdc1RawRes.EngMin = 0;
MotCtrlAdc1RawRes.EngMax = 4095;
MotCtrlAdc1RawRes.TestTolerance = 0;
MotCtrlAdc1RawRes.WrittenIn = {'DmaCfgAndUseInit1'};
MotCtrlAdc1RawRes.WriteType = 'NonRte';


MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec = DataDict.OpSignal;
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.LongName = 'Motor Control Mgr Motor Control from 2ms';
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.Description = 'Motor Control from 2ms ';
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.DocUnits = 'Cnt';
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.SwcShoName = 'DmaCfgAndUse';
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.EngDT = struct.MotCtrlFromTwoMilliSecRec1;
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.EngInit = [];
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.EngMin = [];
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.EngMax = [];
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.TestTolerance = 0;
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.WrittenIn = {'DmaCfgAndUseInit1'};
MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec.WriteType = 'NonRte';


MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec = DataDict.OpSignal;
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.LongName = 'Motor Control Mgr 2ms from Motor Control';
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Description = '2ms from Motor Control';
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.DocUnits = 'Cnt';
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.SwcShoName = 'DmaCfgAndUse';
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.EngDT = struct.TwoMilliSecFromMotCtrlRec1;
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.EngInit = [];
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.EngMin = [];
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.EngMax = [];
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.TestTolerance = 0;
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.WrittenIn = {'DmaCfgAndUseInit1'};
MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.WriteType = 'NonRte';


RegOutpDMASSDRQC14 = DataDict.OpSignal;
RegOutpDMASSDRQC14.LongName = 'Register DMASSDRQC14';
RegOutpDMASSDRQC14.Description = 'Register DMASSDRQC14';
RegOutpDMASSDRQC14.DocUnits = 'Cnt';
RegOutpDMASSDRQC14.SwcShoName = 'DmaCfgAndUse';
RegOutpDMASSDRQC14.EngDT = dt.u08;
RegOutpDMASSDRQC14.EngInit = 0;
RegOutpDMASSDRQC14.EngMin = 0;
RegOutpDMASSDRQC14.EngMax = 1;
RegOutpDMASSDRQC14.TestTolerance = 0;
RegOutpDMASSDRQC14.WrittenIn = {'DmaCfgAndUsePer1'};
RegOutpDMASSDRQC14.WriteType = 'Phy';


RegOutpDMASSDRQC9 = DataDict.OpSignal;
RegOutpDMASSDRQC9.LongName = 'Register DMASSDRQC9';
RegOutpDMASSDRQC9.Description = 'Register DMASSDRQC9';
RegOutpDMASSDRQC9.DocUnits = 'Cnt';
RegOutpDMASSDRQC9.SwcShoName = 'DmaCfgAndUse';
RegOutpDMASSDRQC9.EngDT = dt.u08;
RegOutpDMASSDRQC9.EngInit = 0;
RegOutpDMASSDRQC9.EngMin = 0;
RegOutpDMASSDRQC9.EngMax = 1;
RegOutpDMASSDRQC9.TestTolerance = 0;
RegOutpDMASSDRQC9.WrittenIn = {'DmaEna2MilliSecToMotCtrlTrf'};
RegOutpDMASSDRQC9.WriteType = 'Phy';


RegOutpDMASSDTE14 = DataDict.OpSignal;
RegOutpDMASSDTE14.LongName = 'Register DMASSDTE14';
RegOutpDMASSDTE14.Description = 'Register DMASSDTE14';
RegOutpDMASSDTE14.DocUnits = 'Cnt';
RegOutpDMASSDTE14.SwcShoName = 'DmaCfgAndUse';
RegOutpDMASSDTE14.EngDT = dt.u08;
RegOutpDMASSDTE14.EngInit = 0;
RegOutpDMASSDTE14.EngMin = 0;
RegOutpDMASSDTE14.EngMax = 1;
RegOutpDMASSDTE14.TestTolerance = 0;
RegOutpDMASSDTE14.WrittenIn = {'DmaCfgAndUsePer1'};
RegOutpDMASSDTE14.WriteType = 'Phy';


RegOutpDMASSDTE9 = DataDict.OpSignal;
RegOutpDMASSDTE9.LongName = 'Register DMASSDTE9';
RegOutpDMASSDTE9.Description = 'Register DMASSDTE9';
RegOutpDMASSDTE9.DocUnits = 'Cnt';
RegOutpDMASSDTE9.SwcShoName = 'DmaCfgAndUse';
RegOutpDMASSDTE9.EngDT = dt.u08;
RegOutpDMASSDTE9.EngInit = 0;
RegOutpDMASSDTE9.EngMin = 0;
RegOutpDMASSDTE9.EngMax = 1;
RegOutpDMASSDTE9.TestTolerance = 0;
RegOutpDMASSDTE9.WrittenIn = {'DmaEna2MilliSecToMotCtrlTrf'};
RegOutpDMASSDTE9.WriteType = 'Phy';


RegOutpDMASSDTFR9 = DataDict.OpSignal;
RegOutpDMASSDTFR9.LongName = 'Register DMASSDTFR9';
RegOutpDMASSDTFR9.Description = 'Register DMASSDTFR9';
RegOutpDMASSDTFR9.DocUnits = 'Cnt';
RegOutpDMASSDTFR9.SwcShoName = 'DmaCfgAndUse';
RegOutpDMASSDTFR9.EngDT = dt.u32;
RegOutpDMASSDTFR9.EngInit = 0;
RegOutpDMASSDTFR9.EngMin = 0;
RegOutpDMASSDTFR9.EngMax = 4294967295;
RegOutpDMASSDTFR9.TestTolerance = 0;
RegOutpDMASSDTFR9.WrittenIn = {'DmaEna2MilliSecToMotCtrlTrf'};
RegOutpDMASSDTFR9.WriteType = 'Phy';


RegOutpDMASSTCC14 = DataDict.OpSignal;
RegOutpDMASSTCC14.LongName = 'Register DMASSTCC14';
RegOutpDMASSTCC14.Description = 'Register DMASSTCC14';
RegOutpDMASSTCC14.DocUnits = 'Cnt';
RegOutpDMASSTCC14.SwcShoName = 'DmaCfgAndUse';
RegOutpDMASSTCC14.EngDT = dt.u08;
RegOutpDMASSTCC14.EngInit = 0;
RegOutpDMASSTCC14.EngMin = 0;
RegOutpDMASSTCC14.EngMax = 1;
RegOutpDMASSTCC14.TestTolerance = 0;
RegOutpDMASSTCC14.WrittenIn = {'DmaCfgAndUsePer1'};
RegOutpDMASSTCC14.WriteType = 'Phy';


RegOutpDMASSTCC15 = DataDict.OpSignal;
RegOutpDMASSTCC15.LongName = 'Register DMASSTCC15';
RegOutpDMASSTCC15.Description = 'Register DMASSTCC15';
RegOutpDMASSTCC15.DocUnits = 'Cnt';
RegOutpDMASSTCC15.SwcShoName = 'DmaCfgAndUse';
RegOutpDMASSTCC15.EngDT = dt.u08;
RegOutpDMASSTCC15.EngInit = 0;
RegOutpDMASSTCC15.EngMin = 0;
RegOutpDMASSTCC15.EngMax = 1;
RegOutpDMASSTCC15.TestTolerance = 0;
RegOutpDMASSTCC15.WrittenIn = {'DmaWaitForMotCtrlTo2MilliSecTrf'};
RegOutpDMASSTCC15.WriteType = 'Phy';


RegOutpDMASSTCC9 = DataDict.OpSignal;
RegOutpDMASSTCC9.LongName = 'Register DMASSTCC9';
RegOutpDMASSTCC9.Description = 'Register DMASSTCC9';
RegOutpDMASSTCC9.DocUnits = 'Cnt';
RegOutpDMASSTCC9.SwcShoName = 'DmaCfgAndUse';
RegOutpDMASSTCC9.EngDT = dt.u08;
RegOutpDMASSTCC9.EngInit = 0;
RegOutpDMASSTCC9.EngMin = 0;
RegOutpDMASSTCC9.EngMax = 1;
RegOutpDMASSTCC9.TestTolerance = 0;
RegOutpDMASSTCC9.WrittenIn = {'DmaEna2MilliSecToMotCtrlTrf'};
RegOutpDMASSTCC9.WriteType = 'Phy';


RegOutpTSG31CMPWE = DataDict.OpSignal;
RegOutpTSG31CMPWE.LongName = 'Register TSG31CMPWE';
RegOutpTSG31CMPWE.Description = 'TSG31CMPWE Reg Destination Address';
RegOutpTSG31CMPWE.DocUnits = 'Cnt';
RegOutpTSG31CMPWE.SwcShoName = 'DmaCfgAndUse';
RegOutpTSG31CMPWE.EngDT = dt.u32;
RegOutpTSG31CMPWE.EngInit = 0;
RegOutpTSG31CMPWE.EngMin = 0;
RegOutpTSG31CMPWE.EngMax = 4294967295;
RegOutpTSG31CMPWE.TestTolerance = 0;
RegOutpTSG31CMPWE.WrittenIn = {'DmaCfgAndUseInit1'};
RegOutpTSG31CMPWE.WriteType = 'Phy';


RegOutpTSG31DCMP0E = DataDict.OpSignal;
RegOutpTSG31DCMP0E.LongName = 'Register TSG31DCMP0E';
RegOutpTSG31DCMP0E.Description = [...
  'TSG31DCMP0E Reg Destination Address'];
RegOutpTSG31DCMP0E.DocUnits = 'Cnt';
RegOutpTSG31DCMP0E.SwcShoName = 'DmaCfgAndUse';
RegOutpTSG31DCMP0E.EngDT = dt.u32;
RegOutpTSG31DCMP0E.EngInit = 0;
RegOutpTSG31DCMP0E.EngMin = 0;
RegOutpTSG31DCMP0E.EngMax = 4294967295;
RegOutpTSG31DCMP0E.TestTolerance = 0;
RegOutpTSG31DCMP0E.WrittenIn = {'DmaCfgAndUseInit1'};
RegOutpTSG31DCMP0E.WriteType = 'Phy';



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

d2MilliSecAdcActDmaTrfTi = DataDict.Display;
d2MilliSecAdcActDmaTrfTi.LongName = '2ms ADC Actual Dma Transfer time';
d2MilliSecAdcActDmaTrfTi.Description = 'Display variable used to help understand the Actual Dma Transfer time';
d2MilliSecAdcActDmaTrfTi.DocUnits = 'Cnt';
d2MilliSecAdcActDmaTrfTi.EngDT = dt.u32;
d2MilliSecAdcActDmaTrfTi.EngMin = 0;
d2MilliSecAdcActDmaTrfTi.EngMax = 4294967295;
d2MilliSecAdcActDmaTrfTi.InitRowCol = [1  1];


d2MilliSecAdcMaxDmaTrfTi = DataDict.Display;
d2MilliSecAdcMaxDmaTrfTi.LongName = '2ms ADC Maximum Dma Transfer time';
d2MilliSecAdcMaxDmaTrfTi.Description = 'Display variable used to help understand the Maximum Dma Transfer time';
d2MilliSecAdcMaxDmaTrfTi.DocUnits = 'Cnt';
d2MilliSecAdcMaxDmaTrfTi.EngDT = dt.u32;
d2MilliSecAdcMaxDmaTrfTi.EngMin = 0;
d2MilliSecAdcMaxDmaTrfTi.EngMax = 4294967295;
d2MilliSecAdcMaxDmaTrfTi.InitRowCol = [1  1];
%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------
DmaCfgAndUse2MilliSecAdcStrtTi = DataDict.PIM;
DmaCfgAndUse2MilliSecAdcStrtTi.LongName = 'Dma Configuration and Use 2ms ADC Start Time';
DmaCfgAndUse2MilliSecAdcStrtTi.Description = 'ADC Conversion transfer start time';
DmaCfgAndUse2MilliSecAdcStrtTi.DocUnits = 'Cnt';
DmaCfgAndUse2MilliSecAdcStrtTi.EngDT = dt.u32;
DmaCfgAndUse2MilliSecAdcStrtTi.EngMin = 0;
DmaCfgAndUse2MilliSecAdcStrtTi.EngMax = 4294967295;
DmaCfgAndUse2MilliSecAdcStrtTi.InitRowCol = [1  1];

%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------
MAXWAIT_MICROSEC_U32 = DataDict.Constant;
MAXWAIT_MICROSEC_U32.LongName = 'Max Wait';
MAXWAIT_MICROSEC_U32.Description = 'Max wait time allowed for ADC transfer Complete ' ;
MAXWAIT_MICROSEC_U32.DocUnits = 'Cnt';
MAXWAIT_MICROSEC_U32.EngDT = dt.u32;
MAXWAIT_MICROSEC_U32.EngVal = 400;
MAXWAIT_MICROSEC_U32.Header = 'None';
MAXWAIT_MICROSEC_U32.Define = 'Local';


MCUDIAGCERRINJ = DataDict.ConfigParam;
MCUDIAGCERRINJ.LongName = 'MCU Diagnostic Error Injection';
MCUDIAGCERRINJ.Description = [...
 'This is false for production builds.  It is set to true at compile tim' ...
 'e only for s/w special builds with MCU Error Injection active.'];
MCUDIAGCERRINJ.IsBuildPrm = false;
MCUDIAGCERRINJ.DocUnits = 'Cnt';
MCUDIAGCERRINJ.EngDT = dt.lgc;
MCUDIAGCERRINJ.EngVal = 0;
MCUDIAGCERRINJ.EngMin = 0;
MCUDIAGCERRINJ.EngMax = 1;
MCUDIAGCERRINJ.Define = 'Global';


STD_ON = DataDict.Constant;
STD_ON.LongName = 'Standard On';
STD_ON.Description = 'TRUE';
STD_ON.DocUnits = 'Cnt';
STD_ON.EngDT = dt.lgc;
STD_ON.EngVal = 1;
STD_ON.Define = 'Global';


STD_OFF = DataDict.Constant;
STD_OFF.LongName = 'Standard Off';
STD_OFF.Description = 'FALSE';
STD_OFF.DocUnits = 'Cnt';
STD_OFF.EngDT = dt.lgc;
STD_OFF.EngVal = 0;
STD_OFF.Define = 'Global';
%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
%end of Data Dictionary
