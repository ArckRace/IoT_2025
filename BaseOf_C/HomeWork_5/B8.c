#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);

    int check;
    int i = 0;
    while (a != 0) {
        check = a % 10;
        a /= 10;
        if (check == 9){
            i++;
        }
    }

    (i == 1) ? printf("YES") : printf("NO");

    return 0;
}
