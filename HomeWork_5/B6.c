#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);

    int first, second, x;
    while (a != 0) {
        first = a%10;
        a /= 10;
        second = a%10;
        if (first == second) {
            x = 1;
            break;
        } else {
            x = 0;
        }
    }

    x ? printf("YES") : printf("NO");

    return 0;
}
