#include <stdio.h>

void remove_extra_spaces(const char* input, char* output) {
    int i = 0, j = 0;
    int space_flag = 0;
    
    while (input[i] == ' ') {
        i++;
    }
    
    while (input[i] != '\0') {
        if (input[i] != ' ') {
            output[j++] = input[i++];
            space_flag = 0;
        } else {
            if (!space_flag) {
                output[j++] = ' ';
                space_flag = 1;
            }
            i++;
        }
    }
    
    if (j > 0 && output[j-1] == ' ') {
        j--;
    }
    
    output[j] = '\0';
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (input == NULL || output == NULL) {
        return 1;
    }

    char str[1001];
    char result[1001];
    int i = 0;
    int ch;
    
    while ((ch = fgetc(input)) != EOF && ch != '\n' && i < 1000) {
        str[i++] = ch;
    }
    str[i] = '\0';

    remove_extra_spaces(str, result);
    
    fprintf(output, "%s", result);

    fclose(input);
    fclose(output);
    return 0;
}