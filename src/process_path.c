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
		/* Skip . and .. directories */
		if (strcmp(entry->d_name, ".") == 0 ||
		    strcmp(entry->d_name, "..") == 0)
			continue;

		snprintf(full_path, sizeof(full_path), "%s/%s",
			 directory_path, entry->d_name);

		if (is_regular_file(full_path))
		{
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
	printf("-------------------------------------------------------------------");
	printf("\nProcessing path: %s\n", path);

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
