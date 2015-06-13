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

const int INF = 1e9;
const int MAXN = 1e5+10;
const int MAXVAL = 15;
int N;
vector<vector<int> > adjList;

int dp[MAXN][MAXVAL];

int dfs(int cur, int prev, int val) {
    if(dp[cur][val] != -1)
        return dp[cur][val];

    int res = val;
    for(int nxt : adjList[cur])
        if(nxt != prev) {
            int tt = INF;
            for(int j=1;j<MAXVAL;++j)
                if(j != val)
                    tt = min(tt, dfs(nxt, cur, j));
            res += tt;
        }
    dp[cur][val] = res;
    return res;
}

int main() {
    while(cin >> N && N) {
        cin.ignore();
        adjList.assign(N, vector<int>());
        memset(dp, -1, sizeof(dp));

        for(int i=0;i<N;++i) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            
            int u;
            char c;
            ss >> u >> c;
            int v;
            while(ss >> v) {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
        cin.ignore();

        int ans = INF;
        for(int i=1;i<MAXVAL;++i)
            ans = min(ans, dfs(0, -1, i));

        cout << ans << "\n";
    }
    return 0;
}
