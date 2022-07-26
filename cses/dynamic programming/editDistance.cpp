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
    string str1, str2;
    cin >> str1 >> str2;
    int n = sz(str1); int m = sz(str2);
    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] +1);
            }
            if (j) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] +1);
            }
            if (i && j) {
                int same = str1[i-1] == str2[j-1] ? 0 : 1;
                int comp = dp[i-1][j-1] + same;
                dp[i][j] = min(dp[i][j], comp);
            }
        }
    }
    cout << dp[n][m];




    return 0;
}
