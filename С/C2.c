#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10005];
    fgets(s, sizeof(s), stdin);
    
    int stack[10005];
    int top = 0;
    
    for (int i = 0; s[i]; ) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            stack[top++] = num;
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '×') {
            int b = stack[--top];
            int a = stack[--top];
            
            if (s[i] == '+') stack[top++] = a + b;
            else if (s[i] == '-') stack[top++] = a - b;
            else if (s[i] == '*' || s[i] == '×') stack[top++] = a * b;
            else if (s[i] == '/') stack[top++] = a / b;
            
            i++;
        } else if (s[i] == '.') {
            break;
        } else {
            i++;
        }
    }
    
    printf("%d\n", stack[0]);
    return 0;
}