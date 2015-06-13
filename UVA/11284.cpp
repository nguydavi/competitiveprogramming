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

const int MAXN = 60;
const int MAXP = 15;
const int MASK = 1<<13;
const int INF = (int)1e9;
int N, M, P;
int dist[MAXN][MAXN], price[MAXN], dp[MAXP][MASK];
int sto[MAXP], stoId[MAXP];
int result;
int totalSto;

int solve(int cur, int bitmask) {
    if(!bitmask)
        return 0;
    if(dp[cur][bitmask] != -INF)
        return dp[cur][bitmask];

    int res = -INF;
    if(bitmask == (1<<cur))
        res = -dist[stoId[cur]][0] + price[stoId[cur]];
    else 
        for(int i=0;i<totalSto;++i)
            if(cur != i && (bitmask & (1<<i))) {
                int ss = solve(i, bitmask - (1<<cur));
                res = max(res, ss - dist[stoId[cur]][stoId[i]] + price[stoId[cur]]);
            }

    dp[cur][bitmask] = res;
    result = max(result, res - dist[stoId[cur]][0]);
    return res;
}

/*
int rec(int state,int id,int pre){
    if(state==0)
        return 0;
    if(dp[pre][state]!=-INF)
        return dp[pre][state];
    int i,j;
    int ret = -INF,tmp;

    if(state==(1<<pre))
        ret = -dist[stoId[pre]][0] + price[stoId[pre]];
    else
        for(i=0;i<id;i++){
            if(pre!=i && (state&(1<<i))!=0){
                tmp = rec(state-(1<<pre),id,i);
                tmp -= dist[stoId[i]][stoId[pre]];
                tmp += price[stoId[pre]];
                ret = max(ret,tmp);
            }
        }

    result = max(result, ret-dist[stoId[pre]][0]);
    return dp[pre][state] = ret;
}
*/

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> N >> M;
        for(int i=0;i<=N;++i)
            for(int j=0;j<=N;++j)
                dist[i][j] = INF;
        
        for(int i=0;i<M;++i) {
            int a, b;
            cin >> a >> b;
            //cin >> dist[a][b];
            int x, y;
            scanf("%d.%d", &x, &y);
            dist[b][a] = dist[a][b] = 100*x + y;
            //dist[a][b] = min(dist[a][b], 100*x+y);
            //dist[b][a] = min(dist[b][a], 100*x+y);
        }
        for(int i=0;i<=N;++i)
            dist[i][i] = 0;
        cin >> P;
        memset(price, 0, sizeof(price));
        for(int i=0;i<P;++i) {
            cin >> sto[i];
            int x, y;
            scanf("%d.%d", &x, &y);
            price[sto[i]] += 100*x + y;
        }
        totalSto = 0;
        //totalSto = 1; // 0 would give most the good answers, 1 doesn't but
        //give right answer to the rest ?!
        memset(stoId, 0, sizeof(stoId));
        for(int i=1;i<=N;++i)
            if(price[i])
                stoId[totalSto++] = i;

        /*
        for(int i=0;i<totalSto;++i)
            cout << stoId[i] << " ";
        cout << endl;
        for(int i=0;i<=N;++i)
            cout << price[i] << " ";
        cout << endl;
        */

        // Floyd-Warshall
        for(int k=0;k<=N;++k)
            for(int i=0;i<=N;++i)
                for(int j=0;j<=N;++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        /*
        for(int i=0;i<=N;++i) {
            for(int j=0;j<=N;++j)
                cout << dist[i][j] << " ";
            cout << endl;
        }
        */


        result = -INF;
        for(int i=0;i<P;++i)
            for(int j=0;j<(1<<totalSto);++j)
                dp[i][j] = -INF;
        
        int ans = solve(0, (1<<totalSto)-1);
        //int ans = rec((1<<totalSto)-1, totalSto, 0);
        /*
        for(int i=0;i<totalSto;++i) {
            for(int j=0;j<(1<<totalSto);++j)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        cout << "DEBUG " << " " << ans << " " << result << endl;
        */
        if(result <= 0)
            cout << "Don't leave the house\n";
        else
            printf("Daniel can save $%d.%02d\n", result/100, result%100);
    } 
    return 0;
}
