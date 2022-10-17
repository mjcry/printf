#include "main.h"

/**
 * p_char - prints character c
 * @arg: character to print
 * Return: number of characters printed
 */
int p_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);

	_putchar(c);

	return (1);
}

/**
 * p_str - prints string s
 * @arg: string to print
 * Return: number of characters printed
 */

int p_str(va_list arg)
{
	unsigned int i;
	char *s;

	s = va_arg(arg, char *);

	i = 0;

	if (s == NULL)
		s = "null";

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);

}

/**
 * p_dec - prints decimal
 * @arg: argument to print
 * Return: number of characters printed
 */

int p_dec(va_list arg)
{
	int n = va_arg(arg, int);
	int num;
	int last = n % 10;
	int dig;
	int exp = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num < 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig + '0');
			num = num - (dig * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last = '0');

	return (i);
}

/**
 * p_int - orints integer
 * @arg: argument to print
 * Return: number of characters printed
 */
int p_int(va_list arg)
{
	int n = va_arg(arg, int);
	int num;
	int last = n % 10;
	int dig;
	int exp = 1;
	int i =1;

	n = n / 10;
	num =n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig + '0');
			num = num - (dig * exp);
			exp = exp / 10;
			i++;
		}
		
	}
	_putchar(last + '0');

	return (i);
}
