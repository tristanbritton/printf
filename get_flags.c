#include "custom_printf.h"

/**
 * calculate_flags - Calculates active formatting flags
 * @format: Format string in which to identify flags
 * @index: Current index within the format string
 * Return: Flags:
 */
int calculate_flags(const char *format, int *index)
{
    int flagIndex, currentIndex;
    int flags = 0;
    const char VALID_FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    for (currentIndex = *index + 1; format[currentIndex] != '\0'; currentIndex++)
    {
        for (flagIndex = 0; VALID_FLAGS[flagIndex] != '\0'; flagIndex++)
        {
            if (format[currentIndex] == VALID_FLAGS[flagIndex])
            {
                flags |= FLAG_VALUES[flagIndex];
                break;
            }
        }

        if (VALID_FLAGS[flagIndex] == '\0')
            break;
    }

    *index = currentIndex - 1;

    return flags;
}

