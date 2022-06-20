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

ll expon (ll y) {
    ll sum = 1;
    for (int i = 0; i < y; i++) {
        sum *= 10;

    }
    return sum;
}


// very long-thought solution (google a better one)
// idea: take index k and find the digits of the numbers k is present in
// ex: k = 9 represents 1 digit number 9, but k = 189 represents 2 digit number 99
// then, once you find the digits present in the numbers, do k - (index of first number of that digit i.e. 10, 100, 1000, 10000, etc) and find remainder
// get the actual number by dividing rem by num of digits and then adding that to 10, 100, 1000 etc. (whichever has the right amount of digits
// once num is found, turn it into a string and find the specific number using modulo with rem and # of digits of number

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll k;

    while (cin >> k) {
        ll digits = 1;
        ll index = 9;
        ll lastindex;
        if (k <= 9) {
            cout << k << "\n";
            continue;
        }
        while (k > (index)) {
            digits += 1;
            lastindex = index;
            index = index + ((9*digits) * expon(digits-1));

        }
        ll rem = (k-(lastindex+1));
        ll toAdd = rem/digits;
        ll number = expon(digits-1) + toAdd;
        ll digitOfNumber = rem % digits;
        string s = to_string(number);
        cout << s[digitOfNumber] << "\n";
    }

    return 0;
}
