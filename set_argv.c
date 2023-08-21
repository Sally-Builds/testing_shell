#include "main.h"


int set_argv(char *buffer, char **cmd)
{

	int i = 0;

	char *token = strtok(buffer, " \t\r\n");

	while(token != NULL)
	{
		cmd[i] = token;
		token = strtok(NULL, " \t\r\n");
		i++;
	}
	cmd[i] = NULL;
	return (i);
}
