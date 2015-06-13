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
#define MAXX 30
ll cube[MAXX][MAXX][MAXX], ps[MAXX][MAXX][MAXX];
int A,B,C;

// ps contains prefix sum (x,y,z) for row up to x, only column y and depth from
// z to C
void precompute() {
    for(int i=0;i<A;++i)
        for(int j=0;j<B;++j) {
            ll prefixSum = 0LL;
            for(int k=0;k<C;++k) {
                prefixSum += cube[i][j][k];
                ps[i][j][k] = prefixSum;
                if(i)
                    ps[i][j][k] += ps[i-1][j][k];
            }
        }
}

ll getCell(int y, int x1, int x2, int z1, int z2) {
    ll res = ps[x2][y][z2];
    if(x1)
        res -= ps[x1-1][y][z2];
    if(z1)
        res -= ps[x2][y][z1-1];
    if(x1 && z1)
        res += ps[x1-1][y][z1-1];
    return res;
}

ll maxSubArray(const vector<ll>& vv) {
    ll cur=0, res=0, maxEl = -1LL << 31;
    for(int i=0;i<vv.size();++i) {
        cur = max(0LL, cur+vv[i]);
        res = max(res, cur);
        maxEl = max(maxEl, vv[i]);
    }
    if(!res)
        res = maxEl;
    return res;
}

// reducing the problem to a 1d array to use maxSubArray
ll solve() {
    ll ans = -1LL<<33;
    for(int x1=0;x1<A;++x1)
        for(int z1=0;z1<C;++z1)
            for(int x2=x1;x2<A;++x2)
                for(int z2=z1;z2<C;++z2) {
                    vector<ll> vv;
                    for(int y=0;y<B;++y)
                        vv.push_back(getCell(y,x1,x2,z1,z2));
                    ans = max(ans, maxSubArray(vv));
                }
    return ans;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> A >> B >> C;
        for(int i=0;i<A;++i)
            for(int j=0;j<B;++j)
                for(int k=0;k<C;++k)
                    cin >> cube[i][j][k];
        precompute();

        cout << solve() << "\n";
        if(tc)
            cout << "\n";
    }
    
    return 0;
}
