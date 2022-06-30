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



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // find position where each number is in input string
    int n, m;
    cin >> n >> m;
    int indexes[n+1];
    int found[n+1] = {};
    int nums[n+1];
    int ans = 1;

    int prev;
    cin >> prev;
    nums[1] = prev;
    indexes[prev] = 1;
    if (prev != 1) ans++;
    found[prev] = 1;

    indexes[0] = 0;
    found[0] = 0;
    for (int i = 2; i < n+1; i++) {
        int k;
        cin >> k;
        found[k] = 1;
        indexes[k] = i;
        nums[i] = k;
        if (k != 1 && !(found[k-1])) {
            ans++;
        }
        prev = k;

    }

    for (int i = 0; i < m; i++) {
        int change = 0;
        int a, b;
        cin >> a >> b;
        int x = nums[a], y = nums[b];
        swap(nums[a], nums[b]);
        if (indexes[x-1] <= indexes[x] && indexes[x-1] > b) change++;
        if (indexes[x-1] > indexes[x] && indexes[x-1] <= b) change--;
        if (indexes[x+1] <= indexes[x] && indexes[x+1] > b) change--;
        if (indexes[x+1] > indexes[x] && indexes[x+1] <= b) change++;

        if (indexes[y-1] <= indexes[y] && indexes[y-1] > a) change++;
        if (indexes[y-1] > indexes[y] && indexes[y-1] <= a) change--;
        if (indexes[y+1] <= indexes[y] && indexes[y+1] > a) change--;
        if (indexes[y+1] > indexes[y] && indexes[y+1] <= a) change++;

        indexes[x] = b;
        indexes[y] = a;
        ans = ans + change;
        cout << ans << "\n";



    }

    return 0;
}
/*
        int aChecksBefore[4] = {}; // after below -1, before below +1, after above +1, before above - 1
        int aChecksAfter[4] = {};
        int bChecksBefore[4] = {};
        int bChecksAfter[4] = {};

        int numa = nums[a];
        int numb = nums[b];
        if (numa != n) {
            if (a > indexes[numa+1]) {
                aChecksBefore[2] = 1;
            } else {
                aChecksBefore[3] = -1;
            }

        }
        if (numa != 1) {
            if (a > indexes[numa-1]) {
                aChecksBefore[0] = -1;
            } else {
                aChecksBefore[1] = 1;
                }
        }

        if (numb != n) {
            if (b > indexes[numb+1]) {
                bChecksBefore[2] = 1;
            } else {
                bChecksBefore[3] = -1;
            }

        }
        if (numb != 1) {
            if (b > indexes[numb-1]) {
                bChecksBefore[0] = -1;
            } else {
                bChecksBefore[1] = 1;
                }
        }
        swap(nums[a], nums[b]);

        if (numa != n) {
            if (a > indexes[numa+1]) {
                aChecksAfter[2] = 1;
            } else {
                aChecksAfter[3] = -1;
            }

        }
        if (numa != 1) {
            if (a > indexes[numa-1]) {
                aChecksAfter[0] = -1;
            } else {
                aChecksAfter[1] = 1;
                }
        }

        if (numb != n) {
            if (b > indexes[numb+1]) {
                bChecksAfter[2] = 1;
            } else {
                bChecksAfter[3] = -1;
            }

        }
        if (numb != 1) {
            if (b > indexes[numb-1]) {
                bChecksAfter[0] = -1;
            } else {
                bChecksAfter[1] = 1;
                }
        }

        for (int j = 0; j < 4; j++) {
            if (aChecksAfter[j] != 0 && aChecksAfter[j] != aChecksBefore[j])  {
                change += aChecksAfter[j];
            }
        }
        for (int l = 0; l < 4; l++) {
            if (bChecksAfter[l] != 0 && bChecksAfter[l] != bChecksBefore[l])  {
                change += bChecksAfter[l];
            }
        }

        ans = ans + change;
        cout << ans <<"\n";


    }
*/
