#include "list.h"

List* create_list() {
  List* list = malloc(sizeof(List));
  if (list == NULL) {
    printf("Unable to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  list->head = NULL;
  return list;
}

void destory_list(List* list) {
  struct Node* temp = list->head;
  list->head = NULL;
  while (temp != NULL) {
    struct Node* cur = temp;

    temp = temp->next;

    free(cur);
  }
}

void print(List* list) {
  struct Node* node = list->head;

  while (node != NULL) {
    printf("%d", node->data);
    if (node->next != NULL) {
      printf("->");
    }
    node = node->next;
  };
  printf("\n");
}

void printDebug(List* list) {
  printf("----------------\n");
  printf("Size: %d\n", size(list));
  printf("Empty: %d\n", empty(list));
  print(list);
}

int size(List* list) {
  struct Node* node = list->head;
  int i = 0;

  while (node != NULL) {
    node = node->next;
    i++;
  };

  return i;
}

bool empty(List* list) {
  return list->head == NULL;
}

Data value_at(List* list, int index) {
  struct Node* temp = list->head;
  int i=0;
  while (i != index && temp != NULL) {
    temp = temp->next;
    i++;
  }

  if (temp == NULL) {
    printf("Index of bound.\n");
    exit(EXIT_FAILURE);
  }

  return temp->data;
}

void push_front(List* list, Data value) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = list->head;
  list->head = newNode;
}

void push_back(List* list, Data value) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = value;
  newNode ->next = NULL;

  if (list->head == NULL) list->head = newNode;
  else {
    struct Node* temp = list->head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

Data pop_front(List* list) {
  if (list->head == NULL) {
    printf("Cannot pop from empty list.\n");
    exit(EXIT_FAILURE);
  }

  struct Node* first = list->head;
  Data data = first->data;
  
  if (first->next != NULL) list->head = first->next;
  else list->head = NULL;

  free(first);
  return data;
}

Data pop_back(List* list) {
  if (list->head == NULL) {
    printf("Cannot pop from empty list.\n");
    exit(EXIT_FAILURE);
  }

  struct Node* temp = list->head;
  struct Node* last = NULL;

  while (temp->next != NULL) {
    last = temp;
    temp = temp->next;
  }
  Data data = temp->data;
  if (last != NULL) last->next = NULL;
  else list->head = NULL;
  free(temp);

  return data;
}

Data front(List* list) {
  if (empty(list)) {
    printf("Cannot front from empty list.\n");
    exit(EXIT_FAILURE);
  }

  return list->head->data;
}

Data back(List* list) {
  if (empty(list)) {
    printf("Cannot back from empty list.\n");
    exit(EXIT_FAILURE);
  }

  struct Node* temp = list->head;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  return temp->data;
}

void insert(List* list, int index, Data value) {
  struct Node* temp = list->head;
  struct Node* last = NULL;
  int i = 0;

  while (i != index && temp != NULL) {
    last = temp;
    temp = temp->next;
    i++;
  }

  if (i != index) {
    printf("Index of bound.\n");
    exit(EXIT_FAILURE);
  }

  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = temp;
  if (last != NULL )last->next = newNode;
  else list->head = newNode;
}

Data erase(List* list, int index) {
  struct Node* temp = list->head;
  struct Node* last = NULL;
  int i = 0;

  while (i != index && temp != NULL) {
    last = temp;
    temp = temp->next;
    i++;
  }

  if (temp == NULL) {
    printf("Index of bound.\n");
    exit(EXIT_FAILURE);
  }
  
  if (last != NULL)last->next = temp->next;
  else list->head = temp->next;
  Data data = temp->data;
  free(temp);

  return data;
}

Data value_n_from_end(List* list, int n) {
  int sizeList = size(list) - 1;

  if (n > sizeList) {
    printf("Index of bound.\n");
    exit(EXIT_FAILURE);
  }

  int index = sizeList - n;
  struct Node* temp = list->head;

  while (index > 0) {
    temp = temp->next;
    index --;
  }

  return temp->data;
}

void reverse(List* list) {
  struct Node* previous = list->head;
  struct Node* current = NULL;
  struct Node* next = NULL;

  if (previous != NULL) {
    current = previous->next;
    previous->next = NULL;
  }
  if (current != NULL) next = current->next;

  while (current != NULL) {
    current->next = previous;
    previous = current;
    current = next;
    if (next != NULL) next = next->next;
  }

  list->head = previous;
}

void remove_value(List* list, Data value) {
  struct Node* node = list->head;
  bool removed = false;
  int i = 0;
  while (node != NULL && !removed) {
    if (node->data == value) {
      erase(list, i);
      removed = true;
    }
    node = node->next;
    i++;
  }
}
