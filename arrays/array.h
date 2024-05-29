#include <stdbool.h>

int minCapacity = 4;
int growthFactor = 2;
int shrinkFactor = 2;

typedef struct {
  int *data;
  int capacity;
  int size;
} Array;

// Contructs
Array *newArray(int capacity);
// Destroy array
void array_destroy(Array *ptr);
// Return array size
int size(Array *ptr);
// Return array capacity
int capacity(Array *ptr);
// Return capacity determined for minCapacity. Private
int determine_capacity(int capacity);
// Return true or false if array is empty
bool is_empty(Array *ptr);
// Return value on array at index
int at(Array *ptr, int index);
// Insert value on array
void push(Array *ptr, int value);
// Insert value on array at index
void insert(Array *ptr, int index, int value);
// Insert value on array at index 0
void prepend(Array *ptr, int value);
// Remove last item from array 
int pop(Array *ptr);
// Remove all ocurrences of value on array
void removeValue(Array *ptr, int value);
// Remove value at index
int removeByIndex(Array *ptr, int index);
// Resize array with new capacity
void resize(Array *ptr, int new_capacity);
// Growth array capacity
void array_up_size(Array *ptr);
// Shrink array capacity
void array_down_size(Array *ptr);
//Find the new capacity for array growth
int determine_new_capacity(int capacity);
// Print array and otrhers infos
void toString(Array *ptr);
// Verify if ptr is null
void verifyPtr(void *ptr);
