#include <getopt.h>
#include <stdlib.h>

#include "temp_functions.h"

#define SIZE 30000000

void print_help(char* argv[]) {
    printf("Usage: %s [OPTION]... [FILE]...\n", argv[0]);
    printf("The program of temperature output for a month or a year\n");
    printf("\n");
    printf("Mandatory arguments.\n");
    printf("-h This help text\n");
    printf("-f [FILENAME]\t\tspecifying the file to process\n");
    printf("-m [MONTH NUMBER]\tspecifying the month to get statistics for a specific month\n");
    printf("\n");
    printf("Example:\n");
    printf("%s file_name.csv -m 3\tPrint the temperature for the 3rd month from the file\n",
           argv[0]);
}

int compare_date(const void* a, const void* b) {
    struct data_temp* date1 = (struct data_temp*)a;
    struct data_temp* date2 = (struct data_temp*)b;

    if (date1->year != date2->year) {
        return date1->year - date2->year;
    }
    if (date1->month != date2->month) {
        return date1->month - date2->month;
    }
    if (date1->day != date2->day) {
        return date1->day - date2->day;
    }
    if (date1->hour != date2->hour) {
        return date1->hour - date2->hour;
    }
    return date1->minute - date2->minute;
}

void sort_data(struct data_temp* data, int count) {
    qsort(data, count, sizeof(struct data_temp), compare_date);
}

int read_data_from_file(const char* filename, struct data_temp* data) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    int r = 0;
    while ( (r = fscanf(file, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd", &data[count].year, &data[count].month,
                  &data[count].day, &data[count].hour, &data[count].minute,
                  &data[count].temperature)) > 0) {
                    if (r < 6) {
                        char s[20], c;
                        r = fscanf(file,"%[^\n]%c", s, &c);
                        printf("Wrong format in line %d: %s\n", count + 1, s);
                        continue;
                    }
        count++;
        if (count >= SIZE) {
            break;
        }
    }

    fclose(file);
    return count;
}

void print_general_information(struct data_temp* data, int count) {
    printf("Year\tMonth\tAverage Temp\tMin Temp\tMax Temp\n");
    for (int i = 1; i <= MAX_MONTH; i++) {
        float avg_temp = month_average_temp(data, count, i);
        int min_temp = month_min_temp(data, count, i);
        int max_temp = month_max_temp(data, count, i);
        printf("%4d %6d %12.2f %12d %15d\n", data[i].year, i, avg_temp, min_temp, max_temp);
    }
    printf("Year statistic: average is %.2f, max is %d, min is %d\n",year_average_temp(data, count),
           year_max_temp(data, count), year_min_temp(data, count));
    printf("\n");
}

int main(int argc, char* argv[]) {
    int status = 0;
    int show_help = 0;
    int has_options = 0;
    char* filename = NULL;
    int month = -1;

    struct data_temp* data = malloc(SIZE * sizeof(struct data_temp));

    while ((status = getopt(argc, argv, "hf:m:")) != -1) {
        has_options = 1;
        switch (status) {
            case 'h':
                show_help = 1;
                break;
            case 'f':
                filename = optarg;
                break;
            case 'm':
                month = atoi(optarg);
                if (month < MIN_MONTH || month > MAX_MONTH) {
                    printf("Invalid month number: %d. Month must be between %d and %d.\n", month, MIN_MONTH, MAX_MONTH);
                    return 1;
                }
                break;
            case '?':
                printf("Try '%s -h' for more information\n", argv[0]);
                return 1;
        }
    }

    if (show_help) {
        print_help(argv);
    }

    if (!has_options) {
        printf("The program of temperature output for a month or a year\n");
        printf("Try '%s -h' for more information\n", argv[0]);
        return 1;
    }

    if (filename != NULL) {
        int count = read_data_from_file(filename, data);
        sort_data(data, count);
        printf("Read %d records from file %s\n", count, filename);

        if (month == -1) {
            print_general_information(data, count);
        } else {
            printf("Year\tMonth\tAverage Temp\tMin Temp\tMax Temp\n");
            float avg_temp = month_average_temp(data, count, month);
            int min_temp = month_min_temp(data, count, month);
            int max_temp = month_max_temp(data, count, month);
            printf("%4d %6d %12.2f %12d %15d\n", data[month].year, month, avg_temp, min_temp, max_temp);
            printf("\n");
        }
    }

    free(data);
    return 0;
}
