#include "lexer.h"

/**
 * skip_line_comment - Skips a single-line comment or preprocessor directive
 * @index: Pointer to current position in buffer
 * @buffer: Source buffer containing the code
 *
 * Description: Advances index past all characters until newline.
 */
void skip_line_comment(int *index, char *buffer)
{
	while (buffer[*index] && buffer[*index] != '\n')
		(*index)++;
}

/**
 * skip_block_comment - Skips a multi-line block comment
 * @index: Pointer to current position in buffer
 * @buffer: Source buffer containing the code
 *
 * Description: Advances index past characters until closing asterisk-slash.
 */
static void skip_block_comment(int *index, char *buffer)
{
	(*index) += 2;
	while (buffer[*index] &&
	       !(buffer[*index] == '*' && buffer[*index + 1] == '/'))
		(*index)++;
	if (buffer[*index])
		(*index) += 2;
}

/**
 * skip_whitespace_and_comments - Skips whitespace, comments, preprocessor
 * @index: Pointer to current position in buffer
 * @buffer: Source buffer containing the code
 *
 * Description: Advances the index past all whitespace characters,
 * single-line comments (//), multi-line comments, and
 * preprocessor directives (#).
 */
void skip_whitespace_and_comments(int *index, char *buffer)
{
	while (buffer[*index])
	{
		if (isspace(buffer[*index]))
		{
			(*index)++;
		}
		else if (buffer[*index] == '/' && buffer[*index + 1] == '/')
		{
			skip_line_comment(index, buffer);
		}
		else if (buffer[*index] == '/' && buffer[*index + 1] == '*')
		{
			skip_block_comment(index, buffer);
		}
		else if (buffer[*index] == '#' &&
			 (*index == 0 || buffer[*index - 1] == '\n'))
		{
			skip_line_comment(index, buffer);
		}
		else
		{
			break;
		}
	}
}
