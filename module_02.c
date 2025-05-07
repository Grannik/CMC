#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>   // для sleep() и usleep()
#include <signal.h>   // для обработки сигналов
#include "common.h"

// Переменная для отслеживания, был ли установлен обработчик SIGINT
static volatile int handler_set = 0;

// Обработчик сигнала SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    (void)sig; // Подавляем предупреждение о неиспользуемом параметре
    // Показываем курсор обратно и делаем перенос строки
    printf("\033[?25h\n");
    fflush(stdout);
    // Выход из программы
    _exit(0);
}

int module_02_run(const char *arg) {
    // Проверяем, соответствует ли аргумент ключу модуля
    if (arg == NULL || strcmp(arg, "mu") != 0) {
        return 0; // Аргумент не соответствует, ничего не делаем
    }

    // Устанавливаем обработчик сигнала SIGINT только один раз
    if (!handler_set) {
        signal(SIGINT, handle_sigint);
        handler_set = 1;
    }

    // Скрываем курсор
    printf("\033[?25l");
    fflush(stdout);

    // Основной цикл
    while (1) {
        time_t rawtime;
        struct tm *timeinfo;

        // Получаем текущее время
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        const char* season = get_season(timeinfo->tm_mon + 1);
        const char* month_name = get_month_name(timeinfo->tm_mon + 1);
        const char* weekday_name = get_weekday_name(timeinfo->tm_wday);

        // Возвращаем курсор в начало строки
        printf("\r    %d\033[90m/\033[0m%s\033[90m/\033[0m%s \033[90;1m|\033[0m %d\033[90m/\033[0m%s \033[90;1m|\033[0m %02d\033[90m:\033[0m%02d\033[90m:\033[0m%02d",
               timeinfo->tm_year + 1900,
               season,
               month_name,
               timeinfo->tm_mday,
               weekday_name,
               timeinfo->tm_hour,
               timeinfo->tm_min,
               timeinfo->tm_sec);

        fflush(stdout);

        sleep(1); // Спим одну секунду
    }

    return 0;
}
