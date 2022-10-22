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

 string minWindow(string s, string t) {
     
        int ans=INT_MAX,start=0;
        unordered_map<char,int> freCnt;
        for(auto & x:t)freCnt[x]++;
        int cnt=freCnt.size();
        
        int i=0,j=0;
        while(j<s.size()){
            freCnt[s[j]]--;
            if(freCnt[s[j]]==0)cnt--;
            
            while(cnt==0){
                if(j-i+1<ans){
                    ans=j-i+1;
                    start=i;
                }
                freCnt[s[i]]++;
                if(freCnt[s[i]]>0)cnt++;
                
                i++;
            }
            j++;
        }
        if(ans==INT_MAX)return "";
        return s.substr(start,ans);
    }
