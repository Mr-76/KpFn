#include "../Killfw/readAllDirs.h"
#include "../killPart/kill.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <program name> and flag <-NP> or <-P>\n", argv[0]);
    return 1;
  }
  findProcess(argv[1], argv[2]);
  printf("2nd part\n");
  killProgram();
  return 0;
}
