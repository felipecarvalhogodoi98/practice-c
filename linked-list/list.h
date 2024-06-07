#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef LINKED_LIST
#define LINKED_LIST

typedef int Data;

struct Node
{
  Data data;
  struct Node* next;
};

typedef struct 
{
  struct Node* head;
} List;

List* create_list();
void destory_list(List* list);
void print(List* list);
void printDebug(List* list);
int size(List* list);
bool empty(List* list);
Data value_at(List* list, int index);
void push_front(List* list, Data value);
Data pop_front(List* list);
void push_back(List* list, Data value);
Data pop_back(List* list);
Data front(List* list);
Data back(List* list);
void insert(List* list, int index, Data value);
Data erase(List* list, int index);
Data value_n_from_end(List* list, int n);
void reverse(List* list);
void remove_value(List* list, Data value);

#endif