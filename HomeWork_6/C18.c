#include <stdio.h>

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int main(int argc, char **argv) {
    char c;
    int count = 0;
    while ((c = getchar()) != '.')
        count += is_digit(c);
    printf("%d\n", count);
    return 0;
}
