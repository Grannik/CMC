#ifndef PSEUDOGRAPHIC_FONT_3_H
#define PSEUDOGRAPHIC_FONT_3_H

// Псевдографический шрифт для цифр 0-9 и разделителя (:).
// Каждый символ представлен 3 строками по 3 символа (UTF-8).
// Используемые символы: ┌ ─ ┐ └ ┘ ┤ и пробел.

// Определение псевдографического шрифта (3x3 символа)
static const char* font_3[11][3] = {
    // 0
    {
        "┌─┐",
        "│ │",
        "└─┘"
    },
    // 1
    {
        " ┌┐",
        "  │",
        "  ┘"
    },
    // 2
    {
        "┌─┐",
        "┌─┘",
        "└─┘"
    },
    // 3
    {
        "┌─┐",
        " ─┤",
        "└─┘"
    },
    // 4
    {
        "┌ ┐",
        "└─┤",
        "  ┘"
    },
    // 5
    {
        "┌─┐",
        "└─┐",
        "└─┘"
    },
    // 6
    {
        "┌─┐",
        "├─┐",
        "└─┘"
    },
    // 7
    {
        "┌─┐",
        "  ┤",
        "  ┘"
    },
    // 8
    {
        "┌─┐",
        "├─┤",
        "└─┘"
    },
    // 9
    {
        "┌─┐",
        "└─┤",
        "└─┘"
    },
    // : (разделитель)
    {
        " ┌┐ ",
        " ├┤ ",
        " └┘ "
    }
};

// Пустой символ для некорректных входных данных
static const char* empty_char[3] = {
    "   ",
    "   ",
    "   "
};

// Функция для получения псевдографического символа по значению
const char** get_pseudographic_char_3(char c) {
    if (c >= '0' && c <= '9') {
        return font_3[c - '0'];
    } else if (c == ':') {
        return font_3[10];
    }
    return empty_char;
}

#endif
