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

void troublesort(vector<int>& v) {
    bool done = false;
    while(!done) {
        done = true;
        for(int i=0;i<v.size()-2;++i) {
            if(v[i] > v[i+2]) {
                done = false;
                int tmp = v[i];
                v[i] = v[i+2];
                v[i+2] = tmp;
            }
        }
    }
}

int solve(const vector<int>& v) {
    vector<int> evenV, oddV;
    for(int i=0;i<v.size();++i) {
        if(i%2==0)
            evenV.push_back(v[i]);
        else
            oddV.push_back(v[i]);
    }
    sort(evenV.begin(), evenV.end());
    sort(oddV.begin(), oddV.end());

    int last = evenV[0];
    int res = -1;
    for(int i=1;i<v.size();++i) {
        if(i%2==0) {
            if(evenV[i/2] < last) {
                res = i-1;
                break;
            }
            last = evenV[i/2];
        } else {
            if(oddV[i/2] < last) {
                res = i-1;
                break;
            }
            last = oddV[i/2];
        }
    }
    return res;
}

int main() {
    int tt;
    scanf("%d", &tt);
    for(int ii=1;ii<=tt;++ii) {
        int N;
        scanf("%d", &N);
        vector<int> v;
        for(int i=0;i<N;++i) {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }

        int ans = solve(v);

        printf("Case #%d: ", ii);
        if(ans == -1)
            printf("OK\n");
        else
            printf("%d\n", ans);

    }
    return 0;
}
