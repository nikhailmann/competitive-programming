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
    int rem = n%4;
    vi nums1;
    vi nums2;
    if (rem == 1 || rem == 2) {
        cout << "NO" << "\n";
        return 0;
    } else if (rem == 3) {
        nums1.pb(1);
        nums1.pb(2);
        nums2.pb(3);
        for (int i = 4; i<=n; i+=4){
            nums1.pb(i);
            nums1.pb(i+3);
            nums2.pb(i+1);
            nums2.pb(i+2);
        }
    } else if (rem == 0) {
        nums1.pb(1);
        nums1.pb(4);
        nums2.pb(2);
        nums2.pb(3);
        for (int i = 5; i<=n; i+=4){
            nums1.pb(i);
            nums1.pb(i+3);
            nums2.pb(i+1);
            nums2.pb(i+2);
        }
    }


    cout << "YES\n";
    cout << sz(nums1) << "\n";
    for (auto x : nums1) {
        cout << x << " ";
    }
    cout << "\n" << sz(nums2) << "\n";
    for (auto x : nums2) {
        cout << x << " ";
    }


    return 0;
}
