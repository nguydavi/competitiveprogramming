#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int c,d;
    scanf(" %d %d", &c, &d);

    int n, m;
    scanf(" %d %d", &n, &m);

    int k;
    scanf(" %d", &k);

    double r = m * n - k;
    int minProb = 0;
    if(r > 0) {
        minProb = r * d;
        for(int i = 1; i <= ceil(r/n)  ; ++i) {
            int q = (int) r - (i * n);
            if(q < 0) q = 0; 

            int p = i * c + q * d;
            if(p < minProb) minProb = p;
        }
    }
    printf("%d\n", minProb);

    return 0;
}
