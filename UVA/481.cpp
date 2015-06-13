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

#define MAXX 1000000
int N = 0;
int arr[MAXX];

int findIndex(const vector<deque<pair<int, int> > >& vv, int val) {
    int left = 0, right = vv.size();
    while(left < right) {
        int mid = (left+right)/2;

        if(vv[mid][0].first == val)
            return mid;
        if(vv[mid][0].first < val)
            left = mid + 1;
        else if(vv[mid][0].first > val)
            right = mid;
    }
    return left;
}

deque<int> lis() {
    // Simpler: put index-1 as parent of i, then go through parents recursively
    vector<deque<pair<int, int> > > vv;
    for(int i=0;i<N;++i) {
        int index = findIndex(vv, arr[i]);
        if(index == vv.size())
            vv.push_back(deque<pair<int, int> >());
        vv[index].push_front(make_pair(arr[i], i));
    }
    
    deque<int> res;
    int curIndex = MAXX;

    for(int i=vv.size()-1; i>=0; --i)
        for(int j=0;j<vv[i].size();++j)
            if(vv[i][j].second < curIndex) {
                res.push_front(vv[i][j].first), curIndex = vv[i][j].second;
                break;
            }
    return res; 
}

int main() {
    while(cin >> arr[N])
        ++N;
    deque<int> sol(lis());

    cout << sol.size() << "\n-\n";
    for(int i=0;i<sol.size();++i)
        cout << sol[i] << "\n";
    return 0;
}
