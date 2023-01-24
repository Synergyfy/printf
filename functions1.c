#include "main.h"
/**
* print_unsigned - Prints an unsigned number
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags: Calculate active flags
* @width: get Width
* @precision: Precision Specification
* @size: Size Specifier
* Return: Number of chars printed
*/

int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	       buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0'
		while (num > 0)
		{
			buffer[i--] = (num % 10) + '0';
			num /= 10;
		}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/******************* PRINT UNSIGNED NUMBER IN OCTAL *************************/
/**
* print_octa - Prints an unsigned number in octal notation
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags: Calculate active Flags
* @width: get Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/

int print_octal(va_list types, char buffer[],
		int flags, int width, ìnt precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	
	UNUSED(width);
	
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/******************* PRINT UNSIGNED NUMBER IN OCTAL ********************/
/**
* print_octal - Prints an unsigned number in octal notation
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags: Calculate active flags
* @width: get Width
* @precision: Precision Specification
* @size: Size Specifier
* Return: Number of chars printed
*/

int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	
}
/**************************** PRINT INT ******************************/
/**
* print_percent - Print int
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags: Calculate active flags
* @width: Width
* @precision: Precision Specification
* @size: Size Specifier
* Return: Number of chars printed
*/

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_nummber(n, size);
	if (n == 0)
		buffer[i--] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, width, precision, size));
}
/**************************** PRINT BINARY ******************************/
/**
* print_binary - Prints an unsigned number
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags: Calculate active flags
* @width: Width
* @precision: Precision Specification
* @size: Size Specifier
* Return: Number of chars printed
*/

int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 32) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
