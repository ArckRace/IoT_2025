#include <stdio.h>

int abs(int a) {
    return (a < 0) ? -a : a;
}

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);
    printf("%d", abs(a));
    return 0;
}
