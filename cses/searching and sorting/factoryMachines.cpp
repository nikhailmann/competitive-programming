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
    ll n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v[i] = k;
    }
    sort(v.begin(), v.end());
    ll rb = 1e18, lb = 0, ans = 1e18;
    ll noOverFlow = 1e9;
    while (lb <= rb) {
        ll mb = (lb+rb)/2;
        ll products = 0;
        for (int i = 0; i < n; i++) {
            products += min(mb/v[i], noOverFlow);

        }
        if (products >= t) {
            if (mb < ans) ans = mb;
            rb = mb - 1;
        } else {
            lb = mb+1;
        }
    }
    cout << ans;




    return 0;
}
