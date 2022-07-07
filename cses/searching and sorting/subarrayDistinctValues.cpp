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
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

const int MOD = 1e9+7;
const int INF = 1e9;


//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<ll> s;
    multiset<ll> ms;
    ll ans = 0;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    bool e = true;
    for (ll rb = 0, lb = 0; rb < n; rb++) {
        s.insert(v[rb]);
        if (e) {
            ms.insert(v[rb]);
        }
        e = true;
        if (sz(s) <= k) {
            ans = ans + (rb - lb);
        } else {
            if ((ms.count(v[lb]) == 1)) {
                s.erase(v[lb]);
            }
            ms.erase(ms.find(v[lb]));
            lb++;
            rb--;
            e = false;
        }


    }
    cout << ans+n;



    return 0;
}
