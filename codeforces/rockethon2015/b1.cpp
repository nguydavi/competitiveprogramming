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
int arr[MAXN];

int f() {
    int res = 0;
    for(int i=0;i<N;++i)
        for(int j=i;j<N;++j) {
            int minEl = 1e9;
            for(int k=i;k<=j;++k)
                minEl = min(minEl, arr[k]);
            res += minEl;
        }
    return res;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i)
        arr[i] = i+1;

    int maxF = 0;
    do {
        maxF = max(maxF, f());
    } while(next_permutation(arr, arr+N));

    vector<vector<int> > ans;
    sort(arr, arr+N);
    do {
        int point = f();
        if(point == maxF)
            ans.push_back(vector<int>(arr, arr+N));
    } while(next_permutation(arr, arr+N));

    sort(ans.begin(), ans.end());
    vector<int> sol = ans[M-1];
    for(int i=0;i<sol.size();++i) {
        if(i)
            printf(" ");
        printf("%d", sol[i]);
    }
    printf("\n");
    return 0;
}
