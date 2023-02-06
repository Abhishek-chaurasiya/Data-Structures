Description

You are given N marbles in different colours. You have to remove marbles till there are no marbles left. Each time you can choose continuous marbles with the same color, remove them and get k*k points. Find the maximum points you can get.

Input Format

The first line contains one integer N - the length of the array. 

The second line contains N space-separated integers - the colours of the marbles.

Output Format

Print the maximum points you can get in a new line.

1 ≤ N ≤ 100
0 ≤ Ai ≤ 100
Sample Input 1
4
2 1 3 2
Sample Output 1
6
Sample Input 2
6
4 3 1 1 4 2
Sample Output 2
10
  
int n;
vector<int> arr;
int dp[101][101][101];

int helper(int l,int r,int k){
	if(l>r)return 0;
	if(dp[l][r][k]!=-1)return dp[l][r][k];

	int ans = (k+1)*(k+1)+helper(l+1,r,0);
	for(int i=l+1;i<=r;i++){
		if(arr[i]==arr[l]){
			ans=max(ans,helper(l+1,i-1,0)+helper(i,r,k+1));
		}
	}
	return dp[l][r][k]=ans;
}

void solve(){
 cin>>n;
 arr.resize(n);
 rep(i,0,n)cin>>arr[i];
 debug(arr);
 memset(dp,-1,sizeof dp);
 cout<<helper(0,n-1,0);  
	
}  
