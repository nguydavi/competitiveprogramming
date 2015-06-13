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

typedef pair<int, int> pii;
const int MAXN = 200;
int N, K;
pii arr[MAXN];

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;++i) {
        int v;
        scanf("%d", &v);
        arr[i] = {v, i};
    }
    sort(arr, arr+N);
    
    int sum = 0;
    int index = 0;
    vector<int> ans;
    for(int i=0;i<N;++i) {
        sum += arr[i].first;
        if(sum > K)
            break;
        ans.push_back(arr[i].second+1);
    }
    printf("%d\n", ans.size());
    for(int i=0;i<ans.size();++i) {
        if(i)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}
