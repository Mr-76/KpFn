/* file minunit_example.c */

#include "../Killfw/readAllDirs.h"
#include "minunit.h"
#include <stdio.h>
#include <string.h>
int tests_run = 0;

int foo = 7;
int bar = 4;

static char *test_foo() {
  mu_assert("error, foo != 7", foo == 7);
  return 0;
}

static char *test_read_proc() {
  mu_assert("error not working", 0 == findProcess("firefox", "-NP"));
  return 0;
}

static char *test_patter_mach_true() {
  mu_assert("wrong patter ", 0 == patterMach("firefox", "firefox", "-NP"));
  return 0;
}

static char *test_patter_mach_false() {
  mu_assert("correct it cant", 0 != patterMach("firefox", "firefo", "-NP"));
  return 0;
}

static char *test_patter_mach_true_p() {
  mu_assert("incorrect match incomplete word wont match ",
            0 == patterMach("fi", "firfo", "-P"));

  mu_assert("incorrect match incomplete word wont match ",
            0 == patterMach("f", "firfo", "-P"));

  mu_assert("incorrect match incomplete word wont match ",
            0 == patterMach("firefox", "firefox", "-P"));

  return 0;
}

static char *test_patter_mach_false_p() {
  mu_assert("some how correct match ", 0 != patterMach("fire", "firf", "-P"));

  mu_assert("some how correct match ", 0 != patterMach("fi", "fe", "-P"));

  mu_assert("some how worked bigger search word",
            0 != patterMach("firefox", "firefo", "-P"));

  return 0;
}

static char *test_incorrect_word() {
  mu_assert("correct word cant be",
            (0 != strcmp("Hello World", readContend("text.txt"))));
  return 0;
}

static char *test_correct_word() {
  mu_assert("incorrect  word",
            (0 == strcmp("hello workld", readContend("text.txt"))));
  return 0;
}

static char *all_tests() {
  mu_run_test(test_patter_mach_true);
  mu_run_test(test_patter_mach_false_p);
  mu_run_test(test_patter_mach_true_p);
  mu_run_test(test_patter_mach_false);
  mu_run_test(test_read_proc);
  mu_run_test(test_foo);
  mu_run_test(test_incorrect_word);
  mu_run_test(test_correct_word);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
