#include "lexer.h"

int lexer(char *filename)
{
    size_t buffer_size;
    int i = 0;
    char *lexeme;
    char *buffer;

    // Opening file in reading mode
    buffer = read_file(filename, &buffer_size);
    if (buffer == NULL)
    {
        fprintf(stderr, "Error: Unable to open file '%s'\n", filename);
        return -1;
    }
    lexeme = malloc(buffer_size);
    if (lexeme == NULL)
    {
        free(buffer);
        fprintf(stderr, "Error: Memory allocation failed\n");
        return -1;
    }

    // Reading file character by character
    while (buffer[i])
    {
        skip_whitespace_and_comments(&i, buffer);

	if (!buffer[i])
	    break;
        
        if (is_punctuator(buffer[i]))
        {
            printf("\'%c\' : PUNCTUATOR\n", buffer[i]);
            i++;
            continue;
        }
        
        if (isalpha(buffer[i]) || buffer[i] == '_')
        {
            i = read_identifier(i, buffer, lexeme);
            if (is_keyword(lexeme))
                printf("\'%s\' : KEYWORD\n", lexeme);
            else
                printf("\'%s\' : IDENTIFIER\n", lexeme);
        } else if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            i = read_number(i, buffer, lexeme);
            printf("\'%s\': CONSTANT\n", lexeme);
        } else if (buffer[i] == '"')
        {
            i = read_string(i + 1, buffer, lexeme);
            printf("\'%s\': STRING\n", lexeme);
            i++;
        } else if (buffer[i] == '\'' && buffer[i + 1] && buffer[i + 2] == '\'')
        {
            printf("\'%c\': CONSTANT\n", buffer[i + 1]);
            i += 3;
        } else if (is_valid_operators(buffer, &i, lexeme))
        {
            printf("\'%s\': OPERATOR\n", lexeme);
        } else
        {
            printf("Unknown token starting with \'%c\'\n", buffer[i]);
            i++;
        }
    }

    //cleaning    
    free(lexeme);
    free(buffer);

    return (0);
}
