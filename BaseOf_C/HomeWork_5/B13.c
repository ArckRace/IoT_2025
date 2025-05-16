#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d",&a);

    int odd = 0;
    int even = 0;
    int check = 0;

    while (a > 0)
    {
       check = a % 10;

       ((check % 2) == 0) ? even++ : odd++;

       a /= 10;
    }

    printf("%d %d",even, odd);
    return 0;    
}
