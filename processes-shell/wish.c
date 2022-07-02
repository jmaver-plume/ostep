#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int
main (int argc, char *argv[])
{
  char * ch;
  do {
    ch = readline("wish> ");
    printf("%s\n", ch);
  } while (strcmp(ch, "exit") != 0);

  return 0;
}
