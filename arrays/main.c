#include "array.c"

void printTestMethod(char *method, bool cond) {
  if (cond) {
    printf("%s method success.\n", method);
  } else {
    printf("%s method error.\n", method);
  }
}

void fillArray(Array *arr, int size) {
  for(int i = 0; i < size; i++) {
    push(arr, i);
  }
}

void tests() {
  Array *arr = newArray(4);
  int sizeArr = 31;

  fillArray(arr, sizeArr);

  toString(arr);

  printTestMethod("at", at(arr, 5) == 5);
  printTestMethod("size", size(arr) == capacity(arr));
  printTestMethod("capacity", size(arr) == capacity(arr));
  
  // Push
  int valueToPush = 300;
  push(arr, valueToPush);
  printTestMethod("push", at(arr, size(arr) - 1) == valueToPush);

  // Insert
  int valueToInsert = 222;
  int indexToInsert = 23;
  insert(arr, indexToInsert, valueToInsert);
  printTestMethod("insert", at(arr, indexToInsert) == valueToInsert);

  // Prepend
  int valueToPrepend = 152;
  prepend(arr, valueToPrepend);
  printTestMethod("prepend", at(arr, 0) == valueToPrepend);

  // Pop
  valueToPush = 125;
  push(arr, valueToPush);
  int popValue = pop(arr);
  printTestMethod("pop", popValue == valueToPush);

  // Remove By index
  int valueToRemoveIndex = 1126;
  int indexToRemove = 8;
  insert(arr, indexToRemove, valueToRemoveIndex);
  int valueRemoved = removeByIndex(arr, indexToRemove);
  printTestMethod("pop", 
    at(arr, indexToRemove) != valueRemoved &&
    valueToRemoveIndex == valueRemoved
  );

  // Remove Value
  int valueToRemove = 758;
  insert(arr, 1, valueToRemove);
  insert(arr, 8, valueToRemove);
  insert(arr, 16, valueToRemove);
  push(arr, valueToRemove);
  removeValue(arr, valueToRemove);
  printTestMethod("removeValue", 
    valueToRemove != at(arr, size(arr)-1) &&
    valueToRemove != at(arr, 1) &&
    valueToRemove != at(arr, 8) &&
    valueToRemove != at(arr, 16)
  );

  // Resize shrink
  int currentCapacity = capacity(arr);
  int currentSize = size(arr);
  while (currentSize + 1 > currentCapacity / shrinkFactor) {
    pop(arr);
    currentSize = size(arr);
  }
  printTestMethod("intern method resize shrink", 
    capacity(arr) == currentCapacity/growthFactor
  );

  // Resize growth
  currentCapacity = capacity(arr);
  currentSize = size(arr);
  while (currentCapacity >= capacity(arr)) {
    push(arr, 1);
  }
  printTestMethod("intern method resize growth", 
    capacity(arr) == currentCapacity * growthFactor
  );

  array_destroy(arr);
}

int main(int argc, char* argv[]) {
  tests();
  return EXIT_SUCCESS;
}

