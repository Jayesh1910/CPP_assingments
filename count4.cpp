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
     
    while(ch != EOF){ 
        ch = fgetc(fptr); 
        if((e == 's' && ch == ' ') || (e == 's' && ch == '.')){ 
            count++; 
        }else{ 
            e = ch; 
        } 
    } 
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
 
    cout << "No of word that ends with s is : " << WordCount; 
 
    fclose(fptr); 
 
    return 0; 
}