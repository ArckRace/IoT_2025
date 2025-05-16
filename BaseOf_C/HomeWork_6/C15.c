#include <stdio.h>

int grow_up(int n) {
    int temp;
    int x = 1;
    while (n != 0) {
        temp = n % 10;
        n /= 10;
        if (temp <= (n%10)){
            x = 0;
            break;
        }
    }
    return x;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    (grow_up(n)) ? printf("YES") : printf("NO");
    return 0;
}
