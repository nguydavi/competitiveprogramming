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

const int MAXN = 60;
int N, M;

int main() {
    scanf("%d %d", &N, &M);

    bool left = false;
    for(int i=0;i<N;++i) {
        bool nextLeft = left;
        for(int j=0;j<M;++j) {
            if(i%2 != 0) {
                if(!left && j == M-1) {
                    printf("#");
                    nextLeft = true;
                } else if(left && j == 0) {
                    printf("#");
                    nextLeft = false;
                } else
                    printf(".");
            } else
                printf("#");
        }
        left = nextLeft;
        printf("\n");
    }
    return 0;
}
