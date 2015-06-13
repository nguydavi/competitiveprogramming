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

const int MAXN = 1010;
int N;
vector<int> arr;
priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;

vector<int> findMin(const vector<int>& a) {
    deque<int> v(a.begin(), a.end());
    deque<int> ans(N, (int)1e9);
    for(int i=0;i<N;++i) {
        ans = min(ans, v);
        int t = v.back();
        v.pop_back();
        v.push_front(t);
    }
    return vector<int>(ans.begin(), ans.end());
}

int main() {
    scanf("%d", &N);
    string line;
    cin >> line;
    arr.assign(N, -1);
    for(int i=0;i<N;++i)
        arr[i] = line[i]-'0';

    for(int i=0;i<10;++i) {
        arr = findMin(arr);
        pq.push(arr);
        for(int j=0;j<N;++j)
            arr[j] = (arr[j]+1)%10;
    }
    vector<int> ans = pq.top();
    for(int i=0;i<N;++i)
        printf("%d", ans[i]);
    printf("\n");


    return 0;
}
