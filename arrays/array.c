#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

Array *newArray(int capacity) {
  int newCapacity = determine_capacity(capacity);

  Array *arr = malloc(sizeof(Array));

  arr->size = 0;
  arr->capacity = newCapacity;
  arr->data = (int *)malloc(sizeof(int) * newCapacity);

  verifyPtr(arr->data);

  return arr;
}

void array_destroy(Array *ptr) {
  free(ptr->data);
  free(ptr);
}

int size(Array *ptr) {
  return ptr->size; 
}

int capacity(Array *ptr) {
  return ptr->capacity; 
}

bool is_empty(Array *ptr) {
  return ptr->size == 0;
}

void push(Array *ptr, int value) {
  resize(ptr, ptr->size + 1);

  *(ptr->data + ptr->size++) = value;
}

void insert(Array *ptr, int index, int value) {
  if (index < 0 || index > ptr->size) {
    printf("Index invalid.\n");
    exit(EXIT_FAILURE);
  }

  resize(ptr, ptr->size + 1);

  int lastValue;

  for (int i=index; i < ptr->size + 1; i++) {
     lastValue = *(ptr->data + i);
     *(ptr->data + i) = value;
     value = lastValue;
  }

  ptr->size++;
}

void prepend(Array *ptr, int value) {
  insert(ptr, 0, value);
}

int pop(Array *ptr) {
  if (ptr->size == 0) {
    printf("Array is empty.\n");
    exit(EXIT_FAILURE);
  }

  int value = *(ptr->data + --ptr->size);

  resize(ptr, ptr->size);

  return value;
}

void removeValue(Array *ptr, int value) {
  int curruntValue;
  for (int i=0; i<ptr->size; i++) {
    curruntValue = *(ptr->data + i);
    if (value == curruntValue) {
      removeByIndex(ptr, i);
    }
  }
}

int removeByIndex(Array *ptr, int index) {
  if (index < 0 || index >= ptr->size) {
    printf("Index invalid.\n");
    exit(EXIT_FAILURE);
  }

  int value = *(ptr->data + index);
  
  resize(ptr, ptr->size - 1);
  memmove((ptr->data + index), (ptr->data + index+1), sizeof(int) * (ptr->size - index));

  --ptr->size;
  return value;
}

int at(Array *ptr, int index){
  if (index < 0 || index >= ptr->size) {
    printf("Index invalid.\n");
    exit(EXIT_FAILURE);
  }

  return *(ptr->data + index);
}

void toString(Array *ptr) {
  printf("-------------\n");
  printf("Size: %d.\n", size(ptr));
  printf("Capacity: %d.\n", capacity(ptr));

  if (is_empty(ptr)) 
    printf("Array is empty.\n");
  else {
    for (int i=0; i < ptr->size; i++) {
      int value = *(ptr->data + i);
      printf("%d ", value);
    }
    printf("\n");
  }
  printf("-------------\n");
}

int determine_capacity(int capacity) {
  if (capacity < minCapacity) return minCapacity;

  return capacity;
}

void resize(Array *ptr, int new_capacity) {
  int oldCapacity = ptr->capacity;
  if (new_capacity >= oldCapacity) {
    array_up_size(ptr);
  } else if (ptr->size < ptr->capacity / shrinkFactor) {
    array_down_size(ptr);
  }
}

void array_up_size(Array *ptr) {
  int newCapacity = determine_new_capacity(ptr->capacity);
  int *newData = (int *)realloc(ptr->data, sizeof(int) * newCapacity);

  verifyPtr(newData);

  ptr->data = newData;
  ptr->capacity = newCapacity;
}

void array_down_size(Array *ptr) { 
  int newCapacity = ptr->capacity / shrinkFactor;

  if (newCapacity < minCapacity) newCapacity = minCapacity;

  if (newCapacity == ptr->capacity) return;

  int *newData = (int *)realloc(ptr->data, sizeof(int) * newCapacity);

  verifyPtr(newData);

  ptr->data = newData;
  ptr->capacity = newCapacity;
}

int determine_new_capacity(int capacity) {
  int trueCapacity = 1;

  if (capacity < minCapacity) return minCapacity;

  while (capacity > trueCapacity / growthFactor) {
    trueCapacity *= growthFactor;
  }

  return trueCapacity;
}

void verifyPtr(void *ptr) {
  if (ptr == NULL) {
    printf("Failed to allocate memory.\n");
    exit(EXIT_FAILURE);
  }
}