#include "custom_printf.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned_number - Prints an unsigned number
 * @args: List of arguments
 * @output_buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int print_unsigned_number(va_list args, char output_buffer[],
    int flags, int width, int precision, int size)
{
    int i = OUTPUT_BUFFER_SIZE - 2;
    unsigned long int num = va_arg(args, unsigned long int);

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        output_buffer[i--] = '0';

    output_buffer[OUTPUT_BUFFER_SIZE - 1] = '\0';

    while (num > 0)
    {
        output_buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return (write_unsgnd(0, i, output_buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal_number - Prints an unsigned number in octal notation
 * @args: List of arguments
 * @output_buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_octal_number(va_list args, char output_buffer[],
    int flags, int width, int precision, int size)
{
    int i = OUTPUT_BUFFER_SIZE - 2;
    unsigned long int num = va_arg(args, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        output_buffer[i--] = '0';

    output_buffer[OUTPUT_BUFFER_SIZE - 1] = '\0';

    while (num > 0)
    {
        output_buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & F_HASH && init_num != 0)
        output_buffer[i--] = '0';

    i++;

    return (write_unsgnd(0, i, output_buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal_number - Prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @output_buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal_number(va_list args, char output_buffer[],
    int flags, int width, int precision, int size)
{
    return (print_hexa_number(args, "0123456789abcdef", output_buffer,
        flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexadecimal_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @output_buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal_upper(va_list args, char output_buffer[],
    int flags, int width, int precision, int size)
{
    return (print_hexa_number(args, "0123456789ABCDEF", output_buffer,
        flags, 'X', width, precision, size));
}

/************** PRINT HEXADECIMAL NUMBER IN LOWER OR UPPER **************/
/**
 * print_hexa_number - Prints a hexadecimal number in lower or upper case
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @output_buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_number(va_list args, char map_to[], char output_buffer[],
    int flags, char flag_ch, int width, int precision, int size)
{
    int i = OUTPUT_BUFFER_SIZE - 2;
    unsigned long int num = va_arg(args, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        output_buffer[i--] = '0';

    output_buffer[OUTPUT_BUFFER_SIZE - 1] = '\0';

    while (num > 0)
    {
        output_buffer[i--] = map_to[num % 16];
        num /= 16;
    }

    if (flags & F_HASH && init_num != 0)
    {
        output_buffer[i--] = flag_ch;
        output_buffer[i--] = '0';
    }

    i++;

    return (write_unsgnd(0, i, output_buffer, flags, width, precision, size));
}

