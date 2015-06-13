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

const int MAXN = 310;
const int BLACK = 0;
const int WHITE = 1;
int N;
vector<int> adj[MAXN];
int color[MAXN];

/**
 * Suppose center of claws are blacks, the non centers are white and cannot be
 * center of another claw because they are of degree 2 now. The goal is to prove
 * that it is bipartite so that all black nodes are centers and all white can be
 * used in different claws
 */
bool bfs(int id) {
    queue<int> qq;
    qq.push(id);
    color[id] = BLACK;

    while(!qq.empty()) {
        int cur = qq.front();
        qq.pop();

        for(int i=0;i<adj[cur].size();++i) {
            int nxt = adj[cur][i];
            if(color[nxt] != -1 && color[nxt] != color[cur]^1)
                return false;

            if(color[nxt] == -1) {
                qq.push(nxt);
                color[nxt] = color[cur]^1;
            }
        }

    }
    return true;
}

int main() {
    while(scanf("%d", &N) == 1 && N) {
        for(int i=0;i<N;++i)
            adj[i].clear();

        int a, b;
        while(scanf("%d %d", &a, &b) && a && b) {
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        bool ans = false;
        memset(color, -1, sizeof(color));
        for(int i=0;i<N;++i)
            if(color[i] == -1)
                ans |= bfs(i);

        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }    
    return 0;
}
