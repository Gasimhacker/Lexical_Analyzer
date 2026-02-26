#include "lexer.h"

/**
 * process_directory - Processes all files in a directory
 * @directory_path: Path to the directory
 *
 * Description: Opens a directory and runs the lexer on each
 * regular file found within it.
 */
void process_directory(const char *directory_path)
{
	DIR *dir;
	struct dirent *entry;
	char full_path[PATH_MAX];

	dir = opendir(directory_path);
	if (dir == NULL)
	{
		perror("Unable to open directory");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_REG)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s",
				 directory_path, entry->d_name);
			printf("Processing file: %s\n", full_path);
			lexer(full_path);
			printf("\n");
		}
	}
	closedir(dir);
}

/**
 * is_directory - Checks if a path is a directory
 * @path: Path to check
 *
 * Description: Uses stat to determine if the path points to a directory.
 *
 * Return: 1 if directory, 0 otherwise
 */
int is_directory(const char *path)
{
	struct stat st;

	if (stat(path, &st) != 0)
		return (0);
	return (S_ISDIR(st.st_mode));
}

/**
 * is_regular_file - Checks if a path is a regular file
 * @path: Path to check
 *
 * Description: Uses stat to determine if the path points to a regular file.
 *
 * Return: 1 if regular file, 0 otherwise
 */
int is_regular_file(const char *path)
{
	struct stat st;

	if (stat(path, &st) != 0)
		return (0);
	return (S_ISREG(st.st_mode));
}

/**
 * process_path - Processes a single path (file or directory)
 * @path: Path to process
 *
 * Description: Determines if path is a file or directory and
 * processes it accordingly.
 */
void process_path(const char *path)
{
	printf("-------------------------------------------------------------------\n");
	printf("Processing path: %s\n", path);

	if (is_directory(path))
	{
		printf("Path is a directory. Processing all files.\n");
		process_directory(path);
	}
	else if (is_regular_file(path))
	{
		printf("Path is a regular file. Processing the file.\n");
		if (lexer((char *)path) != 0)
			fprintf(stderr, "Error processing file: %s\n", path);
		printf("\n");
	}
	else
	{
		fprintf(stderr, "Invalid path: %s\n", path);
	}
}

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
