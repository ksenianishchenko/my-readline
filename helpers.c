#include "header.h"

char *my_strcpy(char *str1, char *str2) {
    if (str1 == NULL) {
        return NULL;
    }

    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';

    return str1;
};

char *my_strncpy(char *str1, char *str2, int n) {

    if (str1 == NULL) {
        return NULL;
    }

    while (n >= 0) {
        if (*str2 == '\0') {
            break;
        }
        *str1 = *str2;
        str1++;
        str2++;
        n--;
    }

    *str1 = '\0';

    return str1;

};

char *my_strcat(char *str1, char *str2) {
  while(*str1 != '\0') {
    str1++;
  }

  while(*str2 != '\0') {
    *str1 = *str2;
    str1++;
    str2++;
  }

  *str1 = '\0';

  return str1;
}


char *my_strchr(char *str, int c) {

  while(*str) {

    if(*str == c) {
      return str;
    }

    str++;
  }

  return NULL;
}
