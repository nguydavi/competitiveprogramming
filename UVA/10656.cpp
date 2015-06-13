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

int N;

int main() {
    while(scanf("%d", &N) && N) {
        bool first = true;
        for(int i=0;i<N;++i) {
            int a;
            scanf("%d", &a);
            if(a) {
                if(!first)
                    printf(" ");
                printf("%d", a), first = false;
            }
        }
        if(first)
            printf("0");
        printf("\n");
    }    
    return 0;
}
