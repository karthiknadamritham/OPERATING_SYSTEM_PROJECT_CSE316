#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Process {
    string id;
    int arrival, burst, priority, start, end;
    bool done;
};

int main() {
    vector<Process> p = {
        {"P1", 0, 4, 2},
        {"P2", 1, 3, 1},
        {"P3", 2, 1, 3}
    };
    int n = p.size(), time = 0, done = 0;
    ofstream fout("schedule.csv");
    fout << "Process,Start,End\n";

    for (int i = 0; i < n; ++i) p[i].done = false;

    while (done < n) {
        int idx = -1, high = 1e9;
        for (int i = 0; i < n; ++i) {
            if (!p[i].done && p[i].arrival <= time && p[i].priority < high) {
                high = p[i].priority;
                idx = i;
            }
        }

        if (idx == -1) { time++; continue; }

        p[idx].start = time;
        p[idx].end = time + p[idx].burst;
        time = p[idx].end;
        p[idx].done = true;
        done++;
        fout << p[idx].id << "," << p[idx].start << "," << p[idx].end << "\n";
    }

    fout.close();
    return 0;
}
