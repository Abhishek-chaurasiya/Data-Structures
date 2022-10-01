class Solution {
public:
    int solve(string s,int indx,vector<int> &dp){
        if(indx>=s.size())return 1;
        
        if(dp[indx]!=-1)return dp[indx];
        int ans=0;
        int op1=s[indx]-'0';
        if(op1>0)ans+=solve(s,indx+1,dp);
        
        if(indx+1<s.size() && op1>0){
            int op2=10*op1+s[indx+1]-'0';
            if(op2>0 && op2<=26)ans+=solve(s,indx+2,dp);
        }
        return dp[indx]=ans;
    }
    
    int numDecodings(string s) {
        
     
        int totalways=0;
        vector<int> dp(101,-1);
        return solve(s,0,dp);
    }
};
