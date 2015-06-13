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

string mat[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

char findKey(int shift, char c) {
    for(int i=0;i<3;++i) {
        string keys = mat[i];
        int id;
        if((id=keys.find(c)) != keys.npos)
            if(shift == -1)
                return keys[max(0, id-1)];
            else
                return keys[min((int)keys.size()-1, id+1)];
    }
}

string solveRight(const string& line) {
    string ans;
    for(int i=0;i<line.size();++i) {
        ans += findKey(-1, line[i]); 
    }
    return ans;
}

string solveLeft(const string& line) {
    string ans;
    for(int i=0;i<line.size();++i) {
        ans += findKey(1, line[i]); 
    }
    return ans;
}


int main() {
    char lr;
    string line;
    cin >> lr >> line;

    if(lr == 'L')
        cout << solveLeft(line);
    else 
        cout << solveRight(line);
    cout << endl;
    return 0;
}
