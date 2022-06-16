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

void solve(vi& out, int y, int col[8], int diag1[16], int diag2[16], int n, vector<string>& board) {
    if (y == n) {
        out.pb(1);
        return;
    }
    for (int x = 0; x < n; x++) {
        if ((board[y][x] == '*') || col[x] || diag1[x+y] || diag2[x-y+n-1]) { continue;}
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        solve(out, y+1, col, diag1, diag2, n, board);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> board;
    string line;
    while (cin >> line) {
        board.pb(line);
    }

    vi out;
    int y = 0;
    int col[8] = {};
    int n = 8;
    int diag1[16] = {};
    int diag2[16] = {};

    solve(out, y, col, diag1, diag2, n, board);
    cout << sz(out);



    return 0;
}
