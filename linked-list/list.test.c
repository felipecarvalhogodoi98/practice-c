#include <assert.h>
#include "list.h"
#include "list.c"

void run_tests() {
  test_create_list();
  test_size();
  test_empty();
  test_value_at();
  test_push_front();
  test_pop_front();
  test_push_back();
  test_pop_back();
  test_front();
  test_back();
  test_insert();
  test_erase();
  test_value_n_from_end();
  test_reverse();
  test_remove_value();
}

void test_create_list() {
  List* list = create_list();
  
  assert(list != NULL);
  assert(list->head == NULL);

  destory_list(list);
}

void test_size() {
  List* list = create_list();

  assert(size(list) == 0);

  push_back(list, 1);
  assert(size(list) == 1);

  destory_list(list);
}

void test_empty() {
  List* list = create_list();

  assert(empty(list));

  destory_list(list);
}

void test_value_at() {
  List* list = create_list();

  push_back(list, 0);
  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);
  push_back(list, 4);

  int valueAt = 1;
  assert(value_at(list, valueAt) == valueAt);
  valueAt = 4;
  assert(value_at(list, valueAt) == valueAt);

  destory_list(list);
}

void test_push_front() {
  List* list = create_list();

  int value = 0;
  push_front(list, value);
  assert(value_at(list, 0) == value);

  value = 120;
  push_front(list, value);
  assert(value_at(list, 0) == value);

  destory_list(list);
}

void test_pop_front() {
  List* list = create_list();

  push_front(list, 1);
  push_front(list, 2);
  push_front(list, 3);

  int value = 100;
  push_front(list, value);
  assert(pop_front(list) == value);

  value = 120;
  push_front(list, value);
  assert(pop_front(list) == value);

  destory_list(list);
}

void test_push_back() {
  List* list = create_list();

  int value = 0;
  push_back(list, value);
  assert(value_at(list, 0) == value);

  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);
  value = 120;
  push_back(list, value);
  assert(value_at(list, size(list) - 1) == value);

  destory_list(list);
}

void test_pop_back() {
  List* list = create_list();

  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);

  int value = 100;
  push_back(list, value);
  int sizeList = size(list);
  assert(pop_back(list) == value);
  assert(size(list) == sizeList - 1);

  value = 120;
  push_back(list, value);
  assert(pop_back(list) == value);
  assert(size(list) == sizeList - 1);

  destory_list(list);
}

void test_front() {
  List* list = create_list();

  int value = 100;
  push_back(list, value);
  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);

  assert(front(list) == value);

  destory_list(list);
}

void test_back() {
  List* list = create_list();

  int value = 100;
  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);
  push_back(list, value);

  assert(back(list) == value);

  destory_list(list);
}

void test_insert() {
  List* list = create_list();

  int value = 100;
  int index = 8;
  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);
  push_back(list, 4);
  push_back(list, 5);
  push_back(list, 6);
  push_back(list, 7);
  push_back(list, 8);
  push_back(list, 9);
  push_back(list, 10);
  insert(list, index, value);

  assert(value_at(list, index) == value);

  destory_list(list);
}

void test_erase() {
  List* list = create_list();

  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);
  push_back(list, 4);
  push_back(list, 5);
  push_back(list, 6);
  push_back(list, 7);
  push_back(list, 8);
  push_back(list, 9);
  push_back(list, 10);
  
  int value = 100;
  int index = 4;
  insert(list, index, value);
  int sizeList = size(list);

  assert(erase(list, index) == value);
  assert(size(list) == sizeList - 1);

  destory_list(list);
}

void test_value_n_from_end() {
  List* list = create_list();

  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);
  push_back(list, 4);
  push_back(list, 5);
  push_back(list, 6);
  push_back(list, 7);
  push_back(list, 8);
  int value1 = 9;
  push_back(list, value1);
  int value0 = 10;
  push_back(list, value0);
  
  assert(value_n_from_end(list, 0) == value0);
  assert(value_n_from_end(list, 1) == value1);

  destory_list(list);
}

void test_reverse() {
  List* list = create_list();

  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);
  push_back(list, 4);
  push_back(list, 5);
  push_back(list, 6);
  push_back(list, 7);
  push_back(list, 8);
  int value1 = 9;
  push_back(list, value1);
  int value0 = 10;
  push_back(list, value0);

  reverse(list);

  assert(value_at(list, 0) == value0);
  assert(value_at(list, 1) == value1);

  destory_list(list);
}

void test_remove_value() {
  List* list = create_list();

  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);
  push_back(list, 4);
  push_back(list, 5);
  push_back(list, 6);
  push_back(list, 7);
  push_back(list, 8);
  push_back(list, 9);
  push_back(list, 10);
  
  int value = 60;
  int index = 2;
  insert(list, index, value);

  int sizeList = size(list);
  remove_value(list, value);

  assert(value_at(list, index) != value);
  assert(sizeList - 1 == size(list));

  destory_list(list);
}