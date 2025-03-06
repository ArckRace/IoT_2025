#include <stdio.h>

int posMax = 0;

int max(int *arr, int len) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (max < arr[i]) {
            max = arr[i];
            posMax = i;
        }
    }
    return max;
}

int main() {
    int a[10];
    int max1 = 0;
    int max2 = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d",&a[i]);
    }
    max1 = max(a,10);
    a[posMax] = -999;
    max2 = max(a,10);

    printf("%d\n",max1 + max2);
    return 0;
}