/////////////////////////approach 1 - using trie ////////////////////////////////////////////////////////////////////////////////////////
struct TrieNode {
    TrieNode *next[26]={};
    bool end = false;
};

class WordDictionary {
    TrieNode *root = new TrieNode();
 public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode *node = root;
        for(auto &c:word){
            if(!node->next[c-'a'])node->next[c-'a'] = new TrieNode();
            node = node->next[c-'a'];
        }
        node->end = true;
    }
    bool dfs(TrieNode *node,int idx,string &word){
       
        if(!node)return false;
        if(idx == word.size())return node->end;
        if(word[idx] == '.'){
            for(int j=0;j<26;j++){
                if(node->next[j]){
                    if(dfs(node->next[j],idx+1,word))return true;
                }
            }
        }
        else{
            if(dfs(node->next[word[idx]-'a'],idx+1,word))return true;
        }
        return false;
    }
    bool search(string word) {
        TrieNode *node = root;
        return dfs(node,0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

///////////////////approach -2 /////////////////////////////////////////////////////////////
sexy solution based on string size we are storing in map and that's awesome

  class WordDictionary {
    unordered_map<int,vector<string>> mp;
    public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
        if(mp.count(word.size()) == 0)return false;
        for(auto &s:mp[word.size()]){
            int i = 0;
            for(;i<word.size();i++){
                if(word[i]!='.' && word[i]!=s[i])break;
            }
            if(i == word.size())return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
