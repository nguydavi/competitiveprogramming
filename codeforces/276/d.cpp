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

const int MAXN = (int)3e5;
const int MAXA = (int)2e6+7;
int N;
int arr[MAXA];

int main() {
    scanf("%d", &N);
    memset(arr, 0, sizeof(arr));
    for(int i=0;i<N;++i) {
        int a;
        scanf("%d", &a);
        arr[a] = a;
    }
    arr[0] = 0;
    for(int i=1;i<MAXA;++i)
        if(arr[i] != i)
            arr[i] = arr[i-1];
     
     int ans = 0;
     for(int i=1;i<MAXA;++i)
         if(arr[i] == i) {
             int j = 2;
             while(i*j-1 < MAXA) {
                 ans = max(ans, arr[i*j-1]%i);
                 ++j;
             }
         }
    printf("%d\n", ans);
    return 0;
}
