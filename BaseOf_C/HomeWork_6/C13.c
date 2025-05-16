#include <stdio.h>

float power(float n, float P) {

    float power = 1;
    for (int i = 0; i <= P - 1; i++) {
        power *= n;
    }
    return power;
}

float factorial(float n){
    if (n == 0 || n == 1) {
        return 1;
    }
    float output = n * factorial(n - 1);
    return output;
}

float cosinus(float x) {
    x *= 0.01745;
    float cos2 = (power(x,2)/factorial(2));
    float cos3 = (power(x,4)/factorial(4));
    float cos4 = (power(x,6)/factorial(6));
    return (1 - cos2 + cos3 - cos4);
}

int main(int argc, char **argv) {
    float x;
    scanf("%f", &x);
    printf("%.3f\n", cosinus(x));
    return 0;
}
