@Echo Off
setlocal

for %%* in (../.) do set SWC=%%~n*

for /D %%G in ("..\..\*_EPS_*") do set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

echo Deleting Old Directory
rmdir %INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\ImcArbn /s /q
rmdir %INTPJTDIR%\tools\SIP\Generators\Components\_Schemes\ImcArbn /s /q
rmdir %INTPJTDIR%\tools\SIP\BSWMD\ImcArbn /s /q
echo Copying New Directory
mkdir %INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\ImcArbn
mkdir %INTPJTDIR%\tools\SIP\Generators\Components\_Schemes\ImcArbn\bswmd
mkdir %INTPJTDIR%\tools\SIP\BSWMD\ImcArbn
xcopy ..\autosar\ImcArbn_bswmd.arxml               %INTPJTDIR%\tools\SIP\Generators\Components\_Schemes\ImcArbn\bswmd /s
xcopy ..\autosar\ImcArbn_bswmd.arxml               %INTPJTDIR%\tools\SIP\BSWMD\ImcArbn /s
xcopy ..\tools\IntegrationCopy\Configurator         %INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\ImcArbn /s /y

pause
:end

endlocal
