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

typedef long long ll;
typedef pair<int, int> pii;
int N, R, AVG;
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() {
    scanf("%d %d %d", &N, &R, &AVG);
    ll curSum = 0;
    for(int i=0;i<N;++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        pq.push(pii(b, a));
        curSum += a;
    }

    ll ans = 0;
    while(curSum < 1LL*N*AVG) {
        while(pq.top().second == R)
            pq.pop();
        pii cur = pq.top();
        pq.pop();

        ll tmp = min(1LL*N*AVG-curSum, 1LL*R-cur.second);
        ans += tmp*cur.first;
        curSum += tmp;
    }
    cout << ans << "\n";

    return 0;
}
