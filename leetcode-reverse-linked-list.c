// FOR LEETCODE ONLY

struct ListNode* reverseList(struct ListNode* head){
    if(head != NULL && head->next != NULL) { 
        struct ListNode * last = head;
        struct ListNode * this = last->next;
        head->next = NULL;
        while(last != NULL && this != NULL){
            struct ListNode * next = this->next;
            this->next = last;
            last = this;
            this = next;
        }
        return last;
    }else{
        return head;
    }
}