#include <stdio.h>

int main(int argc, char **argv) {
    int a, b;
    scanf("%d%d", &a, &b);

    if (a > b) {
        // printf("a must be lower than b\n");
    } else {
        for (; a <= b; a++) {
            printf("%d ", a*a);
        }
        printf("\n");
    }
    return 0;
}
