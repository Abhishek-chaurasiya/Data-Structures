Idea is to merge two list at a time.
class Solution {
public:
    ListNode* merge(ListNode *first,ListNode *second){
        ListNode *comb = new ListNode();
        ListNode *trav = comb;
        
        while(first && second){
            if(first->val <= second->val){
                trav->next = first;
                // copying that particular node to comb and removing from first
                ListNode *tmp = first;
                first = first->next;
                tmp->next = NULL;
          
                trav = trav->next;
            }
            else{
                trav->next = second;
                // copying that particular node to comb and removing from second
                ListNode *tmp = second;
                second = second->next;
                tmp->next = NULL;
             
                trav = trav->next;
            }
        }
        while(first){
            trav->next = first;
            ListNode *tmp = first;
            first = first->next;
            tmp->next = NULL;
           

            trav = trav->next;
        }
        while(second){
            trav->next = second;
            ListNode *tmp = second;
            second = second->next;
            tmp->next = NULL;
     
            trav = trav->next;
        }
        
        return comb->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0)return NULL;
        ListNode *head = lists[0];
        for(int i = 1; i < len; i++){
            head = merge(head,lists[i]);
        }
        return head;
    }
};
