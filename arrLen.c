#include "main.h"


int arrLen(char *buffer)
{
	int i = 0;

	char *token = strtok(buffer, " \t\r\n");

	while(token != NULL)
	{
		token = strtok(NULL, " \t\r\n");
		i++;
	}
	return (i);
}
