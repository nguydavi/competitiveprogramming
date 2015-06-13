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

const int MAXN = 3010;
int N;
int arr[MAXN];

void swap(int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);

    vector<pair<int, int> > res;
    for(int i=0;i<N;++i) {
        int curMin = i;
        for(int j=i+1;j<N;++j)
            if(arr[j] < arr[curMin])
                curMin = j;

        if(curMin != i) {
            res.push_back(make_pair(i, curMin));
            swap(i, curMin);
        }
    }

    printf("%d\n", res.size());
    for(int i=0;i<res.size();++i)
        printf("%d %d\n", res[i].first, res[i].second);

    return 0;
}
