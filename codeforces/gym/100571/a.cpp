#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = (int)1e5+10;
int N, Q;
int arr[MAXN];
ll psum[MAXN];

int main() {
    cin >> N >> Q;
    for(int i=0;i<N;++i)
        cin >> arr[i];
    
    psum[0] = arr[0];
    for(int i=1;i<N;++i)
        psum[i] = psum[i-1] + arr[i];
    
    while(Q--) {
        ll T;
        cin >> T;
        T %= psum[N-1];
        int ans = upper_bound(psum, psum+N, T)-psum + 1;
        cout << ans << "\n";
    }
    return 0;
}
