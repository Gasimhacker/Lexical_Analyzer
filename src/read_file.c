#include "lexer.h"

/**
 * read_file - Reads entire file content into a buffer
 * @filename: Path to the file to read
 * @size: Pointer to store the file size
 *
 * Description: Opens a file, determines its size, allocates memory,
 * reads the content into the buffer, and null-terminates it.
 *
 * Return: Pointer to buffer containing file content, or NULL on failure
 */
char *read_file(char *filename, size_t *size)
{
	char *buffer;
	FILE *fp;

	fp = fopen(filename, "r");
	if (!fp)
		return (NULL);

	fseek(fp, 0, SEEK_END);
	*size = ftell(fp);
	rewind(fp);

	buffer = malloc(*size + 1);
	if (!buffer)
	{
		fclose(fp);
		return (NULL);
	}

	fread(buffer, 1, *size, fp);
	buffer[*size] = '\0';

	fclose(fp);
	return (buffer);
}
