#include "custom_printf.h"

/**
 * calculate_print_width - Calculates the width for printing
 * @format: Format string in which to identify the print width
 * @index: Current index within the format string
 * @args: List of arguments
 *
 * Return: Width.
 */
int calculate_print_width(const char *format, int *index, va_list args)
{
    int currentIndex;
    int width = 0;

    for (currentIndex = *index + 1; format[currentIndex] != '\0'; currentIndex++)
    {
        if (is_digit(format[currentIndex]))
        {
            width *= 10;
            width += format[currentIndex] - '0';
        }
        else if (format[currentIndex] == '*')
        {
            currentIndex++;
            width = va_arg(args, int);
            break;
        }
        else
        {
            break;
        }
    }

    *index = currentIndex - 1;

    return width;
}

