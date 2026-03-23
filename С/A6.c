#include <stdio.h>

int main() {
    unsigned int n;
    scanf("%u", &n);
    
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    
    printf("%d\n", count);
    return 0;
}