#include <iostream>
#include <vector>
using namespace std;
vector<int> vis, color;
int n, ans = 1;
vector<vector<int>> adj;
void dfs(int x, int c) {
    vis[x] = 1;
    color[x] = c;
    for (int i : adj[x]) {
        if (vis[i]) continue;
        dfs(i, !c);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vis.resize(n);
    color.resize(n, -1);
    adj.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x)
                adj[i].push_back(j);
        }
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i, 0);
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            if (color[i] == color[j]) {
                cout << 0;
                return 0;
            }
    cout << 1;
}