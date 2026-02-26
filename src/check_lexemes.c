#include "lexer.h"

int is_keyword(char *lexeme)
{
    int i;
    char *keywords[] = {"char", "int", "float", "double", "void", "short", "long",
                        "signed", "unsigned", "sizeof", "return", "goto", "typedef",
                        "if", "else", "switch", "case", "default", "for", "while",
                        "do", "continue", "auto", "register", "static", "extern",
                        "const", "volatile", "struct", "union", "enum"};

    for (i = 0; i < 31; i++)
        if (strcmp(lexeme, keywords[i]) == 0)
            return (1);
    return (0);
}

int is_punctuator(char lexeme)
{
    int i;
    char Punctuators[] = {':', ',', '[', ']', '(', ')', '#', '.', '{', '}', ';'};
    for (i = 0; i < 11; i++)
        if (lexeme == Punctuators[i])
            return (1);

    return (0);
    
}

int is_valid_operators(char *buffer, int *start, char *lexeme)
{
    if (is_valid_three_char_operator(buffer, *start, lexeme))
    {
        *start += 3;
        return 3;
    } else if (is_valid_two_char_operator(buffer, *start, lexeme))
    {
        *start += 2;
        return 2;
    } else if (is_valid_one_char_operator(buffer, *start, lexeme))
    {
        *start += 1;
        return 1;
    }
    return 0;
}