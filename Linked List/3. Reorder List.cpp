The idea is very simple that after mid we have to reverse the linked list and merge the first part and reverse part we will get the required ans.
class Solution {
public:
    array<ListNode*,2> reverse(ListNode *head){
        if(!head)return {head,head};
        if(!head->next)return {head,head};
        auto [h,t] = reverse(head->next);
        t->next = head;
        head->next = NULL;
        
        return {h,head};
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next)[0];
        ListNode *first = head, *second = slow;
        second = second->next;
        slow->next = NULL;
        
        while(second){
            ListNode *forw = first->next;
            first->next = second;
            
            ListNode *tmp = second;
            second = second->next;
            tmp->next = forw;
            
            first = first->next->next;
        }
       
    }
};
