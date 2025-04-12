#include "temp_functions.h"


float month_average_temp(struct data_temp* data, int count, int month) {
    float sum = 0;
    int avg = 0;
    for (int i = 0; i < count; i++) {
        if (data[i].month == month) {
           sum += data[i].temperature;
           avg++;
        }
    }
    return (avg == 0) ? 0 : sum / avg;
}

int month_min_temp(struct data_temp* data, int count, int month) {
    int min = TEMP_MAX;
    for (int i = 0; i < count; i++) {
        if (data[i].month == month && data[i].temperature < min) {
            min = data[i].temperature;
        }
    }
    return (min == TEMP_MAX) ? 0 : min;
}

int month_max_temp(struct data_temp* data, int count, int month) {
    int max = TEMP_MIN;
    for (int i = 0; i < count; i++) {
        if (data[i].month == month && data[i].temperature > max) {
            max = data[i].temperature;
        }
    }
    return (max == TEMP_MIN) ? 0 : max;
}

float year_average_temp(struct data_temp* data, int count) {
    float sum = 0;
    int avg = 0;
    for (int i = 1; i <= MAX_MONTH; i++) {
        sum += month_average_temp(data, count, i);
        avg++;
    }
    return (avg == 0) ? 0 : sum / avg;
}

int year_min_temp(struct data_temp* data, int count) {
    int min = TEMP_MAX;
    for (int i = 1; i <= MAX_MONTH; i++) {
        int temp = month_min_temp(data, count, i);
        if (temp < min) {
            min = temp;
        }
    }
    return (min == TEMP_MAX) ? 0 : min;
}

int year_max_temp(struct data_temp* data, int count) {
    int max = TEMP_MIN;
    for (int i = 1; i <= MAX_MONTH; i++) {
        int temp = month_max_temp(data, count, i);
        if (temp > max) {
            max = temp;
        }
    }
    return (max == TEMP_MIN) ? 0 : max;
}