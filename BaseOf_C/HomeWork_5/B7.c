#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);

    int first, second, temp;
    int x = 0;
    while (a != 0) {
        first = a % 10;
        a /= 10;
        temp = a;
        while (temp != 0) {
            second = temp % 10;
            temp /= 10;
            if (first == second) {
                x = 1;
                goto skip;
            } else {
                x = 0;
            }
        }
    }
skip:
    x ? printf("YES") : printf("NO");

    return 0;
}
