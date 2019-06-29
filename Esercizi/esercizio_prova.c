/// Implementazione lista tipo 1
/// Implementazione lista tipo 2 (120)
/// Implementazione stack 1 (230)
/// Implementazione stack 2 (310)
/// Implementazione stack 3 (390)
/// Implementazione queue 1 (480)

#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void printNode(ListNode *n)
{
  printf("Name : %s age : %d\n", n->info.name, n->info.age);  
}

ListNode *readNode()
{
  ListNode *n = newNode();
  printf("Inserisci il nome\n");
  scanf("%9s",n->info.name );
  printf("Inserisci l'età\n");
  scanf("%d",&(n->info.age) );
  
  return n;
}

ListNode *newNode()
{
  ListNode *n = (ListNode *)malloc(sizeof(ListNode));
  return n;
}

void freeNode(ListNode *n)
{
  free(n);
}

bool emptyLista(List list)
{
  if( list.head == NULL )
    return TRUE;
  else
    return FALSE;
}

ListNode *firstElem( List list )
{
  return list.head;
}

ListNode *lastElem(List list)
{
  if( emptyLista(list) == TRUE )
    return NULL;
  else
  {
    ListNode *e;
    for( e = list.head; ; e = e->next )
    {
      if( e->next == NULL ) 
        break;
    }
    return e;
  }
}

void deleteFirst(List *list)
{
  if( emptyLista(*list) == TRUE )
    return;
  
  ListNode *tmp = list->head;
  list->head = list->head->next;
  freeNode( tmp );
}

void deleteLast(List *list)
{
  if( emptyLista(*list) == TRUE )
    return;
  else if( list->head->next == NULL )
  {
    freeNode(list->head);
    list->head = NULL;
  }
  else
  {
    ListNode *e;     
    for( e = list->head; ; e = e->next )
    {
      if( e->next->next == NULL ) 
        break;
    }
    freeNode(e->next);
    e->next = NULL;
  }
}

void initLista(List *list)
{
  list->head = NULL;
}

void addElem(List *list, ListNode *e)
{
  e->next = list->head;
  list->head = e;
}

void printList(List list )
{
  for( ListNode *e = list.head; e != NULL ; e = e->next )
    printNode(e);
}



/// Implementazione lista 2

#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void printNode(ListNode *n)
{
  printf("Name : %s age : %d\n", n->info.name, n->info.age);  
}

ListNode *readNode()
{
  ListNode *n = newNode();
  printf("Inserisci il nome\n");
  scanf("%9s",n->info.name );
  printf("Inserisci l'età\n");
  scanf("%d",&(n->info.age) );
  
  return n;
}

ListNode *newNode()
{
  ListNode *n = (ListNode *)malloc(sizeof(ListNode));
  return n;
}

void freeNode(ListNode *n)
{
  free(n);
}

bool emptyLista(List list)
{
  if( list.head == NULL )
    return TRUE;
  else
    return FALSE;
}

ListNode *firstElem( List list )
{
  return list.head;
}

ListNode *lastElem(List list)
{
  return list.tail;
}

void deleteFirst(List *list)
{
  if( emptyLista(*list) == TRUE )
    return;
  
  ListNode *tmp = list->head;
  list->head = list->head->next;
  list->head->prev = NULL;
  freeNode( tmp );
}

void deleteLast(List *list)
{
  if( emptyLista(*list) == TRUE )
    return;
  
  ListNode *tmp = list->tail;
  list->tail = list->tail->prev;
  list->tail->next = NULL;
  freeNode( tmp );
}

void initLista(List *list)
{
  list->head = list->tail = NULL;
}

void addElemFront(List *list, ListNode *e)
{
  if( emptyLista(*list) == TRUE )
  {
    list->head = list->tail = e;
    e->next = e->prev = NULL;
  }
  else
  {
    e->next = list->head;
    list->head->prev = e;
    e->prev = NULL;
    list->head = e;
  }
}

void printList(List list )
{
  for( ListNode *e = list.head; e != NULL ; e = e->next )
    printNode(e);
}

void printListReverse(List list )
{
  for( ListNode *e = list.tail; e != NULL ; e = e->prev )
    printNode(e);
}




/// Implementazione Stack 1

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void printNode(StackNode *n)
{
  printf("Name : %s age : %d\n", n->info.name, n->info.age);  
}

StackNode *readNode()
{
  StackNode *n = newNode();
  printf("Inserisci il nome\n");
  scanf("%9s",n->info.name );
  printf("Inserisci l'età\n");
  scanf("%d",&(n->info.age) );
  
  return n;
}

StackNode *newNode()
{
  StackNode *n = (StackNode *)malloc(sizeof(StackNode));
  return n;
}

void freeNode(StackNode *n)
{
  free(n);
}

bool emptyStack(Stack stack)
{
  if( stack.head == NULL )
    return TRUE;
  else
    return FALSE;
}

StackNode *top( Stack stack )
{
  return stack.head;
}


void pop(Stack *stack)
{
  if( emptyStack(*stack) == TRUE )
    return;
  
  StackNode *tmp = stack->head;
  stack->head = stack->head->next;
  freeNode( tmp );
}


void initStack(Stack *stack)
{
  stack->head = NULL;
}

void push(Stack *stack, StackNode *e)
{
  e->next = stack->head;
  stack->head = e;
}

