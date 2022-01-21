#include <iostream>
#include <cstdio>
using namespace std;
#define SET_IO freopen("input.txt","r",stdin);
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	SET_IO;
	int a, b; cin >> a >> b;
	int ans = 0, g = gcd(a, b);
	a /= g; b /= g;
	int flag = 0;
	for (int i = 2; i < a + b + 1; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j < a + b + 1; j++) {
				if (i > j && gcd(j, i - j) == 1) {
					ans++;
				}
				if (i - j == b && j == a) {
					flag = 1;
					break;
				}
			}
		} else {
			for (int j = a + b; j > 0; j--) {
				if (gcd(j, i - j) == 1 && i > j) {
					ans++;
				}
				if (j == a && i - j == b) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) break;
	}
	printf("position=%d number=%d/%d \n", ans, a, b);
}