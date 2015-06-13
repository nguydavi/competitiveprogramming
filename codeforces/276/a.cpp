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
const int MAX = (int)8e6;
int A, M;

int main() {
    scanf("%d %d", &A, &M);
    ll sum = A;
    bool ans = false;
    for(int i=0;i<MAX;++i) {
        sum += sum%M;
        if(sum % M == 0) {
            ans = true;
            break;
        }
    }
    if(ans)
        printf("Yes\n");
    else
        printf("No\n");
        
    return 0;
}
