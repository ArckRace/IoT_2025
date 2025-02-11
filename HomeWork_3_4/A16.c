#include <stdio.h>

int main(int argc, char **argv){
    int a,b,c;

    scanf("%d%d%d",&a,&b,&c);

    (a >= b) ? printf("NO")
            : (b >= c) ? printf("NO")
            : printf("YES");

    return 0;
}
