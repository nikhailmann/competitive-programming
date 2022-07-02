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
    int n;
    ll k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i < n+1; i++) {
        v.pb(i);
    }

   while (v.size() > 1) {
        ll p = k % v.size();
        vi left;
        vi help;
        for (int i=0; i < v.size(); i++) {
            if (i < p) {
                help.pb(v[i]);
            } else if (i == p){
                cout << v[i] << " ";
            } else {
                left.pb(v[i]);
            }
        }
        for (int j = 0; j < help.size(); j++) {
            left.pb(v[j]);
        }
        v = left;

    }

    cout << v[0];



    return 0;
}
