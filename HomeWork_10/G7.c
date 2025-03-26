#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");


    int lowercase = 0, uppercase = 0;
    char c;

    while ((c = fgetc(input)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            lowercase++;
        } else if (c >= 'A' && c <= 'Z') {
            uppercase++;
        }
    }

    fprintf(output, "%d %d", lowercase, uppercase);

    fclose(input);
    fclose(output);
    return 0;
}
