vector<int> dp;
int rec(int sum){
  if(sum == 0)return 0;
  if(sum < 0)return INT_MAX;
  if(dp[sum] != -1)return dp[sum];

  int ans = INT_MAX, tmp = sum;
  while(tmp){
    if(tmp%10!=0)ans = min(ans,1+rec(sum-tmp%10));
    debug(ans);
    tmp/=10;
  }
  return dp[sum] = ans;
}

set<int> getDigit(int n){
  set<int> digits;
  while(n){
    digits.insert(n%10);
    n/=10;
  }
  return digits;
}

void solve(){
  int n; cin>>n;
  dp.resize(n+1,-1);
  //.cout<<rec(n)<<endl;
  dp[0] = 0;
  for(int i=1;i<=n;i++){
      dp[i] = 1e9;
      for(auto d:getDigit(i)){
        dp[i] = min(dp[i],1+dp[i-d]);
      }
  }
 
  cout<<dp[n];

}
