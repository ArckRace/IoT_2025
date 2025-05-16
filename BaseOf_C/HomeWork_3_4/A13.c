#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);

    int n = 1;

    n *= a / 100;
    n *= (a / 10) % 10;
    n *= a % 10;

    printf("%d", n);
    return 0;
}
