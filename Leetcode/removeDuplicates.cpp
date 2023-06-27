//83. Remove Duplicates from Sorted List (Leetcode Easy)

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


ListNode* deleteDuplicates(ListNode* head) {
        ListNode * current;
        current= head;

        while(current)
        {
            while(current->next && current->next->val == current->val)
            {
                current->next = current->next->next;
            }
            current= current->next;
        }
        return head;
    }

int main()
{
  //write main logic here.
  return 0;
}
