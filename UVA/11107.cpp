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
//const int MAXLEN = 1010; // limit's too high in memory
const int MAXLEN = 110;
const int INF = (int)1e9;
int N;
string arr[MAXN];
int tries[MAXN][MAXLEN*MAXLEN][26];
int nxt[MAXN];

/**
 * Solution works for small inputs. Memory required does not fit and
 * algorithm probably TLE
 */
void addTrie(int index, int start) {
    int cur = 0;
    for(int i=start;i<arr[index].size();++i) {
        int let = arr[index][i]-'a';
        if(tries[index][cur][let] == -1)
            tries[index][cur][let] = nxt[index]++;
        cur = tries[index][cur][let];
    }
}

int longestCommonPrefix(int index, int start) {
    vector<int> res;
    string s = arr[index];
    for(int i=0;i<N;++i) {
        int cur = 0;
        int j;
        for(j=start;j<s.size();++j) {
            int let = s[j]-'a';
            if(tries[i][cur][let] == -1)
                break;
            cur = tries[i][cur][let];
        }
        res.push_back(j-start);
    }
    sort(res.begin(), res.end(), greater<int>());
    return res[N/2];
}

int main() {
    int tc = 0;
    while(scanf("%d", &N) == 1 && N) {
        if(tc++)
            cout << "\n";
        memset(tries, -1, sizeof(tries));
        for(int i=0;i<N;++i)
            nxt[i] = 1;

        for(int i=0;i<N;++i) {
            cin >> arr[i];
            for(int j=0;j<arr[i].size();++j)
                addTrie(i, j);
        }

        set<string> sols;
        int maxLen = 0;
        for(int i=0;i<N;++i)
            for(int j=0;j<arr[i].size();++j) {
                int len = longestCommonPrefix(i, j);
                maxLen = max(maxLen, len);
                if(len)
                    sols.insert(arr[i].substr(j, len));
            }

        if(sols.empty())
            cout << "?\n";
        else
            for(set<string>::iterator it=sols.begin();it!=sols.end();++it)
                if(it->size() == maxLen)
                    cout << *it << "\n";
    }
    return 0;
}
