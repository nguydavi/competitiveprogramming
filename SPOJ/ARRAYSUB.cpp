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
int N, K;
int arr[MAXN];

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);
    scanf("%d", &K);
    
    deque<int> dq;
    for(int i=0;i<N;++i) {
        while(!dq.empty() && dq.back() < arr[i])
            dq.pop_back();
        dq.push_back(arr[i]);

        if(i >= K-1) {
            if(i-K+1)
                printf(" ");
            printf("%d", dq.front());
            if(dq.front() == arr[i-K+1])
                dq.pop_front();
        }
    }
    printf("\n");
    return 0;
}
