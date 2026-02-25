# include "lexer.h"


int read_identifier(int start, char *buffer, char *lexeme)
{
    int i = 0;

    while (buffer[start] && (isalnum(buffer[start]) || buffer[start] == '_'))
        lexeme[i++] = buffer[start++];
    
    lexeme[i] = '\0';
    return start;
}

int read_number(int start, char *buffer, char *lexeme)
{
    int i = 0;

    while (buffer[start] && (buffer[start] >= '0' && buffer[start] <= '9'))
        lexeme[i++] = buffer[start++];
    
    lexeme[i] = '\0';
    return start;
}

int read_string(int start, char *buffer, char *lexeme)
{
    int i = 0;

    while (buffer[start] && buffer[start] != '"')
        lexeme[i++] = buffer[start++];
    
    if (buffer[start] == '\0')
    {
        printf("Error: Unterminated string literal\n");
        exit(1);
    }
    lexeme[i] = '\0';
    return start;
}