#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void partOne(){
  int distance = 0;
  int depth = 0;

  FILE *input = fopen("input.md", "r");

  char* str = malloc(20*sizeof(char));

  while(fgets(str, 20, input)){

    char* tok = strtok (str," \n");

    if(strcmp(tok, "forward") == 0) {
      tok = strtok(NULL, " \n");
      distance += atoi(tok);  
    }
    else if(strcmp(tok, "down") == 0) {
      tok = strtok(NULL, " \n");
      depth += atoi(tok);
    }
    else if(strcmp(tok, "up") == 0) {
      tok = strtok(NULL, " \n");
      depth -= atoi(tok);
    }
  }
  printf("\tDistance:\t%d\n\tDepth:\t\t%d\n\tAnswer:\t\t%d\n", distance, depth, distance*depth);
}

void partTwo(){
  int distance = 0;
  int depth = 0;
  int aim = 0;

  FILE *input = fopen("input.md", "r");

  char* str = malloc(20*sizeof(char));

  while(fgets(str, 20, input)){
    char* tok = strtok (str," \n");

    if(strcmp(tok, "forward") == 0) {
      tok = strtok(NULL, " \n");
      int x = atoi(tok);
      distance += x;
      depth += aim*x;
    }
    else if(strcmp(tok, "down") == 0) {
      tok = strtok(NULL, " \n");
      int x = atoi(tok);
      aim += x;
    }
    else if(strcmp(tok, "up") == 0) {
      tok = strtok(NULL, " \n");
      int x = atoi(tok);
      aim -= x;
    }
  }
  printf("\tDistance:\t%d\n\tDepth:\t\t%d\n\tAnswer:\t\t%d\n", distance, depth, distance*depth);
}

int main(int argc, char **argv) {

  printf("part One:\n");
  partOne();
  printf("\n");

  printf("part Two:\n");
  partTwo();
  printf("\n");

    return 0;
}
