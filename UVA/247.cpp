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

const int MAXN = 30;
int N, M, tc;
map<string, int> mm;
string arr[MAXN];
bool adj[MAXN][MAXN];

int dfsNumberCounter;
int dfs_num[MAXN], dfs_low[MAXN];
vector<int> S;
bool visited[MAXN];

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = true;

    for(int v=0;v<N;++v)
        if(adj[u][v]) {
            if(dfs_num[v] == -1)
                tarjanSCC(v);
            if(visited[v])
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }

    if(dfs_low[u] == dfs_num[u]) {
        bool first = true;
        while(1) {
            int v = S.back();
            S.pop_back();
            visited[v] = false;
            if(first)
                first = false;
            else
                cout << ", ";
            cout  << arr[v];

            if(u == v)
                break;
        } 
        cout << "\n";
    }
}

int main() {
    tc = 0;
    while(scanf("%d %d", &N, &M) && (N || M)) {
        mm.clear();
        memset(adj, false, sizeof(adj));
        int cur = 0;
        for(int i=0;i<M;++i) {
            string a, b;
            cin >> a >> b;
            if(mm.find(a) == mm.end())
                mm[a] = cur, arr[cur] = a, ++cur;
            if(mm.find(b) == mm.end())
                mm[b] = cur, arr[cur] = b, ++cur;
            adj[mm[a]][mm[b]] = true;
        }

        memset(dfs_num, -1, sizeof(dfs_num));
        memset(dfs_low, 0, sizeof(dfs_low));
        memset(visited, false ,sizeof(visited));
        dfsNumberCounter = 0;

        if(tc)
            printf("\n");
        printf("Calling circles for data set %d:\n", ++tc);
        for(int i=0;i<N;++i)
            if(dfs_num[i] == -1)
                tarjanSCC(i);


    }    
    return 0;
}
