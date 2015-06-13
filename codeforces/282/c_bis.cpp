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

int main() {
    string line;
    cin >> line;
    int total = 0;
    int countHash = 0;
    int hashPos = -1;
    for(int i=0;i<line.size();++i) {
        if(line[i] == '(')
            ++total;
        else if(line[i] == ')')
            --total;
        else {
            ++countHash;
            --total;
            hashPos = i;
        }

        if(total < 0) {
            printf("-1\n");
            return 0;
        }
    }
    if(total < 0) {
        printf("-1\n");
        return 0;
    }

    int last = total+1;
    int total2 = 0;
    for(int i=0;i<line.size();++i) {
        if(i == hashPos)
            total2 -= last;
        else if(line[i] == '(')
            ++total2;
        else
            --total2;

        if(total2 < 0) {
            printf("-1\n");
            return 0;
        }
    }

    total += countHash;
    for(int i=0;i<countHash-1;++i)
        printf("1\n");
    printf("%d\n", total-countHash+1);

    return 0;
}
