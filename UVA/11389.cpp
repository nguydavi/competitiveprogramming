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
int N, D, R;
int morning[MAXN], evening[MAXN];

int main() {
    while(scanf("%d %d %d", &N, &D, &R) && N && D && R) {
        for(int i=0;i<N;++i)
            scanf("%d", &morning[i]);
        for(int i=0;i<N;++i)
            scanf("%d", &evening[i]);
        sort(morning, morning+N);
        sort(evening, evening+N);

        int total = 0;
        for(int i=0;i<N;++i) {
            int kk = morning[i] + evening[N-1-i] - D;
            if(kk > 0)
                total += kk;
        }
        printf("%d\n", total*R);
    }
    
    return 0;
}
