#include "lexer.h"

/**
 * main - Entry point for the lexical analyzer
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Description: Processes files or directories provided as arguments.
 * If no arguments given, prompts to process the tests directory.
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i;
	char user_choice[2];

	if (argc >= 2)
	{
		for (i = 1; i < argc; i++)
			process_path(argv[i]);
		return (0);
	}

	printf("\nUsage: %s <file_or_directory> [more paths...]\n", argv[0]);
	printf("If a directory is provided, all files will be processed.\n");
	printf("No file or directory specified.\n");
	printf("Process files in the test directory? (Y/N): ");

	if (scanf("%1s", user_choice) == 1 &&
	    (user_choice[0] == 'y' || user_choice[0] == 'Y'))
		process_directory("tests");

	return (0);
}
