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

#define MAXX 80
int N;
int mat[MAXX][MAXX], ps[2*MAXX][2*MAXX];

void precompute() {
    for(int j=0;j<N;++j) {
        int sum = 0;
        for(int i=0;i<2*N;++i) {
            sum += mat[i%N][j];
            ps[i][j] = sum;
        }
    }
}

int maxSubArray(const deque<int>& dq) {
    int cur = 0, res = 0, maxEl = -200;
    for(int i=0;i<dq.size();++i) {
        cur = max(0, cur+dq[i]);
        res = max(res, cur);
        maxEl = max(maxEl, dq[i]);
    }
    if(!res)
        res = maxEl;
    return res;
}

int solve() {
    int res = -200;
    set<pair<int, int> > cache;
    for(int x1=0;x1<2*N;++x1)
        for(int x2=x1;x2<min(2*N,x1+N);++x2) {
            if(cache.find(make_pair(x1%N, x2%N)) == cache.end()) {
                deque<int> vv;
                for(int y=0;y<N;++y) {
                    int cc = ps[x2][y];
                    if(x1)
                        cc -= ps[x1-1][y];
                    vv.push_back(cc);
                }
                for(int k=0;k<N;++k) {
                    res = max(res, maxSubArray(vv));
                    int tmp = vv.back();
                    vv.pop_back();
                    vv.push_front(tmp);
                }
                cache.insert(make_pair(x1%N,x2%N));
            }
        }
    return res;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> N;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                cin >> mat[i][j];
        precompute();
        cout << solve() << "\n";
    } 
    return 0;
}
