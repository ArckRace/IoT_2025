#include <stdio.h>
#include <inttypes.h>

uint32_t trans(uint32_t n, uint32_t P) {
    uint32_t output = 0, k = 1;

    while (n)
    {
        output += (n % P) * k;
        k *= 10;
        n /= P;
    }

    return output;
}

int main(int argc, char **argv) {
    uint32_t n, P;
    scanf("%" SCNu32 "%" SCNu32, &n, &P);
    printf("%" PRIu32 "\n", trans(n, P));
    return 0;
}
