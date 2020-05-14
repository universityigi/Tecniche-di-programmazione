#include "correttore_esercizio3.h"
#include <stdlib.h>
#include <stdio.h>

void printString(char* string) {
  if(string == NULL)
    return;
  while(*string != '\0') {
    printf("%c", *string);
    string++;
  }
  printf("\n");
  fflush(stdout);
}

char* copyString(char* string, int *size){  
  if(string == NULL){
    *size = 0;
    return NULL;
  }

  int dimension = getStringSize(string);
  *size = dimension;
  
  int id = 0;
  char* copy = (char*)calloc(' ',dimension*sizeof(char));
  while(*string != '\0'){
    copy[id] = *string;
    ++id;
    string++;
  }
  return copy;
}

char* getInfo(int id, char* c){
  if(id == 0){
    char* string = "Use gcc to compile your C programs.";
    *c = 'C';
    return string;
  }
  if(id == 1){
    char* string1 = "Use emacs to edit your Programs.";
    *c = 'P';
    return string1;
  }
  if(id == 2){
    char* string2 = "Use firefox to navigate the Internet.";
    *c = 'I';
    return string2;
  }
  if(id == 3){
    char* string3 = "Use Ubuntu instead of Windows.";
    *c = 'U';
    return string3;
  }
  if(id == 4){
    char* string4 = "Use Ubuntu instead of Windows.";
    *c = 'W';
    return string4;
  }
  if(id == 5){
    char* string5 = "Turn Off your Computer.";
    *c = 'O';
    return string5;
  }
  if(id == 6){
    char* string6 = "Turn Off your Computer.";
    *c = 'f';
    return string6;
  }
  if(id == 7){
    char* string7 = "Turn Off your Computer.";
    *c = 'T';
    return string7;
  }
  if(id == 8){
    char* string8 = "Enjoy tecniche di Programmazione.";
    *c = 'm';
    return string8;
  }
  if(id == 9){
    char* string9 = "Enjoy tecniche di Programmazione.";
    *c = 'e';
    return string9;
  }
  return NULL;
}


int getStringSize(char* string){
  if(string == NULL)
    return 0;
  int size = 0;
  while(*string != '\0'){
    ++size;
    string++;
  }
  return size;
}

void removeCharSolution(char* string, char c, char* result){

  if(*string == '\0')
    return;
  
  if(*string != c){
    *result = *string;
    result++;   
  }
  string++; 
  removeCharSolution(string, c, result);
  
}

int checkIfGood(char* string, char c, char* student_out){

  int string_size = getStringSize(string);
  char* good_out = (char*)calloc(' ',string_size*sizeof(char));
  removeCharSolution(string, c, good_out);

  printf("Expected Result\n");
  printString(good_out);
  printf("Computed Result\n");
  printString(student_out);
  fflush(stdout);
  
  if(!good_out && !student_out)
    return 1;

  
  for(int i=0; i < string_size; ++i){
    if(good_out[i] != student_out[i]){
      free(good_out);
      return 0;
    }
  }
  
  free(good_out); 
  return 1; 
}

