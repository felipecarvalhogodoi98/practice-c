#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#ifndef HASH_TABLE
#define HASH_TABLE

const int growFactor = 2; 
const int shrinkFactor = 3; 

typedef struct Item {
  char* key;
  char* value;
  struct Item* next;
} Item;

typedef struct HashTable
{
  Item** table;
  int size;
  int capacity;
} HashTable;

HashTable* createHashTable(int capacity);
void destroyHashTable(HashTable* hashTable);
int hash(HashTable* hashTable, char* key);
void add(HashTable** hashTablePtr, char* key, char* value);
bool exists(HashTable* hashTable, char* key);
Item* get(HashTable* hashTable, char* key);
void removeItem(HashTable** hashTable, char* key);
void resize(HashTable** hashTable, int newCapacity);
void printDebug(HashTable *hashTable);
#endif