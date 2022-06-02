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



int main() // this solution is probably not optimal
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string m;
    cin >> m;
    int n = sz(m);
    int letters[26] = { 0 };
    for (int i = 0; i < n; i++) {
        char curletter = m[i];
        letters[int(curletter) - 65] += 1;
    }

    int oddcount = 0;
    int evencount = 0;
    int oddindex;

    for (int i = 0; i < 26; i++) {
        if (letters[i]%2 == 0) {
            evencount++;
        } else {
            oddcount++;
            oddindex = i;

        }
    }

    string output = "";
    if (n%2 == 0) {
        if (evencount != 26) {
            cout << "NO SOLUTION";
        } else {
            for (int i = 0; i < 26; i++) {
                char curr = char(i + 65);
                string curr2(letters[i]/2, curr);
                output += curr2;
            }
            string reverseEvenoutput = output;
            reverse(reverseEvenoutput.begin(), reverseEvenoutput.end());
            output += reverseEvenoutput;
            cout << output;
        }


    } else {
        if (evencount != 25 && oddcount != 1) {
            cout << "NO SOLUTION";
        } else {
            for (int i = 0; i < 26; i++) {
                if (i != oddindex) {
                    char curr = char(i + 65);
                    string curr2(letters[i]/2, curr);
                    output += curr2;
                }
            }
            string reverseOddoutput = output;
            reverse(reverseOddoutput.begin(), reverseOddoutput.end());
            char odd = char(oddindex + 65);
            string odds(letters[oddindex], odd);
            output = output + odds + reverseOddoutput;
            cout << output;
        }
    }

    return 0;
}
