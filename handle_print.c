#include "custom_printf.h"

/**
 * print_argument - Prints an argument based on its type
 * @format: Format string in which to print the arguments
 * @index: Current index within the format string
 * @args: List of arguments to be printed
 * @output_buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_argument(const char *format, int *index, va_list args,
                   char output_buffer[], int flags, int width, int precision, int size)
{
    int unknownLength = 0;
    int printedChars = -1;

    FormatSpecifier formatSpecifiers[] = {
        {'c', print_character},
        {'s', print_string},
        {'%', print_percent},
        {'i', print_integer},
        {'d', print_integer},
        {'b', print_binary},
        {'u', print_unsigned_number},
        {'o', print_octal_number},
        {'x', print_hexadecimal_number},
        {'X', print_hexadecimal_upper},
        {'p', print_pointer},
        {'S', print_non_printable},
        {'r', print_reverse},
        {'R', print_rot13_string},
        {'\0', NULL}
    };

    for (int i = 0; formatSpecifiers[i].format != '\0'; i++)
    {
        if (format[*index] == formatSpecifiers[i].format)
        {
            return formatSpecifiers[i].function(args, output_buffer, flags, width, precision, size);
        }
    }

    if (formatSpecifiers[0].format == '\0')
    {
        if (format[*index] == '\0')
        {
            return (-1);
        }

        unknownLength += write(1, "%%", 1);

        if (format[*index - 1] == ' ')
        {
            unknownLength += write(1, " ", 1);
        }
        else if (width)
        {
            (*index)--;

            while (format[*index] != ' ' && format[*index] != '%')
            {
                (*index)--;
            }

            if (format[*index] == ' ')
            {
                (*index)--;
            }

            return (1);
        }

        unknownLength += write(1, &format[*index], 1);
        return unknownLength;
    }

    return printedChars;
}

