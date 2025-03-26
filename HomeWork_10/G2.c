#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");;

    int n;
    char c = 'A';
    char buffer;
    int even = 2;

    fscanf(input, "%d", &n);
    fclose(input);

    for (int i = 0; i < n; i++){
        if (i % 2 == 0) {
            buffer = c++;
            putc(buffer,output);
        } else {
            buffer = even + '0';
            even += 2;
            putc(buffer,output);

            if (even > 8) {
                even = 2;
            }
        }
    }

    fclose(output);

    return 0;
}
