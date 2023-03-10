void solve(){
  cin>>n>>x;
  price.resize(n);
  pages.resize(n);
  dp.resize(n+1,vector<int>(x+1,0));

  rep(i,0,n)cin>>price[i];
  rep(i,0,n)cin>>pages[i];

  
  for(int i=1;i<=n;i++){
    for(int tot=0;tot<=x;tot++){
      if(tot >= price[i-1]){
        dp[i][tot]=max(dp[i-1][tot],dp[i-1][tot-price[i-1]]+pages[i-1]);
      }
      else dp[i][tot] = dp[i-1][tot];
    }
    debug(dp);
    
  }
 
 cout<<dp[n][x];

}
