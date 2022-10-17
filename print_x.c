
LiJoBaZar
/
holbertonschool-printf
Public
Code
Issues
Pull requests
Actions
Projects
Security
Insights
holbertonschool-printf/print_x.c
@davesantiarlom
davesantiarlom Create print_x.c
…
 1 contributor
39 lines (36 sloc)  766 Bytes
#include "main.h"
#include <stdlib.h>

/**
 * print_x - A function that prints an ascii char value in
 * lowercase hexadecimal
 * @x: char to print
 * Return: number of printed characters
 */
 
int print_x(va_list x)
{
    unsigned int a[8];
    unsigned int j = 1, m = 268435456, n, sum = 0;
    char diff;
    int counter = 0;

    n = va_arg(x, unsigned int);
    diff = 'a' - ':';
    a[0] = n / m;
    for (; j < 8; j++)
    {
        m /= 16;
        a[j] = (n / m) % 16;
    }
    for (j = 0; j < 8; j++)
    {
        sum += a[j];
        if (sum || j == 7)
        {
            if (a[j] < 10)
                _putchar('0' + a[j]);
            else
                _putchar('0' + diff + a[j]);
            counter++;
        }
    }
    return (counter);
}
