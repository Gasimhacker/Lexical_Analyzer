#include "lexer.h"

char *read_file(char *filename, size_t *size)
{
    char *buffer;
    FILE *fp = fopen(filename, "r");

    if (!fp)
        return NULL;

    fseek(fp, 0, SEEK_END);
    *size = ftell(fp);
    rewind(fp);

    buffer = malloc(*size + 1);
    fread(buffer, 1, *size, fp);
    buffer[*size] = '\0';

    fclose(fp);
    return buffer;
}