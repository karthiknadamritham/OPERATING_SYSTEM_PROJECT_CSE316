@echo off
echo Choose Algorithm to Run:
echo 1. FCFS
echo 2. SJF
echo 3. Priority
echo 4. Preemptive Priority
echo 5. Round Robin
set /p choice=Enter choice [1-5]:

if "%choice%"=="1" g++ fcfs.cpp -o run.exe && run.exe
if "%choice%"=="2" g++ sjf.cpp -o run.exe && run.exe
if "%choice%"=="3" g++ priority.cpp -o run.exe && run.exe
if "%choice%"=="4" g++ pp.cpp -o run.exe && run.exe
if "%choice%"=="5" g++ rr.cpp -o run.exe && run.exe

echo.
echo Generating Gantt Chart...
python plot_schedule.py
pause
