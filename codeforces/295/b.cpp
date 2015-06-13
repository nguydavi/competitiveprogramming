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

const int MAXN = 3e4;
const int MAX_ITER = 1e5;
int N, M;
int dist[MAXN];

int solve() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(N);
    dist[N] = 0;

    int iter = 0;
    while(iter < MAX_ITER) {
        int cur = q.front();
        q.pop();
        if(cur == M)
            return dist[M];

        if(cur && dist[cur-1] == -1) {
            dist[cur-1] = dist[cur] + 1;
            q.push(cur-1);
        }
        if(2*cur < MAXN && dist[2*cur] == -1) {
            dist[2*cur] = dist[cur] + 1;
            q.push(2*cur);
        }

        ++iter;
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);

    printf("%d\n", solve());
    return 0;
}
