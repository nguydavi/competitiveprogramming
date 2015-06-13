#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf(" %d", &n);

    map<int, int> q;
    for(int i = 0; i < n; ++i) {
        int x, k;
        scanf(" %d %d", &x, &k);

        if(q.find(k) == q.end()) {
            if(x) {
                printf("NO\n");
                return 0;
            }
            q[k] = x;
        } else {
            if(x > q[k] + 1) {
                printf("NO\n");
                return 0;
            }
            q[k] = max(x, q[k]);
        }
    }

    printf("YES\n");

    return 0;
}
