#include <stdio.h>

void recursion(int n) {
    if (n > 1) {
        recursion(n - 1);
    }
    printf("%d ", n);
}


int main(int argc, char **argv) {
    int n;
    scanf("%d",&n);
    recursion(n);
    return 0;
}
