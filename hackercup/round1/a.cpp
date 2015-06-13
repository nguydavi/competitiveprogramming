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
#include <fstream>

using namespace std;

const int MAXN = (int)1e7+10;
int A, B, K;
bool divis[MAXN];
int primacity[MAXN];

void precompute() {
    memset(divis, false, sizeof(divis));
    memset(primacity, 0, sizeof(primacity));
    //Note: do not stop at i*i >= MAXN(to count high primes) and start j at i*i!
    for(int i=2;i<MAXN;++i)
        if(!divis[i])
            for(int j=i;j<MAXN;j+=i) {
                divis[j] = true;
                ++primacity[j];
            }
}

int main() {
    precompute();

    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d %d %d", &A, &B, &K);

        int ans = 0;
        for(int i=A;i<=B;++i)
            if(primacity[i] == K)
                ++ans;

        printf("Case #%d: %d\n", ii, ans);
    }
    return 0;
}
