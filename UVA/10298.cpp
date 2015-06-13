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

const int MAXN = (int)1e6+10;
int N;
char s[MAXN];

int main() {
    while(scanf("%s", &s) == 1 && strcmp(s, ".") != 0) {
        N = strlen(s);
        int ans = 1;

        for(int len=1;len<=N;++len) {
            if(N%len == 0) {
                bool found = true;
                for(int j=len;j<N;++j)
                    if(s[j] != s[j%len]) {
                        found = false;
                        break;
                    }

                if(found) {
                    ans = len;
                    break;
                }
            }
        }
        printf("%d\n", N/ans);
    }
    return 0;
}
