#include <stdbool.h>
#include <stdio.h>

#ifndef F_QUEUE
#define F_QUEUE

typedef struct QueueNode
{
  int data;
  struct QueueNode *prev;
  struct QueueNode *next;
} QueueNode;

typedef struct 
{
  QueueNode* head;
  QueueNode* tail;
} Queue;

Queue *create();
void enqueue(Queue* q, int item);
int dequeue(Queue* q);
bool empty(Queue* q);
void print(Queue* q);

#endif