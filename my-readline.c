#include "header.h"

char *createLine(char *line, char *strFromBuf) {
  int lineLength = 0;
  char *temp;
  int tempInx = 0;

  while(strFromBuf[lineLength] != '\n' && strFromBuf[lineLength] != '\0') {
    lineLength++;
  }

  line = (char *)malloc(lineLength * sizeof(char) + 1);

  if(strFromBuf[lineLength] == '\n') {
    my_strncpy(line, strFromBuf, lineLength);
  } else {
    my_strcpy(line, strFromBuf);
  }

  line[lineLength] = '\0';

  temp = (char *)malloc(strlen(strFromBuf) * sizeof(char) + 1);

  for(int j = lineLength + 1; strFromBuf[j] != '\0'; j++) {
    temp[tempInx] = strFromBuf[j];
    tempInx++;
  }

  temp[tempInx] = '\0';

  my_strcpy(strFromBuf, temp);

  free(temp);

  return line;
}

char *my_readline(int fd) {
  char buffer[BUFF_SIZE + 1];
  char *line;

  static char strFromBuf[4095];

  int size_read = 0;

  while((size_read = read(fd, buffer, BUFF_SIZE)) > 0) {
    buffer[size_read] = '\0';
    my_strcat(strFromBuf, buffer);
    if(my_strchr(strFromBuf, '\n')) {
      break;
    };
  }

  line = createLine(line, strFromBuf);

  int len = strlen(line);

  if(size_read == 0 && len == 0) {
    printf("%s\n", "ENd");
    return NULL;
  }

  return line;
};


int main(int ac, char **av) {
  char *str = NULL;
  int fd = open("./test.txt", O_RDONLY);

  str = my_readline(fd);
  printf("%s\n", str);
  free(str);

  str = my_readline(fd);
  printf("%s\n", str);
  free(str);

  close(fd);

  return 0;
}
