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

int N,M;

vector<int> arr, sum;

int main() {
    int tc = 1;
    while(cin >> N) {
        if(!N)
            break;
        arr.clear();
        sum.clear();

        for(int i=0;i<N;++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        for(vector<int>::iterator i=arr.begin();i!=arr.end();++i)
            for(vector<int>::iterator j=i;j!=arr.end();++j)
                if(i!=j)
                    sum.push_back(*i+*j);

        cout << "Case " << tc++ << ":\n";
        cin >> M;
        while(M--) {
            int query;
            cin >> query;

            int ans = 0;
            int diff = 2147483647;
            vector<int>::iterator it = sum.begin();
            while(it != sum.end()) {
                if(diff > abs(query-*it))
                    diff = abs(query-*it), ans = *it;
                ++it;
            }
            cout << "Closest sum to " << query << " is " << ans << ".\n";
        }
    }
    return 0;
}
