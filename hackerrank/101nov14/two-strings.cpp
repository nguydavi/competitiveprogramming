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
    int tc;
    scanf("%d", &tc);
    cin.ignore();
    while(tc--) {
        string word;
        cin >> word;
        
        set<char> ss;
        for(int i=0;i<word.size();++i)
            ss.insert(word[i]);
        cin >> word;
        bool ans = false;
        for(int i=0;i<word.size();++i)
            if(ss.find(word[i]) != ss.end())
                ans = true;
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }
    return 0;
}
