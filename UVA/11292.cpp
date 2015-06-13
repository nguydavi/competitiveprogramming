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

const int MAXN = 20010;
const int MAXM = 20010;
int N, M;
int drag[MAXN], knights[MAXM];

int main() {
    while(scanf("%d %d", &N, &M) && N && M) {
        for(int i=0;i<N;++i)
            scanf("%d", &drag[i]);
        for(int i=0;i<M;++i)
            scanf("%d", &knights[i]);
        sort(drag, drag+N);
        sort(knights, knights+M);

        int indexN = 0;
        int indexM = 0;
        int killed = 0;
        int total = 0;
        while(indexN < N && indexM < M) {
            if(drag[indexN] <= knights[indexM])
                ++killed, total += knights[indexM], ++indexN, ++indexM;
            else
                ++indexM;
        }

        if(killed != N)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", total);
    }    
    return 0;
}
