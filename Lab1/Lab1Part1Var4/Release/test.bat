rem @echo off
SET program="%1"
if %program% == "" goto err

%program% > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt CheckOutput1.txt
if ERRORLEVEL 1 goto testFailed

%program% TrueInput.txt > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt CheckOutput1.txt
if ERRORLEVEL 1 goto testFailed

%program% TrueInput.txt output.txt > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt CheckOutput1.txt
if ERRORLEVEL 1 goto testFailed

%program% TrueInput.txt output.txt word1 word2 word3 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt CheckOutput2.txt
if ERRORLEVEL 1 goto testFailed

%program% help > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt help.txt
if ERRORLEVEL 1 goto testFailed

%program% TrueInput.txt output.txt ma> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt OutputWithoutReplace.txt
if ERRORLEVEL 1 goto testFailed

%program% TrueInput.txt output.txt ma ma> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt OutputWithoutReplace.txt
if ERRORLEVEL 1 goto testFailed

%program% TrueInput.txt output.txt ma mama> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt OutputWithReplace.txt
if ERRORLEVEL 1 goto testFailed

%program% FalseInput.txt output.txt ma mama> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt NotFound.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>