#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d",&a);

    int check = 0;

    while (a > 0)
    {
       check += a % 10;
       a /= 10;
    }

    (check == 10) ? printf("YES") : printf("NO");
    return 0;    
}
