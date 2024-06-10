
#include <stdlib.h>
#include "queue.h"

Queue *create() {
  Queue* queue = malloc(sizeof(Queue));

  if (queue == NULL) {
    printf("Unable to allocate memmory.\n");
    exit(EXIT_FAILURE);
  }

  queue->head = NULL;
  queue->tail = NULL;

  return queue;
}

void enqueue(Queue* q, int item) {
  QueueNode* newNode = malloc(sizeof(QueueNode));
  newNode->data = item;
  newNode->next = NULL;
  newNode->prev = NULL;
  
  if (q->head == NULL) {
    q->head = newNode;
    q->tail = newNode;
  } else {
    q->tail->next = newNode;
    newNode->prev = q->tail;
    q->tail = newNode;
  }
}

int dequeue(Queue* q) {
  if (empty(q)) {
    printf("Cannot dequeue from empty queue\n");
    exit(EXIT_FAILURE);
  }

  int dataDequeue =  q->head->data;
  QueueNode* temp = q->head;
  
  if (q->head == q->tail) {
    q->head = q->tail = NULL;
  } else {
    q->head->next->prev = NULL;
    q->head = q->head->next; 
  }

  free(temp);
  return dataDequeue;
}

bool empty(Queue* q) {
  return q->head == NULL;
}

void print(Queue* q) {
  QueueNode* aux = q->head;

  if (empty(q)) printf("Empty queue");

  while (aux != NULL) {
    printf("%d->", aux->data);
    aux = aux->next;
  }

  printf("\n");
}
