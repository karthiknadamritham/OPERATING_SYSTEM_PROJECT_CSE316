#include <iostream>
using namespace std;

struct Process {
    int id, burstTime, remainingTime, waitingTime, turnaroundTime;
};

int main() {
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter Burst Time for P" << p[i].id << ": ";
        cin >> p[i].burstTime;
        p[i].remainingTime = p[i].burstTime;
        p[i].waitingTime = 0;
    }
}
