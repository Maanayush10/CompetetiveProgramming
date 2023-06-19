struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
}; 

void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow =head;
        Node * fast = head;
        
        while(fast!=NULL && fast->next !=NULL)
        {
            slow=slow->next;
            fast= fast->next->next;
            
            if(fast==slow)
            {
                break;
            }
        }
        if(slow==fast)
        {
            slow=head;
            if(slow==fast){
                while(fast->next != slow)
                {
                    fast = fast->next;
                }
            }else{
            while(slow->next != fast->next)
            {
                slow= slow->next;
                fast = fast->next;
            }
            }
        fast->next= NULL;
        }
