 Time Complexcity of any DP problem is O(Number of state * (1 + Number of transition) )
 Approach of LCS 
 string A = "AGGTAB"
 string B = "GXTXATB"
  
 State of dp(i,j) --> what does dp(i,j) means
 dp(i,j) = LCS of A[i,n-1] and LCS of B[j,m-1]
 
 Transition 
 
              |---dp(i,j+1) ith character does not match with j th character ,so jth character is a waste
 dp(i,j)------>---dp(i+1,j) jth character does not match with i th character ,so ith character is a waste 
              |--- if it's a match then we move to dp(i+1,j+1)
                
 TC - O(N*M(1+3)) as the transition is three
 
 
string a,b;
int n,m;
int dp[1001][1001];

int helper(int i,int j){
  //return the LCS of a[i..n-1]  & b[j..m-1]
  if(i>=n || j>=m)return 0;
  if(dp[i][j] != -1) return dp[i][j];
  int ans = 0;

  ans = max(ans,helper(i,j+1));
  ans = max(ans,helper(i+1,j));
  if(a[i] == b[j]){
    ans = max(ans,1+helper(i+1,j+1));
  }

  return dp[i][j] = ans;
}

void solve(){

 cin>>a>>b;
 n=sz(a),m=sz(b);
 memset(dp,-1,sizeof dp);
 cout<<helper(0,0);


}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
