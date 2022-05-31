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

ll sq(ll base) {
    return base * base; // used pow here before and it was not precise enough
    }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll,ll>> points(n);
    ll p;
    ll i = 0;
    ll loopnum = 0;
    while (cin >> p) {
        if (loopnum%2 == 0) {
            points[i].F = p;
        } else {
            points[i].S = p;
            i++;
        }
        loopnum++;
    }
    ll out;
    for (auto x : points) {
        if ((x.F >= x.S) && x.F %2 == 0) {
            out = sq(x.F) - (x.S-1);
        } else if ((x.F >= x.S) && x.F%2 != 0) {
            out = sq(x.F-1) +1 + (x.S - 1);
        } else if ((x.S > x.F) && x.S%2 != 0) {
            out = sq(x.S) - (x.F - 1);
        } else if ((x.S > x.F) && x.S%2 == 0) {
            out = sq(x.S-1) + 1 + (x.F -1);

        }
        cout << out << "\n";

    }
    return 0;
}
