#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define SET_IO freopen("input.txt","r",stdin);
int n;
int anti_symmetric(vector<vector<int>> a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 and a[j][i] == 1 and i != j) {
				return 0;
			}
		}
	}
	return 1;
}
int transitive(vector<vector<int>> a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[i][j] == 1 and a[j][k] == 1 and a[i][k] != 1) {
					return 0;
				}
			}
		}
	}
	return 1;
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
	cout << anti_symmetric(a) << transitive(a) << endl;
}