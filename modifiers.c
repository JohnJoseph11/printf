#include "main.h"

unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);

/**
 * print_width - It Stores leading spaces to a buffer for a width modifi                 er.
 * @output: A buffer_t struct that contains a character array.
 * @printed: The current number of characters which is already printed
 *           to the outputfor a given number specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: Numbers of bytes stored to the buffer.
 */
unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_string_width - Storing leading spaces to a buffer for a width 
 *                      modifier.
 * @output: A buffer_t struct having a character array.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @size: Size of the string.
 *
 * Return: Numbers of bytes that is stored to the buffer.
 */
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_neg_width - Storing trailing spaces to a buffer for a '-' flag.
 * @output: A buffer_t struct which contains a character array.
 * @printed: The current number of bytes that is stored to output
 *           for a given specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: Number of bytes stored to the buffer.
 */
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}
