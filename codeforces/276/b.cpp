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

typedef long long ll;
const int MAXN = 1010;
const int INF = (int)1e9+7;
int N;
pair<int, int> arr[MAXN];

int main() {
    scanf("%d", &N);    
    int minX = INF;
    int minY = INF;
    int maxX = -INF;
    int maxY = -INF;
    for(int i=0;i<N;++i) {
        scanf("%d %d", &(arr[i].first), &(arr[i].second));
        minX = min(minX, arr[i].first);
        minY = min(minY, arr[i].second);
        maxX = max(maxX, arr[i].first);
        maxY = max(maxY, arr[i].second);
    }

    ll distX = 0LL + maxX - minX;
    ll distY = 0LL + maxY - minY;
    ll dist = max(distX, distY);
    cout << dist*dist << "\n";

    return 0;
}
