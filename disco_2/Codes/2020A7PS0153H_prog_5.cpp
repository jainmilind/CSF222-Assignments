#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x)
                adj[i].push_back(j);
        }
    int r; cin >> r;
    r--;
    vector<int> dis(n), vis(n);
    queue<int> q;
    q.push(r);
    vis[r] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i : adj[u]) {
            if (vis[i]) continue;
            vis[i] = 1;
            q.push(i);
            dis[i] = dis[u] + 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << dis[i] << "$ "[i == n - 1];
}