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
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll lb = *max_element(v.begin(), v.end());
    ll rb = 1e18;
    ll ans = 1e18;
    while (lb <= rb) {
        ll mb = (lb + rb)/2;
        ll divisions = 1;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + v[i] > mb) {
                sum = 0;
                divisions++;
            }
            sum += v[i];
        }
        if (divisions > k) {
            lb = mb + 1;
        } else {
            if (ans > mb) {
                ans = mb;
            }
            rb = mb - 1;
        }
    }
    cout << ans;

    return 0;
}
