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
int N, T;
int arr[MAXN];

int main() {
    scanf("%d %d", &N, &T);
    --T;
    for(int i=0;i<N-1;++i)
        scanf("%d", &arr[i]);

    int tries = 0;
    int cur = 0;
    while(tries < MAXN) {
        cur = cur + arr[cur];
        if(cur == T) {
            printf("YES\n");
            return 0;
        }
        ++tries;
    }
    printf("NO\n");
    return 0;
}
