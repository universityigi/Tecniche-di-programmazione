#pragma once
#include "char_list.h"

void printCharList(CharList* src);
void freeCharList(CharList* src);
CharList* getCharList(int id);
CharList* copyCharList(CharList* src);

int checkIfGood(CharList* src, int);
