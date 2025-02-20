#include <stdio.h>

int main(int argc, char **argv) {
    int a = 0;
    int b = 0;
    scanf("%d",&a);

    while (a > 0) {
        b = b * 10 + a % 10;
        a /= 10;
    }
    printf("%d",b);
    return 0;
}