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

const int mxN = 1e6;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<ll>> dp(mxN, vector<ll>(8, 0));
    for (int i = 0; i < 8; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < mxN; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5) { // different states based on height of 2 having 8 base cases
                dp[i][j] += dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5];
                dp[i][j] %= MOD;
            } else if (j == 1 || j == 6 || j == 7){
                dp[i][j]+= dp[i-1][2] + dp[i-1][6] + dp[i-1][7];
                dp[i][j] %= MOD;
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        ll ans = dp[n-1][2] + dp[n-1][6];
        ans %= MOD;
        cout << ans<< "\n";
    }



    return 0;
}
