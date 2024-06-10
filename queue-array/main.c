#include "queue.c"
#include "queue.h"

int main() {
  Queue* q = create();
  print(q);
  for (int i = 0; i < sizeQueue; i++) {
    enqueue(q, i);
    print(q);
  }

  printf("removed: %d\n", dequeue(q));
  printf("removed: %d\n", dequeue(q));
  print(q);
  enqueue(q, 5);
  print(q);
  printf("removed: %d\n", dequeue(q));
  print(q);

  enqueue(q, 6);
  print(q);
  printf("removed: %d\n", dequeue(q));
  print(q);

  enqueue(q, 7);
  print(q);
  printf("removed: %d\n", dequeue(q));
  print(q);

  printf("removed: %d\n", dequeue(q));
  printf("removed: %d\n", dequeue(q));
  // printf("removed: %d\n", dequeue(q));

  return 0;
}