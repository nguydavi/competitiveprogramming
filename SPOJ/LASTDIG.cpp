#include <cstdio>

using namespace std;

int solve(int a, int b) {
    int res = 1;
    int base = a;

    while(b) {
        if(b%2 == 1) {
            res *= base;
            res %= 10;
        }
        base *= base;
        base %= 10;
        b /= 2;
    }
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", solve(a, b));
    }
    return 0;
}
