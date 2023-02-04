#include <signal.h>
#include <stdio.h>
#include <string.h>
void killProgram() {
  char input[100];
  int pid;
  int sig;
  printf("Input the number of the process u want to terminate\n");
  fgets(input, sizeof(input), stdin);
  sscanf(input, "%d", &pid);

  printf("Choose\n1- sigterm\n2- sigkill\nAdvised to use sigterm\n");

  fgets(input, sizeof(input), stdin);
  sscanf(input, "%d", &sig);

  printf("Ending process %d\n", pid);
  if (sig == 1) {
    kill(pid, SIGTERM);
  } else if (sig == 2) {
    kill(pid, SIGKILL);
  }else{
	  printf("Nothing selected exiting.....\n");
  }
}
