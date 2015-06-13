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

const int MAXN = 110;
int N, M;
string arr[MAXN];
bool adj[MAXN][MAXN];
int inc[MAXN];
vector<int> ans;

void solve() {
    priority_queue<int, vector<int>, greater<int> > qq;
    for(int i=0;i<N;++i)
        if(inc[i] == 0)
            qq.push(i);

    while(!qq.empty()) {
        int id = qq.top();
        qq.pop();
        ans.push_back(id);

        for(int i=0;i<N;++i)
            if(adj[id][i]) {
                --inc[i];
                if(inc[i] == 0)
                    qq.push(i);
            }
    }
}

int main() {
    int tc = 1;
    while(scanf("%d", &N) == 1) {
        map<string, char> mm;
        for(int i=0;i<N;++i) {
            cin >> arr[i];
            mm[arr[i]] = i;
        }
        scanf("%d", &M);
        memset(adj, false, sizeof(adj));
        memset(inc, 0, sizeof(inc));
        for(int i=0;i<M;++i) {
            string a, b;
            cin >> a >> b;
            if(!adj[mm[a]][mm[b]]) {
                adj[mm[a]][mm[b]] = true;
                ++inc[mm[b]];
            }
        }

        ans.clear();
        solve();
        printf("Case #%d: Dilbert should drink beverages in this order: ", tc++);
        cout << arr[ans[0]];
        for(int i=1;i<ans.size();++i)
            cout << " " << arr[ans[i]];
        printf(".\n\n");
    }    
    return 0;
}
