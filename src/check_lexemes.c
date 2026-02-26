#include "lexer.h"

/**
 * is_keyword - Checks if a lexeme is a C keyword
 * @lexeme: The string to check
 *
 * Description: Compares the lexeme against all 31 C keywords.
 *
 * Return: 1 if keyword, 0 otherwise
 */
int is_keyword(char *lexeme)
{
	int i;
	char *keywords[] = {"char", "int", "float", "double", "void",
			    "short", "long", "signed", "unsigned", "sizeof",
			    "return", "goto", "typedef", "if", "else",
			    "switch", "case", "default", "for", "while",
			    "do", "continue", "auto", "register", "static",
			    "extern", "const", "volatile", "struct", "union",
			    "enum"};

	for (i = 0; i < 31; i++)
	{
		if (strcmp(lexeme, keywords[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * is_punctuator - Checks if a character is a punctuator
 * @lexeme: The character to check
 *
 * Description: Checks against common C punctuators like
 * braces, brackets, semicolons, etc.
 *
 * Return: 1 if punctuator, 0 otherwise
 */
int is_punctuator(char lexeme)
{
	int i;
	char punctuators[] = {':', ',', '[', ']', '(', ')',
			      '#', '.', '{', '}', ';'};

	for (i = 0; i < 11; i++)
	{
		if (lexeme == punctuators[i])
			return (1);
	}
	return (0);
}

/**
 * is_valid_operators - Checks for valid operator and updates position
 * @buffer: Source buffer containing the code
 * @start: Pointer to current position (updated on match)
 * @lexeme: Buffer to store the matched operator
 *
 * Description: Tries to match 3-char, 2-char, then 1-char operators
 * in order of precedence.
 *
 * Return: Length of matched operator (1-3), or 0 if no match
 */
int is_valid_operators(char *buffer, int *start, char *lexeme)
{
	if (is_valid_three_char_operator(buffer, *start, lexeme))
	{
		*start += 3;
		return (3);
	}
	else if (is_valid_two_char_operator(buffer, *start, lexeme))
	{
		*start += 2;
		return (2);
	}
	else if (is_valid_one_char_operator(buffer, *start, lexeme))
	{
		*start += 1;
		return (1);
	}
	return (0);
}