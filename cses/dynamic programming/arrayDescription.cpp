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
    int n, m;
    cin >> n >> m;
    vi values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(m+1, 0)); // how to declare 2d vector https://stackoverflow.com/questions/28663299/declaring-a-2d-vector
    if (values[0] == 0) {
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][values[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (values[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] += dp[i-1][j];
                if (j-1 >= 1) dp[i][j] += dp[i-1][j-1];
                if (j+1 <= m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        } else {
            int curval = values[i];
            dp[i][curval] += dp[i-1][curval];
            if (curval-1 >= 1) dp[i][curval] += dp[i-1][curval-1];
            if (curval+1 <= m) dp[i][curval] += dp[i-1][curval+1];
            dp[i][curval] %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m;  i++){
        ans += dp[n-1][i];
        ans %= MOD;
    }
    cout << ans;



    return 0;
}
