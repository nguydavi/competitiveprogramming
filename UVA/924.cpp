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

const int MAXN = 2510;
const int INF = (int)1e9;
int N;
vector<int> adjList[MAXN];

void solve(int start) {
    vector<int> dist(N, INF);
    vector<int> boom(N+1, 0);
    queue<int> qq;
    qq.push(start);
    dist[start] = 0;

    while(!qq.empty()) {
        int u = qq.front();
        qq.pop();

        for(int i=0;i<adjList[u].size();++i) {
            int v = adjList[u][i];
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                ++boom[dist[v]];
                qq.push(v);
            }
        }
    }

    int day = -1;
    int maxBoom = 0;
    for(int i=1;i<=N;++i) {
        if(boom[i] > maxBoom) {
            maxBoom = boom[i];
            day = i;
        }
    }
    if(day != -1)
        cout << maxBoom << " " << day << "\n";
    else
        cout << "0\n";
}

int main() {
    cin >> N;
    cin.ignore();
    for(int i=0;i<N;++i)
        adjList[i].clear();

    for(int i=0;i<N;++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int nn;
        ss >> nn;
        for(int j=0;j<nn;++j) {
            int neigh;
            ss >> neigh;
            adjList[i].push_back(neigh);
        }
    }

    int tc;
    cin >> tc;
    while(tc--) {
        int start;
        cin >> start;
        solve(start);
    }
    return 0;
}
