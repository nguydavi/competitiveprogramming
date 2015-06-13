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

const int MAXN = 3010;
const int MAXM = 30010;
int N, M;
vector<int> adjList[MAXN];
bool adj[MAXN][MAXN];

int main() {
    scanf("%d %d", &N, &M); 
    memset(adj, false, sizeof(adj));
    for(int i=0;i<M;++i) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u, --v;
        adjList[u].push_back(v);
        adj[u][v] = true;
    }

    int ans = 0;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            if(i!=j) {
                int neigh = 0;
                for(int k=0;k<adjList[i].size();++k)
                    if(adjList[i][k] != j && adj[adjList[i][k]][j])
                        ++neigh;
                ans += neigh * (neigh-1) / 2;
            }
    printf("%d\n", ans);

    return 0;
}
