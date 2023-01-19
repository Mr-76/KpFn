gcc -Wall -c Killfw/readAllDirs.c 
gcc -Wall -c test/minunit_example.c
gcc -o testprogram minunit_example.o readAllDirs.o
