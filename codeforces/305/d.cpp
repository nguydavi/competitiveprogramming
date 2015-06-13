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

const int MAXN = 2e5+10;
int N;
int arr[MAXN];
int le[MAXN], ri[MAXN];
int ans[MAXN];

int main() {
    memset(arr, 0, sizeof(arr));
    // setting to -1 so that if min of all array is between -1;N
    memset(le, -1, sizeof(le));
    memset(ri, 0, sizeof(ri));
    memset(ans, 0, sizeof(ans));
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);

    stack<int> s;
    for(int i=0;i<N;++i) {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if(s.size())
            le[i] = s.top();
        s.push(i);
    }

    while(s.size())
        s.pop();

    for(int i=N-1;i>=0;--i) {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if(s.size())
            ri[i] = s.top();
        else
            ri[i] = N;
        s.push(i);
    }

    for(int i=0;i<N;++i) {
        int len = ri[i]-le[i]-1;
        ans[len] = max(ans[len], arr[i]);
    }
    for(int i=N;i>=0;--i)
        ans[i] = max(ans[i], ans[i+1]);

    for(int i=1;i<=N;++i) {
        if(i-1)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
