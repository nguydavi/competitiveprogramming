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

const int MAXN = 4000;
int N;
int adj[MAXN][MAXN];
int path[MAXN];

int pow2(int n) {
    int res = 1;
    while(n--)
        res *= 2;

    return res;
}

int getMaxPath(int node) {
    if(node > N)
        return 0;

    int left = 2*node;
    int right = 2*node+1;
    return path[node] = max(adj[node][left] + getMaxPath(left),
                            adj[node][right] + getMaxPath(right));
}

int solve(int node, int maxPath) {
    if(node > N)
        return 0;

    int left = 2*node;
    int right = 2*node+1;

    int leftpath = maxPath - (maxPath - path[left]);
    int res = maxPath - (adj[node][left] + path[left]);
    res += solve(left, leftpath);

    int rightpath = maxPath - (maxPath - path[right]);
    res += maxPath - (adj[node][right] + path[right]);
    res += solve(right, rightpath);

    return res;
}

int main() {
    int levels;
    scanf("%d", &levels);
    N = pow2(levels+1)-1;
    for(int i=0;i<N-1;++i) {
        int d;
        scanf("%d", &d);

        int u = i+2;
        int v = (i+2)/2;
        adj[u][v] = d;
        adj[v][u] = d;
    }

    int maxPath = getMaxPath(1);
    printf("%d\n", solve(1, maxPath));

    return 0;
}
