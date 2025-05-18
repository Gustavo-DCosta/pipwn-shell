#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

int main() {
  while (1) {
    printf(CYAN "Pipwn-shell> " RESET);
    fflush(stdout);

    char command[MAX_INPUT_SIZE];
    char *version = "version?";
    char *help = "help?";

    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0'; // Remove newline

    if (strcmp(command, version) == 0) {
      char path[256];
      snprintf(path, sizeof(path), "%s/Desktop/pipwn-shell/src/version.txt", getenv("HOME"));
      FILE *Vptr = fopen("version.txt", "r");
      if (!Vptr) {
        perror(RED "Couldn't open version.txt" RESET);
        continue;
      }

      char ch;
      printf(GREEN); // Set color
      while ((ch = fgetc(Vptr)) != EOF) {
        putchar(ch);
      }
      printf(RESET); // Reset color

      fclose(Vptr);
    }
  }

  return 0;
}

