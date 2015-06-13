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
const int MAXN = (int)2e5+10;
const int MAXM = (int)2e5+10;
int N, M;
int arr1[MAXN], arr2[MAXM];
vector<int> arr12;

ll getTotal2(int val) {
    ll total2;
    if(arr2[M-1] <= val)
        total2 = M*2;
    else {
        int index2 = upper_bound(arr2, arr2+M, val) - arr2;
        total2 = 2*index2 + 3*(M-index2);
    }
    return total2;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d", &arr1[i]), arr12.push_back(arr1[i]);
    scanf("%d", &M);
    for(int i=0;i<M;++i)
        scanf("%d", &arr2[i]), arr12.push_back(arr2[i]);
    sort(arr1, arr1+N);
    sort(arr2, arr2+M);
    sort(arr12.begin(), arr12.end());
            
    ll ansA = 3*N, ansB = 3*M, maxDiff = ansA-ansB;
    if(maxDiff < 2*N - 2*M) {
        maxDiff = 2*N - 2*M;
        ansA = 2*N;
        ansB = 2*M;
    }

    for(int i=0;i<arr12.size();++i) {
        int index1 = upper_bound(arr1, arr1+N, arr12[i])-arr1;
        ll total1 = 2*index1 + 3*(N-index1);
        ll total2 = getTotal2(arr12[i]);

        if(maxDiff < total1 - total2 || (maxDiff == total1-total2 && total1 > ansA)) {
            maxDiff = total1 - total2;
            ansA = total1;
            ansB = total2;
        }
    }
    cout << ansA << ":" << ansB << "\n";
    return 0;
}
