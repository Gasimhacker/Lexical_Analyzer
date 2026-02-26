# include "lexer.h"

int is_valid_three_char_operator(char *buffer, int start, char *lexeme)
{
    size_t i;
    char *three_char_operators[] = {">>=", "<<="};

    for (i = 0; i < sizeof(three_char_operators) / sizeof(three_char_operators[0]); i++)
    {
        if (strncmp(three_char_operators[i], buffer + start, 3) == 0)
        {
            strcpy(lexeme, three_char_operators[i]);
            return (1);
        }
    }
    return (0);
}

int is_valid_two_char_operator(char *buffer, int start, char *lexeme)
{
    size_t i;
    char *two_char_operators[] = {"+=", "*=", "-=", "/=", "%%=",
                                  "&=", "|=", "^=", ">=", "<=", "!=", "==",
                                  "++", "--", "&&", "||", ">>", "<<", "->"};

    for (i = 0; i < sizeof(two_char_operators) / sizeof(two_char_operators[0]); i++)
    {
        if (strncmp(two_char_operators[i], buffer + start, 2) == 0)
        {
            strcpy(lexeme, two_char_operators[i]);
            return (1);
        }
    }
    return (0);
}

int is_valid_one_char_operator(char *buffer, int start, char *lexeme)
{
    size_t i;
    char *one_char_operators[] = {"+", "-", "*", "/", "%%", "=",
                                 "&", "|", "^", "~", ">", "<", "!"};

    for (i = 0; i < sizeof(one_char_operators) / sizeof(one_char_operators[0]); i++)
    {
        if (buffer[start] == one_char_operators[i][0])
        {
            lexeme[0] = buffer[start];
            lexeme[1] = '\0';
            return (1);
        }
    }
    return (0);
}
