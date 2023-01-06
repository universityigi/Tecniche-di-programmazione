#include "insf_scl.h"
#include <stdio.h>
#include <stdlib.h>

Insieme init(int *arr, int n);
void print(Insieme s);
Insieme copy(Insieme s);
int size(Insieme s);
bool subset(Insieme a, Insieme b);
bool equal(Insieme a, Insieme b);
Insieme intersection(Insieme a, Insieme b);
Insieme union1(Insieme a, Insieme b);

int main(){
  T arr1[5] = {1, 2, 3, 3, 5};
  T arr2[4] = {3, 3, 1, 7};
  Insieme ins1 = init(arr1, 5); printf("INSIEME1 = ");print(ins1);
  Insieme ins2 = copy(ins1); printf("INSIEME2 = "); print(ins2);
  Insieme ins3 = init(arr2, 4); printf("INSIEME3 = "); print(ins3);
  printf("SIZE2 = %d\n", size(ins2));
  printf("SIZE3 = %d\n", size(ins2));
  printf("SUBSET = %d\n", subset(ins3, ins1));
  printf("EQUAL = %d\n", equal(ins3, ins1));
  Insieme inters = intersection(ins1, ins3);printf("INTERSECT = "); print(inters);
  Insieme unione1 = union1(ins1, ins3); printf("UNION = "); print(unione1);
  return 0;
}

Insieme init(T *arr, int n){
  if (n==0) return insiemeVuoto();
  else return inserisci(init(arr+1,n-1), *arr);
}

void print_aux(IteratoreInsieme it){
  if (!hasNext(it)) printf("\n");
  else{
    T value = next(it);
    printf("%d ",value);
    print_aux(it);
  }
}

void print(Insieme s){
  IteratoreInsieme it = creaIteratoreInsieme(s);
  print_aux(it);
}

Insieme copy_aux(IteratoreInsieme it)
{
  if (!hasNext(it)) return insiemeVuoto();
  else{
    T value = next(it);
    return inserisci(copy_aux(it), value);
  }
}

Insieme copy(Insieme s){
  IteratoreInsieme it = creaIteratoreInsieme(s);
  return copy_aux(it);
}

int size(Insieme s){
  int num = 0;
  IteratoreInsieme it = creaIteratoreInsieme(s);
  while(hasNext(it)){
    num++;
    next(it);
  }
  return num * sizeof(int);
}

bool subset_aux(IteratoreInsieme it, Insieme b){
  if (!hasNext(it)) return 1;
  else{
    T elem = next(it);
    return (membro(b, elem)) && subset_aux(it, b);
  }
}

bool subset(Insieme a, Insieme b){
  IteratoreInsieme it = creaIteratoreInsieme(a);
  return subset_aux(it, b);
}

bool equal(Insieme a, Insieme b){
  return subset(a, b) && subset(b, a);
}

Insieme intersection_aux(IteratoreInsieme it_a, Insieme b){
  if (!hasNext(it_a)) return insiemeVuoto();
  else{
    T val = next(it_a);
    if (membro(b, val)) return inserisci(intersection_aux(it_a, b), val);
    else return intersection_aux(it_a, b);
  }
}

Insieme intersection(Insieme a, Insieme b){
  if (estVuoto(a)) return insiemeVuoto();
  else{
    IteratoreInsieme it = creaIteratoreInsieme(a);
    return intersection_aux(it, b);
  }
}

Insieme union1_aux(IteratoreInsieme it_a, Insieme b){
  if (!hasNext(it_a)) return b;
  else{
    T val = next(it_a);
    return inserisci(union1_aux(it_a,b), val);
  }
}

Insieme union1(Insieme a, Insieme b){
  IteratoreInsieme it = creaIteratoreInsieme(a);
  return union1_aux(it, b);
}
