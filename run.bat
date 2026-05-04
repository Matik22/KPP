@echo off
cd /d "%~dp0"

taskkill /f /im app.exe >nul 2>&1
del /f /q app.exe >nul 2>&1

echo Compilation...
"C:\msys64\ucrt64\bin\g++.exe" -std=c++17 -I. main.cpp User\User.cpp Auth\Auth.cpp Photographer\Photographer.cpp Administrator\Administrator.cpp Photo\Photo.cpp Menu\CMenu.cpp Menu\CMenuItem.cpp -o app.exe
if %errorlevel% neq 0 (
    echo Compilation error!
    pause
    exit /b 1
)

echo Running...
chcp 65001 >nul
app.exe
pause