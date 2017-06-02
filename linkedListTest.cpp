/*
 * Test file for Linked List class.
 * test all functions. Verify works as expected.
 */

#include <iostream>
#include "linkedList.h"

using namespace std;

const int minVal    = -10;
const int maxVal    = 10;
const string ERROR  = "Error found in Linked List data structure, function: ";

int main()
{
  LinkedList firstList;
  LinkedList secondList;

  /* Verify both lists are set to size 0. */
  if (firstList.getSize() != 0) {
    cout << ERROR << "constructor" << endl;
  }
  if (secondList.getSize() != 0) {
    cout << ERROR << "constructor" << endl;
  }

  /* Verify adding to list 1. */
  for (int i = minVal; i < maxVal; i++) {
    firstList.append(i);
  }

  cout << "List 1: ";
  firstList.printList();

  /* Test findVal function. */
  if (firstList.findVal(0) != true) {
    cout << ERROR << "findVal" << endl;
  }

  if (firstList.findVal(11) != false) {
    cout << ERROR << "findVal" << endl;
  }

  if (firstList.getSize() != (abs(minVal) + maxVal)) {
    cout << ERROR << "getSize" << endl;
  }

  /* Get value from first list and assign to second list.
   * delete from first list.*/
  firstList.moveFront();
  for (int i = minVal; i < maxVal; i++) {
    int temp = firstList.getCurrent();
    firstList.moveNext();
    firstList.deleteFront();
    if (temp != i) {
      cout << ERROR << "getCurrent" << endl;
      return 0;
    }
    secondList.append(temp);
  }

  /* delete second list. */
  secondList.moveBack();
  for (int i = maxVal - 1; i >= minVal; i--) {
    int temp = secondList.getCurrent();
    secondList.movePrev();
    secondList.deleteBack();
    if (temp != i) {
      cout << ERROR << "getCurrent" << endl;
    }
  }

  /* Verify second list is empty now. */
  if (secondList.getSize() != 0 && !secondList.isEmpty()) {
    cout << ERROR << "getSize" << endl;
  }

  /* Verify adding to list 1. */
  for (int i = minVal; i < maxVal; i++) {
    firstList.prepend(i);
  }

  if (firstList.getSize() != (abs(minVal) + maxVal)) {
    cout << ERROR << "getSize" << endl;
  }

  firstList.clear();

  /* Verify second list is empty now. */
  if (firstList.getSize() != 0 && !firstList.isEmpty()) {
    cout << ERROR << "clear" << endl;
  }

  secondList.prepend(1);
  if (secondList.getCurrent() != -1) {
    cout << ERROR << "getCurrent" << endl;
  }

  secondList.moveFront();
  secondList.insertAfter(2);
  secondList.insertBefore(0);
  /* 0 1 2 */

  cout << "List 2: ";
  secondList.printList();

  secondList.deleteCurrent();
  /* 0 2 */

  /* Test findVal function. */
  if (secondList.findVal(2) != true) {
    cout << ERROR << "findVal" << endl;
  }

  /* Verify second list has two entries. */
  if (secondList.getSize() != 2) {
    cout << ERROR << "deleteCurrent" << endl;
  }

  secondList.moveBack();
  secondList.deleteCurrent();
  /* 0 */
  secondList.prepend(1);
  /* 1 0 */
  secondList.moveBack();

  if (secondList.getCurrent() != 0) {
    cout << ERROR << "deleteCurrent" << endl;
  }

  secondList.moveFront();
  if (secondList.getCurrent() != 1) {
    cout << ERROR << "deleteCurrent" << endl;
  }

  secondList.clear();
  /* Verify second list is empty now. */
  if (secondList.getSize() != 0 && !secondList.isEmpty()) {
    cout << ERROR << "getSize" << endl;
  }

  return 0;
}