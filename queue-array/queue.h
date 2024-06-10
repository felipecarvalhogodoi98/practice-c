#include <stdbool.h>
#include <stdio.h>

#ifndef F_QUEUE
#define F_QUEUE

#define sizeQueue 4

typedef struct 
{
  int data[sizeQueue];
  int remove;
  int insert;
  int capacity;
} Queue;

Queue *create();
void enqueue(Queue* q, int item);
int dequeue(Queue* q);
bool empty(Queue* q);
bool full(Queue* q);
void print(Queue* q);

#endif