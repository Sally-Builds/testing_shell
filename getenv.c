#include "main.h"

int _match(char *s, char *m);
int _len(char *s);
char *_getenv(char *name)
{
	extern char** environ;
	int i = 0;
	char *s;

	while(environ[i] != NULL)
	{
		s = strtok(environ[i], "=");
		if (_match(s, name) == 0)
		{
			s = strtok(NULL, "=");
			return (s);
		}
		i++;
	}
	return NULL;
}


int _match(char *s, char *m)
{
	int j = 0;
	int m_len = _len(m);
	int max = _len(s);
	if(m_len > max)
		max = m_len;
	while (j < max)
	{
		if (s[j] != m[j])
		{
			return (-1);
		}
		j++;
	}
	return (0);
}

int _len(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
