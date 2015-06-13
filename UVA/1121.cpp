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

const int MAXN = (int)1e5+10;
const int INF = (int)1e9;
int N, S;
int arr[MAXN];

int main() {
    while(scanf("%d %d", &N, &S) == 2) {
        for(int i=0;i<N;++i)
            scanf("%d", &arr[i]);

        int k = 0;
        int sum = 0;
        int len = INF;
        for(int i=0;i<N;++i) {
            while(k < N && sum < S)
                sum += arr[k++];
            if(sum >= S)
                len = min(len, k-i);
            sum -= arr[i];
        }
        if(len == INF)
            len = 0;
        printf("%d\n", len);
    }
    return 0;
}
