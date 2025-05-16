#include <stdio.h>

int main(int argc, char **argv) {
    int a,b;

    scanf("%d%d", &a,&b);

    if (a > b) {
        printf("Above");
    }

    if (a == b) {
        printf("Equal");
    }

    if (a < b) {
        printf("Less");
    }


    return 0;
}
