#include "lexer.h"

/**
 * process_char_literal - Handles character literal tokens
 * @buffer: Source buffer containing the code
 * @i: Pointer to current position in buffer
 *
 * Description: Processes single character literals like 'a'.
 *
 * Return: 1 if processed, 0 otherwise
 */
int process_char_literal(char *buffer, int *i)
{
	if (buffer[*i] == '\'' && buffer[*i + 1] && buffer[*i + 2] == '\'')
	{
		printf("\'%c\': CONSTANT\n", buffer[*i + 1]);
		*i += 3;
		return (1);
	}
	return (0);
}

/**
 * process_token - Identifies and prints the current token
 * @buffer: Source buffer containing the code
 * @i: Pointer to current position in buffer
 * @lexeme: Buffer to store extracted lexemes
 *
 * Description: Checks for punctuators, identifiers, keywords,
 * numbers, strings, character literals, and operators.
 */
void process_token(char *buffer, int *i, char *lexeme)
{
	if (is_punctuator(buffer[*i]))
	{
		printf("\'%c\' : PUNCTUATOR\n", buffer[*i]);
		(*i)++;
	}
	else if (isalpha(buffer[*i]) || buffer[*i] == '_')
	{
		*i = read_identifier(*i, buffer, lexeme);
		if (is_keyword(lexeme))
			printf("\'%s\' : KEYWORD\n", lexeme);
		else
			printf("\'%s\' : IDENTIFIER\n", lexeme);
	}
	else if (buffer[*i] >= '0' && buffer[*i] <= '9')
	{
		*i = read_number(*i, buffer, lexeme);
		printf("\'%s\': CONSTANT\n", lexeme);
	}
	else if (buffer[*i] == '"')
	{
		*i = read_string(*i + 1, buffer, lexeme);
		printf("\'%s\': STRING\n", lexeme);
		(*i)++;
	}
	else if (process_char_literal(buffer, i))
	{
		return;
	}
	else if (is_valid_operators(buffer, i, lexeme))
	{
		printf("\'%s\': OPERATOR\n", lexeme);
	}
	else
	{
		printf("Unknown token starting with \'%c\'\n", buffer[*i]);
		(*i)++;
	}
}
