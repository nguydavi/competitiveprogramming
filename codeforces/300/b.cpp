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

int n;

int main() {
    scanf("%d", &n);
    vector<int> ans;

    int pw10 = 1;
    while(n) {
        int t = n%10;
        for(int i=0;i<t;++i) {
            if(ans.size() <= i)
                ans.push_back(0);
            ans[i] += pw10;
        }

        n/=10;
        pw10 *= 10;
    }

    printf("%d\n", ans.size());
    for(int i=0;i<ans.size();++i) {
        if(i)
            printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
