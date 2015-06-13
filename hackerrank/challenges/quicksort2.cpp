#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int> > partition(const vector<int>& arr) {
    int pivot = arr[0];
    vector<int> bef, aft;
    
    for(int i=1;i<arr.size();++i)
        if(arr[i] < pivot)
            bef.push_back(arr[i]);
        else
            aft.push_back(arr[i]);
    
    vector<vector<int> > res(2);
    res[0] = bef;
    res[1] = aft;
    return res;
}

void quickSort(vector <int>&  arr) {
    if(arr.size() <= 1)
        return;
    
    int pivot = arr[0];
    vector<vector<int> > v = partition(arr);
    quickSort(v[0]);
    quickSort(v[1]);
    
    int index = 0;
    for(int i=0;i<v[0].size();++i)
        arr[index++] = v[0][i];
    arr[index++] = pivot;
    for(int i=0;i<v[1].size();++i)
        arr[index++] = v[1][i];
    
    for(int i=0;i<arr.size();++i) {
        if(i)
            cout << " ";
        cout << arr[i];
    }
    cout << "\n";
}

int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

    quickSort(_ar);
   
   return 0;
}
