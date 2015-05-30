@echo off
:: BatchGotAdmin
:-------------------------------------
REM  --> Check for permissions
>nul 2>&1 "%SYSTEMROOT%\system32\cacls.exe" "%SYSTEMROOT%\system32\config\system"

REM --> If error flag set, we do not have admin.
if '%errorlevel%' NEQ '0' (
    
    goto UACPrompt
) else ( goto gotAdmin )

:UACPrompt
    echo Set UAC = CreateObject^("Shell.Application"^) > "%temp%\getadmin.vbs"
    set params = %*:"=""
    echo UAC.ShellExecute "cmd.exe", "/c %~s0 %params%", "", "runas", 1 >> "%temp%\getadmin.vbs"

    "%temp%\getadmin.vbs"
    del "%temp%\getadmin.vbs"
    exit /B

:gotAdmin
    pushd "%CD%"
    CD /D "%~dp0"
:--------------------------------------
@echo on
mingw32-gcc.exe -Wall -std=c99 -g -I..\..\SDL\32\include -c D:\Development\CWorkspace\Brikz\src\Brikz.c -o obj\Debug\Brikz.o
//mingw32-gcc.exe -Wall -std=c99 -g -I..\..\SDL\32\include -c D:\Development\CWorkspace\Brikz\src\levelMaker.c -o obj\Debug\levelMaker.o
//mingw32-gcc.exe -Wall -std=c99 -g -I..\..\SDL\32\include -c D:\Development\CWorkspace\Brikz\src\levels.c -o obj\Debug\levels.o
//mingw32-gcc.exe -Wall -std=c99 -g -I..\..\SDL\32\include -c D:\Development\CWorkspace\Brikz\src\MainMenu.c -o obj\Debug\MainMenu.o
//mingw32-gcc.exe -Wall -std=c99 -g -I..\..\SDL\32\include -c D:\Development\CWorkspace\Brikz\src\Program.c -o obj\Debug\Program.o
//mingw32-g++.exe -L..\..\SDL\32\lib -o Brikz.exe obj\Debug\Brikz.o obj\Debug\levelMaker.o obj\Debug\levels.o obj\Debug\MainMenu.o obj\Debug\Program.o -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL_gfx
//pause
//C:\Program Files (x86)\CodeBlocks\MinGW
start %comspec% /k ""C:\TDM-GCC-64\mingwvars.bat""