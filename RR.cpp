#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

struct Process {
    string id;
    int arrival, burst, remaining;
    int last_exec = -1;
};

int main() {
    int quantum = 2;
    vector<Process> p = {
        {"P1", 0, 5, 5},
        {"P2", 1, 3, 3},
        {"P3", 2, 4, 4}
    };

    int time = 0, n = p.size(), completed = 0;
    queue<int> q;
    vector<bool> in_queue(n, false);

    ofstream fout("schedule.csv");
    fout << "Process,Start,End\n";

    while (completed < n) {
        for (int i = 0; i < n; ++i)
            if (p[i].arrival <= time && !in_queue[i] && p[i].remaining > 0) {
                q.push(i);
                in_queue[i] = true;
            }

        if (q.empty()) {
            time++;
            continue;
        }

        int idx = q.front(); q.pop();
        int slice = min(quantum, p[idx].remaining);
        fout << p[idx].id << "," << time << "," << time + slice << "\n";

        time += slice;
        p[idx].remaining -= slice;

        for (int i = 0; i < n; ++i)
            if (p[i].arrival <= time && !in_queue[i] && p[i].remaining > 0) {
                q.push(i);
                in_queue[i] = true;
            }

        if (p[idx].remaining > 0) {
            q.push(idx);
        } else {
            completed++;
        }
    }

    fout.close();
    return 0;
}
