#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define SET_IO freopen("input.txt","r",stdin);

int main() {
	SET_IO;
	int n;
	cin >> n;
	int ans[n + 2];
	memset(ans, 0, sizeof(ans));
	ans[0] = 0; ans[1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		ans[i] = ans[i - 1] + ans[i - 2];
	}
	cout << ans[n + 1] << endl;
}