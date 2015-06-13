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

const int MAXN = 20;
const int MASK = 500;
int N, maxMask;
pair<int, int> arr[MAXN];
double dp[MAXN][MASK];// min TSP starting from dp[i][j]
int next[MAXN][MASK];

double squareDist(int a, int b) {
    int x = arr[a].first - arr[b].first;
    int y = arr[a].second - arr[b].second;
    return sqrt((double)x*x + y*y)+16;
}

double solve(int cur, int mask) {
    if(mask == maxMask)
        return 0;
    if(dp[cur][mask] != -1)
        return dp[cur][mask];

    double res = 1e9;
    for(int i=0;i<N;++i)
        if(!(mask & (1 << i))) {
            double tmp = squareDist(cur, i) + solve(i, mask | (1 << i));
            if(tmp < res) {
                res = tmp;
                next[cur][mask] = i;
            }
        }
    dp[cur][mask] = res; 
    return res;
}

int main() {
    int tc = 1;
    while(cin >> N && N) {
        maxMask = (1<<N)-1;
        for(int i=0;i<N;++i)
            cin >> arr[i].first >> arr[i].second;

        memset(next, -1, sizeof(next));
        for(int i=0;i<N;++i)
            for(int j=0;j<maxMask;++j)
                dp[i][j] = -1;

        double ans = 1e9;
        int startNode = -1;
        for(int i=0;i<N;++i) {
            double tmp = solve(i, 1 << i);
            if(tmp < ans) {
                ans = tmp;
                startNode = i;
            }
        }
        
        int curMask = 1<<startNode;
        int curNode = startNode;
        cout << "**********************************************************\n";
        cout << "Network #" << tc++ << "\n";
        while(curMask != maxMask) {
            int nextNode = next[curNode][curMask];
            cout << "Cable requirement to connect (" << arr[curNode].first << "," << arr[curNode].second << ") to ";
            cout << "(" << arr[nextNode].first << "," << arr[nextNode].second << ") is ";
            printf("%.2lf feet.\n", squareDist(curNode, nextNode));

            curNode = nextNode;
            curMask = curMask | (1<<curNode);
        }
        printf("Number of feet of cable required is %.2lf.\n", ans);
    }    
    return 0;
}
