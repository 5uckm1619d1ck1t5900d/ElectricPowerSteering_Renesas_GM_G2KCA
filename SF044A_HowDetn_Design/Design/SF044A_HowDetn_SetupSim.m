%% Simulation Setup Script for SF044A Hands On Wheel Detection
clear,clc
 
run SF044A_HowDetn_DataDict
Ts =0.002;

%%
% Simulink.BlockDiagram.loadActiveConfigSet('SF044A_HowDetn','NxtrMBDConfig.mat')