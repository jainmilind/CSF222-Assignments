#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int v1, v2; cin >> v1 >> v2;
    int n = v1 + v2;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x) 
                adj[i].push_back(j);
        }
    for (int i = 0; i < (1 << v1); i++) {
        int c1 = 0;
        set<int> st;
        for (int j = 0; j < v1; j++)
            if (1 << j & i) {
                c1++;
                for (int x : adj[j])
                    st.insert(x);
            }
        if (c1 > (int)st.size()) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}