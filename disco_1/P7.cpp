#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define SET_IO freopen("input.txt","r",stdin);
int n;
vector<vector<int>> trans_closure(vector<vector<int>> a) {
	vector<vector<int>> ans = a;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][j] = (ans[i][j] | (ans[i][k] & ans[k][j]));
			}
		}
	}
	return ans;
}

int main() {
	SET_IO;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>> ans = trans_closure(a);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			cout << ans[i][j] << "$";
		}
		cout << ans[i][n - 1] << "$$";
	}
	for (int j = 0; j < n - 1; j++) {
		cout << ans[n - 1][j] << "$";
	}
	cout << ans[n - 1][n - 1];
}