#include <stdio.h>

int main(int argc, char **argv) {
    int a,b;
    scanf("%d%d",&a,&b);

    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    printf("%d",a);

    return 0;
}
