//////////////////////////Top down approach/////////////////////////////////////////////////////////////////////////////////

int n,target;
vi den,picked;
vector<int> dp;


int rec(int sum){
  if(sum == 0){ return 1;}
  if(dp[sum] != -1)return dp[sum];

  int ans=0;
  for(int i=0;i<n;i++){
    if(sum >= den[i]){
      ans = (ans + rec(sum - den[i]))%mod;  
    }
  }
  return dp[sum] = ans;  
}

void solve(){
  cin>>n>>target;
  den.resize(n);
  rep(i,0,n)cin>>den[i];
 
  dp.resize(target+1,-1);
  cout<<rec(target)<<endl;


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(){
  cin>>n>>target;
  den.resize(n);
  rep(i,0,n)cin>>den[i];
 
  dp.resize(target+1,0);
  // cout<<rec(target)<<endl;
  // number of ways to make sum eqaul to 0 with a empty array is 1
  dp[0] = 1;
  for(int sum=0;sum<=target;sum++){
    for(int i=0;i<n;i++){
        if(sum >= den[i]){
          dp[sum] = (dp[sum] + dp[sum-den[i]])%mod;
        }
    }
    debug(dp);
  }
  cout<<dp[target]; 

}
