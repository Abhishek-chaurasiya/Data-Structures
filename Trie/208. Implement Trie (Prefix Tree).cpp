class Trie {
    struct Trienode{
        char val;
        int cnt;
        int wordEnded=0;
        Trienode *child[26];
    };
    Trienode *root;
    
    Trienode* getnode(int index){
        //create a new node
        Trienode *newnode=new Trienode();
        newnode->cnt=newnode->wordEnded=0;
        newnode->val='a'+index;
        for(int i=0;i<26;i++)newnode->child[i]=NULL;
        
        return newnode;
    }
public:
    Trie() {
        
        root=getnode(-'a'+'/');
    }
    
    void insert(string word) {
        Trienode *cur=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(cur->child[index]==NULL){
                cur->child[index]=getnode(index);
            }
            cur->child[index]->cnt+=1; 
            cur=cur->child[index];
        }
        cur->wordEnded+=1;
    }
    
    bool search(string word) {
        Trienode *cur=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(cur->child[index]==NULL){
               return false;
            }
            cur=cur->child[index];
        }
        if(cur->wordEnded>=1)return true;
        return false;
        
    }
    
    bool startsWith(string prefix) {
         Trienode *cur=root;
        for(int i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(cur->child[index]==NULL){
               return false;
            }
            cur=cur->child[index];
        }
        if(cur->cnt>=1)return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
