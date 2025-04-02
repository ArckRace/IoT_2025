#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdio.h>
#include <stdint.h>


/*
Вывод среднемесяченой температуры
*/
void month_average_temp();

/*
Вывод минимальной температуры в месяце
*/
void month_min_temp();

/*
Вывод максимальной температуры в месяце
*/
void month_max_temp();

/*
Вывод среднегодовой температуры
*/
void year_average_temp();

/* 
Вывод минимальной температуры в году
*/
void year_min_temp();

/*
Вывод максимальной температуры в году
*/
void year_max_temp();


/*
Структура для хранения данных о температуре
*/
struct data_temp {
    uint16_t year;      // Год
    uint8_t month;      // Месяц
    uint8_t day;        // День
    uint8_t hour;       // Час
    uint8_t minute;     // Минуты
    int8_t temperature; // Температура, градусы Цельсия
};

#endif /*TEMP_FUNCTIONS_H*/