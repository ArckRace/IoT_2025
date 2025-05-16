#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdint.h>
#include <stdio.h>

#define TEMP_MAX 99
#define TEMP_MIN -99

#define MAX_MONTH 12
#define MIN_MONTH 1

/*
Структура для хранения данных о температуре
*/
struct data_temp {
    uint16_t year;       // Год
    uint8_t month;       // Месяц
    uint8_t day;         // День
    uint8_t hour;        // Час
    uint8_t minute;      // Минуты
    int8_t temperature;  // Температура, градусы Цельсия
};

/*
Вывод среднемесяченой температуры
*/
float month_average_temp(struct data_temp* data, int count, int month);

/*
Вывод минимальной температуры в месяце
*/
int month_min_temp(struct data_temp* data, int count, int month);

/*
Вывод максимальной температуры в месяце
*/
int month_max_temp(struct data_temp* data, int count, int month);

/*
Вывод среднегодовой температуры
*/
float year_average_temp(struct data_temp* data, int count);

/*
Вывод минимальной температуры в году
*/
int year_min_temp(struct data_temp* data, int count);

/*
Вывод максимальной температуры в году
*/
int year_max_temp(struct data_temp* data, int count);



#endif /*TEMP_FUNCTIONS_H*/