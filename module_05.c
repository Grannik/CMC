#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "pseudographic_font_5.h"

// Флаг для корректного завершения
static volatile sig_atomic_t keep_running = 1;

// Переменная для отслеживания обработчика SIGINT
static volatile int handler_set = 0;

// Обработчик сигнала SIGINT (Ctrl+C)
static void handle_sigint(int sig) {
    (void)sig;
    keep_running = 0;
    printf("\033[2J\033[H\033[?25h");
    fflush(stdout);
    _exit(0);
}

// Функция для вывода псевдографического времени
static void print_pseudographic_time(int hours, int mins, int secs) {
    if (hours < 0 || hours > 23 || mins < 0 || mins > 59 || secs < 0 || secs > 59) {
        printf("\033[H\033[1mInvalid time: %02d:%02d:%02d\033[0m\n", hours, mins, secs);
        fflush(stdout);
        return;
    }

    char time_str[9];
    snprintf(time_str, 9, "%02d:%02d:%02d", hours, mins, secs);

    const char** chars[8];
    for (int i = 0; i < 8; i++) {
        chars[i] = get_pseudographic_char_5(time_str[i]);
    }

    printf("\033[H");
    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < 8; i++) {
            if (i == 2 || i == 5) {
                printf("\033[1m\033[90m%s\033[0m", chars[i][row]);
            } else {
                printf("\033[1m\033[37m%s\033[0m", chars[i][row]);
            }
        }
        printf("\n");
    }
    fflush(stdout);
}

int module_05_run(const char *arg) {
    if (arg == NULL || strcmp(arg, "m5") != 0) {
        return 0;
    }

    if (!handler_set) {
        signal(SIGINT, handle_sigint);
        handler_set = 1;
    }

    printf("\033[?25l\n\n\n\n\n");
    fflush(stdout);

    while (keep_running) {
        time_t rawtime;
        struct tm *timeinfo;

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

        print_pseudographic_time(timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        sleep(1);
    }

    return 0;
}
