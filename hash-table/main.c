#include <stdio.h>
#include "hash.h"
#include "hash.c"

#define valuesSize 14
char* values[valuesSize] = {"Cube", "Cylinder", "Triangle", "Sphere", "Circle", "Pyramide", "Hexagon", "Pentagon", "Rectangulo", "Car", "Table", "Listen", "Time", "Three"};

void test1() {
  HashTable* table = createHashTable(2);
  
  for (int i = 0; i < valuesSize; i++) {
    add(&table, values[i], values[i]);
    // printDebug(table);
  }

  for (int i = 0; i < valuesSize; i++) {
    assert(exists(table, values[i]) == 1);
  }

  char* search = "ab";
  assert(exists(table, search) == 0);

  for (int i = 0; i < valuesSize; i++) {
    Item* aux = get(table, values[i]);
    assert(aux != NULL);
    // if (aux != NULL) printf("[%s, %s]\n", aux->key, aux->value);
  }

  Item* aux = get(table, search);
  assert(aux == NULL);

  char* toRemove1 = "Cube";
  removeItem(&table, toRemove1);
  // printDebug(table);

  char* toRemove2 = "Pyramide";
  removeItem(&table, toRemove2);
  // printDebug(table);

  char* toRemove3 = "Listen";
  removeItem(&table, toRemove3);
  printDebug(table);

  assert(get(table, toRemove1) == NULL);
  assert(get(table, toRemove2) == NULL);
  assert(get(table, toRemove3) == NULL);

  char* key = "Car";
  char* value = "Car2";
  add(&table, key, value);
  assert(strcmp(get(table, key)->value, value) == 0);

  destroyHashTable(table);
}

void test2() {
  HashTable* table = createHashTable(2);
  
  for (int i = 0; i < valuesSize; i++) {
    add(&table, values[i], values[i]);
    // printDebug(table);
  }

  for (int i = 0; i < valuesSize - 3; i++) {
    removeItem(&table, values[i]);
    printDebug(table);
  }

  destroyHashTable(table);
}

int main() {
  test1();
  test2();
  return 0;
}