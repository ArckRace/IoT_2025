#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);

    int temp;
    int x = 1;
    while (a != 0) {
        temp = a % 10;
        a /= 10;
        if (temp <= (a%10)){
            x = 0;
            break;
        }
    }

    x ? printf("YES") : printf("NO");

    return 0;
}
