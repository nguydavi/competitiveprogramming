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
const int MAXM = 110;
int N, M;
int boys[MAXN], girls[MAXM];

int main() {
    scanf("%d", &N);    
    for(int i=0;i<N;++i)
        scanf("%d", &boys[i]);
    scanf("%d", &M);
    for(int i=0;i<M;++i)
        scanf("%d", &girls[i]);

    sort(boys, boys+N);
    sort(girls, girls+M);

    int indexBoys = 0;
    int indexGirls = 0;
    int ans = 0;
    while(indexBoys < N && indexGirls < M) {
        if(abs(boys[indexBoys] - girls[indexGirls]) <= 1)
            ++ans, ++indexBoys, ++indexGirls;
        else if(boys[indexBoys] < girls[indexGirls])
            ++indexBoys;
        else
            ++indexGirls;
    }

    printf("%d\n", ans);
    return 0;
}
