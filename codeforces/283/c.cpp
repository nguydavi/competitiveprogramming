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
const int MAXM = 110;
int N, M;
vector<vector<char> > mat;
set<int> removedCol;

bool isGood(const vector<char>& a, const vector<char>& b) {
    for(int i=0;i<a.size();++i) {
        if(removedCol.find(i) == removedCol.end()) {
            if(a[i] < b[i])
                return true;
            if(a[i] > b[i])
                return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &M);
    string line;
    for(int i=0;i<N;++i) {
        cin >> line;
        mat.push_back(vector<char>(line.begin(), line.end()));
    }

    removedCol.clear();
    int curRow = 0;
    while(curRow < N-1) {
        int curCol = 0;
        while(curCol < M && !isGood(mat[curRow], mat[curRow+1])) {
            if(removedCol.find(curCol) == removedCol.end() && mat[curRow][curCol] > mat[curRow+1][curCol]) {
                removedCol.insert(curCol);
                curRow = -1;
                break;
            }
            ++curCol;
        }
        ++curRow;
    }
    printf("%d", removedCol.size());
    return 0;
}
