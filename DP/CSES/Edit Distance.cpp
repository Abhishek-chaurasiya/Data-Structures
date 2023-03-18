

    vector<vector<int>> dp;
    int helper(int i,int j,string &s1,string &s2){
        if(j == s2.size())return s1.size() - i;
        if(i == s1.size())return s2.size() - j;
        
        if(dp[i][j] != -1)return dp[i][j];
       
       
        int op1 = (s1[i]!=s2[j]) + helper(i+1,j+1,s1,s2); //replace
        int op2 = 1 + helper(i+1,j,s1,s2);  // delete
        int op3 = 1 + helper(i,j+1,s1,s2);  // insert
        
        return dp[i][j]= min(op1,min(op2,op3));
    }




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 int minDistance(string s1, string s2) {
         int n = s1.size() , m = s2.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
         for(int i=n;i>=0;i--){
             for(int j=m;j>=0;j--){
                 if(i==n||j==m){
                     dp[i][j] = (n-i)+(m-j);
                 }
                 else{
                     // add the jth character to i
                     dp[i][j]=1+dp[i][j+1];
                     // remove the ith character
                     dp[i][j]=min(dp[i][j],1+dp[i+1][j]);
                     dp[i][j]=min(dp[i][j],dp[i+1][j+1]+(s1[i]==s2[j]?0:1));
                 }
             }
         }
        return dp[0][0];
    }
