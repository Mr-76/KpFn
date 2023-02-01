#include "readAllDirs.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

const char *readContend(char *path) {
  static char c[1000];
  FILE *fptr;
  if ((fptr = fopen(path, "r")) != NULL) {
    fscanf(fptr, "%[^\n]", c);
    // printf("data \n %s", c);
    fclose(fptr);
  }
  return c;
}

int flag_validator(char *flag) {
  int valid = 0;
  if (0 == strcmp("-NP", flag)) {
    valid = 1;
  } else if (0 == strcmp("-P", flag)) {
    valid = 1;
  } else {
    printf("Wrong flag \n");
  }
  return valid;
}

int findProcess(char *process_name, const char *flag) {
  int found = 0;
  if (0 == flag_validator(flag)) {
  } else {

    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char *elfile = "comm";
    char path[1024];

    dir = opendir("/proc");

    if (dir == NULL) {
      perror("opendir");
      return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
      if (entry->d_type == DT_DIR) {

        snprintf(path, sizeof(path), "%s/%s/%s", "/proc", entry->d_name,
                 elfile);

        if (stat(path, &statbuf) == 0) {
          const char *read_name_Fpid = readContend(path);
          if (0 == patterMach(process_name, read_name_Fpid, flag)) {
            printf("FOUND MATCH PID  %s OF NAME %s \n", entry->d_name,
                   read_name_Fpid);
            found = 1;
          }
        }
      }
    }

    closedir(dir);
  }

  return found;
}

int patterMach(char *search, const char *found, const char *flag) {
  int result = 0;
  int lenSeach = strlen(search);
  int lenFound = strlen(found);
  if (0 == strcmp("-NP", flag)) {
    result = (strcmp(search, found));
  } else if (0 == strcmp("-P", flag) && lenSeach <= lenFound) {
    for (int i = 0; i < lenSeach; i++) {
      if (search[i] != found[i]) {
        result = 1;
        break;
      }
    }
  } else {
    result = 1;
  }
  return result;
}
