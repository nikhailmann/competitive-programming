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
            cout << 0 << " ";
        }
        return 0;
   }
   if (k==2) {
        for (int i = 0; i < n-1; i++) {
            cout << abs(v[i+1] - v[i]) << " ";
        }
        return 0;
   }
   vector<pair<int,int>> start(k);
   for (int i=0;i<k;i++) {
        start[i].first = v[i];
        start[i].second = i;
   }
   sort(start.begin(), start.end());
   ll lsum = 0;
   ll rsum = 0;
   for (int i = 0; i < k/2 + (k%2); i++)  {
        l.insert(start[i]);
        lsum += start[i].first;
   }
   for (int i = k/2 + (k%2); i < k; i++)  {
        r.insert(start[i]);
        rsum += start[i].first;
   }
   auto x = *l.rbegin();
   ll med = x.first;
   cout << sz(l)*med - lsum + rsum - sz(r)*med << " ";
   for (int j = 1; j < n-k+1; j++) {
        if (l.count({v[j-1],j-1})) {
            l.erase({v[j-1],j-1});
            lsum -= v[j-1];
        } else {
            r.erase({v[j-1],j-1});
            rsum -= v[j-1];
        }
        if (*(l.rbegin()) < mp(v[k-1+j], k-1+j)) {
            r.insert({v[k-1+j], k-1+j});
            rsum += v[k-1+j];

        } else {
            l.insert({v[k-1+j], k-1+j});
            lsum += v[k-1+j];
        }
        while (sz(l) < k/2+(k%2)) {
            pair<int,int> a = *r.begin();
            l.insert(a);
            lsum += a.first;
            r.erase(a);
            rsum -= a.first;
        }
         while (sz(l) > k/2+(k%2)) {
            pair<int,int> a = *l.rbegin();
            l.erase(a);
            lsum -= a.first;
            r.insert(a);
            rsum += a.first;
        }
        auto x = *l.rbegin();
        ll med = x.first;
        cout << sz(l)*med - lsum + rsum - sz(r)*med << " ";
   }





    return 0;
}
/*
slow sol

    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ordered_set<pair<int,int>> s;
    for (int i = 0; i<k; i++){
        s.insert({v[i], i});
    }
    ll med = (*s.find_by_order((k-1)/2)).first;
    ll sum = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        sum += abs((*it).first - med);
    }
    cout << sum << " ";
    for (int i = 1; i < n-k+1; i++) {
        s.erase({v[i-1], i-1});
        s.insert({v[i+k-1], i+k-1});
        med = (*s.find_by_order((k-1)/2)).first;
        sum = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            sum += abs((*it).first - med);
        }
        cout << sum << " ";
    }
    */
