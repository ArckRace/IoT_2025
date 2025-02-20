#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);

    int i = 0;
    while (a != 0) {
        a /= 10;
        i++;
    }

    (i == 3) ? printf("YES") : printf("NO");

    return 0;
}
