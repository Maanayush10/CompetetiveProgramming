#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

///brute force solution
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp;
        while(headA!=NULL)
        {
            temp= headB;
            while(temp!=NULL)
            {
                if(temp==headA)
                {
                    return temp;
                }
                temp= temp->next;
            }
            headA= headA->next;
        }
        return NULL;
    }


int main()
{
  //main logic here
  return 0;  
}
