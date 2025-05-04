#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
  printf("Pipwn-shell: 0.01\n");  
  char command[MAX_INPUT_SIZE];

  fgets(command, sizeof(command), stdin);
  printf("%s", command);

  int spaces;

  for (int i = 0; i < strlen(command); i++) {
    printf("%c", command[i]);
  }

  return 0;
}
