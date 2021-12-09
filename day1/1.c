#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partOne(){

    FILE *input = fopen("input.md", "r");
    char *str = calloc(10, sizeof(char));
    char *oldStr = calloc(10, sizeof(char));
    int count = 0;
    //initialising str and oldstr
    fgets(str, 10, input);
    strcpy(oldStr, str);

    while(fgets(str, 10, input)){
        if(atoi(oldStr) < atoi(str)){
            count++;
        }
    strcpy(oldStr, str);
    }
    free(str);
    free(oldStr);

    return count;

}

int partTwo(){

    FILE *input = fopen("input.md", "r");

    char *str1 = calloc(10, sizeof(char));
    char *str2 = calloc(10, sizeof(char));
    char *str3 = calloc(10, sizeof(char));

    int count = 0;
    int sum1 = 0;
    int sum2 = 0;

    //initialising the strings
    fgets(str1, 10, input);
    strcpy(str3, str1);
    fgets(str1, 10, input);
    strcpy(str2, str1);
    fgets(str1, 10, input);
    sum2 = atoi(str1) + atoi(str2) + atoi(str3);
    strcpy(str3, str2);
    strcpy(str2, str1);

    while(fgets(str1, 10, input)){
        
        sum1 = atoi(str1) + atoi(str2) + atoi(str3);

        if(sum2 < sum1){
            count++;
        }

        sum2 = sum1;
        strcpy(str3, str2);
        strcpy(str2, str1);
    
    }

    free(str1);
    free(str2);
    free(str3);

    return count;
}

int main(int argc, char **argv) {

    printf("part One: '%d'\n", partOne());

    printf("part Two: '%d'\n", partTwo());

    return 0;
}
