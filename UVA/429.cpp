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

const int MAXN = 210;
const int INF = (int)1e9;
int N;
map<string, int> mm;
string arr[MAXN];
vector<int> adjList[MAXN];

int solve(const string& start, const string& end) {
    vector<int> dist(N, INF);
    queue<int> qq;
    qq.push(mm[start]);
    dist[mm[start]] = 0;

    while(!qq.empty()) {
        int cur = qq.front();
        qq.pop();

        for(int i=0;i<adjList[cur].size();++i) {
            int v = adjList[cur][i];
            if(dist[v] == INF) {
                dist[v] = dist[cur] + 1;
                qq.push(v);
            }
        }
    }
    return dist[mm[end]];
}

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    for(int ii=0;ii<tc;++ii) {
        mm.clear();
        for(int i=0;i<MAXN;++i)
            adjList[i].clear();

        int cur = 0;
        string word;
        while(getline(cin, word)) {
            if(word == "*")
                break;
            arr[cur] = word;
            mm[word] = cur++;
        }
        N = cur;
        for(int i=0;i<N;++i)
            for(int j=i+1;j<N;++j) {
                if(arr[i].size() == arr[j].size()) {
                    int diff = 0;
                    for(int k=0;k<arr[i].size();++k)
                        if(arr[i][k] != arr[j][k])
                            ++diff;
                    if(diff == 1) {
                        adjList[mm[arr[i]]].push_back(mm[arr[j]]);
                        adjList[mm[arr[j]]].push_back(mm[arr[i]]);
                    }
                }
            }

        if(ii)
            cout << "\n";
        string line;
        while(getline(cin, line)) {
            if(line.empty())
                break;
            stringstream ss(line);
            string start, end;
            ss >> start >> end;

            cout << start << " " << end << " " << solve(start, end) << "\n";
        }

    }
    return 0;
}
