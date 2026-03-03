// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "student.h"

int middleNodeValue(struct ListNode *head) {
    // TODO: implement
    if(head == NULL){
        // By definition
        return -1;
    }

    if(head->next == NULL){
        return head->val;
    }

    if(head->next->next == NULL){
        return head->next->val;
    }

    struct ListNode *fast, *slow;

    slow = head->next;
    fast = head->next->next;

    while(fast != NULL){
        if(fast->next == NULL){
            return slow->val;
        }else{
            fast = fast->next->next;
            slow = slow->next;
        }
    }

    return slow->val;
}