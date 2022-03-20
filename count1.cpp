#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define BUFFER_SIZE 1000 
 
int CountTheWord(FILE *fptr, const char *word) 
{ 
    char str[BUFFER_SIZE]; 
    char *pos; 
 
    int index, count; 
     
    count = 0; 
 
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL) 
    { 
        index = 0; 
 
        while ((pos = strstr(str + index, word)) != NULL) 
        { 
            index = (pos - str) + 1; 
            count++; 
        } 
    } 
    return count; 
} 
 
 
 
int main() 
{ 
    FILE *fptr; 
    char word[50]; 
    int WordCount; 
 
    printf("Enter word to search in the file: "); 
    scanf("%s", word); 
 
 
    fptr = fopen("demo.txt", "r"); 
 
    if (fptr == NULL) 
    { 
        printf("Unable to open file.\n"); 
        exit(0); 
    } 
 
    WordCount = CountTheWord(fptr, word); 
 
    printf("'%s' is found %d times in file.", word, WordCount); 
 
    fclose(fptr); 
 
    return 0; 
}