#include "queue.c"

int main () {
  Queue* q = create();
  print(q);

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);

  print(q);

  printf("dequeue: %d\n", dequeue(q));
  printf("dequeue: %d\n", dequeue(q));
  printf("dequeue: %d\n", dequeue(q));
  printf("dequeue: %d\n", dequeue(q));

  print(q);


  return 0;
}