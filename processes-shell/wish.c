#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

char **get_command (char *line);
char *concat (char *s1, char *s2);
int is_builtin_command (char *command);


int
main (int argc, char *argv[])
{
  char **path = malloc(1 * sizeof(char *));
  path[0] = "/bin";
  char *line;
  do {
    line = readline("wish> ");
    // printf("Line: %s\n", line);

    char **command = get_command(line);
    printf("Command: %s\n", command[0]);
    if (is_builtin_command(command[0]) == 1) {
      if (strcmp("exit", command[0]) == 0) {
        return 0;
      }
      printf("Builtin command: %s\n", command[0]);
    } else {
      // int access_result = access(command[0], X_OK);
      // if (access_result != 0) {
      //   exit(1);
      // }
      // // printf("Access result: %d\n", access_result);
      // 
      // int pid = fork();
      // if (pid == 0) {
      //   execv(command[0], command);
      // } else if (pid > 0) {
      //   wait(NULL);
      // }

      // int result = access(
    }

  } while (1);

  return 0;
}

char **get_command (char *line) 
{
    char **command = malloc(8 * sizeof(char *));
    char * sep = " ";
    int index = 0;
    char *parsed;
    parsed = strtok(line, sep);
    while (parsed != NULL) {
      command[index] = parsed;
      index++;

      parsed = strtok(NULL, sep);
    }
    return command;
}


char *concat (char *s1, char *s2)
{
  char *result = malloc(sizeof(s1) + sizeof(s2) + 1);
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

int is_builtin_command (char *command) 
{
  if (strcmp("cd", command) == 0) {
    return 1;
  }

  if (strcmp("exit", command) == 0) {
    return 1;
  }

  if (strcmp("path", command) == 0) {
    return 1;
  }

  return 0;
}
