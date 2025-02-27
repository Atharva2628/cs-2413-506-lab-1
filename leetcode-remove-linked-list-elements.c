// FOR LEETCODE ONLY

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
