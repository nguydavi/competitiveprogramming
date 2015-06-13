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

typedef pair<int, int> pii;

const int MAXN = 200010;
int M, N;
vector<pii> adjList[MAXN];
int sets[MAXN];
int total;
priority_queue<pii, vector<pii>, greater<pii> > pq;
bool visited[MAXN];

void solve(int u) {
    visited[u] = true;

    for(int i=0;i<adjList[u].size();++i)
        if(!visited[adjList[u][i].second])
            pq.push(adjList[u][i]);
}

int main() {
    while(scanf("%d %d", &N, &M) == 2 && (M || N)) {
        memset(visited, false, sizeof(visited));
        for(int i=0;i<N;++i)
            adjList[i].clear();
        total = 0;
        for(int i=0;i<M;++i) {
            int u, v, z;
            scanf("%d %d %d", &u, &v, &z);
            adjList[u].push_back(make_pair(z, v));
            adjList[v].push_back(make_pair(z, u));
            total += z;
        }

        int ans = 0;
        solve(0);
        while(!pq.empty()) {
            pii tt = pq.top();
            pq.pop();

            if(!visited[tt.second]) {
                ans += tt.first;
                solve(tt.second);
            }
        }

        printf("%d\n", total-ans);
    }    
    return 0;
}
