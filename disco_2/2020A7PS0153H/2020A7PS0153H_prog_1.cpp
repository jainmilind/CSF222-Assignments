#include <iostream>
#include <vector>
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
    vector<int> color(n);
    for (int i = 0; i < n; i++) cin >> color[i];
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            if (color[i] == color[j]) {
                cout << 0;
                return 0;
            }
    cout << 1;
}