#include "lexer.h"

/**
 * read_identifier - Extracts an identifier from the buffer
 * @start: Starting index in the buffer
 * @buffer: Source buffer containing the code
 * @lexeme: Destination buffer to store the identifier
 *
 * Description: Reads alphanumeric characters and underscores
 * starting from the given position to form an identifier.
 *
 * Return: Index position after the identifier
 */
int read_identifier(int start, char *buffer, char *lexeme)
{
	int i = 0;

	while (buffer[start] && (isalnum(buffer[start]) || buffer[start] == '_'))
		lexeme[i++] = buffer[start++];

	lexeme[i] = '\0';
	return (start);
}

/**
 * read_number - Extracts a numeric constant from the buffer
 * @start: Starting index in the buffer
 * @buffer: Source buffer containing the code
 * @lexeme: Destination buffer to store the number
 *
 * Description: Reads consecutive digit characters to form a number.
 *
 * Return: Index position after the number
 */
int read_number(int start, char *buffer, char *lexeme)
{
	int i = 0;

	while (buffer[start] && (buffer[start] >= '0' && buffer[start] <= '9'))
		lexeme[i++] = buffer[start++];

	lexeme[i] = '\0';
	return (start);
}

/**
 * read_string - Extracts a string literal from the buffer
 * @start: Starting index in the buffer (after opening quote)
 * @buffer: Source buffer containing the code
 * @lexeme: Destination buffer to store the string content
 *
 * Description: Reads characters until a closing double quote is found.
 * Exits with error if string is unterminated.
 *
 * Return: Index position at the closing quote
 */
int read_string(int start, char *buffer, char *lexeme)
{
	int i = 0;

	while (buffer[start] && buffer[start] != '"')
		lexeme[i++] = buffer[start++];

	if (buffer[start] == '\0')
	{
		printf("Error: Unterminated string literal\n");
        free(lexeme);
        free(buffer);
		exit(1);
	}
	lexeme[i] = '\0';
	return (start);
}