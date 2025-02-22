#include <stdio.h>

void check_sum_even(int n) {
    int check = 0;

    while (n > 0)
    {
       check += n % 10;
       n /= 10;
    }
    (check % 2 == 0) ? printf("YES") : printf("NO");
}

int main(int argc, char **argv) {
    int n;
    scanf("%d",&n);
    check_sum_even(n);
    return 0;    
}
