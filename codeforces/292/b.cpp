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

const int MAXN = 210;
int N, M;
bool adj[MAXN][MAXN];
bool happy[MAXN];
bool vis[MAXN];

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

void dfs(int i) {
    vis[i] = true;
    happy[i] = true;

    for(int j=0;j<N+M;++j)
        if(!vis[j] && adj[i][j])
            dfs(j);
}

int main() {
    memset(adj, false, sizeof(adj));
    memset(happy, false, sizeof(happy));
    memset(vis, false, sizeof(vis));

    scanf("%d %d", &N, &M);
    int n, m;
    scanf("%d", &n);
    while(n--) {
        int x;
        scanf("%d", &x);
        happy[x] = true;
    }
    scanf("%d", &m);
    while(m--) {
        int x;
        scanf("%d", &x);
        happy[N+x] = true;
    }

    int commonMultiple = lcm(N, M);
    for(int i=0;i<=commonMultiple;++i)
        adj[i%N][N+i%M] = adj[N+i%M][i%N] = true;

    for(int i=0;i<N+M;++i)
        if(!vis[i] && happy[i])
            dfs(i);

    for(int i=0;i<N+M;++i)
        if(!happy[i]) {
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
    return 0;
}
