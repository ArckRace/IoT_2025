#include <stdio.h>

int main() {
    int a[12];
    float mean = 0;

    for (int i = 0; i < 12; i++) {
        scanf("%d",&a[i]);
        mean += a[i];
    }
    mean /= 12;

    printf("%.2f", mean);
    return 0;
}