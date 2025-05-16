#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (input == NULL || output == NULL) {
        return 1;
    }

    char word1[101], word2[101];
    fscanf(input, "%100s %100s", word1, word2);

    for (char c = 'a'; c <= 'z'; c++) {
        int count1 = 0, count2 = 0;
        
        for (int i = 0; word1[i] != '\0'; i++) {
            if (word1[i] == c) count1++;
        }
        
        for (int i = 0; word2[i] != '\0'; i++) {
            if (word2[i] == c) count2++;
        }
        
        if (count1 == 1 && count2 == 1) {
            fprintf(output, "%c ", c);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
