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

#define MAXS 50
int R,F;
int ff[MAXS], rr[MAXS];
vector<double> dratios;

int main() {
    while(cin >> F && F) {
        cin >> R;
        dratios.clear();

        for(int i=0;i<F;++i)
            cin >> ff[i];
        for(int i=0;i<R;++i)
            cin >> rr[i];

        for(int i=0;i<F;++i)
            for(int j=0;j<R;++j)
                dratios.push_back((double)rr[j]/ff[i]);
        sort(dratios.begin(), dratios.end());

        double maxSpread = 0;
        for(int i=1;i<dratios.size();++i)
            maxSpread = max(maxSpread, ((double)dratios[i])/dratios[i-1]);
        printf("%.2lf\n", maxSpread);

    }
    return 0;
}
