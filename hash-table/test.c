#include <assert.h>
#include <time.h>
#include "test.h"
#include "hash.c"


#define initialCapacity 16

void runTests() {
  srand(time(NULL)); 

  getTest();
  existsTest();
  addTest();
  removeTest();
  growCapacityTest();
  shrinkCapacityTest();
}

void getTest() {
  HashTable* hash = createHashTable(initialCapacity);
  Item* item = generateItem();

  add(&hash, item->key, item->value);

  assert(strcmp(get(hash, item->key)->key, item->key) == 0);
  removeItem(&hash, item->key);
  assert(get(hash, item->key) == NULL);
}

void existsTest() {
  HashTable* hash = createHashTable(initialCapacity);
  Item* item = generateItem();

  add(&hash, item->key, item->value);

  assert(exists(hash, item->key));
  removeItem(&hash, item->key);
  assert(!exists(hash, item->key));
}

void addTest() {
  HashTable* hash = createHashTable(initialCapacity);
  
  for (int i = 0; i < initialCapacity/2; i++){
    Item* item = generateItem();
    add(&hash, item->key, item->value);
  }

  assert(hash->size == initialCapacity/2);
}

void removeTest() {
  HashTable* hash = createHashTable(initialCapacity);
  char* newKey = (char*)malloc((2) * sizeof(char));
  newKey[1] = '\0';

  for (int i = 0; i < initialCapacity/2; i++){
    newKey[0] = charset[i];
    Item* item = generateItem();
    add(&hash, newKey, item->value);
  }

  for (int i = 0; i < initialCapacity/2; i++){
    newKey[0] = charset[i];
    assert(exists(hash, newKey));
    removeItem(&hash, newKey);
    assert(!exists(hash, newKey));
  }  
}

void growCapacityTest() {
  HashTable* hash = createHashTable(initialCapacity);
  
  for (int i = 0; i < initialCapacity - 1; i++){
    Item* item = generateItem();
    add(&hash, item->key, item->value);
  }

  assert(hash->size == initialCapacity - 1);
  assert(hash->capacity == initialCapacity);

  for (int i = 0; i < 2; i++){
    Item* item = generateItem();
    add(&hash, item->key, item->value);
  }

  assert(hash->size == initialCapacity + 1);
  assert(hash->capacity == initialCapacity * growFactor);
}

void shrinkCapacityTest() {
  HashTable* hash = createHashTable(initialCapacity);
  char* newKey = (char*)malloc((2) * sizeof(char));
  newKey[1] = '\0';
  
  for (int i = 0; i < initialCapacity - 1; i++){
    newKey[0] = charset[i];
    Item* item = generateItem();
    add(&hash, newKey, item->value);
  }

  assert(hash->size == initialCapacity - 1);
  assert(hash->capacity == initialCapacity);

  for (int i = 0; i < initialCapacity - (initialCapacity/shrinkFactor); i++){
    newKey[0] = charset[i];
    Item* item = generateItem();
    removeItem(&hash, newKey);
  }

  assert(hash->size == (initialCapacity - 1 - (initialCapacity - (initialCapacity/shrinkFactor))));
  assert(hash->capacity == initialCapacity / growFactor);
}

Item* generateItem() {
  Item* item = malloc(sizeof(Item));
  assert(item != 0);

  item->key = strdup(generateString());
  item->value = strdup(generateString());

  return item;
}

char* generateString() {
    char* newString = (char*)malloc((maxStringSize + 1) * sizeof(char));
    if (newString == NULL) {
        printf("Failed to allocate memory.\n");
        return NULL;
    }

    for (int i = 0; i < maxStringSize; i++) {
        char caracter = charset[rand() % charsetSize];
        newString[i] = caracter;
    }
    newString[maxStringSize] = '\0';

    return newString;
}

int main() {
  runTests();
  return 0;
}