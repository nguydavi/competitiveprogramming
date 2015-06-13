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

int main() {
    int tc;
    scanf("%d" ,&tc);
    while(tc--) {
        int K;
        scanf("%d", &K);

        int term = 0;
        int nxt = 1;
        while(true) {
            if(term + nxt >= K)
                break;
            term += nxt;
            ++nxt;
        }

        --nxt;
        ++term;
        int i, j;
        if(nxt%2 == 0) {
            i = nxt;
            j = 0;
            while(term < K) {
                --i, ++j;
                ++term;
            }
        } else {
            i = 0;
            j = nxt;
            while(term < K) {
                ++i, --j;
                ++term;
            }
        }
        printf("TERM %d IS %d/%d\n", K, i+1, j+1);
    }
    return 0;
}
