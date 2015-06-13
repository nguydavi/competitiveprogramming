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

#define MAXX 100

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int A, B, C;
        cin >> A >> B >> C;

        int x,y,z;
        bool found = false;
        for(x=-MAXX;x<=MAXX && !found;++x)
            for(y=x+1;y<=MAXX && !found;++y) {
                z = A - x - y;
                if(x!=y && y!=z && x!=z && x*y*z == B && x*x+y*y+z*z == C)
                    cout << x << " " << y << " " << z << "\n", found = true;
            }
        if(!found)
            cout << "No solution.\n";
    } 

    return 0;
}
