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

const int MAXN = 5010;
int N;
deque<int> ones, twos, threes;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;++i) {
        int skill;
        scanf("%d", &skill);
        if(skill == 1)
            ones.push_back(i);
        else if(skill == 2)
            twos.push_back(i);
        else
            threes.push_back(i);
    }

    int len = min(ones.size(), min(twos.size(), threes.size()));
    printf("%d\n", len);
    for(int i=0;i<len;++i) {
        printf("%d %d %d\n", ones.front(), twos.front(), threes.front());
        ones.pop_front();
        twos.pop_front();
        threes.pop_front();
    }

    return 0;
}
