struct TrieNode{
    TrieNode *next[26]={};
    int cnt = 0;
};

class Trie{
    TrieNode root;
    public:
    void insert(string word){
        auto node = &root;
        for(auto &c:word){
            if(!node->next[c-'a'])node->next[c-'a'] = new TrieNode();
            node = node->next[c-'a'];
            node->cnt++;
        }
    }
    int search(string prefix){
        auto node = &root;
        int ans = 0;
        for(auto &c:prefix){
            if(!node->next[c-'a'])return ans;
            ans += node->cnt;
            node = node->next[c-'a'];
        }
        ans += node->cnt;
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie T;
        for(auto &str:words){
            T.insert(str);
        }
        int n = words.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int tres = 0;
        
            tres += T.search(words[i]);
            
            ans[i] = tres;
        }
        return ans;
    }
};
