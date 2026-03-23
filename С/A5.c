#include <stdio.h>

int main() {
    unsigned n; int k;
    scanf("%u%d", &n, &k);
    unsigned m = 0;
    for (int i = 0; i <= 32 - k; ++i) {
        unsigned t = (n >> i) & ((1u << k) - 1);
        if (t > m) m = t;
    }
    printf("%u\n", m);
    return 0;
}