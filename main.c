#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ** parse_args( char * line ){
  char** args = calloc(5, sizeof(char*));
  for(int i=0; line; i++){
    args[i] = strsep(&line, " ");
  }
  
  return args;
  
}

int main(){
  char line[10] = "ls -l -a";
  char * args = line;
  char ** parsed_args = parse_args(args);
  printf("args passed: \n");

  int i = 0;
  while(parsed_args[i])
    printf("%s\n", parsed_args[i++]);
  
  printf("executing command: \n");
  execvp(parsed_args[0], parsed_args);
  
}
