#include "common.h"

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
