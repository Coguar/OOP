rem @echo off
SET program="%1"
if %program% == "" goto err

%program% > out.txt
if ERRORLEVEL 2 goto testFailed
fc.exe out.txt CheckOutput1.txt
if ERRORLEVEL 1 goto testFailed

%program% 2 3 > out.txt
if ERRORLEVEL 2 goto testFailed
fc.exe out.txt CheckOutput1.txt
if ERRORLEVEL 1 goto testFailed

%program% 2 3 4 5 > out.txt
if ERRORLEVEL 2 goto testFailed
fc.exe out.txt CheckOutput2.txt
if ERRORLEVEL 1 goto testFailed

%program% 1 3 12 > out.txt
if ERRORLEVEL 2 goto testFailed
fc.exe out.txt WrongNotation.txt
if ERRORLEVEL 1 goto testFailed

%program% 10 37 12 > out.txt
if ERRORLEVEL 2 goto testFailed
fc.exe out.txt WrongNotation.txt
if ERRORLEVEL 1 goto testFailed

%program% 35 13 PPO > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt PPO.txt
if ERRORLEVEL 1 goto testFailed

%program% 35 13 -PPO > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt PPOMinus.txt
if ERRORLEVEL 1 goto testFailed

%program% 35 13 +PPO > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt PPOPLUS.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>