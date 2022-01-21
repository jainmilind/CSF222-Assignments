#include "bits/stdc++.h"
using namespace std;
#define forn(i,n) for(int i=n-1;i>=0;i--)
#define in(n) int n; cin>>n;
#define w(x) int x; cin>>x; while(x--)
#define sa(x) sort(x.begin(), x.end())
#define pb(x) insert("x")
#define dbg(x) cerr << #x << "->" << x << "\n"
#define prnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<T<<' ';cerr<<"}\n";
#define prntp(x) cerr<<#x<<'{';for(auto T:x)cerr<<T.first<<'-'<<T.second<<' ';cerr<<"}\n";
#define int long long
#define str(s) string s; cin>>s;
#define endl "\n"
const int N = 1e5 + 1;
#define sz(x) static_cast<int32_t>(x.size())
const int mod = 1000000007;
typedef std::vector<int> vi;
#define matrix vector<vector<int>>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

int32_t main() {
    FAST;
    freopen("input.txt", "r", stdin);
    int count = 3;
    in(n);
    in(m);
    int num = 2;
    int den = 1;
    int h = gcd(n, m);
    n = n / h;
    m = m / h;
    while (num <= n or den <= m) {
        if (den == 1) {
            num++;
            if (gcd(num, den) == 1) {
                count++;
            }
            if (num == n and den == m) {
                cout << count;
                return 0;
            }
        }
        while (num > 1) {
            num--;
            den++;
            if (gcd(num, den) == 1) {
                count++;
            }
            if (num == n and den == m) {
                cout << count;
                return 0;
            }
        }
        if (num == 1) {
            den++;

            if (gcd(num, den) == 1) {
                count++;
            }
            if (num == n and den == m) {
                cout << count;
                return 0;
            }
        }
        while (den > 1) {
            num++;
            den--;
            if (gcd(num, den) == 1) {
                count++;
            }
            if (num == n and den == m) {
                cout << count;
                return 0;
            }
        }
    }






    return 0;
}