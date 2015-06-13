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

const int MAXN = (int)1e5+10;
int N;
int arr[MAXN];

/**
 * vector V has all maximums in decreasing order. When an element is pushed back to V,
 * it means it is a maximum of a subarray, the element before him are maximums of
 * bigger subarrays containing the smaller subarray with the new element.
 *
 * So for every new element we XOR it with every max element until that element
 * is bigger (because the new element can only be 2nd max at most)
 */
int solve() {
    int res = 0;
    vector<int> v;
    for(int i=0;i<N;++i) {
        while(!v.empty()) {
            res = max(res, arr[i]^v.back());
            if(arr[i] < v.back())
                break;
            v.pop_back();
        }
        v.push_back(arr[i]);
    }
    return res;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);

    printf("%d\n", solve());
    return 0;
}
