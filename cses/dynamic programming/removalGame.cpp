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
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    //https://www.youtube.com/watch?v=WxpIHvsu1RI video

    vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>>(n));
    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (j == i) {
                dp[i][j].first = x[i];
                dp[i][j].second = 0;
            } else {
                dp[i][j].first = max(dp[i+1][j].second + x[i], dp[i][j-1].second + x[j]);

                if (dp[i+1][j].second + x[i] > dp[i][j-1].second + x[j]) {
                    dp[i][j].second = dp[i+1][j].first;
                } else {
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }
    }

    cout << dp[0][n-1].first;



    return 0;
}
