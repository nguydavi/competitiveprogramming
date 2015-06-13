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

typedef pair<int, int> pii;
int N, M;
vector<int> arr;
vector<int> weights;

int solve(const vector<int>& v) {
    deque<int> dq(v.begin(), v.end());
    int res = 0;

    for(int i=0;i<M;++i) {
        int j = 0;
        while(dq[j] != arr[i]) {
            res += dq[j] == -1 ? 0 : weights[dq[j]];
            ++j;
        }
        dq[j] = -1;
        dq.push_front(arr[i]);
    }
    return res;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i) {
        int w;
        scanf("%d", &w);
        weights.push_back(w);
    }
    for(int i=0;i<M;++i) {
        int r;
        scanf("%d", &r);
        --r;
        arr.push_back(r);
    }

    set<int> ss;
    vector<int> sol;
    for(int i=0;i<M;++i)
        if(ss.find(arr[i]) == ss.end()) {
            ss.insert(arr[i]);
            sol.push_back(arr[i]);
        }

    int ans = solve(sol);
    printf("%d\n", ans);
    return 0;
}
