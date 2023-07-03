#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* reverseList(ListNode* head) {
        ListNode * dummy= NULL;
        while(head!=NULL)
        {
            ListNode * next= head->next;
            head->next= dummy;
            dummy=head;
            head=next;
        }
        return dummy;
    }
int main()
{
  //main logic here
  return 0;
}
