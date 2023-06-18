mkdir out
echo off

rem -- Setup shader detail level --

rem - HAS_GRAIN: Number of maximum grain taps on parchmentEffect and gameParchEffect
set HAS_GRAIN=0

rem -------------------------------

setlocal enabledelayedexpansion
for %%f in (*.fx) do (
    echo -- Compiling %%f --
    ..\..\dxsdk\fxc.exe /nologo /DHAS_GRAIN=%HAS_GRAIN% /T fx_2_0 /O3 %%f /Fo out/%%f%b
    if !errorlevel! neq 0 exit /b !errorlevel!
)

echo -----------------------------
echo - Compilation Successful :) -
echo -----------------------------