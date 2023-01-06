KEY IDEA - IF YOU SEE (PATH/SEQUENCE/SUBARRAY) DEPENDENCIES MAY BE IT IS FORM 2


//Lis using form 1 - classical knapsack way

int dp[100][100];
int helper(int idx,int last,vi &arr){
  if(idx==sz(arr))return 0;

  if(dp[idx][last]!=-1)return dp[idx][last];
  
  int op1=0,op2=0;
  if(arr[idx]>last)op1=1+helper(idx+1,arr[idx],arr);
  op2=helper(idx+1,last,arr);

  return dp[idx][last] =max(op1,op2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lis using form 2- Ending form - what is the maximum lis ending at level  = l 
vi dp(1000);


int helper(int level,vi &arr){

  if(dp[level] != -1)return dp[level];

  int ans=1;
  for(int prev=0;prev<level;prev++){
    if(arr[level] > arr[prev]){
      ans = max(ans,1+helper(prev,arr));
    }
  }
  return dp[level]=ans;
}

void solve(){
 int n; cin>>n;
 dp.resize(n);
 fill(dp.begin(),dp.end(),-1);
 vi arr(n); rep(i,0,n)cin>>arr[i];
 
 int ans = 0;
 for(int i=0;i<n;i++){
  ans=max(ans,helper(i,arr));
  debug(dp);
 }
 
 cout<<ans<<endl;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Problem - In a 2-d grid find the max-sum path form (1,1) to (n,m) if only you can move downward or rightward .
Solution - 
  if suppose you are at row = r and column = c;
  what is dp state ?
    dp(r,c) --> best (maximum sum path ending at (r,c) starting from (1,1)
  what is transition ?
     
                         | dp(r,c-1) + arr[r][c] if (c-1>=0)
       dp(r,c)-----------^ 
                         | dp(r-1,c) + arr[r][c] if (r-1>=0)
                      
                      
vector<vi> grid;
vector<vi> dp;
vector<vector<bool>> done;

int helper(int r,int c){

  if(r==0 && c==0)return grid[r][c];
  if(done[r][c])return dp[r][c];

  int ans = -1e9;
  if(r!=0)ans=max(ans,helper(r-1,c)+ grid[r][c]);
  if(c!=0)ans=max(ans,helper(r,c-1)+ grid[r][c]);

  done[r][c] = 1;
  return dp[r][c]=ans;
}

void solve(){

 int n,m; cin>>n>>m;
 grid.resize(n,vector<int>(m,0));
 dp.resize(n,vector<int>(m,-1));
 done.resize(n,vector<bool>(m,0));

 for(int i=0;i<n;i++){
  for(int j=0;j<m;j++)cin>>grid[i][j];
 }
 // debug(grid)

  cout<<helper(n-1,m-1);
   debug(dp);


} 
                      
                      
                      
  
  
  
