#!/bin/bash

echo "Choose an algorithm:"
echo "1. FCFS"
echo "2. SJF"
echo "3. Priority"
echo "4. Preemptive Priority"
read -p "Enter choice [1-4]: " choice

case $choice in
    1) g++ fcfs.cpp -o run && ./run ;;
    2) g++ sjf.cpp -o run && ./run ;;
    3) g++ priority.cpp -o run && ./run ;;
    4) g++ pp.cpp -o run && ./run ;;
    *) echo "Invalid choice" && exit 1 ;;
esac

python3 plot_schedule.py
