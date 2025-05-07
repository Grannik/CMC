#include <stdio.h>
#include <time.h>

// Функция определения времени года на английском
const char* get_season(int month) {
    if (month == 12 || month == 1 || month == 2)
        return "Winter";
    else if (month >= 3 && month <= 5)
        return "Spring";
    else if (month >= 6 && month <= 8)
        return "Summer";
    else
        return "Autumn";
}

// Функция названия месяца на английском
const char* get_month_name(int month) {
    const char* months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    if (month >= 1 && month <= 12)
        return months[month - 1];
    else
        return "Unknown";
}

// Функция названия дня недели на английском
const char* get_weekday_name(int weekday) {
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    if (weekday >= 0 && weekday <= 6)
        return days[weekday];
    else
        return "Unknown";
}

int main(int argc, char *argv[]) {
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

// gcc clock_sr.c -o clock_sr
