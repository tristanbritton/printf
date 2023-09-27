#include "main.h"

/**
 * is_printable - Checks if a character is printable
 * @c: Character to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise.
 */
int is_printable(char c)
{
    return (c >= 32 && c < 127);
}

/**
 * append_hexa_code - Appends ASCII in hexadecimal code to a buffer
 * @buffer: Array of characters.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII code.
 *
 * Return: Always 3.
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
    const char hexDigits[] = "0123456789ABCDEF";

    if (ascii_code < 0)
        ascii_code *= -1;

    buffer[i++] = '\\';
    buffer[i++] = 'x';

    buffer[i++] = hexDigits[ascii_code / 16];
    buffer[i] = hexDigits[ascii_code % 16];

    return 3;
}

/**
 * is_digit - Checks if a character is a digit
 * @c: Character to be evaluated.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num.
 */
long int convert_size_number(long int num, int size)
{
    if (size == S_LONG)
        return num;
    else if (size == S_SHORT)
        return (short)num;

    return (int)num;
}

/**
 * convert_size_unsgnd - Casts an unsigned number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num.
 */
unsigned long int convert_size_unsgnd(unsigned long int num, int size)
{
    if (size == S_LONG)
        return num;
    else if (size == S_SHORT)
        return (unsigned short)num;

    return (unsigned int)num;
}
