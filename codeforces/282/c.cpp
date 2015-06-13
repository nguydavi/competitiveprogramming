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

int main() {
    string line;
    cin >> line;
    N = line.size();
    reverse(line.begin(), line.end());

    vector<int> stak;
    int countOpen = 0, countHash = 0;
    string norm("");
    for(int i=0;i<N;++i)
        if(line[i] == ')')
            stak.push_back(1);
        else if(line[i] == '(') {
            if(!stak.empty()) {
                stak.pop_back();
            } else {
                norm += line[i];
                ++countOpen;
            }
        } else {
            norm += line[i];
            ++countHash;
        }
    reverse(norm.begin(), norm.end());

    if(!stak.empty() || countOpen < countHash || norm[norm.size()-1] == '(')
        printf("-1\n");
    else {
        int counter = 0;
        vector<int> ans;
        for(int i=0;i<norm.size();++i) {
            if(norm[i] == '(')
                ++counter;
            else {
                if(counter) {
                    if(i != norm.size()-1) {
                        --counter;
                        ans.push_back(1);
                    } else {
                        for(int j=0;j<ans.size();++j)
                            printf("1\n");
                        printf("%d\n", counter);
                    }
                } else {
                    printf("-1\n");
                    break;
                }
            }
        }
    }
    return 0;
}
