#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d",&a);

    int check = 0;

    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            check++;
        }
    }

    (check == 2) ? printf("YES") : printf("NO");
    return 0;    
}
