#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define F first
#define S second
#define mp make_pair

using ll = long long;
using db = long double;
using str = string;
#define lb lower_bound  // First element NOT LESS than val
#define ub upper_bound  // First element GREATER than val

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

const int MOD = 1e9+7;
const int INF = 1e9;


//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> coins(n);
    ll p;
    ll t;
    int i = 0;
    while(cin >> p >> t) {
            coins[i].F = p;
            coins[i].S = t;
            i++;
    }

    for (auto x : coins) {
            if (x.S == 0 && x.F == 0) {
                cout <<"YES\n";
            } else if ((x.S + x.F) < 3) {
                cout << "NO\n";
            } else  if (((x.F + x.S)%3 == 0)) {
                if (x.F >= x.S) {
                    if (x.S *2 >= x.F) {
                        cout <<"YES\n";
                    } else cout << "NO\n";
                } else if (x.F < x.S) {
                    if (x.F *2 >= x.S) {
                        cout <<"YES\n";
                    } else cout << "NO\n";
                }
            } else {
                cout << "NO\n";
            }
        }

    return 0;
}
