#include "lexer.h"

void process_directory(const char *directory_path)
{
    DIR *dir = opendir(directory_path);
    struct dirent *entry;
    char full_path[PATH_MAX];

    if (dir == NULL)
    {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
	{ // Check if it's a regular file
            snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);
            printf("Processing file: %s\n", full_path);
            lexer(full_path);
            printf("\n");
        }
    }
    closedir(dir);
}

/* Check if path is a directory */
int is_directory(const char *path)
{
    struct stat st;
    if (stat(path, &st) != 0)
        return 0;
    return S_ISDIR(st.st_mode);
}

/* Check if path is a regular file */
int is_regular_file(const char *path)
{
    struct stat st;
    if (stat(path, &st) != 0)
        return 0;
    return S_ISREG(st.st_mode);
}


int main(int argc, char *argv[])
{
    char user_choice[1];

    if (argc >= 2)
    {
        for (int i = 1; i < argc; i++)
	{
	    
            printf("-------------------------------------------------------------------\n");
            printf("Processing path: %s\n", argv[i]);
            if (is_directory(argv[i]))
	    {
                printf("Path is a directory. Processing all files in the directory.\n");
                process_directory(argv[i]);
            } else if (is_regular_file(argv[i]))
	    {
                printf("Path is a regular file. Processing the file.\n");
                if (lexer(argv[i]) != 0)
                    fprintf(stderr, "Error processing file: %s\n", argv[i]);
                printf("\n");
            } else
	    {
                fprintf(stderr, "Invalid path: %s\n", argv[i]);
            }
        }
        return 0;
    }

    printf("\n");
    printf("Usage: %s <file_or_directory> [more paths...]\n", argv[0]);
    printf("If a directory is provided, all files in the directory will be processed.\n");
    printf("Since there is no file or directory specified the lexer will process all files in the tests directory:\n");
    printf("Do you want to process the files in the test directory? (Y/N)\n");
    scanf("%s", user_choice);
    if (user_choice[0] == 'y' || user_choice[0] == 'Y')
    	process_directory("tests");
    return (0);
}
