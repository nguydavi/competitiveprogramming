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

#define MAXX 101
#define BLACK 1
#define WHITE 0
int N,K, maxColor;
int color[MAXX], solColor[MAXX];
vector<vector<int> > adjList;

int sumOnes() {
    int sum = 0;
    for(int i=1;i<=N;++i)
        sum += color[i];
    return sum;
}

void solve(int node, int totalBlack) {
    if(node > N) {
        if(totalBlack > maxColor) {
            maxColor = totalBlack;
            for(int i=1;i<=N;++i)
                solColor[i] = color[i];
        }
        return;
    }

    color[node] = WHITE;
    solve(node+1, totalBlack);
    
    bool canBlack = true;
    for(int i=0;i<adjList[node].size();++i)
        if(color[adjList[node][i]] == BLACK) {
            canBlack = false;
            break;
        }
    if(canBlack) {
        color[node] = BLACK;
        solve(node+1, totalBlack+1);
    }
    color[node] = -1;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> N >> K;
        adjList.clear();
        for(int i=0;i<=N;++i)
            adjList.push_back(vector<int>());
        memset(color, -1, sizeof(color));
        maxColor = 0;

        while(K--) {
            int a,b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        solve(1, 0);
        cout << maxColor << "\n";

        bool isFirst = true;
        for(int i=1;i<=N;++i)
            if(solColor[i] == BLACK) {
                if(isFirst)
                    isFirst = false;
                else
                    cout << " ";
                cout << i;
            }
        cout << "\n";
    } 
    return 0;
}
