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
#define MAXN 100010
int N, M;
vector<ll> psum;

int main() {
    scanf("%d", &N);
    ll sum = 0;
    for(int i=0;i<N;++i) {
        int a;
        scanf("%d", &a);
        sum += a;
        psum.push_back(sum);
    }

    scanf("%d", &M);
    for(int i=0;i<M;++i) {
        ll q;
        cin >> q;
        printf("%d\n", (int)(lower_bound(psum.begin(), psum.end(), q)-psum.begin())+1);
    }
        
    return 0;
}
