You are given N elements, in an array A. You can take any 2 consecutive elements a and b and merge them. On merging you get a single element with value (a+b)%100 and this process costs you a*b. After merging you will place this element in place of those 2 elements.
 

If the sequence is [A1, A2, A3, A4] and you merge A2 and A3, you incur a cost of A2*A3 and the array becomes [A1, (A2+A3)%100, A4].
 

Find the Minimum/Maximum cost to merge all the elements into a single element.
  
int n;
vi arr;

int dp[501][501];

int helper(int l, int r){
  if(l == r){
    return 0;
  }
  if(dp[l][r]!=-1)return dp[l][r];
  int tot = 0;
  for(int i=l;i<=r;i++)tot+=arr[i];

  int ans = 0,sum=0;
  for(int mid=l;mid<r;mid++){
    sum+=arr[mid];
    ans=max(ans,helper(l,mid)+helper(mid+1,r)+(sum%100)*((tot-sum)%100));
  }

  return dp[l][r]=ans;
}

void solve(){
  cin>>n;
  arr.resize(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  memset(dp,-1,sizeof dp);
  cout<<helper(0,n-1);


}  
  
