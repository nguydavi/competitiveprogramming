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

const int MAXN = 5010;
int N;
int arr[MAXN];

int main() {
    scanf("%d", &N);
    memset(arr, -1, sizeof(arr));

    if(N == 3) {
        printf("2\n1 3\n");
        return 0;
    }
    if(N == 4) {
        printf("4\n3 1 4 2\n");
        return 0;
    }

    int f = N/2;
    if(N%2==1)
        ++f;

    int i = 0;
    for(int j=1;j<=f;++j) {
        arr[i] = j;
        i+= 2;
    }
    i = 1;
    for(int j=f+1;j<=N;++j) {
        if(abs(arr[i-1]-j) != 1 && abs(arr[i+1]-j) != 1) {
            arr[i] = j;
            i+=2;
        }
    }

    int ans = 0;
    while(arr[ans] != -1)
        ++ans;

    printf("%d\n", ans);
    for(int i=0;i<ans;++i) {
        if(i)
            printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
