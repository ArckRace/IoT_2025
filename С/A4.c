#include <stdio.h>

int main() {
    unsigned int n;
    int k;
    scanf("%u %d", &n, &k);
    
    unsigned int result = n & ((1u << k) - 1);
    
    printf("%u\n", result);
    return 0;
}