#include <bits/stdc++.h>
using namespace std;

//brute force approach using  dummy and duplicate dummy pointers.
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* first = list1;
    ListNode* second = list2;
    ListNode* result = new ListNode();
    ListNode* current = result; // Pointer to track the current node

    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    while (first != NULL && second != NULL) {
        if (first->val <= second->val) {
            current->next = first;
            first = first->next;
        } else {
            current->next = second;
            second = second->next;
        }
        current = current->next; // Update current to the newly added node
    }

    if (first != NULL) {
        current->next = first;
    }
    if (second != NULL) {
        current->next = second;
    }

    return result->next;
}


int main(){
  //main logic here
  return 0;
}
