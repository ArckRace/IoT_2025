#include <stdio.h>

int is_prime(int n, int delitel) {
    if (n == 1) {
        return 0;
    }
    if (delitel > n/2) {
        return 1;
    }
    if (n % delitel == 0) {
        return 0;
    }
    return is_prime(n, delitel + 1);
}

int main(int argc, char **argv) {
    int a;
    scanf("%d",&a);
    (is_prime(a, 2)) ? printf("YES") : printf("NO");
    return 0;    
}
