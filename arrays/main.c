#include "array.c"

int main(int argc, char* argv[]) {
  Array *arr = newArray(4);
  
  printf("Array size: %d.\n", size(arr));
  printf("Array capacity: %d.\n", capacity(arr));
  toString(arr);
  insert(arr, 0, 1);
  insert(arr, 1, 5);
  insert(arr, 2, 6);
  insert(arr, 1, 2);
  insert(arr, 2, 3);
  insert(arr, 3, 4);
  toString(arr);

  array_destroy(arr);

  return 0;
}