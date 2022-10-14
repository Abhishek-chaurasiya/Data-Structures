


ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)return NULL;
        ListNode *slow=NULL,*fast=head,*prev=NULL;
        while(fast && fast->next){
          
            prev=(prev==NULL)?head:prev->next;
            fast=fast->next->next;
        }
        cout<<prev->val;
        prev->next=prev->next->next;
        return head;
    }
