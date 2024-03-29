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
    int n; cin >> n;
    ll sum = n*(n+1)/2;
    if (sum%2==1) {
        cout << 0;
        return 0;
    }
    sum /= 2;
    vector<vector<ll>> dp(n, vector<ll>(sum+1,0));
    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] += dp[i-1][j]; // if we don't include num i
            if (j-i >= 0) {
                dp[i][j] += dp[i-1][j-i]; // if we include num i
            }
            dp[i][j] %= MOD;

        }
    }
    cout << dp[n-1][sum];






    return 0;
}
