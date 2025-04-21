# OPERATING SYSTEM PROJECT – CPU SCHEDULING VISUALIZER

This project is a simulation of classic **CPU scheduling algorithms** implemented in **C++**, with graphical visualization of Gantt charts using **Python**. It demonstrates how processes are managed by different scheduling strategies in operating systems.

>  Developed as part of the Operating Systems course (CSE316) for submission to the university.

----------------------------------------------------------------------------------------

## Features

- Implementation of five major CPU scheduling algorithms
- Generates process execution timelines in `.csv` format
- Automatic Gantt chart generation using Python & Matplotlib
- Menu-based execution using a batch script (no IDE required)

-------------------------------------------------------------------------------------

##  Scheduling Algorithms Implemented

1. **FCFS** – First Come First Serve  
2. **SJF** – Shortest Job First (Non-preemptive)  
3. **Priority Scheduling** (Non-preemptive)  
4. **Preemptive Priority Scheduling**  
5. **Round Robin** (configurable time quantum)

-------------------------------------------------------------------------------------

## Technologies Used

| Language | Use                    |
|----------|------------------------|
| C++      | Scheduling algorithms  |
| Python   | Plotting Gantt chart   |
| CSV      | Exporting output data  |
| Batch    | One-click execution    |

-------------------------------------------------------------------------------------

## Prerequisites

- Windows PC
- No IDE required
- Must install:
  - [TDM-GCC (C++ Compiler)](https://jmeubank.github.io/tdm-gcc/)
  - [Python](https://www.python.org/downloads/) (with `matplotlib` & `pandas`)

To install required Python packages:
- pip install matplotlib pandas

---------------------------------------------------------------------------------------

Project Structure
├── fcfs.cpp
├── sjf.cpp
├── priority.cpp
├── pp.cpp
├── rr.cpp
├── plot_schedule.py
├── schedule.csv         ← Output after algorithm run
├── run_all.bat          ← One-click launcher
└── README.md

---------------------------------------------------------------------------------------

**How to Run**
Download or clone the repository:
-> git clone https://github.com/karthiknadamritham/OPERATING_SYSTEM_PROJECT_CSE316.git
cd OPERATING_SYSTEM_PROJECT_CSE316

-> Double-click run_all.bat

-> Choose an algorithm (1 to 5)

-> See the Gantt chart generated automatically

-> Gantt Chart Output
  After running any algorithm, schedule.csv will be created with columns:
    Process, Start, End
    The Python script plot_schedule.py reads this file and shows a Gantt chart for visual representation of process execution timelines.

