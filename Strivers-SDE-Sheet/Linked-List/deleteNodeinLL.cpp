#include<stdio.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void deleteNode(ListNode* node) {
        node->val= node->next->val;
        node->next= node->next->next;
    }
int main()
{
  //main logic here
  return 0;
}
