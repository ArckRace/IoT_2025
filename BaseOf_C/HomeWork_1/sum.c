#include <stdio.h>

int main(int argc, char **argv) {

    int x;
    int y;
    int z;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    printf("%d+%d+%d=%d\n",x,y,z,(x+y+z));

    return 0;
}