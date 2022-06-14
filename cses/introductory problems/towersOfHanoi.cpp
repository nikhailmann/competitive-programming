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


void solve(vector<pair<int,int>>& sol, int n, int src, int dest, int help) {
    if (n == 1) {
        sol.pb({src, dest});
        return;
    }

    solve(sol, n-1, src, help, dest);
    sol.pb({src, dest});
    solve(sol, n-1, help, dest, src);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    vector<pair<int, int>> v;
    solve(v, n, 1, 3, 2);
    for(auto x : v) {
        cout << x.F << " " << x.S << "\n";
    }
    return 0;
}
