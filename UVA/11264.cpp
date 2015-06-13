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

typedef long long ll;
const int MAXN = 1010;
int N;
int arr[MAXN];


int main() {
    int tt;
    scanf("%d", &tt); 
    while(tt--) {
        scanf("%d", &N);
        for(int i=0;i<N;++i)
            scanf("%d", &arr[i]);

        ll sum = 0;
        int ans = 0;
        for(int i=0;i<N;++i) {
            if(sum < arr[i]) {
                ++ans;
                sum += arr[i];
            } else {
                sum -= arr[i-1];
                sum += arr[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
