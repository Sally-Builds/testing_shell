#include "main.h"

char ** _getdir(char **dir, char *path_value)
{
	int i = 0;
	char *path_val;
	path_val = (char *) malloc(32 * sizeof(char));
	strcpy(path_val, path_value);

	char *token = strtok(path_val, ":");

	while(token != NULL)
	{
		dir[i] = token;
		printf("%s\n", token);
		token = strtok(NULL, ":");
		i++;
	}
	//free(path_val);
	return (dir);
}
