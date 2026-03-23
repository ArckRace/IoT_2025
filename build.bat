@echo off
REM Build script for test.cpp

if "%1"=="clean" (
    echo Cleaning...
    del /Q test.exe test.o 2>nul
    echo Done!
    goto :eof
)

if "%1"=="run" (
    echo Building and running...
    g++ -Wall -Wextra -std=c++11 -o test test.cpp
    if %errorlevel% equ 0 (
        echo.
        echo Running program:
        echo ================
        test.exe
    ) else (
        echo Build failed!
    )
    goto :eof
)

echo Building...
g++ -Wall -Wextra -std=c++11 -o test test.cpp
if %errorlevel% equ 0 (
    echo Build successful! Use 'build.bat run' to execute.
) else (
    echo Build failed!
)
