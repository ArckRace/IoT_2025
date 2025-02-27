#include <stdio.h>

int sum(int n){
    if (n == 1) {
        return 1;
    }
    int output = n + sum(n - 1);
    return output;
}

int main(int argc, char **argv) {
    int x;
    scanf("%d", &x);
    printf("%d",sum(x));
    return 0;
}
