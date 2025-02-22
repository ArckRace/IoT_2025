#include <stdio.h>

void print_simple(int n){

    int i = 2;
    while (i <= n) {
        if (n % i == 0) {
            n /= i;
            printf("%d ",i);
        } else {
            i++;
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    print_simple(n);
    return 0;
}