#include <iostream>
using namespace std;

struct process {
    int id;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void sortByPriority(process p[], int n) {
    process temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void calculateTimes(process p[], int n) {
    p[0].waiting_time = 0;

    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }

    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void printProcess(process p[], int n) {
    float totalWT = 0, totalTAT = 0;

    cout << "\nPID\tBurstTime\tPriority\tWaitingTime\tTurnaroundTime\n";

    for (int i = 0; i < n; i++) {
        totalWT += p[i].waiting_time;
        totalTAT += p[i].turnaround_time;

        cout << p[i].id << "\t"
             << p[i].burst_time << "\t\t"
             << p[i].priority << "\t\t"
             << p[i].waiting_time << "\t\t"
             << p[i].turnaround_time << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << endl;
}

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    process p[100];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;

        cout << "Enter Burst Time and Priority for Process " << p[i].id << ": ";
        cin >> p[i].burst_time >> p[i].priority;
    }

    sortByPriority(p, n);
    calculateTimes(p, n);
    printProcess(p, n);

    return 0;
}


//3 // // 

//546 // // 

//312       
