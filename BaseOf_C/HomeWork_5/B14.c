#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    scanf("%d", &a);
    int count = 0;
    while (a != 0) {
        count++;
        scanf("%d", &a);
    }
    printf("%d\n", count);
    return 0;
}
