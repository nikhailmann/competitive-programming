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
const ll INF = 1e18;


//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n+1);
    for (int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        v[i] = x + v[i-1];
    }
    multiset<ll> s;
    ll ans = -INF;
    for (int i = a; i <= b; i++){
        s.insert(v[i]);
    }
    for (int i = 1; i <= n-a+1; i++) {
        ans = max(ans, *s.rbegin() - v[i-1]);
        s.erase(s.find(v[i+a-1]));
        if (i+b <= n) {
            s.insert(v[i+b]);
        }

    }
    cout << ans;




    return 0;
}
