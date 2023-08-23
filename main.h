#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
void run_shell(char **argv);
int set_argv(char *buffer, char**argv);
int check_if_file_exist(char *cmd);
char *_getenv(char *name);
char *concat(char *dest, char *s1, char *s2);
char **_getdir(char **dir, char *path_value);
int _getdirLen(char *path_value);
int arrLen(char *buffer);
char *does_path_exist(char *cmd);
void exit_shell(char *s);
#endif

