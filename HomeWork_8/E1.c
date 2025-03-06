#include <stdio.h>

int main() {
    int a[5];
    float mean = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d",&a[i]);
        mean += a[i];
    }
    mean /= 5;

    printf("%.3f", mean);
    return 0;
}