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

int pop[5][5], cpy[5][5];
vector<int> sol;
int minDist;

pair<int, int> getPos(int id) {
    return make_pair(id/5, id%5);
}

vector<int> newSol(int a, int b, int c, int d, int e) {
    vector<int> res(5);
    res[0] = a;
    res[1] = b;
    res[2] = c;
    res[3] = d;
    res[4] = e;
    return res;
}

void initCpy() {
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
            cpy[i][j] = pop[i][j];
}

void setOffices(vector<int> poss) {
    for(int i=0;i<poss.size();++i) {
        pair<int, int> pos = getPos(poss[i]);
        cpy[pos.first][pos.second] = -1;
    }
}

int solve(vector<int> poss) {
    int totalDist = 0;
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
            if(cpy[i][j] != -1 && cpy[i][j] != 0) {
                int curDist = 1<< 25;
                for(int k=0;k<poss.size();++k) {
                    pair<int, int> position = getPos(poss[k]);
                    curDist = min(curDist, abs(position.first - i) + abs(position.second - j));
                }
                totalDist += curDist * cpy[i][j];
            }
    return totalDist;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        memset(pop, 0, sizeof(pop));
        sol.clear();

        int N;
        cin >> N;
        while(N--) {
            int r, c, v;
            cin >> r >> c >> v;
            pop[r][c] = v;
        }

        minDist = 1<<25;
        for(int i=0;i<21;++i)
            for(int j=i+1;j<22;++j)
                for(int k=j+1;k<23;++k)
                    for(int m=k+1;m<24;++m)
                        for(int n=m+1;n<25;++n) {
                            initCpy();
                            vector<int> poss = newSol(i,j,k,m,n);
                            setOffices(poss);
                           
                            int curDist = solve(poss);
                            if(curDist < minDist)
                                sol = poss, minDist = curDist;
                        }
        bool first = true;
        for(int i=0;i<5;++i) {
            if(first)
                first = false;
            else
                cout << " ";
            cout << sol[i];
        }
        cout << "\n";
    }
    return 0;
}
