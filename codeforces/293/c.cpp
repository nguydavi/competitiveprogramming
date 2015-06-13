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

const int MAXN = 1e5+10;
int N, M, K;
int arr[MAXN];
map<int, int> appToPlace;

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0;i<N;++i) {
        scanf("%d", &arr[i]);
        appToPlace[arr[i]] = i;
    }

    int ans = 0;
    while(M--) {
        int a;
        scanf("%d", &a);

        ans += appToPlace[a]/K + 1;
        if(appToPlace[a] > 0) {
            int curPlace = appToPlace[a];

            int tmp = arr[curPlace];
            arr[curPlace] = arr[curPlace-1];
            arr[curPlace-1] = tmp;

            appToPlace[arr[curPlace]] = curPlace;
            appToPlace[arr[curPlace-1]] = curPlace-1;
        }
        /*
        cout << "DEBUG " << ans << endl;
        for(int i=0;i<N;++i)
            cout << arr[i] << " ";
        cout << endl << endl;
        for(auto kv : appToPlace) {
            cout << kv.first << " " << kv.second << endl;
        }
        */
    }
    printf("%d\n", ans);
    return 0;
}
