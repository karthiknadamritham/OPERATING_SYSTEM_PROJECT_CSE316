#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Process {
    string id;
    int arrival, burst, remaining, priority;
    int lastStart = -1;
    bool done = false;
};

int main() {
    vector<Process> p = {
        {"P1", 0, 7, 7, 2},
        {"P2", 1, 4, 4, 1},
        {"P3", 2, 1, 1, 3}
    };

    int n = p.size(), time = 0, done = 0;
    ofstream fout("schedule.csv");
    fout << "Process,Start,End\n";

    string lastProc = "";
    int segmentStart = 0;

    while (done < n) {
        int idx = -1, pr = 1e9;
        for (int i = 0; i < n; ++i) {
            if (!p[i].done && p[i].arrival <= time && p[i].priority < pr && p[i].remaining > 0) {
                pr = p[i].priority;
                idx = i;
            }
        }

        if (idx == -1) { time++; continue; }

        if (p[idx].id != lastProc) {
            if (lastProc != "") {
                fout << lastProc << "," << segmentStart << "," << time << "\n";
            }
            segmentStart = time;
            lastProc = p[idx].id;
        }

        p[idx].remaining--;
        time++;

        if (p[idx].remaining == 0) {
            p[idx].done = true;
            done++;
        }
    }

    if (lastProc != "")
        fout << lastProc << "," << segmentStart << "," << time << "\n";

    fout.close();
    return 0;
}
