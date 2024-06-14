#include "binary-search.h"

int binary_search(int key, int* array, int min, int max) {
  if (max < min) return -1;

  int mid = findMid(min, max);

  if (array[mid] < key)
    return binary_search(key, array, mid + 1, max);
  else if (array[mid] > key)
    return binary_search(key, array, min, mid - 1);
  
  return mid;
}

int findMid(int min, int max) {
  return (min + max) / 2;
}