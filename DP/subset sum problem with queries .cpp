///////////////////////////////////////////////////////////////////////NORMAL////////////////////////////////////////////////////////////////////////////////
int dp[101][101];
int helper(int idx,int sum,int target,vector<int> &a){
    if(idx == (int) a.size()){
       if(sum == target)return 1;
       return 0;
    }
    if(dp[idx][sum] != -1)return dp[idx][sum];
    int op1 = 0 , op2 = 0;
    op1 = helper(idx+1,sum,target,a);
    if(sum + a[idx] <= target) op2 = helper(idx+1,sum+a[idx],target,a);

    return dp[idx][sum] = (op1||op2);
}

void solve(){
    int n,t; cin>>n>>t;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<helper(0,0,t,a);
}



/////////////////////////////////////////////////////////////////////////WITH QUERIES////////////////////////////////////////////////////////////////////////////
There are Q queries for the target , if target exist print the solution .
  
learning : dp(level,sumleft) helps us to cache the dp array without refreshing it.

    int n;
int dp[101][101];
int helper(int idx,int sumleft,vector<int> &a){
    if(sumleft == 0)return 1;
    if(idx == (int) a.size()){
       if(sumleft == 0)return 1;
       return 0;
    }
    if(dp[idx][sumleft] != -1)return dp[idx][sumleft];
    int op1 = 0 , op2 = 0;
    op1 = helper(idx+1,sumleft,a);
    if(sumleft - a[idx] >= 0) {
        op2 = helper(idx+1,sumleft-a[idx],a);
     
    }

    return dp[idx][sumleft] = (op1||op2);
}

void printset(int idx,int sumleft,vi a,vector<int> &ans){
    cout<< idx <<" "<< sumleft<<endl;
    if(idx == n)return ;

    if(helper(idx+1,sumleft,a))printset(idx+1,sumleft,a,ans);
    else if(helper(idx+1,sumleft-a[idx],a)){
         ans.pb(a[idx]);
         cout<<"took"<<a[idx]<<" ";
         printset(idx+1,sumleft-a[idx],a,ans);
    }
}
