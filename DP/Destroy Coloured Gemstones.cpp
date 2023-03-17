You are given an array of colored gemstones. In one second, you can remove exactly one continuous substring of colored gemstones that is a palindrome. You have to find the minimum number of seconds needed to destroy all the gemstones.
  
  Approach - 
  A gemstone can either be destroyed individually or as a part of a range. When A[i] = A[j], when can say that DP[i][j] = DP[i+1][j-1]. This is because the last subarray which you destroy from [i+1, j-1] will be a palindrome but i and j gemstones are of the same color. If we include A[i] and A[j] at the end positions, it would still be a palindrome.
  
  //Destroy colored gemstone
void solve(){
  int n; cin>>n;
  vi a(n+1); rep(i,1,n+1)cin>>a[i];
  vector<vector<int>> dp(n+2,vector<int>(n+3,0));
  
  for(int l=1;l<=n;l++){
  	for(int s=1,e=l;e<=n;s++,e++){
       if(l == 1)dp[s][e] = 1;
       else{
        // does not include first character
       	dp[s][e] = 1 + dp[s+1][e];
       	// for duplicates like "aa"
       	if(a[s]==a[s+1])dp[s][e] =min(dp[s][e],1 + dp[s+2][e]);
       	for(int k=s+2;k<=e;k++){
       		if(a[s] == a[k]){
       			dp[s][e]=min(dp[s][e],dp[s+1][k-1]+dp[k+1][e]);
       		}
       	}
       }
  	}
  }
  debug(dp);
  cout<<dp[1][n]<<endl;
	
}
