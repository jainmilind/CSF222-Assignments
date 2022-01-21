#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
#define SET_IO freopen("input.txt","r",stdin);

void print_set(set<int> st) {
	if (st.size() == 0) {
		cout << "null set";
	}
	else {
		for (auto it = st.begin(); it != st.end(); it++) {
			cout << *it << " ";
		}
	}
	cout << endl;
}

int main() {
	SET_IO;
	set<int> A, B;
	int n, m;
	cin >> n; //size of set A
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		A.insert(x);
	}
	cin >> m; //size of set B
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		B.insert(x);
	}
	set<int> intersection;
	for (auto it = A.begin(); it != A.end(); it++) {
		if (B.find(*it) != B.end()) {
			intersection.insert(*it);
		}
	}
	set<int> union_set;
	for (auto it = A.begin(); it != A.end(); it++) {
		union_set.insert(*it);
	}
	for (auto it = B.begin(); it != B.end(); it++) {
		union_set.insert(*it);
	}
	set<int> subtract;
	for (auto it = A.begin(); it != A.end(); it++) {
		subtract.insert(*it);
	}
	for (auto it = B.begin(); it != B.end(); it++) {
		if (subtract.find(*it) != subtract.end()) {
			subtract.erase(subtract.find(*it));
		}
	}
	print_set(intersection);
	print_set(union_set);
	print_set(subtract);
}