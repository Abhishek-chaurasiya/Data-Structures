Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
  
 bool contains(unordered_map<char,int> &fres,unordered_map<char,int> &fret){
        
        for(auto x:fret){
            if(x.second>fres[x.first])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        
        if(t.length()>s.length())return "";
        
        unordered_map<char,int > fres,fret;
        for(auto & c:t)fret[c]++;
        int left=INT_MAX,right=-1;
        
        for(int i=0;i<s.size();i++){
               
            if(fret[s[i]])left=min(left,i);
            fres[s[i]]++;
            
            if(contains(fres,fret)){
                right=i; break;
            }
           
        }
        
        if(left>right||right==-1)return "";
        
        int start=left,end=right,len=right-left+1;
        
        while(right<s.size()){
            fres[s[left]]--;
            
            while(right<s.size() && !contains(fres,fret)){
                right++;
                fres[s[right]]++;
            }
            left++;
            if(right-left+1<len){
                start=left,end=right;
                len=right-left+1;
            }
        }
        
        string ans=s.substr(start,end-start+1);
        return ans;
    }


//Second code-----------------------------------------------------------------------------------------------------------------------------------------------
