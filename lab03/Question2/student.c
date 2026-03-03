// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      struct ListNode *current = head;

      if(head == NULL){
            return NULL;
      }

      if(head->next == NULL){
            return head;
      }

      struct ListNode *newHead = head->next;
      
      while(current != NULL){
            if(current->next == NULL){
                  return newHead;
            }else{
                  struct ListNode *temp1, *temp2;
                  temp2 = current->next->next;
                  if(temp2 == NULL){
                        temp1 = NULL;
                  }else{
                        if(current->next->next->next == NULL){
                              temp1 = current->next->next;
                        }else{
                              temp1 = current->next->next->next;
                        }
                  }

                  current->next->next = current;
                  current->next = temp1;
                  current = temp2;
            }
      }

      return newHead;
}