#include <stdio.h>

void dec2bin(int n) {
    if (n > 1) {
        dec2bin(n / 2);
    }
    printf("%d", n % 2);
}

int main(int argc, char **argv) {
    int x;
    scanf("%d", &x);
    dec2bin(x);
    return 0;
}
