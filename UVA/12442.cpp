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

const int MAXN = 50010;
int N;
int sent[MAXN], cnt[MAXN];
bool already[MAXN];

int dfs(int id) {
    if(already[id])
        return 0;
    already[id] = true;
    int res = 1 + dfs(sent[id]);
    cnt[id] = res;
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);    
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d", &N);
        for(int i=0;i<N;++i) {
            int a,b;
            scanf("%d %d", &a, &b);
            sent[a-1] = b-1;
        }

        memset(cnt, -1, sizeof(cnt));
        int toSend = -1;
        int maxCount = 0;
        for(int i=0;i<N;++i) {
            if(cnt[i] == -1) {
                memset(already, false, sizeof(already));
                dfs(i);
            }
            if(maxCount < cnt[i])
                maxCount = cnt[i], toSend = i+1;
        }

        printf("Case %d: %d\n", ii, toSend);
    }
    return 0;
}
