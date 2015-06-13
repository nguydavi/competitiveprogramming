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

#define MAXX 10000
pair<int, int> arr[MAXX];
int sumLis[MAXX], sumLds[MAXX];
int N;

pair<int, int> lisAndLds() {
    int resLis = 0, resLds = 0;
    for(int i=0;i<N;++i) {
        sumLis[i] = arr[i].second;
        sumLds[i] = arr[i].second;

        for(int j=0;j<i;++j)
            if(arr[i].first > arr[j].first)
                sumLis[i] = max(sumLis[i], sumLis[j] + arr[i].second);
            else if(arr[i].first < arr[j].first)
                sumLds[i] = max(sumLds[i], sumLds[j] + arr[i].second);

        resLis = max(resLis, sumLis[i]);
        resLds = max(resLds, sumLds[i]);
    }
    return make_pair(resLis, resLds);
}

int main() {
    int tc;
    cin >> tc;
    for(int ii=1;ii<=tc;++ii) {
        cin >> N;
        for(int i=0;i<N;++i) {
            int tmp;
            cin >> tmp;
            arr[i] = make_pair(tmp, -1);
        }
        for(int i=0;i<N;++i)
            cin >> arr[i].second;

        pair<int, int> ans = lisAndLds();
        int ansLis = ans.first;
        int ansLds = ans.second;

        cout << "Case " << ii << ". ";
        if(ansLis >= ansLds)
            cout << "Increasing (" << ansLis << "). Decreasing (" << ansLds << ").\n";
        else
            cout << "Decreasing (" << ansLds << "). Increasing (" << ansLis << ").\n";
    }
    return 0;
}
