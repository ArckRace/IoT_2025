#include <stdio.h>

void print_num(int n) {
    if (n < 10) {
        printf("%d ", n);
    } else {
        print_num(n / 10);
        printf("%d ", n % 10);
    }
}

int main(int argc, char **argv) {
    int x;
    scanf("%d", &x);
    print_num(x);
    return 0;
}
