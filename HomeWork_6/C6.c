#include <stdio.h>
#include <inttypes.h>

uint64_t geom(int n, int q, int b1) {

    uint64_t power = 1;
    for (int i = 0; i <= n - 2; i++) {
        power *= q;
    }
    return b1 * power;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d",&n);
    printf("%" PRIu64 "\n" ,geom(n, 2, 1));
    return 0;
}
