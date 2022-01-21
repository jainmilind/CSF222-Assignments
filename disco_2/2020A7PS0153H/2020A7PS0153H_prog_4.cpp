#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> adj, ans;
vector<int> vis, v;
int n;
void dfs(int x) {
    v.push_back(x);
    vis[x] = 1;
    for (int i : adj[x]) {
        if (vis[i]) continue;
        dfs(i);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    adj.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x)
                adj[i].push_back(j);
        }
    for (int i = 0; i < n; i++) if (!vis[i]) {
        v.clear();
        dfs(i);
        sort(v.begin(),v.end());
        ans.push_back(v);
    }
    cout << ans.size();
    for (auto& i : ans) {
        cout << "$$";
        string p = "";
        for (int j : i)
            p += to_string(j + 1) + "$";
        p.pop_back();
        cout << p;
    }
}