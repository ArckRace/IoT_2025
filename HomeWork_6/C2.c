#include <stdio.h>

int power(int n, int P) {

    int power = 1;
    for (int i = 0; i <= P - 1; i++) {
        power *= n;
    }
    return power;
}

int main(int argc, char **argv) {
    int n, P;
    scanf("%d%d", &n, &P);
    printf("%d\n", power(n,P));
    return 0;
}
