#include <stdio.h>

int main(int argc, char **argv){
    int a,b,c;

    scanf("%d%d%d",&a,&b,&c);

    float x;
    x = (a + b + c) / 3.;

    printf("%.2f\n",x);

    return 0;
}