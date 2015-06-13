#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXB = 12;
const int MASK = 5000;
int MAXX, MAXY, B;
pair<int, int> arr[MAXB];
int dp[MAXB][MASK]; // min TSP starting from dp[i][j]

int dist(int a, int b) {
    return abs(arr[a].first-arr[b].first)+abs(arr[a].second-arr[b].second);
}

int solve(int cur, int mask) {
    if(mask == (1<<(B+1))-1)
        return dist(cur, 0);
    if(dp[cur][mask] != -1)
        return dp[cur][mask];

    int res = (int)1e9;
    for(int i=0;i<=B;++i)
        if(!(mask & 1 << i))
            res = min(res, dist(cur, i) + solve(i, mask | (1 << i)));
    dp[cur][mask] = res;
    return res;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> MAXX >> MAXY;
        cin >> arr[0].first >> arr[0].second;
        cin >> B;
        for(int i=1;i<=B;++i)
            cin >> arr[i].first >> arr[i].second;

        memset(dp, -1, sizeof(dp));
        cout << "The shortest path has length " << solve(0, 1) << "\n";
    } 
    return 0;
}
