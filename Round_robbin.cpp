#include <iostream>
using namespace std;

int main() {
    int i, NOP, sum = 0, count = 0, y, quant;
    int wt = 0, tat = 0;
    int at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    cout << "Total number of processes in the system: ";
    cin >> NOP;

    y = NOP;

    for(i = 0; i < NOP; i++) {
        cout << "\nEnter Arrival Time and Burst Time for Process " << i + 1 << endl;

        cout << "Arrival Time: ";
        cin >> at[i];

        cout << "Burst Time: ";
        cin >> bt[i];

        temp[i] = bt[i];
    }

    cout << "\nEnter Time Quantum: ";
    cin >> quant;

    cout << "\nProcess No\tBurst Time\tTAT\tWaiting Time\n";

    for(sum = 0, i = 0; y != 0; ) {

        if(temp[i] <= quant && temp[i] > 0) {
            sum += temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if(temp[i] > 0) {
            temp[i] -= quant;
            sum += quant;
        }

        if(temp[i] == 0 && count == 1) {
            y--;

            cout << "P" << i + 1 << "\t\t"
                 << bt[i] << "\t\t"
                 << sum - at[i] << "\t"
                 << sum - at[i] - bt[i] << endl;

            wt += sum - at[i] - bt[i];
            tat += sum - at[i];

            count = 0;
        }

        if(i == NOP - 1)
            i = 0;
        else if(at[i + 1] <= sum)
            i++;
        else
            i = 0;
    }

    avg_wt = (float)wt / NOP;
    avg_tat = (float)tat / NOP;

    cout << "\nAverage Turnaround Time: " << avg_tat;
    cout << "\nAverage Waiting Time: " << avg_wt << endl;

    return 0;
}