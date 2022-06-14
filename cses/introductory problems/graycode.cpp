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

vi convertToBinary(ll num) {
    vi binaryForm;
    do {
        ll remain = num % 2;
        binaryForm.insert(binaryForm.begin(), remain);
        num = num/2;
    } while (num != 0);

    return binaryForm;
}


int main() // lesson for future -- keep track of your indices (this took way longer than it should have).
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (ll i = 0; i < pow(2, n); ++i) {
        vi v(n);
        vi binaryN = convertToBinary(i);
        ll siz = sz(binaryN) - 1;
        for (ll j = siz; j > 0; --j) {
            if (binaryN[j] == binaryN[j-1]) {
                v[siz-j] = 0;
            } else {
                v[siz-j] = 1;
            }
        }
        v[(sz(binaryN)-1)] = binaryN[0];
        for (int i = n-1; i >= 0; --i) {
            cout << v[i];
        }
        cout << "\n";
    }



    return 0;
}
