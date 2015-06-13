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
int N, X, Y;

int main() {
    scanf("%d %d %d", &N, &X, &Y);

    ll cntx, cnty;
    cntx = cnty = 0;
    vector<int> vv; //0=both, 1=Vanya, 2=Vova
    while(cntx < X || cnty < Y) {
        if((cntx+1)*Y < (cnty+1)*X) {
            ++cntx;
            vv.push_back(1);
        } else if((cntx+1)*Y > (cnty+1)*X) {
            ++cnty;
            vv.push_back(2);
        } else {
            ++cntx, ++cnty;
            vv.push_back(0);
            vv.push_back(0);
        }
    }

    while(N--) {
        int a;
        scanf("%d", &a);
        int ans = vv[(a-1)%(X+Y)];
        if(ans == 1)
            printf("Vanya\n");
        else if(ans == 2)
            printf("Vova\n");
        else
            printf("Both\n");
    }
    return 0;
}
