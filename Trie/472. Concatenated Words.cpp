////approach 1 dp --use dp[i] to denote whether we can get word[0..i] by concatenating one or more word from the word list
class Solution {
public:
    unordered_set<string> s;
    bool concatenated(string &word){
        int w = word.size();
        vector<bool> dp(w,false);
        for(int i=0;i<w-1;i++){
            if(s.count(word.substr(0,i+1)))dp[i] = true;
            if(!dp[i])continue;
            for(int j=i+1;j<w;j++){
               if(s.count(word.substr(i+1,j-i)))dp[j] = true;
            }
        }
        return dp[w-1];
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    
        s = unordered_set<string>(words.begin(),words.end());
        vector<string> ans;
        for(auto &word:words){
            if(concatenated(word))ans.push_back(word);
        }
        
        return ans;
    }
};


// aproach 2 - trie + dp ------------------------------------------------------------------------------------------------------------------------------------
struct TrieNode {
    TrieNode *next[26] = {};
    bool end = false;
};
class Solution {
    TrieNode *root = new TrieNode();
    void add(TrieNode *node,string &s){
        
        for(auto &c:s){
           if(!node->next[c-'a']) node->next[c-'a'] = new TrieNode();
            node = node->next[c-'a'];
        }
        node->end = true;
    }
    bool valid(string &s){
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0] = 1;
        for(int i=0;i<n && !dp[n];i++){
            if(!dp[i])continue;
            TrieNode *node = root;
            for(int j=i;j<n-(i==0);j++){
                node = node->next[s[j]-'a'];
                if(!node)break;
                if(node->end)dp[j+1] = true;
            }
        }
        return dp[n];
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(auto &word:words){
            if(word.size())add(root,word);
        }
        vector<string> ans;
        for(auto &word:words){
            if(word.size() && valid(word))ans.push_back(word);
        }
        
        return ans;
    }
};
