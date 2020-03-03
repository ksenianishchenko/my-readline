#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFF_SIZE 8

char *my_strcpy(char *str1, char *str2);
char *my_strncpy(char *str1, char *str2, int n);
char *my_strcat(char *str1, char *str2);
char *my_strchr(char *str, int c);
