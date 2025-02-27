#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ive made it so that all the stuff like the data and vars are dynamic
//------------------------------------------------

// These will be the numbers in the linked list
int arr[] = {0, 2, 2, 1, 5, 9, 2, 3, 99, 2};

// This is the value to remove
int val = 2;

//------------------------------------------------

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val) {
  struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
  node->next = head;
  struct ListNode *this = node;

  while (this->next != NULL) {
    if (this->next->val == val) {
      this->next = this->next->next;
    } else {
      this = this->next;
    }
  }

  return node->next;
}

void main() {
  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *node = head;

  int arrLen = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < arrLen; i++) {
    node->val = arr[i];
    if (i < arrLen - 1) {
      node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
      node = node->next;
    } else {
      node->next = NULL;
    }
  }

  struct ListNode *result = removeElements(head, val);

  while (result != NULL) {
    printf("%d\n", result->val);
    result = result->next;
  }
}