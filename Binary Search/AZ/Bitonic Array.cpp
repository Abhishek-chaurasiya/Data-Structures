Description

Given a bitonic array A consisting of N integers and an integer Q. In each query, you will be given an integer K, find the positions of K in A. Integer K exists in A.

Bitonic array - A bitonic sequence is a sequence with A[1]<A[2]<A[3]....A[k]>A[k+1]>A[k+2]....>A[N] for some 1<=K≤N. 

Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains two space separated-integer N, Q where 1<=N<=10^5, 1<=Q<=10^6.

The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.

Next Q lines contains an integer K, -1e9<=K<=1e9.

Sum of N, Q across all test case ≤10^6

Output Format

For each test case print the positions of K in A in sorted order in a new line.
  
Sample Input 1
 Copy

1
6 4
1 2 5 3 2 1
1
2
5
3
Sample Output 1
 Copy

1 6
2 5
3
4
  
void solve(){

	int n,q; cin>>n>>q;
	vi a(n); rep(i,0,n)cin>>a[i];
	int peakidx = 0;
	int l=0,h=n-1;
	// finding peak
	while(l<=h){
		int mid = l+(h-l)/2;
		if(mid>0 && a[mid] > a[mid-1]){
			peakidx = mid;
			l=mid+1;
		}
		else h=mid-1;
	}


	// cout<<peakidx;

	while(q--){
		int e; cin>>e;
		int l=0,h=peakidx;
		vector<int> idx;
		// finding presence in the first half
		while(l<=h){
			int mid=l+(h-l)/2;
			if(a[mid] == e){
				idx.pb(mid);
				break;
			}
			if(a[mid] > e)h=mid-1;
			else l=mid+1;
		}
		// finding presence in the second half
		l=peakidx+1,h=n;
		while(l<=h){
			int mid=l+(h-l)/2;
			if(a[mid] == e){
				idx.pb(mid);
				break;
			}
			if(a[mid] > e)l=mid+1;
			else h = mid-1;
		}
		for(auto i:idx)cout<<i<<" ";
		cout<<endl;

	} 
}  
  
  
  
  
