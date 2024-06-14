#include <stdio.h>
#include <assert.h>
#include "binary-search.h"
#include "binary-search.c"

int main (int argc, char* argv[]) {
  int array[10] = {4,9,10,17,25,47,50,65,68,99};
  
  for (int i = 0; i < 10; i++) {
    int index = binary_search(array[i], array, 0, 9);
    assert(index == i);
  }

  int index = binary_search(1899, array, 0, 9);
  assert(index == -1);

  index = binary_search(8, array, 0, 9);
  assert(index == -1);

  index = binary_search(51, array, 0, 9);
  assert(index == -1);
  
  return 0;
}