#include <stdio.h>

int is_prime(int n) {
    int check = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            check++;
        }
    }

    return (check == 2);
}

int main(int argc, char **argv) {
    int a;
    scanf("%d",&a);
    (is_prime(a)) ? printf("YES") : printf("NO");
    return 0;    
}
