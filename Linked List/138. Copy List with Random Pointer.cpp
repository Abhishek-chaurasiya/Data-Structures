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
class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto p = head;
        while(p){
            auto node = p;
            p = p->next;
            auto copy = new Node(node->val);
            node->next = copy;
            copy->next = p;
        }
        p = head;
        while(p){
            if(p->random)p->next->random = p->random->next;
            p = p->next->next;
        }
        Node h(0), *dummy = &h;
        p = head;
        while(p){
            auto node = p->next;
            p->next = node->next;
            p = p->next;
            
            dummy->next = node;
            dummy = dummy->next;
        }
        
        return h.next;
    }
};
