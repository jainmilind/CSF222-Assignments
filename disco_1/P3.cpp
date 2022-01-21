#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define SET_IO freopen("input.txt","r",stdin);

int main() {
	SET_IO;
	int n; cin >> n;
	int a[n][n];
	int row[n], col[n];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				row[i]++;
				col[j]++;
			}
		}
	}
	int a1 = 1, a2 = 1;
	for (int i = 0; i < n; i++) {
		if (row[i] != 1) {
			a1 = 0;
			break;
		}
		if (col[i] != 1) {
			a2 = 0;
			break;
		}
	}
	if (a1 == 1 and a2 == 1) {
		cout << "11" << endl;
	} else {
		cout << "00" << endl;
	}
}