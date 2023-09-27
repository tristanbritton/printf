#include "custom_printf.h"

/**
 * determine_argument_size - Determines the size to cast the argument
 * @format: Format string in which to identify the argument size
 * @index: Current index within the format string
 *
 * Return: Argument size identifier.
 */
int determine_argument_size(const char *format, int *index)
{
    int currentIndex = *index + 1;
    int argumentSize = 0;

    if (format[currentIndex] == 'l')
        argumentSize = ARG_SIZE_LONG;
    else if (format[currentIndex] == 'h')
        argumentSize = ARG_SIZE_SHORT;

    if (argumentSize == 0)
        *index = currentIndex - 1;
    else
        *index = currentIndex;

    return argumentSize;
}

