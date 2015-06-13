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

const int MAXN = (int)1e6+10;
const int INF = (int)1e9;
int N, M, K;
int arr[MAXN];
map<int, int> mm;

void generateArr() {
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    for(int i=3;i<N;++i)
        arr[i] = (arr[i-1]+arr[i-2]+arr[i-3])%M +1;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d %d %d", &N, &M, &K);
        mm.clear();
        generateArr();

        int k = 0;
        int len = INF;
        for(int i=0;i<N;++i) {
            while(k < N && mm.size() < K) {
                if(arr[k] <= K)
                    ++mm[arr[k]];
                ++k;
            }
            if(mm.size() == K)
                len = min(len, k-i);

            if(arr[i] <= K)
                --mm[arr[i]];
            if(mm[arr[i]] == 0)
                mm.erase(mm.find(arr[i]));
        }
        if(len == INF)
            printf("Case %d: sequence nai\n", ii);
        else
            printf("Case %d: %d\n", ii, len);
    }
    return 0;
}
