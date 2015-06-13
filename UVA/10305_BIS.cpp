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
int N, M;
bool adj[MAXN][MAXN];
deque<int> ans;
int inc[MAXN]; //incoming edges

void solve() {
    queue<int> noInc;
    for(int i=0;i<N;++i)
        if(inc[i] == 0)
            noInc.push(i);
    while(!noInc.empty()) {
        int id = noInc.front();
        noInc.pop();
        ans.push_back(id+1);

        for(int i=0;i<N;++i) {
            if(adj[id][i]) {
                --inc[i];
                if(!inc[i])
                    noInc.push(i);
            }
        }
    }
}

int main() {
    while(scanf("%d %d", &N, &M) == 2 && (N || M)) {
        memset(adj, false, sizeof(adj));
        memset(inc, 0, sizeof(inc));
        for(int i=0;i<M;++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a-1][b-1] = true;
            ++inc[b-1];
        }

        ans.clear();
        solve();

        printf("%d", ans[0]);
        for(int i=1;i<N;++i)
            printf(" %d", ans[i]);
        printf("\n");

    } 
    return 0;
}
