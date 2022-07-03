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

struct range {
    int l, r, index;
    bool operator < (const range &other) const {
        if (l == other.l) {
            return r > other.r; // in case left values are tied sort by greater right values
        }
        return l < other.l;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<range> inputs(n);
    int contained[n] = { };
    int contains[n] = { };
    ordered_set<pair<int,int>> s;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        inputs[i].l = a;
        inputs[i].r = b;
        inputs[i].index = i;
    }

    sort(inputs.begin(), inputs.end());
    // contained

    for (int i = 0; i < n; i++) {
       s.insert({inputs[i].r, -1*i});
       contained[inputs[i].index] = sz(s) - s.order_of_key({inputs[i].r, -1*i})-1;
    }
    //contains
    s.clear();
   for (int i = n-1; i >= 0; i--) {
       s.insert({inputs[i].r, -1*i});
       contains[inputs[i].index] = s.order_of_key({inputs[i].r, -1*i});
    }

    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << contained[i] << " ";

    }


    return 0;
}
