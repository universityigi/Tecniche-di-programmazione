#ifndef _CHAR_LIST_
#define _CHAR_LIST_

typedef struct CharList
{
  char c;
  struct CharList* next;
} CharList;

#endif
