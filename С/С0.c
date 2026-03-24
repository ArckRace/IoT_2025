#include <stdio.h>
#include <string.h>

int main() {
    char s[10005];
    scanf("%s", s);
    
    int n = strlen(s);
    int used[1000] = {0};
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if (!used[num]) {
                    used[num] = 1;
                    count++;
                }
            }
        }
    }
    
    printf("%d\n", count);
    return 0;
}