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

/* Notes

Observations:
If you know solve(0)... solve(n), you can calculate
the answer between num a and b by doing solve(b) - solve(a-1). For
example, if a = 2 and b = 4, solve(b) = 5, solve(a-1) = solve(1) = 2.
5 - 2 is 3, which is the answer.
If you have an m digit number, for instance if m=2 digits, then you
could choose 1-9 for the first digit, then 0-9 for the second digit
EXCEPT not the digit you chose for the first, so there are 9 x 9
possible 2 digit numbers that satisfy this. For any # digits m, the
amount is 9^m.
dp[digit] = number of numbers that satisfy constraints.
For any number n, ex 321, you know that it (from 0 to n), it contains
at least all the answers from the digits below the digits of n.
ex, 1 (0) + 9 (1 digit) + 9x9 (2 digit numbers). For the rest of the
numbers for n = 321, you start with 1 or 2 for the third digit (cant
use 3) x 9 x 9 for the other 2 digits, aka 2 x dp[2], where dp[2] = 9x9.
Then once you reach three for the 3rd digit 3 _ _, you move on to
the next place, where you can choose 2 numbers (0 or 1 since they
less than 2), or 2 x dp[1] = 2 x 9. Then move to the last digit and do
the same to get 1 x dp[0] = 1. Then, if the number itself is applicable,
you can include that. Then, if 321 represented number b, then you would
do the same for number a-1.


*/

ll solve(ll num, vector<ll>&dp) {
    if (num <= 0) return num == 0 ? 1 : 0;
    string numberString = to_string(num);
    int digits = numberString.size();
    ll ans = 0;
    for (int i = 0; i < digits; i++) {
        ans += dp[i];
    }

    int prev = numberString[0] - '0';

    for (int i = 0; i < digits; i++) {
        int currDigit = numberString[i] - '0'; // how to convert char to int
        int copynum = currDigit;
        copynum--;
        if (i > 0 && prev >= currDigit) {
            copynum++;
        }
        ans += copynum * dp[digits-i-1];
        if (i > 0 && currDigit == prev) {
            return ans; // return it here because all numbers past here will have repeating digits
        }
        prev = currDigit;
    }

    return ans+1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b; cin >> a >> b;
    vector<ll> dp(19);
    ll num = 1;
    for (int i = 0; i < 19; i++) {
        dp[i] = num;
        num *= 9;
    }
    cout << solve(b, dp) - solve(a-1, dp);




    return 0;
}
