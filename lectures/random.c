#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  printf("printing 2 and 3rd: %s and %s", argv[2], argv[3]);
  
  FILE *file;
  file = fopen(argv[1], "w");
  fprintf(file, "hello\n");
  printf("%s", argv[4]);
  return 0;
}