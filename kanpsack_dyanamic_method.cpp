#include <iostream>
#include <algorithm> // for std::max
using namespace std;

int main() {
    int Table[51][51], P[51], W[51];
    int o, m;

    cout << "Enter the number of objects: ";
    cin >> o;

    cout << "Enter the profit of the objects: ";
    for (int i = 0; i < o; i++) {
        cin >> P[i];
    }

    cout << "Enter the weight of the objects: ";
    for (int i = 0; i < o; i++) {
        cin >> W[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> m;

    // Initialize DP table
    for (int i = 0; i <= o; i++) {
        Table[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        Table[0][j] = 0;
    }

    // Fill DP table
    for (int i = 1; i <= o; i++) {
        for (int j = 1; j <= m; j++) {
            if (W[i-1] <= j) {
                Table[i][j] = max(Table[i-1][j], P[i-1] + Table[i-1][j-W[i-1]]);
            } else {
                Table[i][j] = Table[i-1][j];
            }
        }
    }

    cout << "Maximum profit is: " << Table[o][m] << endl;
    return 0;
}