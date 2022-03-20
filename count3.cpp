#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <iostream> 
using namespace std; 
 
#define BUFFER_SIZE 1000 
 
int CountTheWord(FILE *fptr) 
{ 
    char str[BUFFER_SIZE]; 
    char ch; 
 
    int count; 
 
    count = 0; 
    char e = '1'; 
    ch = fgetc(fptr); 
    if(ch == 'e'){ 
        count++; 
    } 
    do 
    { 
        ch = fgetc(fptr); 
        if(ch == 'e' && e == ' '){ 
            count++; 
        }else{ 
            e = ch; 
        } 
         
    } while (ch != EOF); 
 
    return count; 
} 
 
int main() 
{ 
    FILE *fptr; 
    char word[50]; 
    int WordCount; 
 
    fptr = fopen("demo.txt", "r"); 
 
    if (fptr == NULL) 
    { 
        printf("Unable to open file.\n"); 
        exit(0); 
    } 
 
    WordCount = CountTheWord(fptr); 
 
    cout << "No of word that starts with e is : " << WordCount; 
 
    fclose(fptr); 
 
    return 0; 
}