#include "lexer.h"

/**
 * is_valid_three_char_operator - Checks for 3-character operators
 * @buffer: Source buffer containing the code
 * @start: Starting position to check
 * @lexeme: Buffer to store the matched operator
 *
 * Description: Checks for compound assignment operators like >>= and <<=.
 *
 * Return: 1 if match found, 0 otherwise
 */
int is_valid_three_char_operator(char *buffer, int start, char *lexeme)
{
	size_t i;
	size_t count;
	char *three_char_operators[] = {">>=", "<<="};

	count = sizeof(three_char_operators) / sizeof(three_char_operators[0]);
	for (i = 0; i < count; i++)
	{
		if (strncmp(three_char_operators[i], buffer + start, 3) == 0)
		{
			strcpy(lexeme, three_char_operators[i]);
			return (1);
		}
	}
	return (0);
}

/**
 * is_valid_two_char_operator - Checks for 2-character operators
 * @buffer: Source buffer containing the code
 * @start: Starting position to check
 * @lexeme: Buffer to store the matched operator
 *
 * Description: Checks for operators like +=, ==, &&, ||, ->, etc.
 *
 * Return: 1 if match found, 0 otherwise
 */
int is_valid_two_char_operator(char *buffer, int start, char *lexeme)
{
	size_t i;
	size_t count;
	char *two_char_operators[] = {"+=", "*=", "-=", "/=", "%%=",
				      "&=", "|=", "^=", ">=", "<=",
				      "!=", "==", "++", "--", "&&",
				      "||", ">>", "<<", "->"};

	count = sizeof(two_char_operators) / sizeof(two_char_operators[0]);
	for (i = 0; i < count; i++)
	{
		if (strncmp(two_char_operators[i], buffer + start, 2) == 0)
		{
			strcpy(lexeme, two_char_operators[i]);
			return (1);
		}
	}
	return (0);
}

/**
 * is_valid_one_char_operator - Checks for single-character operators
 * @buffer: Source buffer containing the code
 * @start: Starting position to check
 * @lexeme: Buffer to store the matched operator
 *
 * Description: Checks for operators like +, -, *, /, =, &, |, etc.
 *
 * Return: 1 if match found, 0 otherwise
 */
int is_valid_one_char_operator(char *buffer, int start, char *lexeme)
{
	size_t i;
	size_t count;
	char *one_char_operators[] = {"+", "-", "*", "/", "%%", "=",
				      "&", "|", "^", "~", ">", "<", "!"};

	count = sizeof(one_char_operators) / sizeof(one_char_operators[0]);
	for (i = 0; i < count; i++)
	{
		if (buffer[start] == one_char_operators[i][0])
		{
			lexeme[0] = buffer[start];
			lexeme[1] = '\0';
			return (1);
		}
	}
	return (0);
}
