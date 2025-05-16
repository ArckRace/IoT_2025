#include <stdio.h>

void low2up(char c) {
    if (c >= 'a' && c <= 'z')  
        putchar('A' + (c - 'a'));
    else
        putchar(c);
}

int main()
{
    char c;
    while( (c=getchar())!='.')
        low2up(c);
    return 0;
}
