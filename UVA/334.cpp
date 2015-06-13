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
int N, M, E;
map<string, int> mm;
string arr[MAXN];
bool adj[MAXN][MAXN];

int main() {
    int tc = 1;
    while(scanf("%d", &M) == 1 && M) {
        mm.clear();
        memset(adj, false, sizeof(adj));
        N = 0;
        for(int i=0;i<M;++i) {
            int R;
            int prev = -1;
            scanf("%d", &R);
            while(R--) {
                string a;
                cin >> a;
                mm[a] = N;
                arr[N] = a;

                if(prev != -1)
                    adj[prev][N] = true;
                prev = N++;
            }
        }
        for(int i=0;i<N;++i)
            adj[i][i] = true;
        scanf("%d", &E);
        while(E--) {
            string u, v;
            cin >> u >> v;
            adj[mm[u]][mm[v]] = true;
        }

        for(int k=0;k<N;++k)
            for(int i=0;i<N;++i)
                for(int j=0;j<N;++j)
                    adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);

        vector<pair<int, int> > res;
        for(int i=0;i<N;++i)
            for(int j=i+1;j<N;++j)
                if(!adj[i][j] && !adj[j][i])
                    res.push_back(make_pair(i, j));

        if(res.empty())
            printf("Case %d, no concurrent events.\n", tc++);
        else {
            printf("Case %d, %d concurrent events:\n", tc++, (int)res.size());
            for(int i=0;i<min((int)res.size(), 2);++i) {
                cout << "(" << arr[res[i].first] << "," << arr[res[i].second] << ") ";
            }
            printf("\n");
        }

    }

    return 0;
}
