#include <stdio.h>

int main(int argc, char **argv) {
    int a, b;
    scanf("%d%d", &a, &b);

    if (a > b) {
        // printf("a must be lower than b\n");
    } else {
        int sum = 0;
        for (; a <= b; a++) {
            sum += a * a;
        }
        printf("%d\n", sum);
    }
    return 0;
}
