#include <stdio.h>

int main() {
    unsigned int n;
    int k;
    scanf("%u %d", &n, &k);
    
    // Циклический сдвиг вправо на k бит
    unsigned int result = (n >> k) | (n << (32 - k));
    
    printf("%u\n", result);
    return 0;
}