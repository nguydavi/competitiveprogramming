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

const int MAXN = 2e5+10;
int N;
int arr[MAXN];
vector<int> shake[MAXN];

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i) {
        scanf("%d", &arr[i]);
        shake[arr[i]].push_back(i);
    }

    int cur = 0, left = N;
    vector<int> ans;
    while(!shake[cur].empty()) {
        ans.push_back(shake[cur].back()+1);
        shake[cur].pop_back();
        ++cur;
        --left;

        int i=0;
        while(cur-3*i >=0) {
            if(!shake[cur-3*i].empty()) {
                cur -= 3*i;
                break;
            }
            ++i;
        }
    }

    if(left == 0) {
        printf("Possible\n");
        for(int i=0;i<ans.size();++i) {
            if(i)
                printf(" ");
            printf("%d", ans[i]);
        }
    } else
        printf("Impossible\n");
    return 0;
}
