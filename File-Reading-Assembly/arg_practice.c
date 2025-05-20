#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[]) {
 
  printf("Number of arguments: %d\n", argc);
  printf("Arguments:\n");
 
  for (int i = 0; i < argc; i++)
  {
    printf("argv[%d]: %s\n", i, argv[i]);
 
  }
  printf("\n");
  
  if (argc >2) {
    printf("The first arg is int: %d\n", atoi(argv[1]));
    printf("The second arg as string: %s\n", argv[2]);
  }
 
  return 0;
}
