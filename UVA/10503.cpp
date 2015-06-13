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

#define MAXX 20
int N,M;
pair<int, int> arr[MAXX];

bool solve(int index, multiset<pair<int, int> >& remain) {
    if(index == N+1) {
        if(arr[index-1].second == arr[index].first)
            return true;
        else
            return false;
    }

    multiset<pair<int, int> > left(remain);
    bool res = false;
    for(set<pair<int, int> >::iterator it=left.begin();it!=left.end();++it) {
        if(arr[index-1].second == it->first) {
            arr[index] = *it;
            remain.erase(*it);
            remain.erase(make_pair(it->second, it->first));
            res |= solve(index+1, remain);
            if(res)
                return res;
            remain.insert(*it);
            remain.insert(make_pair(it->second, it->first));
        }
    }
    return res;
}

int main() {
    while(cin >> N && N) {
        cin >> M;

        int a,b;
        cin >> a >> b;
        arr[0] = make_pair(a,b);
        cin >> a >> b;
        arr[N+1] = make_pair(a,b);

        multiset<pair<int,int> > domi;
        for(int i=0;i<M;++i) {
           cin >> a >> b;
           domi.insert(make_pair(a,b)); 
           domi.insert(make_pair(b,a)); 
        }

        if(solve(1, domi))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
