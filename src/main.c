#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <limits.h>

#define MAX_INPUT_SIZE 1024

#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int main(int argc, char *argv[]) {
    while (1) {
        printf(CYAN "Pipwn-shell> " RESET);
        fflush(stdout);

        char command[MAX_INPUT_SIZE];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline

        if (strcmp(command, "version?") == 0) {
            char exe_path[PATH_MAX];
            if (realpath(argv[0], exe_path) == NULL) {
                perror(RED "Error getting executable path" RESET);
                continue;
            }

            char *exe_dir = dirname(exe_path);
            char version_path[PATH_MAX];
            snprintf(version_path, sizeof(version_path), "%s/../src/version.txt", exe_dir);

            FILE *Vptr = fopen(version_path, "r");
            if (!Vptr) {
                perror(RED "Couldn't open version.txt" RESET);
                continue;
            }

            char ch;
            printf(GREEN);
            while ((ch = fgetc(Vptr)) != EOF) {
                putchar(ch);
            }
            printf(RESET);
            fclose(Vptr);
        }
    }

    return 0;
}

