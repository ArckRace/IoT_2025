#include <stdio.h>

int main() {
    FILE *f;
    f = fopen("input.txt","r");

    char c;
    char buffer[256];
    int i = 0;

    while ((c = fgetc(f)) != EOF && c != '\n')
    {
        buffer[i++] = c;
    }
    buffer[i] = '\0';

    fclose(f);
    
    f = fopen("output.txt","w");

    fprintf(f,"%s, %s, %s %d",buffer,buffer,buffer,i);
    
    fclose(f);
    return 0;
}