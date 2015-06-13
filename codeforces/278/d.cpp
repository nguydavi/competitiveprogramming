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

const int MAXN = 10010;
const int INF = (int)1e9+7;
int N, S, L;
int start[MAXN];
int end[MAXN];
int arr[MAXN];

int main() {
    scanf("%d %d %d", &N, &S, &L);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);
    memset(start, -1, sizeof(start));
    memset(end, -1, sizeof(end));

    int curSplit = 0;
    int curIndex = 0;
    while(curIndex < N) {
        int curMin = arr[curIndex];
        int curMax = arr[curIndex];

        start[curSplit] = curIndex;
        while(curIndex < N) {
            if(abs(arr[curIndex] - curMin) <= S && abs(arr[curIndex]-curMax) <= S) {
                curMin = min(curMin, arr[curIndex]);
                curMax = max(curMax, arr[curIndex]);
                ++curIndex;
            } else
                break;
        }
        end[curSplit] = curIndex-1;

        if(end[curSplit]-start[curSplit] + 1 < L) {
            if(curSplit == 0) {
                printf("-1\n");
                return 0;
            }
            int needed = L - (end[curSplit]-start[curSplit]+1);
            int backwardIndex = end[curSplit-1];
            while(backwardIndex >= 0 && needed) {
                if(abs(arr[backwardIndex] - curMin) <= S && abs(arr[backwardIndex]-curMax) <= S) {
                    curMin = min(curMin, arr[backwardIndex]);
                    curMax = max(curMax, arr[backwardIndex]);
                    --needed;
                    --backwardIndex;
                } else {
                    printf("-1\n");
                    return 0;
                }
            }

            end[curSplit-1] = backwardIndex;
            if(end[curSplit-1]-start[curSplit-1]+1 < L) {
                printf("-1\n");
                return 0;
            }
            start[curSplit] = backwardIndex+1;
        }

        ++curSplit;
    }

    printf("%d\n", curSplit);
    return 0;
}
