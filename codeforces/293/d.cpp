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

const int MAXN = 2010;
int N, T;
double P;
double prob[MAXN][MAXN];

int main() {
    scanf("%d %lf %d", &N, &P, &T);

    prob[0][0] = 1;
    for(int t=0;t<T;++t) {
        for(int n=0;n<N;++n) {
            prob[n][t+1] += prob[n][t]*(1-P);
            prob[n+1][t+1] += prob[n][t]*P;
        }
        prob[N][t+1] += prob[N][t];
    }

    double ans = 0;
    for(int i=0;i<=N;++i)
        ans += prob[i][T]*i;

    printf("%lf\n", ans);
    return 0;
}
