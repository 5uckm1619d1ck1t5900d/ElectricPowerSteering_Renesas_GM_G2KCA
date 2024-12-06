@Echo Off
set /p UpdateContract= Do you want to update contract files with latest files in autosar folder. CAUTION: This will overwite contents in the contract folder. (Y or N)?
echo.

if "%UpdateContract%" == "N" (goto NoUpdate)
xcopy ..\autosar	.\contract\framework\Config\Developer /y
:NoUpdate
..\..\TL101A_CptRteGen\tools\RteGen4.3.0\DaVinciConfigurator\Core\DVCfgCmd -p "./contract/framework/ImcArbn.dpa" -m /MICROSAR/Rte -g --genArg="Rte: -m ImcArbn -g c -o c="..\tools\contract\generate\RteGen"" 
pause
