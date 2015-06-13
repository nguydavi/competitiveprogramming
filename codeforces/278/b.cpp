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

const int MAXN = 5;
int N;
int arr[MAXN];

bool check(int x1, int x2, int x3, int x4) {
    if((x1+x2+x3+x4)/4 != (x2+x3)/2)
        return false;
    if((x1+x2+x3+x4)/4 != (x4-x1))
        return false;
    if((x2+x3)/2 != (x4-x1))
        return false;
    return true;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);
    sort(arr, arr+N);
    
    if(N == 0) {
        printf("YES\n1\n1\n3\n3\n");
    }
    if(N == 4) {
        if(check(arr[0], arr[1], arr[2], arr[3]))
            printf("YES\n");
        else 
            printf("NO\n");
    }
    if(N == 1) {
        arr[3] = 3*arr[0];
        arr[1] = arr[2] = 2*arr[0];
        printf("YES\n");
        for(int i=1;i<4;++i)
            printf("%d\n", arr[i]);
    }
    if(N == 3) {
        bool found = false;
        int x4 = 3*arr[0];
        if(x4 == arr[2]) {
            int x2x3div2 = x4-arr[0];
            int x3 = 2*x2x3div2-arr[1];
            if(x3 <= arr[2] && x3 >= arr[0] && check(arr[0], arr[1], x3, arr[2]))
                printf("YES\n%d\n", x3), found = true;
        } else if(x4 >= arr[2] && check(arr[0], arr[1], arr[2], x4))
            printf("YES\n%d\n", x4), found = true;
        else  if(arr[2]%3 == 0 && arr[2]/3 <= arr[0] &&  check(arr[2]/3, arr[0], arr[1], arr[2]))
            printf("YES\n%d\n", arr[2]/3), found = true;

        if(!found)
            printf("NO\n");
    }
    if(N == 2) {
        if(arr[1] == 3*arr[0]) {
            int x4 = arr[1];
            int x1 = arr[0];
            int x2x3div2 = x4 - x1;

            if(x2x3div2 <= x4 && x2x3div2 >= x1 && check(x1, x2x3div2, x2x3div2, x4))
                printf("YES\n%d\n%d\n", x2x3div2, x2x3div2);
            else 
                printf("NO\n");
        } else {
            int x4 = 3*arr[0];
            int x2x3div2 = x4-arr[0];
            int x2x3 = 2*x2x3div2 - arr[1];
            if(x2x3 >= arr[0] && x2x3 <= x4 && check(arr[0], min(x2x3, arr[1]), max(x2x3, arr[1]), x4))
                printf("YES\n%d\n%d\n", x2x3, x4);
            else if((arr[0]+arr[1]) %2 == 0 && check(arr[0], arr[0], arr[1], arr[0]+(arr[0]+arr[1])/2))
                printf("YES\n%d\n%d\n", arr[0], arr[0]+(arr[0]+arr[1])/2);
            else if(arr[1]%3==0 && arr[1]/3 <= arr[0] && check(arr[1]/3, arr[0], 4*arr[1]/3-arr[0], arr[1]))
                printf("YES\n%d\n%d\n", arr[1]/3, 4*arr[1]/3-arr[0]);
            else
                printf("NO\n");
                
        }
    }
    return 0;
}
