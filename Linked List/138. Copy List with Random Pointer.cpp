/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
O(N) - space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* ,Node* > m;
        Node *trav = head;
        Node h(0), *dummy = &h;
        while(trav){
            dummy->next = new Node(trav->val);
            dummy = dummy->next;
            if(m.find(trav) != m.end()){
                dummy->random = m[trav];
            }
            else m[trav] = dummy;
            
            trav = trav->next;
        }
        dummy = &h;
        while(head){
            dummy = dummy->next;
             if(m.find(head->random) != m.end()){
                dummy->random = m[head->random];
            }
            head = head->next;
        }
        return h.next;
    }
};

O(1) - space
  
