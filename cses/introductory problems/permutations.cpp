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
    vi nums;
    int a = 1;
    int carrier;
    while (a <= n) {
        nums.pb(a);
        a++;
    }

    if (n==1) {
        cout << n;
        return 0;
    } else if (n <= 3){
        cout << "NO SOLUTION";
        return 0;

    } else if (n==4) {
        cout << "2 4 1 3";
        return 0;

    } else if (n%2 == 0){
        for (int i = 0; i < n-3; i+=2) {
            carrier = nums[i];
            nums[i] = nums[i+3];
            nums[i+3] = carrier;
        }

    } else if  (n%2 == 1) {
        for (int i = 0; i < n-4; i+=2) {
            carrier = nums[i];
            nums[i] = nums[i+3];
            nums[i+3] = carrier;
            carrier = nums[i+2];
            nums[i+2] = nums[i+4];
            nums[i+4] = carrier;
        }
    }

    for (auto x : nums) {
        cout << x << " ";
    }

    return 0;
}
