#include <stdio.h>

int main() {
    unsigned int n;
    scanf("%u", &n);

    // Инвертируем только старший байт (биты 31–24)
    unsigned int result = n ^ 0xFF000000u;

    printf("%u\n", result);
    return 0;
}