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

int N;
string s;

int main() {
    cin >> N;
    cin >> s;

    for(int i=0;i<N;++i) {
        for(int j=1;i+j<N;++j) {
            int cur = i;
            int cnt = 0;

            while(cur+cnt*j < N) {
                if(s[cur+cnt*j] == '*') 
                    ++cnt;
                else
                    break;

                if(cnt == 5) {
                    cout << "yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "no\n";

    return 0;
}
