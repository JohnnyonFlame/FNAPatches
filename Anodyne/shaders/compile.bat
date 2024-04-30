mkdir out
echo off

rem -------------------------------

setlocal enabledelayedexpansion
for %%f in (*.fx) do (
    echo -- Compiling %%f --
    ..\..\dxsdk\fxc.exe /nologo /T fx_2_0 /O3 %%f /Fo out/%%f%b
    if !errorlevel! neq 0 exit /b !errorlevel!
)

echo -----------------------------
echo - Compilation Successful :) -
echo -----------------------------