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

const int MAXN = 6010;
const int INF = (int)1e9;
int N;
vector<int> adjList[MAXN];
int arr[MAXN];
vector<int> lis;
int ans;

void solve(int n, int pn) {
    vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), arr[n]);
    int old = *it;
    *it = arr[n];
    ans = max(ans, (int)(it-lis.begin())+1);

    for(int i=0;i<adjList[n].size();++i) {
        int v = adjList[n][i];
        if(pn != v) {
            solve(v, n);
        }
    }
    *it = old;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);
    for(int i=0;i<N-1;++i) {
        int u, v;
        scanf("%d %d", &u, &v);

        --u, --v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    ans = 0;
    for(int i=0;i<N;++i) {
        lis.assign(N, INF);
        solve(i, -1);
    }
    printf("%d\n", ans);
    return 0;
}
