
/*
 * iterator_test.cpp
 *
 * Tests basic iterator operations
 *
 * by Ziqi Wang
 */

#include "test_suite.h"


/*
 * ForwardIteratorTest() - Tests forward iterator functionalities
 */
void ForwardIteratorTest(TreeType *t, int key_num) {
  printf("========== Forward Iteration Test ==========\n");

  auto it = t->Begin();

  long i = 0;
  while(it.IsEnd() == false) {
    assert(it->first == it->second);
    assert(it->first == i);

    i++;
    it++;
  }

  assert(i == (key_num));

  auto it2 = t->Begin(key_num - 1);
  auto it3 = it2;

  it2++;
  assert(it2.IsEnd() == true);

  assert(it3->first == (key_num - 1));

  auto it4 = t->Begin(key_num + 1);
  assert(it4.IsEnd() == true);

  return;
}

/*
 * BackwardIteratorTest() - Tests backward iteration
 */
void BackwardIteratorTest(TreeType *t, int key_num) {
  auto it = t->Begin(key_num - 1);
  auto it2 = t->Begin(key_num);
  
  // Since they all points to the same key == (key_num - 1)
  assert(it == it2);
  assert(it.IsEnd() == true);
  assert(it.IsBegin() == false);
  
  // This does not test Begin()
  long int key = key_num - 1;
  while(it.IsBegin() == false) {
    assert(it->first == it->second);
    assert(it->first == key);
    key--;
    it--;
  }
  
  // Test for Begin()
  assert(it->first == it->second);
  assert(it->first == key);
  
  return;
}
