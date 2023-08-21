#include "main.h"

int check_if_file_exist(char *cmd)
{
	int status = access(cmd, F_OK);

	if (status == 0)
		return (0);
	return (1);
}
