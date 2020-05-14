#include "correttore_esercizio1.h"
#include <stdlib.h>
#include <stdio.h>

void printCharList(CharList* src) {
  while(src != NULL) {
    printf("%c", src->c);
    src = src->next;
  }
  printf("\n");
  fflush(stdout);
}


void freeCharList(CharList* src) {
  if(!src)
    return;
  CharList* head = src;
  while(src != NULL){
    src = src->next;
    free(head);
    head = src;
  }
}

char* getStr(int id, int *size){  
  if(id == 0){
    char* anna = "anna";
    *size = 4;
    return anna;    
  }
  else if(id == 1){
    char* giorgio = "giorgio";
    *size = 7;
    return giorgio;    
  }
  else if(id == 2){
    char* alberto = "alberto";
    *size = 7;
    return alberto;    
  }
  else if(id == 3){
    char* bob = "bob";
    *size = 3;
    return bob;    
  }
  else if(id == 4){
    char* daniele = "daniele";
    *size = 7;
    return daniele;    
  }
  else if(id == 5){
    char* ottetto = "ottetto";
    *size = 7;
    return ottetto;    
  }
  else if(id == 6){
    char* bartolomeo = "bartolomeo";
    *size = 10;
    return bartolomeo;    
  }
  else if(id == 7){
    char* itopinonavevanonipoti = "itopinonavevanonipoti";
    *size = 21;
    return itopinonavevanonipoti;    
  }
  else if(id == 8){
    char* palindromo = "palindromo";
    *size = 10;
    return palindromo;    
  }
  else if(id == 9){
    char* kayak = "kayak";
    *size = 5;
    return kayak;    
  }
  return NULL;
}


CharList* getCharList(int id) {
  CharList* str = (CharList*)malloc(sizeof(CharList));
  str->next = NULL;
  CharList* head = str;
  
  int str_size = 0;
  char* char_str = getStr(id, &str_size);
  for(int i = 0; i < str_size; ++i){
    str->c = char_str[i];
    if(i != str_size-1){
      str->next = (CharList*)malloc(sizeof(CharList));
      str->next->next = NULL;
      str = str->next;
    }
  }
  return head;
}


CharList* copyCharList(CharList* src){
  if(!src)
    return NULL;
  CharList* copy = (CharList*)malloc(sizeof(CharList));
  CharList* head = copy;
  while(src != NULL){
    copy->c = src->c;
    copy->next = NULL;

    if(src->next != NULL){
      copy->next = (CharList*)malloc(sizeof(CharList));
    }
    copy = copy->next;
    src = src->next;
  }
  return head;
}


int isPalindromeSolution(CharList* src){
  CharList* head = src;
  // get size
  int size=0;
  while(src != NULL){
    src = src->next;
    ++size;
  }
  // get reverted string
  char* str = malloc(size*sizeof(char));
  src = head;
  while(src != NULL){
    str[size-1] = src->c;
    src = src->next;
    --size;
  }
  // compare list with string
  size = 0;
  while(head != NULL){
    if(head->c != str[size]){
      free(str);
      return 0;
    }
    head = head->next;
    ++size;
  }
  free(str);
  return 1;
  
}


int checkIfGood(CharList* src, int stud_solution){
  int solution = isPalindromeSolution(src);
  printf("is Palindrome[solution/student]: ");
  if(solution)
    printf("YES/");
  else
    printf("NO/");
  if(stud_solution)
    printf("YES");
  else
    printf("NO");
  printf("\n");
  
  if(solution != stud_solution)
    return 0;
  return 1;
}
