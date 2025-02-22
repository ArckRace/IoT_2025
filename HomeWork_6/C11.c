#include <stdio.h>

int nod(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main(int argc, char **argv) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", nod(a, b));
    return 0;
}
