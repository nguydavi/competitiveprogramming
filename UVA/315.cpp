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

const int MAXN = 110;
int N;
vector<int> adj[MAXN];

int dfsNumberCounter, dfsRoot, rootChildren;
int dfs_num[MAXN], dfs_low[MAXN], dfs_parent[MAXN];
bool articulVertex[MAXN];

void solve(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(int i=0;i<adj[u].size();++i) {
        int v = adj[u][i];
        if(dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if(u == dfsRoot)
                ++rootChildren;

            solve(v);

            if(dfs_low[v] >= dfs_num[u])
                articulVertex[u] = true;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
    while(cin >> N && N) {
        for(int i=0;i<N;++i)
            adj[i].clear();

        cin.ignore();
        while(1) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            int node;
            ss >> node;
            if(!node)
                break;

            int nxt;
            while(ss >> nxt) {
                adj[node-1].push_back(nxt-1);
                adj[nxt-1].push_back(node-1);
            }
        }

        memset(articulVertex, false, sizeof(articulVertex));
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(dfs_low, 0, sizeof(dfs_low));
        memset(dfs_parent, 0, sizeof(dfs_parent));
        dfsNumberCounter = 0;
        for(int i=0;i<N;++i)
            if(dfs_num[i] == -1) {
                dfsRoot = i;
                rootChildren = 0;
                solve(i);
                articulVertex[dfsRoot] = rootChildren > 1;
            }

        int ans = 0;
        for(int i=0;i<N;++i)
            if(articulVertex[i])
                ++ans;
        printf("%d\n", ans);
    }    
    return 0;
}
