#include "main.h"

/**
  * get_func - pointer to array
  * @conv_spec: specifiers
  * Return: function that is pointed to
  */

int (*get_func(char conv_spec))(va_list)
{
	int j;

	printer_t funct[] = {
		{"i", print_nums},
		{"c", conv_c},
		{"s", conv_s},
		{"d", print_nums},
		{NULL, NULL}
	};
	for (j = 0; funct[j].spec[0] != conv_spec; j++)
	{
		if (funct[j].spec == NULL)
			return (NULL);
	}
	return (funct[j].func);
}
/**
 * _printf - print strings and chars to stdout
 * @format: specifier to print
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0;
	int counter = 0;
	va_list arg;
	int (*point)(va_list);

	va_start(arg, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		for (i = i; format[i] != '%'; i++)
		{
			if (format[i] == '\0')
				return (counter);
			_putchar(format[i]);
			counter++;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%'), counter++, i += 2;
		continue;
		}
		if (format[i] == '%')
		{
			i = i + 1;
			point = get_func(format[i]);
			if (point == NULL)
			{
				_putchar('%');
				_putchar(format[i]);
			}
			else
				counter += point(arg);
			i = i + 1;
		}
	}
	return (counter);
}
