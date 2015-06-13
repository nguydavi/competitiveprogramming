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

const int MAXM = 50;
const int MAXS = 400;
const int INF = (int)1e9;
int N, M, S;
int dp[MAXS][MAXS];
pair<int, int> arr[MAXM];

int solve() {
    for(int i=0;i<=M;++i)
        for(int x=0;x<=S;++x)
            for(int y=0;y<=S;++y)
                dp[x][y] = INF;
    dp[0][0] = 0;

    for(int i=1;i<=M;++i)
        for(int x=0;x<=S;++x)
            for(int y=0;y<=S;++y)
                if(x >= arr[i-1].first && y >= arr[i-1].second)
                    dp[x][y] = min(dp[x][y], dp[x-arr[i-1].first][y-arr[i-1].second]+1);
    int ans = INF;
    for(int x=0;x<=S;++x)
        for(int y=0;y<=S;++y)
            // check if x*x+y*y == s*s is better
            if(dp[x][y] && fabs(sqrt(x*x+y*y) - S) < 1e-7)
                ans = min(ans, dp[x][y]);
    if(ans == INF)
        return -1;
    return ans;
}

int main() {
    cin >> N;
    while(N--) {
        cin >> M >> S;
        for(int i=0;i<M;++i) {
            int x,y;
            cin >> x >> y;
            arr[i] = make_pair(x, y);
        }
        int ans = solve();
        if(ans == -1)
            cout << "not possible\n";
        else
            cout << ans << "\n";
    }    
    return 0;
}
