#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);

    int check;
    int x = 1;
    while (a != 0) {
        check = a % 10;
        a /= 10;
        if ((check % 2) != 0){
            x = 0;
            break;
        }
    }

    x ? printf("YES") : printf("NO");

    return 0;
}
