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

typedef long long ll;
const int MAXN = 50;
int N, A, B;
int arr[MAXN];

vector<ll> getAllSums(int startIndex, int endIndex) {
    vector<ll> res;
    int maxn = 1<<(endIndex-startIndex);
    for(int i=0; i < maxn;++i) {
        int sum = 0;
        for(int j=0;j<endIndex-startIndex;++j)
            if(i&(1<<j))
                sum += arr[startIndex+j];

        res.push_back(sum);
    }
    return res;
}

ll solve() {
    vector<ll> v1 = getAllSums(0, N/2);
    vector<ll> v2 = getAllSums(N/2, N);
    sort(v2.begin(), v2.end());

    ll res = 0;
    for(int n : v1) {
        int startIndex = lower_bound(v2.begin(), v2.end(), A-n)-v2.begin();
        int endIndex = upper_bound(v2.begin(), v2.end(), B-n)-v2.begin();
        res += endIndex-startIndex;
    }
    return res;
}

int main() {
    scanf("%d %d %d", &N, &A, &B);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);
    printf("%lld\n", solve());
    return 0;
}
