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
    int n, x;
    cin >> n >> x;
    vector<ll> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    vector<pair<ll,ll>> dp(1<<n);
    dp[0] = {1, 0};

    for (int i = 1; i < (1<<n); i++) {
        dp[i] = {n+1, INT_MAX};
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                auto test = dp[i^(1<<j)]; //https://gyazo.com/a3175c6c4ec263b35b11bf70c133c088 the idea is that you add 0's before to perform XOR i.e 1 becomes 0001
                if (test.second + weight[j] <= x) {
                    test.second += weight[j];
                } else {
                    test.first++;
                    test.second = weight[j];
                }
                dp[i] = min(dp[i], test);
            }
        }
    }
    cout << dp[(1<<n)-1].first;

    return 0;
}
