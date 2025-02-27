#include <stdio.h>

int sum_digits(int n) {
    if (n < 10) {
        return n;
    }
    int output = n % 10 + sum_digits(n / 10);
    return output;
}

int main(int argc, char **argv) {
    int x;
    scanf("%d", &x);
    printf("%d\n", sum_digits(x));
    return 0;
}
