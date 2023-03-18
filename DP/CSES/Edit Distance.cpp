/////////////////////////////////////////////////////////////Top down/////////////////////////////////////////////////////////////////////////////////

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




/////////////////////////////////////////////////////////bottom up////////////////////////////////////////////////////////////////////////////////////////////
dp[i][j] is the minimum number of operation required to convert s1(0,i-1) to s2(0,j-1)
if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1]
else 
    dp[i][j] = 1 + dp[i-1][j] we delete i-1 the character and compare s1(0,i-2) with s2(0,j-1) which is already computed
    dp[i][j] = 1 + dp[i][j-1] we insert j-1 the character and compare s1(0,i-1) with s2(0,j-2) which is already computed  
    dp[i][j] = 1 + dp[i-1][j-1] we replace the character and compare s1(0,i-2) with s2(0,j-2) 
    
int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
        return dp[M][N];
 }

////////////////////////////////////space optimization //////////////////////////////////////////////////////////////////////////////////////////////////
 int minDistance(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        if(n < m){
            swap(s1,s2);
            swap(n,m);
        }
        vector<vector<int>> dp(2,vector<int>(m+1,INT_MAX));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)dp[i%2][j]=i+j;
                else if(s1[i-1] == s2[j-1])dp[i%2][j] = dp[(i-1)%2][j-1];
                else{
                    dp[i%2][j]=1 + min({dp[(i-1)%2][j],dp[i%2][j-1],dp[(i-1)%2][j-1]});
                }
            }
        }
        return dp[n%2][m];
        
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
