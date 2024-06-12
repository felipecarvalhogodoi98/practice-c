#include "hash.h"

HashTable* createHashTable(int capacity) {
  HashTable* hash = malloc(sizeof(HashTable));
  assert(hash != 0);

  hash->table = malloc(sizeof(Item) * capacity);
  assert(hash->table != 0);

  for (int i = 0; i < capacity; i++) {
    hash->table[i] = NULL;
  }

  hash->capacity = capacity;
  hash->size = 0;

  return hash;
}

void destroyHashTable(HashTable* hashTable) {
  if (hashTable == NULL) return;
  
  Item* current = NULL;
  Item* next = NULL;

  for (int i = 0; i < hashTable->capacity; i++) {
    current = hashTable->table[i];
    hashTable->table[i] = NULL;
    while (current != NULL) {
      next = current->next;
      free(current->key);
      free(current->value);
      free(current);
      current = next;
    }
  }
  
  free(hashTable->table);
  free(hashTable);
}

int hash(HashTable* hashTable, char* key) {
  int hash = 0;
  int i = 0;
  char current = key[i];
  while (current != '\0') {
    hash = (hash * 17 + current) % hashTable->capacity; 
    i++;
    current = key[i];
  }

  return abs(hash);
}

void add(HashTable** hashTablePtr, char* key, char* value) {
  HashTable* hashTable = *hashTablePtr;
  int hashValue = hash(hashTable, key);
  Item* newItem = get(hashTable, key);
  
  if (newItem != NULL) {
    newItem->value = strdup(value);
    return;
  }

  newItem = malloc(sizeof(Item));
  newItem->key = strdup(key);
  newItem->value = strdup(value);
  newItem->next = hashTable->table[hashValue];
  hashTable->table[hashValue] = newItem;
  hashTable->size += 1;

  if (hashTable->size > hashTable->capacity) {
    resize(hashTablePtr, hashTable->capacity * growFactor);
  }
}

bool exists(HashTable* hashTable, char* key) {
  int hashValue = hash(hashTable, key);
  Item* aux = hashTable->table[hashValue];
  bool hasKey = false;

  while (aux != NULL && !hasKey) {
    if (strcmp(aux->key, key) == 0) hasKey = true; 
    aux = aux->next;
  } 

  return hasKey;
}

Item* get(HashTable* hashTable, char* key) {
  int hashValue = hash(hashTable, key);
  Item* aux = hashTable->table[hashValue];

  while (aux != NULL && strcmp(aux->key, key) != 0) {
    aux = aux->next;
  } 
  if (aux != NULL && strcmp(aux->key, key) == 0) return aux;

  return NULL;
}

void removeItem(HashTable** hashTablePtr, char* key) {
  HashTable* hashTable = *hashTablePtr;
  int hashValue = hash(hashTable, key);
  Item* current = hashTable->table[hashValue];
  Item* prev = NULL;

  while (current != NULL && strcmp(current->key, key) != 0) {
    prev = current;
    current = current->next;
  }
  
  if (current != NULL && strcmp(current->key, key) == 0) {
    if (prev != NULL) prev->next = current->next;
    else hashTable->table[hashValue] = current->next;

    hashTable->size -= 1;
    free(current);
  }

  if (hashTable->size < hashTable->capacity / shrinkFactor) {
    resize(hashTablePtr, hashTable->capacity / growFactor);
  }
}

void resize(HashTable** hashTablePtr, int newCapacity) {
  HashTable* hashTable = *hashTablePtr;
  HashTable* newHash = createHashTable(newCapacity);

  Item* aux = NULL;
  for (int i = 0; i < hashTable->capacity; i++) {
    if (hashTable->table[i] != NULL) { 
      aux = hashTable->table[i];
      while (aux != NULL) {
        add(&newHash, strdup(aux->key), strdup(aux->value));
        aux = aux->next;
      }
    }
  }

  destroyHashTable(hashTable);
  *hashTablePtr = newHash;
}

void printDebug(HashTable *hashTable) {
  Item* aux = NULL;
  printf("----------------------\n");
  for (int i = 0; i < hashTable->capacity; i++) {
    if (hashTable->table[i] == NULL) {
      printf("%d -> NULL", i);
    } else {
      printf("%d -> ", i);
      aux = hashTable->table[i];
      while (aux != NULL) {
        printf("[%s, %s]", aux->key, aux->value);
        if (aux->next != NULL) {
          printf(", ");
        }

        aux = aux->next;
      }
    }

    printf("\n");
  }
}