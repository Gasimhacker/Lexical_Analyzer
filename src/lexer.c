#include "lexer.h"

/**
 * lexer - Main lexical analyzer function
 * @filename: Path to the file to analyze
 *
 * Description: Reads a file and tokenizes its content,
 * printing each token with its type.
 *
 * Return: 0 on success, -1 on failure
 */
int lexer(char *filename)
{
	size_t buffer_size;
	int i = 0;
	char *lexeme;
	char *buffer;

	buffer = read_file(filename, &buffer_size);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: Unable to open file '%s'\n", filename);
		return (-1);
	}

	lexeme = malloc(buffer_size);
	if (lexeme == NULL)
	{
		free(buffer);
		fprintf(stderr, "Error: Memory allocation failed\n");
		return (-1);
	}

	while (buffer[i])
	{
		skip_whitespace_and_comments(&i, buffer);
		if (!buffer[i])
			break;
		process_token(buffer, &i, lexeme);
	}

	free(lexeme);
	free(buffer);
	return (0);
}
