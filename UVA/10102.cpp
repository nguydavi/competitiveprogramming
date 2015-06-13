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

#define MAXM 1000
int M;
int mat[MAXM][MAXM];
vector<pair<int, int> > start, end;

int main() {
    while(cin >> M) {
        start.clear(), end.clear();

        for(int i=0;i<M;++i)
            for(int j=0;j<M;++j) {
                char c;
                cin >> c;
                mat[i][j] = c - '0';

                if(mat[i][j] == 1)
                    start.push_back(make_pair(i,j));
                else if(mat[i][j] == 3)
                    end.push_back(make_pair(i,j));
            }

        int maxDist = 0;
        for(int i=0;i<start.size();++i) {
            int curMin = 1<<25;
            for(int j=0;j<end.size();++j)
                curMin = min(curMin, abs(start[i].first-end[j].first) + abs(start[i].second - end[j].second));
            maxDist = max(maxDist, curMin);
        }
        cout << maxDist << "\n";
    }
    return 0;
}
