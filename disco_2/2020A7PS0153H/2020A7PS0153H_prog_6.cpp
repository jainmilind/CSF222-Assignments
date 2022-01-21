#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct union_find {
    vector<int> data;
    int components = 0;
    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }
    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }
    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (-data[x] < -data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x)
                edges.push_back({ x,i,j });
        }
    union_find d(n);
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto& i : edges) {
        int w = i[0], x = i[1], y = i[2];
        if (d.unite(x, y)) ans += w;
    }
    cout << ans;
}