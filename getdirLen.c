#include "main.h"

int  _getdirLen(char *path_value)
{
	int i = 0;
	char *path_val;
	path_val = (char *) malloc(4096 * sizeof(char));
	strcpy(path_val, path_value);

	char *token = strtok(path_val, ":");

	while(token != NULL)
	{
		token = strtok(NULL, ":");
		i++;
	}
	free(path_val);
	return (i);
}
