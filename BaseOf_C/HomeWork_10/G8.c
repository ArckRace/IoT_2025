#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");


    char str[1001];
    int numbers[500];
    int num_count = 0;
    int current_num = 0;
    int in_number = 0;

    fgets(str, sizeof(str), input);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            current_num = current_num * 10 + (str[i] - '0');
            in_number = 1;
        } else {
            if (in_number) {
                numbers[num_count++] = current_num;
                current_num = 0;
                in_number = 0;
            }
        }
    }
    if (in_number) {
        numbers[num_count++] = current_num;
    }

    qsort(numbers, num_count, sizeof(int), compare);

    for (int i = 0; i < num_count; i++) {
        if (i > 0) fprintf(output, " ");
        fprintf(output, "%d", numbers[i]);
    }

    fclose(input);
    fclose(output);
    return 0;
}