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


ListNode *detectCycle(ListNode *head) {
        ListNode * slow= head;
        ListNode * fast = head;
        bool loopExists= false;
        while(fast && fast->next)
        {
            slow= slow->next;
            fast= fast->next->next;

            if(slow == fast)
            {
                loopExists= true;
                break;
            }
        }
        if(loopExists == true)
            {
                slow=head;
                while(slow!=fast)
                {
                    slow= slow->next;
                    fast= fast->next;
                }
                return slow;
            }

        return NULL;
    }

int main()
{
  //main logic here
  return 0;
}
