#include <stdio.h>

int is_happy_number(int n) {
    int sum = 0;
    int mult = 1;

    while (n > 0) {
        sum += n % 10;
        mult *= n % 10;
        n /= 10;
    }

    return (sum == mult);
}

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);
    (is_happy_number(a)) ? printf("YES") : printf("NO");
    return 0;
}
