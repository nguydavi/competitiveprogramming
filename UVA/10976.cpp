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

#define MAXX 100000005
typedef long long ll;
int K;
vector<pair<int, int> > sol;

int main() {
    while(cin >> K) {
        sol.clear();
        for(int y=K+1;y<=2*K;++y)
            if((y*K) % (y-K) == 0)
                sol.push_back(make_pair(y,(y*K)/(y-K)));

        cout << sol.size() << "\n";
        for(int i=0;i<sol.size();++i)
            cout << "1/" << K << " = 1/" << sol[i].second << " + 1/" << sol[i].first << "\n";
    }
    return 0;
}
