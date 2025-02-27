#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ive made it so that all the stuff like the data and vars are dynamic
//------------------------------------------------

// These will be the numbers in the linked list
int arr[] = {0, 1, 2, 3, 99, 995};

//------------------------------------------------

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
  if (head != NULL && head->next != NULL) {
    struct ListNode *last = head;
    struct ListNode *this = last->next;
    head->next = NULL;
    while (last != NULL && this != NULL) {
      struct ListNode *next = this->next;
      this->next = last;
      last = this;
      this = next;
    }
    return last;
  } else {
    return head;
  }
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

  //   struct ListNode *result = removeElements(head, val);

  //   while (result != NULL) {
  //     printf("%d\n", result->val);
  //     result = result->next;
  //   }

  struct ListNode *result = reverseList(head);

  while (result != NULL) {
    printf("%d\n", result->val);
    result = result->next;
  }
}