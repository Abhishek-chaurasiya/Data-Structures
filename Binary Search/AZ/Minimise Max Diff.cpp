Description

You are given N distinct points on the number line in a sorted array A. You can place at most K more points on the Line (Integer coordinates only). You have to make the maximum separation between any two consecutive points in the final configuration as minimum as possible. Output this minimal value.  

Note - You can place the points anywhere you like, but you cannot place more than one point at the same position on the line. 

Input Format

The first line contains an integer T, the number of test cases (1<=T<=10000).

The first line of each test case contains two space-separated integers N, K, 2<=N<=10^5, 0<=K<=10^9.

Next line contains N space-separated distinct integers (0<=Ai<=1e9).

Sum of N across all test cases <= 10^6.

Output Format

For each test case output the minimum maximum separation between any two consecutive points possible in a new line.

  Sample Input 1
 Copy

5
5 5
1 2 3 4 5
5 0
2 5 7 8 10
3 2
100 200 230
6 5
1 3 5 7 9 11
6 4
1 4 8 13 19 26
Sample Output 1
 Copy

1
3
34
1
4

void solve(){

	int n,k; cin>>n>>k;
	vi a(n); rep(i,0,n)cin>>a[i];
	int l=1,h=1e9,mn=0;

	while(l<h){
		int mid=l+(h-l)/2;
		int reqpnt=0;
		for(int i=0;i<n-1;i++){
          int dif=a[i+1]-a[i];
          mn=max(mn,dif);
          reqpnt += (dif+mid-1)/mid -1;
		}
		if(reqpnt <= k)h=mid;
		else l=mid+1;
	}
	cout<<min(l,mn)<<endl;

}
