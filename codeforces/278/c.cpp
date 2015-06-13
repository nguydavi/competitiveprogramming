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

const int MAXATK = 210;
const int MAXDEF = 110;
const int MAXHP = 1000;
const int INF = (int)1e9;
int HPY, ATKY, DEFY;
int HPM, ATKM, DEFM;
int H, A, D;

bool doesWin(int hh, int aa, int dd) {
    int m = ATKY+aa-DEFM <= 0 ? INF : (int)ceil(1.*HPM/(ATKY+aa-DEFM));
    int y = ATKM-DEFY-dd <= 0 ? INF : (int)ceil(1.*(HPY+hh)/(ATKM-DEFY-dd));
    return m < y;
}

int main() {
    scanf("%d %d %d", &HPY, &ATKY, &DEFY);
    scanf("%d %d %d", &HPM, &ATKM, &DEFM);
    scanf("%d %d %d", &H, &A, &D);

    int ans = INF;
    for(int i=0;i<MAXHP;++i)
        for(int j=0;j<MAXATK;++j)
            for(int k=0;k<MAXDEF;++k)
                if(i*H+j*A+k*D < ans && doesWin(i, j, k))
                    ans = i*H+j*A+k*D;

    printf("%d\n", ans);
    return 0;
}
