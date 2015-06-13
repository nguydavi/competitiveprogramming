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

#define MAXX 1000000000
#define MAXITER 1000
int P, Q, R, S, T, U;

double compute(double x) {
    double res = P*exp(-x) + Q*sin(x) + R*cos(x) + S*tan(x) + T*x*x + U;
    return res;
}

int main() {
    while(cin >> P >> Q >> R >> S >> T >> U) {
        int left = 0, right = MAXX, iter = 0;
        bool found = false;
        while(left < right && iter++ < MAXITER) {
            int mid = (left+right)/2;
            double res = compute(mid/(double)MAXX);

            if(fabs(res) < 1e-6) {
                printf("%.4lf\n", mid/(double)MAXX); 
                found = true;
                break;
            }

            if(compute(left/(double)MAXX) * res > 0)
                left = mid;
            else
                right = mid;
        }

        if(!found)
            printf("No solution\n");
    }

    return 0;
}
