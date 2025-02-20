#include <stdio.h>

int main(int argc, char **argv) {
    int a;
    int sum = 0;
    int mult = 1;
    int temp;
    scanf("%d",&a);

    for (int i = 10; i <= a; i++) {
        temp = i;
        while (temp > 0)
        {
            sum += temp % 10;
            mult *= temp % 10;
            temp /= 10;
        }
        
        if (sum == mult) {
            printf("%d ",i);
        }
        sum = 0;
        mult = 1;
    }

    return 0;
}
