#include <stdio.h>
#include <string.h>

void count_digits(const char *number) {
    int count[10] = {0};

    for (int i = 0; number[i] != '\0'; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            count[number[i] - '0']++; 
        }
    }

    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) {
            printf("%d %d\n", i, count[i]);
        }
    }
}

void sort_array(int size, int a[])
{
int temp = 0;
    for(int i = 0; i < size; ++i)
    {
        for(int j = i; j < size; ++j)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sort_even_odd(int n, int a[]) {
    int temp[n];
    int even_index = 0, odd_index = 0;


    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[even_index++] = a[i];
        }
    }


    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[even_index + odd_index++] = a[i];
        }
    }


    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}

void print_digit(char s[]) {
    int count[10] = {0}; 
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count[s[i] - '0']++; 
        }
    }

    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) {
            printf("%d %d\n", i, count[i]);
        }
    }
}

int find_max_array(int size, int a[]) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i]; 
        }
    }

    return max; 
}

int is_two_same(int size, int a[]) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 3};
    int size = sizeof(a) / sizeof(a[0]);

    int result = is_two_same(size, a);
    printf("%d\n", result);

    return 0;
}