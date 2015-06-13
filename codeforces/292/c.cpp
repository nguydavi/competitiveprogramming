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

string arr[] = {"", "", "2", "3", "322", "5", "53", "7", "7222", "7332"};

int main() {
    int N;
    string s;
    cin >> N >> s;

    string res = "";
    for(char c : s)
        if(c > '1')
            res += arr[c-'0'];

    sort(res.begin(), res.end(), greater<char>());
    cout << res << "\n";
    return 0;
}
