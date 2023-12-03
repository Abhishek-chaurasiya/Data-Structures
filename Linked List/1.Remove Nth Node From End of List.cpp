1.First idea to solve this problem is to get length of a linked (len) and we have to find n th node from end which is equal to (len - n + 1) th node from begining. So what should be done is, we 
  should move till (len - n) from forward and then do the modificatino head->next = head->next->next;
  There is small edge case in this what if we have to remove first node then simply we have to return head->next;
  time complexcity - O(2N)

   class Solution {
  public:
      ListNode* removeNthFromEnd(ListNode* head, int n) {
         if(!head->next)return NULL; 
         int len = 0;
         ListNode *tmp = head;
         while(tmp){
             len++; tmp = tmp->next;
         } 
         int stop = len - n ;
       
         ListNode *prev = NULL, *cur = head;
         while(stop--){
             prev = cur;
             cur = cur->next;
         }
         if(prev == NULL)return head->next;  
         prev->next = prev->next->next;
         
         return head; 
      }
  };

2.Optimized Idea is to use two pointer - basically what we want is to somehow reach (n + 1) th node from end to do the modification, so we move our first pointer exactly n times from starting 
  point, then we move our second pointer from starting and first pointer as well, this ensures that the second pointer reach the (n + 1) th position from the last.
  
    class Solution {
  public:
      ListNode* removeNthFromEnd(ListNode* head, int n) {
        // to handle the first node eff
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *slow = start;  
        ListNode *fast = start;
          
        for(int i = 1; i <= n; i++)fast = fast->next;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }   
        slow->next = slow->next->next;
          
        return start->next;  
          
      }
  };
