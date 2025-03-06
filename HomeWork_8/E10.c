#include <stdio.h>

int main() {
    int arr[12];
    
    for (int i = 0; i < 12; i++) 
        scanf("%d", &arr[i]);
    
    int temp[4];
    for (int i = 0; i < 4; i++) 
        temp[i] = arr[8 + i]; 
    
    for (int i = 7; i >= 0; i--) 
        arr[i + 4] = arr[i];
    
    for (int i = 0; i < 4; i++) 
        arr[i] = temp[i];
    
    for (int i = 0; i < 12; i++) 
        printf("%d ", arr[i]);
    
    return 0;
}