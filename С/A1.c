#include <stdio.h>

int main() {
    int n, x, max = -2147483648, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > max) {
            max = x;
            cnt = 1;
        } else if (x == max) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}