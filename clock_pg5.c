#include <stdio.h>
#include <time.h>
#include <unistd.h>   // для sleep()
#include <signal.h>   // для обработки сигналов
#include <stdlib.h>   // для exit()
#include "pseudographic_font_5.h"

// Флаг для корректного завершения
volatile sig_atomic_t keep_running = 1;

// Обработчик сигнала SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    keep_running = 0; // Устанавливаем флаг для выхода из цикла
}

// Функция для вывода псевдографического времени
void print_pseudographic_time(int hours, int mins, int secs) {
    // Проверяем валидность времени
    if (hours < 0 || hours > 23 || mins < 0 || mins > 59 || secs < 0 || secs > 59) {
        printf("\033[H"); // Возврат в начало
        printf("\033[1mInvalid time: %02d:%02d:%02d\033[0m\n", hours, mins, secs);
        fflush(stdout);
        return;
    }

    // Преобразуем время в строку формата "ЧЧ:ММ:СС"
    char time_str[9];
    snprintf(time_str, 9, "%02d:%02d:%02d", hours, mins, secs);

    // Получаем псевдографические символы для каждой цифры и разделителя
    const char** chars[8];
    for (int i = 0; i < 8; i++) {
        chars[i] = get_pseudographic_char_5(time_str[i]);
    }

    // Перемещаем курсор в верхний левый угол (без очистки экрана)
    printf("\033[H");

    // Выводим пять строк псевдографики
    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < 8; i++) {
            if (i == 2 || i == 5) {
                // Жирный серый для разделителя (:)
                printf("\033[1m\033[90m%s\033[0m", chars[i][row]);
            } else {
                // Жирный белый для цифр
                printf("\033[1m\033[37m%s\033[0m", chars[i][row]);
            }
        }
        printf("\n");
    }
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    // Устанавливаем обработчик сигнала SIGINT
    signal(SIGINT, handle_sigint);

    // Скрываем курсор
    printf("\033[?25l");
    fflush(stdout);

    // Выводим пять пустых строк для резервирования места
    printf("\n\n\n\n\n");

    while (keep_running) {
        time_t rawtime;
        struct tm *timeinfo;

        // Получаем текущее время
        if (time(&rawtime) == (time_t)-1) {
            printf("\033[H\033[1mFailed to get time\033[0m\n");
            fflush(stdout);
            sleep(1);
            continue;
        }
        timeinfo = localtime(&rawtime);
        if (timeinfo == NULL) {
            printf("\033[H\033[1mFailed to parse time\033[0m\n");
            fflush(stdout);
            sleep(1);
            continue;
        }

        // Выводим псевдографическое время
        print_pseudographic_time(timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

        sleep(1); // Спим одну секунду
    }

    // Показываем курсор и очищаем экран перед выходом
    printf("\033[2J\033[H\033[?25h");
    fflush(stdout);
    return 0;
}

// gcc clock_pg5.c -o clock_pg5
