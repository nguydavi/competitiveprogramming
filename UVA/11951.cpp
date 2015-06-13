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

#define MAXX 110
int mat[MAXX][MAXX], ps[MAXX][MAXX];
int N, M, K;

void precompute() {
    for(int j=0;j<M;++j) {
        int sum = 0;
        for(int i=0;i<N;++i) {
            sum += mat[i][j];
            ps[i][j] = sum;
        }
    }
}

pair<int, int> maxSubBelowK(const vector<int>& vv) {
    /*
     Simpler version:
     int start = 0;
     int curSum = 0;
     int counter = 0, sum = 0;
     for(int i=0;i<vv.size();++i) {
        curSum += vv[i];
        while(curSum > K)
            curSum -= vv[start++];

        if(i-start+1 > counter)
            counter = i - start+1, sum = curSum;
        else if(i - start+1 == counter && curSum < sum)
            sum = curSum;
     }
     return make_pair(counter, sum);
     */
    int index1 = 0, index2 = 0;
    int curSum = 0;
    int counter = 0, sum = (int)1e9;
    while(index1 < vv.size() && index2 < vv.size()) {
        if(index2)
            if(curSum > K)
                while(curSum > K && index1 < vv.size())
                    curSum -= vv[index1++];
            else
                curSum -= vv[index1++];
        else if(vv[index2] > K)
            ++index2, ++index1;
        while(curSum + vv[index2] <= K && index2 < vv.size())
            curSum += vv[index2++];

        if(index2-index1 > counter)
            counter = index2-index1, sum = curSum;
        else if(index2-index1 == counter && curSum < sum)
            sum = curSum;
    }

    return make_pair(counter, sum);
}

pair<int, int> solve() {
    int res = 0, resPrice = 0;
    for(int x1=0;x1<N;++x1)
        for(int x2=x1;x2<N;++x2) {
            vector<int> vv;
            for(int y=0;y<M;++y) {
                int tt = ps[x2][y];
                if(x1)
                    tt -= ps[x1-1][y];
                vv.push_back(tt);
            }
            pair<int, int> rr(maxSubBelowK(vv));
            if(rr.first*(x2-x1+1) > res)
                res = rr.first*(x2-x1+1), resPrice = rr.second;
            else if(rr.first*(x2-x1+1) == res && rr.second < resPrice)
                resPrice = rr.second;
        }
    return make_pair(res, resPrice);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d %d %d", &N, &M, &K);
        for(int i=0;i<N;++i)
            for(int j=0;j<M;++j)
                scanf("%d", &mat[i][j]);
        precompute();
        pair<int, int> ans = solve();

        printf("Case #%d: %d %d\n", ii, ans.first, ans.second);
    } 
    return 0;
}
