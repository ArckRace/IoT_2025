#include <stdio.h>

int function(int a) {
    if (a >= -2 && a < 2) {
        return a * a;
    }
    if (a >= 2) {
        return a * a + 4 * a + 5;
    }
    if (a < -2) {
        return 4;
    }
}

int main(int argc, char **argv) {
    int a = 0;
    int answer = 0;
    int temp = 0;
    do {
        temp = answer;
        scanf("%d", &a);
        answer = function(a);

        answer = (answer > temp) ? answer : temp;
    } while (a != 0);
    printf("%d",answer);
    return 0;
}