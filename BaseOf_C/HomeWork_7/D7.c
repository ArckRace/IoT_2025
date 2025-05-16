#include <stdio.h>

void recursion(int n) {
    if (n > 0) {
        printf("%d ", n);
        recursion(n - 1);
    }
}


int main(int argc, char **argv) {
    int n;
    scanf("%d",&n);
    recursion(n);
    return 0;
}
