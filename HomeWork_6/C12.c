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

float sinus(float x) {
    x *= 0.01745;
    float sin2 = (power(x,3)/factorial(3));
    float sin3 = (power(x,5)/factorial(5));
    float sin4 = (power(x,7)/factorial(7));
    return (x - sin2 + sin3 - sin4);
}

int main(int argc, char **argv) {
    float x;
    scanf("%f", &x);
    printf("%.3f\n", sinus(x));
    return 0;
}
