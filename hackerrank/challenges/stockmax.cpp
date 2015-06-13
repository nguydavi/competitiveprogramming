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
const int MAXN = 50010;
int N;
int arr[MAXN];
priority_queue<pii> pq;

ll sumInterval(int a, int b) {
    ll res = 0;
    for(int i=a;i<b;++i)
        res += arr[i];
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &N);
        for(int i=0;i<N;++i) {
            scanf("%d", &arr[i]);
            pq.push(pii(arr[i], i));
        }

        int lastMax = -1;
        ll ans = 0;
        while(!pq.empty()) {
            pii cur = pq.top();
            pq.pop();
            int curIndex = cur.second;
            int share = cur.first;
            if(curIndex < lastMax)
                continue;

            ll buy = sumInterval(lastMax+1, curIndex);
            ans += 1LL*(curIndex-1-lastMax)*arr[curIndex] - buy;
            lastMax = curIndex;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
