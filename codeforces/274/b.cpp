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

const int MAXN = 200;
int N, K;
int arr[MAXN];
vector<pair<int, int> > ops;

int instab() {
    int res = 0;
    int mmin = (int)1e9;
    int mmax = 0;
    for(int i=0;i<N;++i)
        mmax = max(mmax, arr[i]), mmin = min(mmin, arr[i]);
    return mmax-mmin;
}

int maxIndex() {
    int mmax = 0;
    int ans = -1;
    for(int i=0;i<N;++i)
        if(mmax < arr[i])
            mmax = arr[i], ans = i;
    return ans;
}

int minIndex() {
    int mmin = (int)1e9;
    int ans = -1;
    for(int i=0;i<N;++i)
        if(mmin > arr[i])
            mmin = arr[i], ans = i;
    return ans;
}

int solve() {
    int currentInstab = instab();
    if(currentInstab == 0)
        return 0;

    vector<pair<int, int> > curOps;
    for(int k=0;k<K;++k) {
        int maxI = maxIndex();
        int minI = minIndex();
        if(maxI != minI) {
            --arr[maxI];
            ++arr[minI];
            curOps.push_back(make_pair(maxI, minI));

            int newInstab = instab();
            if(newInstab < currentInstab) {
                currentInstab = newInstab;
                ops = curOps;
            }
        }
    }
    return currentInstab;
}

int main() {
    cin >> N >> K;
    for(int i=0;i<N;++i)
        cin >> arr[i];
    ops.clear();

    cout << solve() << " "; 
    cout << ops.size() << "\n";
    for(int i=0;i<ops.size();++i)
        cout << ops[i].first+1 << " " << ops[i].second+1 << "\n";
    return 0;
}
