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

const int MAXN = 30;
int N;
char arr[MAXN];
map<char, int> mm;
bool adj[MAXN][MAXN];
bool hasSol;

bool canAdd(const vector<int>& v, int id) {
    for(int i=0;i<v.size();++i)
        if(adj[id][v[i]])
            return false;
    return true;
}

void solve(vector<int>& v) {
    if(v.size() == N) {
        hasSol = true;
        printf("%c", arr[v[0]]);
        for(int i=1;i<N;++i)
            printf(" %c", arr[v[i]]);
        printf("\n");
    } else {
        for(int i=0;i<N;++i) {
            if(canAdd(v, i)) {
                v.push_back(i);
                solve(v);
                v.pop_back();
            }
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    cin.ignore();
    while(tc--) {
        cin.ignore();
        string line;
        getline(cin, line);
        stringstream ss(line);
        char c;
        int i = 0;
        while(ss >> c)
            arr[i++] = c;
        N = i;
        sort(arr, arr+N);
        mm.clear();
        for(int i=0;i<N;++i)
            mm[arr[i]] = i;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        char a, sign, b;
        memset(adj, false, sizeof(adj));
        while(ss >> a >> sign >> b)
            adj[mm[a]][mm[b]] = true;
        for(int i=0;i<N;++i)
            adj[i][i] = true; // to prevent repeated elements

        hasSol = false;
        vector<int> v;
        solve(v);

        if(!hasSol)
            printf("NO\n");
        if(tc)
            printf("\n");
    } 
    return 0;
}
