#include <signal.h>
#include <stdio.h>
#include <string.h>
void killProgram() {
  char input[100];
  int pid;
  printf("input the number of the process u want to terminate\n");
  fgets(input, sizeof(input), stdin);
  sscanf(input, "%d", &pid);
  kill(pid, SIGTERM);
}
