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
    getline(cin, line);
    stringstream ss(line);

    int count1 = 0;
    int count2 = 0;
    int sol1 = 0;
    int sol2 = 0;
    char c;
    while(ss >> c) {
        int num = c - '0';
        if(num == 1) {
            sol1 += count2;
            ++count1;
        } else {
            sol2 += count1;
            ++count2;
        }
    }
    cout << min(sol1, sol2) << "\n";
    return 0;
}
