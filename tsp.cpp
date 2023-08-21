#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_CITIES = 10;
const int INF = INT_MAX;

int n, cost = 0;
int a[MAX_CITIES][MAX_CITIES];
vector<int> visited(MAX_CITIES, 0);

void getCostMatrix() {
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        visited[i] = 0;
    }
}

int findMinCost(int city) {
    visited[city] = 1;
    cout << city + 1 << " -> ";

    int nearestCity = INF;
    int minCost = INF;

    for (int i = 0; i < n; i++) {
        if (a[city][i] != 0 && !visited[i]) {
            int tempCost = a[city][i] + findMinCost(i);
            if (tempCost < minCost) {
                minCost = tempCost;
                nearestCity = i;
            }
        }
    }

    if (nearestCity == INF) {
        nearestCity = 0;
        cout << nearestCity + 1;
        cost += a[city][nearestCity];
    }

    return nearestCity;
}

void printMinimumCost() {
    cout << "\n\nMinimum cost: " << cost << "\n";
}

int main() {
    getCostMatrix();
    
    cout << "\nThe Path is:\n";
    findMinCost(0);
    
    printMinimumCost();
    return 0;
}
