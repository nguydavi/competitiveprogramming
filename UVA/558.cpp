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
const int INF = (int)1e9;
int N, M;
vector<vector<pii> > adjList;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &N, &M);
        adjList.assign(N, vector<pii>());
        while(M--) {
            int u, v, z;
            scanf("%d %d %d", &u, &v, &z);
            adjList[u].push_back(pii(v, z));
        }

        vector<int> dist(N, INF);
        dist[0] = 0;
        for(int i=0;i<N-1;++i)
            for(int j=0;j<N;++j)
                for(int k=0;k<adjList[j].size();++k) {
                    pii nxt = adjList[j][k];
                    if(dist[j] + nxt.second < dist[nxt.first] && dist[j] < INF)
                        dist[nxt.first] = dist[j] + nxt.second;
                }

        bool hasNegCycle = false;
        for(int j=0;j<N;++j)
            for(int k=0;k<adjList[j].size();++k) {
                pii nxt = adjList[j][k];
                if(dist[j] + nxt.second < dist[nxt.first])
                    hasNegCycle = true;
            }

        if(hasNegCycle)
            printf("possible\n");
        else
            printf("not possible\n");
    }
    return 0;
}
