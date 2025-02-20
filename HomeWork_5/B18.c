#include <stdio.h>

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);

    int fib1 = 0;
    int fib2 = 1;

    printf("%d ", fib2);
    int answer = 0;

    for (int i = 2; i <= n; i++) {
        answer = fib2 + fib1;
        printf("%d ",answer);
        fib1 = fib2;
        fib2 = answer;
    }
    printf("\n");

    return 0;
}