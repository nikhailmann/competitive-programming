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
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1));

    for (int i = 0; i <=a; i++) {
        for (int j = 0; j <=b; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INF;

                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
                }
            }
        }
    }
    cout << dp[a][b];



    return 0;
}
