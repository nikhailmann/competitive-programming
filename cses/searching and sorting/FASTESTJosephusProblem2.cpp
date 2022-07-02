#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    ordered_set<int> s;
    for (int i = 1; i < n+1; i++) {
        s.insert(i);
    }
    ll p = k % n;

   while (s.size() > 0) {
        int r = *s.find_by_order(p);
        cout << r << " ";
        s.erase(r);
        if (s.size() > 0) p = (p+k) % s.size();
    }

    return 0;
}
