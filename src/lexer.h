#ifndef LEXER_H
#define LEXER_H

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>

/* Cross-platform PATH_MAX */
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

/* File operations */
char *read_file(char *filename, size_t *size);

/* Lexeme checking */
int is_keyword(char *lexeme);
int is_punctuator(char lexeme);

/* Operator validation */
int is_valid_operators(char *buffer, int *start, char *lexeme);
int is_valid_three_char_operator(char *buffer, int start, char *lexeme);
int is_valid_two_char_operator(char *buffer, int start, char *lexeme);
int is_valid_one_char_operator(char *buffer, int start, char *lexeme);

/* Parsing utilities */
void skip_whitespace_and_comments(int *index, char *buffer);
int read_identifier(int start, char *buffer, char *lexeme);
int read_number(int start, char *buffer, char *lexeme);
int read_string(int start, char *buffer, char *lexeme);

/* Main lexer function */
int lexer(char *filename);

#endif /* LEXER_H */
