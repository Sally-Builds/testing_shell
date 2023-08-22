#include "main.h"


char *concat(char *dest, char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    while(s1[i] != '\0')
    {
        dest[i] = s1[i];
        i++;
   printf("%c\n", s1[i]); 
    }

    dest[i] = '/'; 
    j = i + 1;
    i = 0;
    
    while(s2[i] != '\0')
    {
        dest[j] = s2[i];
        j++;
        i++;
    }
    return dest;
}
