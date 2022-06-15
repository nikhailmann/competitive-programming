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

const int MOD = 1e9+7;
const int INF = 1e9;


//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll p;
    vector<ll> v;
    vector<vector<ll>> allsets;
    ll total = 0;

    while (cin >> p) {
        v.pb(p);
        total += p;
    }

   for (int i = 0; i < (1<<n); i++) { // generate all subsets using bitsets
    vector<ll> subset;
    for (int j = 0; j < n; j++) {
        if (i & (1<<j)) {
            subset.push_back(v[j]);
        }
    }
    allsets.pb(subset);
   }

    ll ans = LLONG_MAX;

    // you can combine this into the first double for loop
    // this basically goes through all subsets, takes the sum of each one, and
    // subtracts that from the total to get the other set of numbers that make up
    // all of the weights
    // it takes the differences between both sets of numbers and saves the one
    // that has the smallest different between them, ans
    for (auto x : allsets) {
        ll sum = 0;
        for (auto y : x) { // used accumulate function originally but there was an error for some test cases.
            sum += y;
        }
        ll curr = abs((total-sum)-sum);
        ans = min(ans, curr);

        }

   cout << ans;





    return 0;
}
