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

/*
NOTES https://www.youtube.com/watch?v=uGYiWMhyc8w
https://www.youtube.com/watch?v=lPLhmuWMRag

Think about the constraints - n is small and m is large
We can use this for optimization. This problem requires bitmasking.
We can build a solution by constructing columns one by one. Each block of
a column can either be filled or unfilled. We can model all of these
possible combinations by using a bitmask. Since each column is of height
n, there are 2^n possible combinations for each column. It is important
to know the state of the previous column for each one we are building so
we can know what blocks are already filled (like in a horizontal tile).
We initialize our 2d dp array with [1001][1<<11]. The second dimension
is the maximum possible combinations of each column 2^10 since n is
at most 10, plus one because that is how the code checks if a mask is valid.
First, we read in the data and initialize our dp array with the values
being -1. Then we call our solve functions with initial column 1 and
mask of 0 (because the current first column is empty. The first two
if statement blocks are just for our base case for recursion and
incorporating dynamic programming. Then, we use the gen next masks function
to generate all possible masks using the current mask and places them
in a vector, then it iterates through that vector and increments answer
by calling solve of the next column using the current next_mask. In
the function, i acts as the row number.
It does this until it's gone through every possible combination and returns
the answer. The gen next masks function uses set bits to determine
whether it can't place a tile (already occupied) for each block of a
column, whether a mask has been created (pushes back onto vector), and
if it can place a vertical or horizontal tile. ***In the fourth block, the
next_mask + (1 << i) call will make the block at row i in next_mask one
to represent the other half of the horizontal block.*** This is
somewhat confusing, but you have to realize the difference between
current_mask, the mask we're currently on, and next_mask, the mask(s) we're
building to put into our vector and use to form other masks. Also,
the condition in our base case will ensure that no horizontal blocks
are placed past the edges.


*/
vector<vector<int>> dp(1001, vector<int>(1<<11, -1));

void generateNextMasks(int current_mask, int row, int next_mask, int n, vector<ll>& next_masks) {

    if (row == n+1) { //if we reached bottom (all rows checked)
        next_masks.pb(next_mask);
        return;
    }

    if ((current_mask & (1<<row)) != 0) { // if space already taken (by 2nd part of horizontal)
        generateNextMasks(current_mask, row+1, next_mask, n, next_masks);
    }

    if ((row != n) && ((current_mask & (1<<row)) == 0) && ((current_mask & (1<<(row+1))) == 0)) { // can place vertical tile
        generateNextMasks(current_mask, row+2, next_mask, n, next_masks);
    }

    if ((current_mask & (1<<row)) == 0) { // can't place vertical but can place first part of horizontal
        generateNextMasks(current_mask, row+1, next_mask + (1<<row), n, next_masks);
    }


}

int solve(int col, int mask, const int n, const int m) {
    if (col == m+1) {
        if (mask == 0) {
            return 1;
        }
        return 0;
    }

    if (dp[col][mask] != -1) {
        return dp[col][mask];
    }

    ll ans = 0;
    vector<ll> next_masks;
    int row = 1;
    generateNextMasks(mask, row, 0, n, next_masks);
    for (ll current_new_mask : next_masks) {
        ans = (ans + solve(col+1, current_new_mask, n, m)) % MOD;
        ans %= MOD;
    }
    dp[col][mask] = ans;

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    int col = 1, starting_mask = 0;
    cout << solve(col, starting_mask, n, m);
    return 0;
}
