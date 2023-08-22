#include "main.h"

int main()
{
	char *buffer;
	size_t buffer_size = 4096;
	char **cmd;
	char **dir;
	int len_of_cmd;
	int len_of_dir_in_path;
	int i = 0;

	//get value of path
	char *path_value = _getenv("PATH");

	buffer = (char *) malloc(buffer_size * sizeof(char));
	
	if (buffer == NULL)
	{
		printf("err alloc");
		return (1);
	}

	printf("$ ");
	getline(&buffer, &buffer_size, stdin);

	len_of_cmd = arrLen(buffer);

	cmd = malloc(len_of_cmd * sizeof(char));

	//assing memory to each string in array
	while (i < len_of_cmd)
	{
		cmd[i] = malloc(buffer_size * sizeof(char));
		i++;
	}

	//add strings to cmd array
	set_argv(buffer, cmd);

	//printf("%d - cmd[0] - %s\n", len_of_cmd, cmd[0]);
	
	len_of_dir_in_path = _getdirLen(path_value);

	dir = malloc(len_of_dir_in_path * sizeof(char));

	i = 0;

	while (i < len_of_dir_in_path)
	{
		dir[i] = malloc(buffer_size * sizeof(char));
		i++;
	}

	dir = _getdir(dir, path_value);

	//printf("%d - dir[4] - %s\n", len_of_dir_in_path, dir[4]);
	

	i = 0;
	if (*cmd[0] == '/')
	{
		if (check_if_file_exist(cmd[0]) == 0)
			printf("command is valid");
		else
			printf("command is not valid");
	}
	else
	{
		while (i < len_of_dir_in_path)
		{
			char s[1000] = "";
			strcat(s, dir[i]);
			strcat(s, "/");
			strcat(s, cmd[0]);

			if (check_if_file_exist(s) == 0)
				printf("command is valid from short\n");
			i++;
		}
	}

	return (0);
}
