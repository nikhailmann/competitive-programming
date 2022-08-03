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


// you can also use "Towers" problem code changing upper bound to lower bound, although this problem is way harder to understand for some reason
// https://www.youtube.com/watch?v=66w10xKzbRM
//On editorial solution -- the *it = x just changes the value at *it (the lower bound of current element) to the current input
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int it = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        if (it == dp.size()) {
            dp.pb(x);
        } else {
            dp[it] = x;
        }

    }
    cout << dp.size();

    return 0;
}

/* O(n^2) solution
int n; cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> dp(n, 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[j] < s[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
*/

/* testing for working solution
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int it = lower_bound(dp.begin(), dp.end(), x) - dp.begin(); // these are both pointers so this finds the exact position of x in the dp array
        cout << i << " " << x << " " << it << "\n";
        cout << "before ";
        for (int l : dp) {
            cout << l << " ";
        }
        cout << "\n";
        if (it == dp.size()) {
            dp.pb(x);
        } else {
            dp[it] = x;
        }
        cout << "after ";
        for (int l : dp) {
            cout << l << " ";
        }
        cout << "\n";

    }
    cout << dp.size();

    return 0;
}
*/
