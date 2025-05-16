#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt", "w");

    char buffer[1001];
    int len = 0;
    char c;

    while ((c = fgetc(input)) != EOF && c != '\n') {
        buffer[len++] = (char)c;
    }
    buffer[len] = '\0';

    char last_c = buffer[len - 1];

    int first = 1;
    for (int i = 0; i < len - 1; i++) {
        if (buffer[i] == last_c) {
            if (!first) {
                fprintf(output, " ");
            }
            fprintf(output, "%d", i);
            first = 0;
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
