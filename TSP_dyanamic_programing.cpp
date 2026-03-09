#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e9;
int Graph[50][50];        // adjacency matrix
int dp[1<<15][15];        // DP table (supports up to 15 cities)
int n;                    // number of nodes

int tsp(int mask, int pos) {
    if (mask == (1<<n) - 1) // all cities visited
        return Graph[pos][0]; // return to start

    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if (!(mask & (1<<city)) && Graph[pos][city] > 0) { // if city not visited and path exists
            int newAns = Graph[pos][city] + tsp(mask | (1<<city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    int p, src, des, cost;

    cout << "Enter the number of nodes :- ";
    cin >> n;
    cout << "Enter the number of paths :- ";
    cin >> p;

    // Initialize adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            Graph[i][j] = 0;

    // Input paths
    for(int i = 0; i < p; i++) {
        cout << "Enter source, destination, cost :- ";
        cin >> src >> des >> cost;
        Graph[src][des] = cost;
        Graph[des][src] = cost; // if undirected
    }

    // Print adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }

    memset(dp, -1, sizeof(dp));

    cout << "Minimum TSP cost: " << tsp(1, 0) << endl;
    return 0;
}