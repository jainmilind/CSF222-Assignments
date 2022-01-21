#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define SET_IO freopen("input.txt","r",stdin);
int n;
vector<vector<int>> adjacency_list;
vector<int> in_degree;
int main() {
    SET_IO;
    cin >> n;
    int a[n][n];
    adjacency_list.resize(n);
    in_degree.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1 and i != j) {
                adjacency_list[i].push_back(j);
                in_degree[j]++;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int i : adjacency_list[u]) {
            in_degree[i]--;
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
    }
    if (topo.size() != n) {
        cout << "Topological Sorting for given doesnt exist" << endl;
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            cout << topo[i] + 1 << "$";
        }
        cout << topo[n - 1] + 1 << endl;
    }
}