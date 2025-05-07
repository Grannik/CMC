#include <stdio.h>
#include <string.h>

// Объявляем функции модулей как слабые (weak), чтобы отсутствующие модули не ломали компиляцию
#define DECLARE_MODULE_RUN(num) extern int module_##num##_run(const char *arg) __attribute__((weak))

DECLARE_MODULE_RUN(00);
DECLARE_MODULE_RUN(01);
DECLARE_MODULE_RUN(02);
DECLARE_MODULE_RUN(03);
DECLARE_MODULE_RUN(04);
DECLARE_MODULE_RUN(05);
DECLARE_MODULE_RUN(06);
DECLARE_MODULE_RUN(07);
DECLARE_MODULE_RUN(08);
DECLARE_MODULE_RUN(09);
DECLARE_MODULE_RUN(10);
DECLARE_MODULE_RUN(11);
DECLARE_MODULE_RUN(12);
DECLARE_MODULE_RUN(13);
DECLARE_MODULE_RUN(14);
DECLARE_MODULE_RUN(15);
DECLARE_MODULE_RUN(16);
DECLARE_MODULE_RUN(17);
DECLARE_MODULE_RUN(18);
DECLARE_MODULE_RUN(19);
DECLARE_MODULE_RUN(20);
DECLARE_MODULE_RUN(21);
DECLARE_MODULE_RUN(22);
DECLARE_MODULE_RUN(23);
DECLARE_MODULE_RUN(24);
DECLARE_MODULE_RUN(25);
DECLARE_MODULE_RUN(26);
DECLARE_MODULE_RUN(27);
DECLARE_MODULE_RUN(28);
DECLARE_MODULE_RUN(29);
DECLARE_MODULE_RUN(30);
DECLARE_MODULE_RUN(31);
DECLARE_MODULE_RUN(32);
DECLARE_MODULE_RUN(33);
DECLARE_MODULE_RUN(34);
DECLARE_MODULE_RUN(35);

int main(int argc, char *argv[]) {
    // Массив указателей на функции модулей
    int (*module_runs[36])(const char *) = {
        module_00_run, module_01_run, module_02_run, module_03_run,
        module_04_run, module_05_run, module_06_run, module_07_run,
        module_08_run, module_09_run, module_10_run, module_11_run,
        module_12_run, module_13_run, module_14_run, module_15_run,
        module_16_run, module_17_run, module_18_run, module_19_run,
        module_20_run, module_21_run, module_22_run, module_23_run,
        module_24_run, module_25_run, module_26_run, module_27_run,
        module_28_run, module_29_run, module_30_run, module_31_run,
        module_32_run, module_33_run, module_34_run, module_35_run
    };

    // Если аргументов нет, сообщаем об этом и выходим
    if (argc < 2) {
        printf("\033[1;31m No arguments provided. Run './connection_module mh' to see the help message.\033[0m\n");
        return 1;
    }

    // Проходим по всем аргументам командной строки (начиная с argv[1])
    for (int arg_idx = 1; arg_idx < argc; arg_idx++) {
        const char *arg = argv[arg_idx];

        // Передаем аргумент всем модулям
        for (int i = 0; i < 36; i++) {
            if (module_runs[i] != NULL) {
                int result = module_runs[i](arg);
                if (result != 0) {
                    fprintf(stderr, "\033[1;31mModule module_%02d failed with error: %d\033[0m\n", i, result);
                }
            }
        }
    }

    return 0;
}

// gcc -o connection_module argument_module.c module_*.c
