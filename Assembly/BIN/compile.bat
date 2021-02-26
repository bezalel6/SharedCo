@echo off
tasm /zi %1
tlink /v %1
if %2 == 1 %1
if %2 == 2 td %1
echo.
