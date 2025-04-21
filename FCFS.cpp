#include <iostream>
#include <fstream>
using namespace std;

struct Process {
    string id;
    int arrival;
    int burst;
    int start;
    int end;
};

int main() {
    ofstream fout("schedule.csv");
    fout << "Process,Start,End\n";

    Process p[3] = {
        {"P1", 0, 5, 0, 5},
        {"P2", 1, 3, 5, 8},
        {"P3", 2, 4, 8, 12}
    };

    for (int i = 0; i < 3; ++i) {
        fout << p[i].id << "," << p[i].start << "," << p[i].end << "\n";
    }

    fout.close();
    return 0;
}
