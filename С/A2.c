#include <stdio.h>

int main() {
    int n;
    scanf("%d ", &n);   // читаем число и пробел после него

    int c;
    while ((c = getchar()) != '.') {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + n) % 26;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + n) % 26;
        }
        // пробел и другие символы остаются без изменений
        putchar(c);
    }

    putchar('.');       // выводим завершающую точку
    putchar('\n');

    return 0;
}