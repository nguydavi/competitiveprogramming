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
int N, K;
int arr[MAXN];

int main() {
    scanf("%d %d", &N, &K);
    int mi = 200;
    int ma = 0;
    for(int i=0;i<N;++i) {
        scanf("%d", &arr[i]);
        mi = min(mi, arr[i]);
        ma = max(ma, arr[i]);
    }

    if(ma-mi > K) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for(int i=0;i<N;++i) {
        vector<int> d;
        for(int j=0;j<mi;++j)
            d.push_back(1);
        for(int j=0;j<arr[i]-mi;++j)
            d.push_back(1+j);

        for(int j=0;j<d.size();++j) {
            if(j)
                printf(" ");
            printf("%d", d[j]);
        }
        printf("\n");
    }

    return 0;
}
