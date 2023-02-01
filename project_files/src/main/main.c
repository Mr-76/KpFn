#include "../killPart/kill.h"
#include "../readDirs/readAllDirs.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <program name> and flag <-NP> or <-P>\n", argv[0]);
    return 1;
  }
  int valid = findProcess(argv[1], argv[2]);
  if (valid == 1) {
    printf("2nd part\n");
    killProgram();
  } else {
    printf("invalid try again\n");
  }
  return 0;
}
