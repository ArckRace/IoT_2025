#include <stdio.h>

int posMin = 0;
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

int min(int *arr, int len) {
    int min = arr[0];
    for (int i = 1; i < len; i++) {
        if (min > arr[i]) {
            min = arr[i];
            posMin = i;
        }
    }
    return min;
}

int main() {
    int a[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d",&a[i]);
    }

    printf("%d %d %d %d\n",posMax+1,max(a,10),posMin+1,min(a,10));
    return 0;
}