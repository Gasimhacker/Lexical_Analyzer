# include "lexer.h"

void skip_whitespace_and_comments(int *index, char *buffer)
{
    while (buffer[*index])
    {
        if (isspace(buffer[*index]))
        {
            (*index)++;
        } else if (buffer[*index] == '/' && buffer[*index + 1] == '/')
        {
            while (buffer[*index] && buffer[*index] != '\n')
                (*index)++;
        } else if (buffer[*index] == '/' && buffer[*index + 1] == '*')
        {
            (*index) += 2;
            while (buffer[*index] && !(buffer[*index] == '*' && buffer[*index + 1] == '/'))
                (*index)++;
            if (buffer[*index])
                (*index) += 2;
        } else if (buffer[*index] == '#' && (*index == 0 || buffer[*index - 1] == '\n'))
        {
            while (buffer[*index] && buffer[*index] != '\n')
                (*index)++;
        } else
        {
            break;
        }
    }
}
