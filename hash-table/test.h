#include "hash.h"

#ifndef HASH_TABLE_TEST
#define HASH_TABLE_TEST

const char* charset =
  "0123456789"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz";
const int charsetSize = 63;
const int maxStringSize = 5;

void runTests();
void getTest();
void existsTest();
void addTest();
void removeTest();
void growCapacityTest();
void shrinkCapacityTest();
Item* generateItem();
char* generateString();

#endif