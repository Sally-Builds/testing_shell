#include "main.h"

int dir_len(char *s, char *delim);
void store_dir_in_array(char **dirs, char *s, char *delim, char *cmd);
int check_if_file_exist(char *cmd);
int full_cmd(char **dirs, int num_of_dir);
char *does_path_exist (char *cmd)
{
	extern char **environ;
	char *delim = ":";

	char *path_value = _getenv("PATH");
	char *path_value_copy;
	char **dirs;
	int num_of_dir;
	//char *cmd = "/bin/ls";
	//char cmd_path[100] = "/";
	char *cmd_path;
	int full_cmd_len = 0;

	path_value_copy = malloc(sizeof(char) * strlen(path_value));

	strcpy(path_value_copy, path_value);

	num_of_dir = dir_len(path_value_copy, delim);
	dirs = (char **)malloc(num_of_dir * sizeof(char));

	//length of cmd and the /
	//cmd_path = malloc(sizeof(char) * (strlen(cmd) + 2));
	printf("%c\n", *cmd);
	if (*cmd == '/')
	{
		if (check_if_file_exist(cmd) == 0)
			return (cmd);
		else
			return (NULL);
	}
	else
	{
		cmd_path = malloc(sizeof(char) * (strlen(cmd) + 2));
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);
		store_dir_in_array(dirs, path_value, delim, cmd_path);

		int p_index = full_cmd(dirs, num_of_dir);

		if (p_index  >= 0)
		{
			full_cmd_len = strlen(dirs[p_index]);
			return (dirs[p_index]);
		}
		else
			return (NULL);
	}
}

int dir_len(char *s, char *delim)
{
	int i = 0;
	char *token = strtok(s, delim);

	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delim);
	}
	printf("%d \n", i);
	i++;

	return (i);
}

void store_dir_in_array(char **dirs, char *s, char *delim, char *cmd)
{
	int i = 0;
	char *token = strtok(s, delim);

	while (token != NULL)
	{
		dirs[i] = malloc(sizeof(char) * (strlen(token + strlen(cmd))));
		strcpy(dirs[i], token);
		strcat(dirs[i], cmd);

		token = strtok(NULL, delim);
		i++;
	}
	dirs[i] = NULL;
}

int full_cmd(char **dirs, int num_of_dir)
{
	int i = 0;
	while (i < num_of_dir)
	{
		if(check_if_file_exist(dirs[i]) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}


int check_if_file_exist(char *cmd)
{
	int status = access(cmd, F_OK);

	if (status == 0)
		return (0);
	return (1);
}
