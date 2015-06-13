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
char arr[MAXN];

int main() {
    int tt;
    scanf("%d", &tt);
    for(int ii=1;ii<=tt;++ii) {
        scanf("%d ", &N);
        for(int i=0;i<N;++i)
            scanf("%c", &arr[i]);

        int i = 0;
        int ans = 0;
        while(i < N) {
            if(arr[i] == '.') {
                ++ans;
                i += 3;
            } else
                ++i;
        }
        printf("Case %d: %d\n", ii, ans);
    } 
    return 0;
}
