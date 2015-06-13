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

const int MAXN = 1010;
int N, M;
vector<string> arr;

bool eq[MAXN];

/**
 * eq array represents if current row is currently equal to the next row, if it
 * is not, the next characters can be in any order and it will still be in
 * lexicographic order. 
 * ex: 
 *      codes
 *      coeaa
 * the suffix "es" can come after "aa" because 'd' < 'e'.
 *
 * We go through every row for each column and if we find a character that comes
 * after the next row's character and eq[i] == true then we MUST remove that
 * column.
 * If we did NOT remove the column we check equality of the word and update eq.
 */
int solve() {
    for(int i=0;i<N;++i)
        eq[i] = true;

    int res = 0;
    for(int j=0;j<M;++j) {
        bool found = false;
        for(int i=0;i+1<N;++i)
            if(eq[i] && arr[i][j] > arr[i+1][j]) {
                ++res;
                found = true;
                break;
            }
        if(!found)
            for(int i=0;i+1<N;++i)
                if(eq[i] && arr[i][j] < arr[i+1][j])
                    eq[i] = false;
    }
    return res;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i) {
        string line;
        cin >> line;
        arr.push_back(line);
    }

    int ans = solve();
    printf("%d\n", ans);

    return 0;
}
