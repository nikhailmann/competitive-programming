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
    int n, k;
    cin >> n >> k;
    set<pair<int,int>> l;
    set<pair<int,int>> r;
    vi v(n);
    for (int i = 0; i < n; i++) {
            cin >> v[i];
    }
   if (k==1) {
        for (auto x : v) {
            cout << x << " ";
        }
        return 0;
   }
   if (k==2) {
        for (int i = 0; i < n-1; i++) {
            cout << min(v[i], v[i+1]) << " ";
        }
        return 0;
   }
   vector<pair<int,int>> start(k);
   for (int i=0;i<k;i++) {
        start[i].first = v[i];
        start[i].second = i;
   }
   sort(start.begin(), start.end());
   for (int i = 0; i < k/2 + (k%2); i++)  {
        l.insert(start[i]);
   }
   for (int i = k/2 + (k%2); i < k; i++)  {
        r.insert(start[i]);
   }
   auto x = *l.rbegin();
   cout << x.first << " ";
   for (int j = 1; j < n-k+1; j++) {
        if (l.count({v[j-1],j-1})) {
            l.erase({v[j-1],j-1});
        } else {
            r.erase({v[j-1],j-1});
        }
        if (*(l.rbegin()) < mp(v[k-1+j], k-1+j)) {
            r.insert({v[k-1+j], k-1+j});

        } else {
            l.insert({v[k-1+j], k-1+j});
        }
        while (sz(l) < k/2+(k%2)) {
            pair<int,int> a = *r.begin();
            l.insert(a);
            r.erase(a);
        }
         while (sz(l) > k/2+(k%2)) {
            pair<int,int> a = *l.rbegin();
            l.erase(a);
            r.insert(a);
        }
        cout << (*l.rbegin()).first << " ";
   }





    return 0;
}

/*

You can also use ordered set as an easy solution that should fit time constraints

old slower solution
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) {
            cin >> v[i];
    }
    int lp = 0;
    int rp = k-1;
    for (int i = 0; i < (n-k)+1; i++) {
        auto startc = v.begin() + lp;
        auto endc = v.begin() + rp + 1;
        vi subvec(k);
        subvec = vi(startc, endc);
        sort(subvec.begin(), subvec.end());
        int out = k/2;
        if (k%2 == 0) out--;
        cout << subvec[out] << " ";
        rp++;
        lp++;
    }
    */
