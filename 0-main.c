#include "main.h"

void execute_command(char **argv);
void store_token_in_array(char **argv, char *s, char *delim);
int total_len_of_string(char *s, char *delim );
void run_shell(char **argv);
int main()
{
	char *buffer = NULL;
	char *buffer_copy;
	size_t buffer_size = 32;
	int buffer_len;
	char *delim = " \t\r\n";
	char **argv;
	int len_of_argv;

	buffer = (char *) malloc(buffer_size * sizeof(char));
	while(true)
	{
		printf("#cisfun$ ");
		buffer_len = getline(&buffer, &buffer_size, stdin);

		buffer_copy = malloc(sizeof(char) * buffer_len);

		if(buffer_len == -1)
		{
			perror("error reading from stdin");
			return(1);
		}

		strcpy(buffer_copy, buffer);

		//get the number of strings(commands, and arguments)
		len_of_argv = total_len_of_string(buffer_copy, delim);
		
		argv =(char **) malloc((len_of_argv + 1) * sizeof(char));
		
		//store the commands in the argv array
		store_token_in_array(argv, buffer, delim);

		//execute command
		//execute_command(argv);
		run_shell(argv);
		free(buffer_copy);
	}
	return (0);
}


int total_len_of_string(char *s, char *delim )
{
	int i = 0;
	char *token;

	token = strtok(s, delim);

	while(token != NULL)
	{
		token = strtok(NULL, delim);
		i++;
	}

	return (i);
}


void store_token_in_array(char **argv, char *s, char *delim)
{
	int i = 0;
	char *token = strtok(s, " \t\r\n");

	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, " \t\r\n");
		i++;
	}
	argv[i] = NULL;
}

void execute_command(char **argv)
{
	if (argv)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
}

void run_shell(char **argv)
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execute_command(argv);
	}
	else
	{
		wait(NULL);
	}
}
