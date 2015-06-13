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
int N;
int arr[MAXN];

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);

    int ans = (int)1e9;
    for(int i=1;i<N-1;++i) {
        int diff = 0;
        int prev = arr[0];
        for(int j=0;j<N;++j) {
            if(i == j)
                continue;
            diff = max(diff, arr[j] - prev);
            prev = arr[j];
        }
        ans = min(ans, diff);
    }
    printf("%d\n", ans);
    return 0;
}
