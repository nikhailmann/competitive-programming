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
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i].first.first >> people[i].first.second;
        people[i].second = i;
    }
    sort(people.begin(), people.end());
    vector<int> roomAssign(n,-1);
    int roomId = 1;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> r;
    for (int i = 0; i < n; i++) {
        if (r.size() == 0) {
            roomAssign[people[i].second] = roomId;
            r.push(mp(people[i].first.second, roomId));
            roomId++;
        }
        else {
            if (r.top().first < people[i].first.first) {
                roomAssign[people[i].second] = r.top().second;
                pair<int,int> x = r.top();
                r.pop();
                r.push(mp(people[i].first.second, x.second));
            }
            else {
                roomAssign[people[i].second] = roomId;
                r.push(mp(people[i].first.second, roomId));
                roomId++;

            }
        }


    }
    cout << roomId-1 << "\n";
    for (int y : roomAssign) {
        if (y > 0) {
            cout << y << " ";
        }
    }





    return 0;
}
