#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
  printf("Pipwn-shell: 0.01\n");  
  char command[MAX_INPUT_SIZE];

  fgets(command, sizeof(command), stdin);
  printf("------------------------------\n");
  printf("%s", command);

  int spaces;
  int cmd_len = strlen(command);
  for (int i = 0; i < cmd_len; i++) {
    printf("%c\n", command[i]);
  }

  return 0;
}