void printStack(Stack stack )
{
  if( emptyStack( stack ) )
    printf("Stack vuoto!");
  else
    for( StackNode *e = stack.head; e != NULL ; e = e->next )
      printNode(e);
}


/// Implementazione Stack 2

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void printData(Data data)
{
  printf("Name : %s age : %d\n", data.name, data.age);  
}


Data readData()
{
  Data data;
  printf("Inserisci il nome\n");
  scanf("%9s",data.name );
  printf("Inserisci l'età\n");
  scanf("%d",&(data.age) );
  
  return data;
}

void initStack(Stack *stack)
{
  stack->pos = -1;
}

bool emptyStack(Stack stack)
{
  if( stack.pos == -1 )
    return TRUE;
  else
    return FALSE;
}

Data top( Stack stack )
{
  if( emptyStack(stack) == FALSE )
    return stack.data[stack.pos];
  else
  {
    printf("Stack vuoto!");
    exit(EXIT_FAILURE);
  }
}


void pop(Stack *stack)
{
  if( emptyStack(*stack) == FALSE )
    stack->pos--;
}

void push(Stack *stack, Data d)
{
  if( stack->pos + 1 < STACK_MAX_SIZE )
  {
    stack->pos++;
    stack->data[stack->pos] = d;
  }
  else
    printf("Stack pieno!");
  
}

void printStack(Stack stack )
{
  if( emptyStack( stack ) == TRUE )
    printf("Stack vuoto!");
  else
    for( int i = stack.pos; i >= 0; i-- )
      printData(stack.data[i]);
}





/// Implementazione stack 3


#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void printData(Data data)
{
  printf("Name : %s age : %d\n", data.name, data.age);  
}


Data readData()
{
  Data data;
  printf("Inserisci il nome\n");
  scanf("%9s",data.name );
  printf("Inserisci l'età\n");
  scanf("%d",&(data.age) );
  
  return data;
}

void initStack(Stack *stack)
{
  stack->data = malloc(STACK_INIT_SIZE*sizeof(Data));
  stack->pos = -1;
  stack->size = STACK_INIT_SIZE;
}

bool emptyStack(Stack stack)
{
  if( stack.pos == -1 )
    return TRUE;
  else
    return FALSE;
}

Data top( Stack stack )
{
  if( emptyStack(stack) == FALSE )
    return stack.data[stack.pos];
  else
  {
    printf("Stack vuoto!");
    exit(EXIT_FAILURE);
  }
}


void pop(Stack *stack)
{
  if( emptyStack(*stack) == FALSE )
    stack->pos--;
}

void push(Stack *stack, Data d)
{
  if( stack->pos + 1 >= stack->size )
  {
    int new_size = 2*stack->size;
    Data *tmp_data = realloc(stack->data, new_size*sizeof(Data));
    if( tmp_data == NULL )
    {
      printf("realloc() failed!");
      return;
    }
    
    stack->data = tmp_data;
    stack->size = new_size;
  }
  
  stack->pos++;
  stack->data[stack->pos] = d;
}

void printStack(Stack stack )
{
  if( emptyStack( stack ) == TRUE )
    printf("Stack vuoto!");
  else
    for( int i = stack.pos; i >= 0; i-- )
      printData(stack.data[i]);
}




//// Implementazione queue 1


#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void printData(Data data)
{
  printf("Name : %s age : %d\n", data.name, data.age);  
}


Data readData()
{
  Data data;
  printf("Inserisci il nome\n");
  scanf("%9s",data.name );
  printf("Inserisci l'età\n");
  scanf("%d",&(data.age) );
  
  return data;
}


// Inizializza una coda vuota
void initQueue( Queue *q )
{
  q->first = q->last = -1;
}
// Restituisce TRUE se la coda è vuota
bool emptyQueue( Queue q )
{
  if( q.first == -1 )
    return TRUE;
  else
    return FALSE;
}

// Restituisce TRUE se la coda è piena
bool fullQueue( Queue q )
{
  if( q.last - q.first == QUEUE_MAX_SIZE - 1 || 
      q.first - q.last == 1 )
    return TRUE;
  else
    return FALSE;
}

// Inserisce un elemento in testa 
void enqueue( Queue *q, Data d)

{
  if( fullQueue( *q ) == TRUE )
  {
    printf("Full queue!\n");
    return;
  }
  
  if( emptyQueue(*q) == TRUE )
  {
    q->first = q->last = 0;
  }
  else
  {
    q->last = q->last +1;
    q->last = q->last%QUEUE_MAX_SIZE;
  }
  q->data[q->last] = d;
}

// Estrae un elemento in coda
void dequeue( Queue *q, Data *d)

{
  if( emptyQueue( *q ) == TRUE )
  {
    printf("Empty queue!\n");
    return;
  }
  
  *d = q->data[q->first];
  if( q->first == q->last )
    q->first = q->last = -1;
  else
  {
    q->first = q->first +1;
    q->first = q->first%QUEUE_MAX_SIZE;  
  }
}

void printQueue(Queue q)
{
  if( emptyQueue( q ) == TRUE )
  {
    printf("Empty queue!\n");
    return;
  }
  int i = q.first;
  while( i <= q.last )
  {
    printData(q.data[i]);
    i = (i + 1)%QUEUE_MAX_SIZE;  
  }
}