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

string path;
int answer;
int visited[7][7];
const int LENGTH = 48;


void solve(int r, int c, int moves) {

    if (moves == LENGTH && r == 6 && c == 0) {
        answer++;
        return;
    }
    char cur = path[moves];
    if(r == 6 && c == 0) {
        return;
    }

    if (c-1 >= 0 && c+1 < 7 && !visited[r][c+1] && !visited[r][c-1] && (r-1 < 0 || visited[r-1][c]) && (r+1>=7|| visited[r+1][c])) {
        return;
    }
    if (r-1 >= 0 && r+1 < 7 && !visited[r-1][c] && !visited[r+1][c] && (c-1 < 0 || visited[r][c-1]) && (c+1>=7|| visited[r][c+1])) {
        return;
    }
    visited[r][c] = 1;
    if (cur == '?' || cur == 'U') {
        if (r-1>=0 && !visited[r-1][c])
            solve(r-1,c,moves+1);
    }
    if (cur == '?' || cur == 'D') {
        if (r+1<7 && !visited[r+1][c])
            solve(r+1,c,moves+1);
    }
    if (cur == '?' || cur == 'L') {
        if (c-1>=0 && !visited[r][c-1])
            solve(r,c-1,moves+1);
    }
    if (cur == '?' || cur == 'R') {
        if (c+1<7 && !visited[r][c+1])
            solve(r,c+1,moves+1);
    }
    visited[r][c] = 0;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> path;
    int r = 0;
    int c = 0;
    int moves = 0;

    solve(r, c, moves);
    cout << answer;


    return 0;
}
