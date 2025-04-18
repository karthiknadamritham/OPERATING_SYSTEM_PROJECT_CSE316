#include <iostream>
using namespace std;

int main()
{
    int n = 3;                         // Number of processes
    int arrival[] = {0, 1, 2};         // Arrival times
    int burst[] = {5, 3, 8};           // Burst times
    int completion[3], turnaround[3], waiting[3];

    int time = 0; // CPU  current time

    // FCFS Scheduling
    for (int i = 0; i < n; i++)
    {
        if (time < arrival[i])
            time = arrival[i];

        completion[i] = time + burst[i];                  // Completion time 
        turnaround[i] = completion[i] - arrival[i];       // Turnaround time
        waiting[i] = turnaround[i] - burst[i];            // Waiting time

        time = completion[i]; 
    }

    // Output Table
    cout << "PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << "\t" << arrival[i] << "\t" << burst[i] << "\t"
             << completion[i] << "\t\t" << turnaround[i] << "\t\t" << waiting[i] << endl;
    }

    return 0;
}
