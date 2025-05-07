#include <stdio.h>
#include <string.h>

int module_00_run(const char *arg) {
    if (arg == NULL || strcmp(arg, "mh") != 0) {
        return 0;
    }

    const char *white = "\033[1;37m";
    const char *gray = "\033[90m";
    const char *reset = "\033[0m";

    printf("Available arguments:\n");
    printf("    %smh%s: %sDisplay this help message.%s\n", white, reset, gray, reset);
    printf("    %sms%s: %sPrint the current date and time in a static format.%s\n", white, reset, gray, reset);
    printf("    %smu%s: %sRun a dynamic clock that updates every second.%s\n", white, reset, gray, reset);
    printf("    %sm3%s: %sRun a pseudographic clock (3x3 font) that updates every second.%s\n", white, reset, gray, reset);
    printf("    %sm5%s: %sRun a pseudographic clock (5x5 font) that updates every second.%s\n", white, reset, gray, reset);
    printf("    %sm7%s: %sRun a pseudographic clock (8x8 font) that updates every second.%s\n", white, reset, gray, reset);

// Финальный сброс форматирования
    printf("\033[0m\n");

    return 0;
}
