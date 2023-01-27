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
