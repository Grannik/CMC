#include <stdio.h>
#include <time.h>
#include <string.h>
#include "common.h"

int module_01_run(const char *arg) {
    // Проверяем, соответствует ли аргумент ключу модуля
    if (arg == NULL || strcmp(arg, "ms") != 0) {
        return 0; // Аргумент не соответствует, ничего не делаем
    }

    // Логика модуля
    time_t rawtime;
    struct tm * timeinfo;

    // Получаем текущее время
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    const char* season = get_season(timeinfo->tm_mon + 1);
    const char* month_name = get_month_name(timeinfo->tm_mon + 1);
    const char* weekday_name = get_weekday_name(timeinfo->tm_wday);

    // Вывод в одну строку с отступом слева (4 пробела)
    printf("    %d/%s/%s | %d/%s | %02d:%02d:%02d\n",
           timeinfo->tm_year + 1900,
           season,
           month_name,
           timeinfo->tm_mday,
           weekday_name,
           timeinfo->tm_hour,
           timeinfo->tm_min,
           timeinfo->tm_sec);

    return 0;
}
