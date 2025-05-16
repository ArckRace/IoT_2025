#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    int max = 0;

    scanf("%d", &a);

    int n = 0;

    n = a / 100;
    if (n > max) {
        max = n;
    }

    n = (a / 10) % 10;
    if (n > max) {
        max = n;
    }

    n = a % 10;
    if (n > max) {
        max = n;
    }

    printf("%d", max);
    return 0;
}
