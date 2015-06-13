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

const int MAXT = 110;
int V1, V2, T, D;
int arr[MAXT];

int main() {
    scanf("%d %d %d %d", &V1, &V2, &T, &D);
    arr[0] = V1;
    arr[T-1] = V2;

    for(int i=1;i<T-1;++i)
        arr[i] = arr[i-1]+D;

    for(int i=T-2;i > 0;--i)
        if(arr[i+1] > arr[i])
            arr[i] = max(arr[i], arr[i+1]-D);
        else
            arr[i] = min(arr[i], arr[i+1]+D);

    int ans = 0;
    for(int i=0;i<T;++i)
        ans += arr[i];
    printf("%d\n", ans);
    return 0;
}
