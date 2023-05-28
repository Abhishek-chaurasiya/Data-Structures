1.//////////////////////////////////////////////////////////////////
  struct TrieNode{
    TrieNode *next[2]={};
};
class Solution {
    void add(TrieNode *node,int n){
        for(int i = 31; i>= 0; i--){
            int b = n>>i&1;
            if(!node->next[b])node->next[b] = new TrieNode();
            node = node->next[b];
        }
    }
    int maxXor(TrieNode *node,int n){
        int ans = 0;
        for(int i = 31; i>=0; i--){
            int b = n>>i&1;
            if(node->next[1-b]){
                ans |= (1<<i);
                node = node->next[1-b];
            }
            else node = node->next[b];
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode root;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            add(&root,nums[i]);
            ans = max(ans,maxXor(&root,nums[i]));
        }
        return ans;
    }
};


2.///////////////////////////////////////////////////////////////////////////////////////////////////////
  class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(),mask = 0, ans = 0;
        unordered_set<int> s;
        for(int i = 31; i >= 0; i--){
            mask |= (1<<i);
            s.clear();
            for(int &n:nums)s.insert(n&mask);
            int next = ans|(1<<i);
            for(auto x:s){
                if(!s.count(next^x))continue;
                ans |= (1<<i);
                break;
            }
        }
        return ans;
    }
};
