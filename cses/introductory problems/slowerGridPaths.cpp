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
int ans = 0;


void solve(int grid[7][7], int row, int col, int moves, string path) {
    grid[row][col] = 1;
    if (moves == 48) {
        ++ans;
        return;
    }

    char curMove = path[moves];

    if(row == 6 && col == 0){ // if end is reached before moves reach 48
        return;
    }

    //optimization 3 and 4

    if (col-1 >= 0 && col+1 < 7 && grid[row][col+1] != 1 && grid[row][col-1] != 1 && (row-1 < 0 || grid[row-1][col] == 1) && (row+1>=7|| grid[row+1][col] == 1)) {
        return;
    }
    if (row-1 >= 0 && row+1 < 7 && grid[row-1][col] != 1 && grid[row+1][col] != 1 && (col-1 < 0 || grid[row][col-1] == 1) && (col+1>=7|| grid[row][col+1] == 1)) {
        return;
    }



    if (curMove != '?') {


        if (curMove == 'D') {
            if (row+1 < 7 && grid[row+1][col] != 1) {
                grid[row+1][col] = 1;
                solve(grid, row+1, col, moves+1,path);
                grid[row+1][col] = 0;
            } else {
                return;
            }
        }
        if (curMove == 'U') {
            if (row-1 >= 0 && grid[row-1][col] != 1) {
                grid[row-1][col] = 1;
                solve(grid, row-1, col, moves+1, path);
                grid[row-1][col] = 0;
            } else {
                return;
            }
        }
        if (curMove == 'L') {
            if (col-1 >= 0 && grid[row][col-1] != 1) {
                grid[row][col-1] = 1;
                solve(grid, row, col-1, moves+1, path);
                grid[row][col-1] = 0;
            } else {
                return;
            }
        }
        if (curMove == 'R') {
            if (col+1 < 7 && grid[row][col+1] != 1) {
                grid[row][col+1] = 1;
                solve(grid, row, col+1, moves+1, path);
                grid[row][col+1] = 0;
            } else {
                return;
            }
        }


    } else {
        if (row+1 < 7 && grid[row+1][col] != 1) { //DOWN
                grid[row+1][col] = 1;
                solve(grid, row+1, col, moves+1, path);
                grid[row+1][col] = 0;
            }
        if (row-1 >= 0 && grid[row-1][col] != 1) { //UP
                grid[row-1][col] = 1;
                solve(grid, row-1, col, moves+1, path);
                grid[row-1][col] = 0;
            }
        if (col-1 >= 0 && grid[row][col-1] != 1) { //LEFT
                grid[row][col-1] = 1;
                solve(grid, row, col-1, moves+1, path);
                grid[row][col-1] = 0;
            }
         if (col+1 < 7 && grid[row][col+1] != 1) { //RIGHT
                grid[row][col+1] = 1;
                solve(grid, row, col+1, moves+1, path);
                grid[row][col+1] = 0;
            }

    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string path;
    cin >> path;
    int grid[7][7];
    int row = 0;
    int col = 0;
    int moves = 0;
    vi counts;
    solve(grid, row, col, moves, path);
    cout << ans;
    return 0;
}
