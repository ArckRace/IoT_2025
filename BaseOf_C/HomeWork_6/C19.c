#include <stdio.h>

int digit_to_num(char c) {
    int num = 0;
    if ((c >= '0' && c <= '9')) {
        num = c - '0';
    }
    return num;
}

int main(int argc, char **argv) {
    char c;
    int count = 0;
    while ((c = getchar()) != '.') 
        count += digit_to_num(c);
    printf("%d\n", count);
    return 0;
}
