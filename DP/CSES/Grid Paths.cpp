int rec(int x,int y){
  if(x==n || y==n || g[x][y]=='*')return 0;
  if(x==n-1 && y==n-1)return 1;
  
  if(dp[x][y] != -1)return dp[x][y];

  int path1 = rec(x+1,y);
  int path2 = rec(x,y+1);

  return dp[x][y] = (path1+path2)%mod;
}

void solve(){
   cin>>n;
  g.resize(n,vector<char>(n));
  dp.resize(n,vector<int>(n,-1));
  rep(i,0,n){
    rep(j,0,n)cin>>g[i][j];
  }
  cout<<rec(0,0);

}
