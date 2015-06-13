#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf(" %d %d", &n, &k);

    bool matches[1000][1000] = {false};
    bool poss = true;
    if(n > 1) {
        for(int i = 0; i < n; ++i) {
            for(int m = 1; m <= k; ++m) {
                if(!matches[i][(i+m)%n]) {
                    matches[i][(i+m)%n] = true;
                    matches[(i+m)%n][i] = true;
                } else {
                    poss = false;
                    break;
                }
            }
        }
    } else {
        poss = false;
    }

    if(!poss) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", k*n);
        for(int i = 0; i < n; ++i) {
            for(int m = 1; m <= k; ++m) {
                printf("%d %d\n", i + 1, ((i+m) %n) + 1);
            }
        }
    }

    return 0;
}
