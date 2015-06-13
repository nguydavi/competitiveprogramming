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

#define MAXX 10010
int prices[MAXX];
int N;
int goal, book1, book2;

int search(int x) {
    int left = 0, right = N-1;
    while(left <= right) {
        int mid = (left+right)/2;
        if(prices[mid] < x)
            left = mid +1;
        else if(prices[mid] > x)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main() {
    while(cin >> N) {
        for(int i=0;i<N;++i)
            cin >> prices[i];
        sort(prices,prices+N);
        cin >> goal;

        int minDiff = 1<<25;
        for(int i=0;i<N;++i) {
            if(abs(2*prices[i] - goal) < minDiff && search(goal-prices[i]) != -1) {
                minDiff = abs(2*prices[i] - goal);
                book1 = min(prices[i], goal-prices[i]);
                book2 = max(prices[i], goal-prices[i]);
            }
        }
        cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << ".\n\n";
    }
    
    return 0;
}
