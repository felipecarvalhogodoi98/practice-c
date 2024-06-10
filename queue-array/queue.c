
#include <stdlib.h>
#include "queue.h"

Queue *create() {
  Queue* queue = malloc(sizeof(Queue));
  queue->remove = -1;
  queue->insert = -1;
  queue->capacity = sizeQueue;

  return queue;
}

void enqueue(Queue* q, int item) {
  if (full(q)) {
    printf("Cannot insert on full queue.\n");
    exit(EXIT_FAILURE);
  }

  if (empty(q)) {
    q->remove = 0;
    q->insert = 0;
  }  

  q->data[q->insert] = item;
  q->insert = (q->insert + 1) % q->capacity;
}

int dequeue(Queue* q) {
  if (empty(q)) {
    printf("Cannot dequeue on empty queue.\n");
    exit(EXIT_FAILURE);
  }

  int data = q->data[q->remove];

  q->remove = (q->remove + 1) % q->capacity;

  if (q->remove == q->insert) {
    q->remove = q->insert = -1;
  }

  return data;
}

bool empty(Queue* q) {
  return q->remove == -1;
}

bool full(Queue* q) {
  return q->remove == q->insert && q->remove != -1;
}

void print(Queue* q) {
  printf("__________________\n");
  printf("Remove: %d\n", q->remove);
  printf("Insert: %d\n", q->insert);
  printf("Capacity: %d\n", q->capacity);

  if (!empty(q))
    for (int i = 0; i < q->capacity; i++) {
      if (q->remove < q->insert)

        if (i >= q->remove && i < q->insert || full(q))
          printf("%d ", q->data[i]);
        else 
          printf("- ");

      else
        if (i >= q->remove || i < q->insert || full(q))
          printf("%d ", q->data[i]);
        else 
          printf("- ");
    }
  else
    printf("Empty queue");
  
  printf("\n");
}
