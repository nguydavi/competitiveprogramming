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

const int MAXN = 1e5+10;
int N;
map<int, int> mm[3];

int main() {
    scanf("%d", &N);
    for(int ii=0;ii<3;++ii) {
        for(int i=0;i<N-ii;++i) {
            int a;
            scanf("%d", &a);
            ++mm[ii][a];
        }
    }

    for(auto kv : mm[0]) {
        if(kv.second != mm[1][kv.first])
            printf("%d\n", kv.first);
    }
    for(auto kv : mm[1]) {
        if(kv.second != mm[2][kv.first])
            printf("%d\n", kv.first);
    }
    return 0;
}
