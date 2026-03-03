// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement
    if(head == NULL){
        // By definition
        return false;
    }
    if(head->next == NULL || head->next->next == NULL){
        // Covering base cases so that I dont get seg faults 
        return false;
    }
    
    struct ListNode *fast, *slow;
    fast = head->next->next;
    slow = head->next;

    while(fast != slow){
        // Any node ending in a null would indicate that there is no cycle. 
        if(fast->next == NULL || fast->next->next == NULL){
            return false;
        }
        fast = fast->next->next;
        if(slow->next == NULL){
            return false;
        }
        slow = slow->next;
    }
    return true;
}