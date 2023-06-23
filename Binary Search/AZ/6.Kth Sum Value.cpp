Description

Given two arrays A of size N and B of size M and an integer K. Create a new array C of size N*M consisting of A[i]+B[j] for 1≤i≤N, 1≤j≤M. Find the Kth smallest element in the array C.

Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains 3 space-separated integer N, M, K where 1<=N<=10^6, 1<=M<=10^6, 1<=K<=N*M.

Next line contains N space-separated integers (0<=Ai<=1e4).

Next line contains M space-separated integers (0<=Bi<=1e4).

Sum of min(N, M) across all test cases<=10^5.

Output Format

For each test case print the Kth smallest element in the array C.
Sample Input 1
 Copy

1
3 3 6
1 2 3
4 5 6
Sample Output 1
 Copy

7
Note

Array C -> [1+4,1+5,1+6,2+4,2+5,2+6,3+4,3+5,3+6] -> [5,6,7,6,7,8,7,8,9]
Array C after sorting - [5,6,6,7,7,7,8,8,9]
6th element is 7.


  
void solve(){
	int n,m,k; cin>>n>>m>>k;
	vi a(n); rep(i,0,n)cin>>a[i];
	vi b(m); rep(i,0,n)cin>>b[i];
	sort0(a); sort0(b);
	
	if(n > m){
		swap(a,b);
		swap(n,m);
	}

	int l = a[0] + b[0], r = a[n-1] + b[m-1];
	int ans = 0;
	while(l <= r){
		int mid = (l+r)>>1;
		int cnt = 0;
		for(int i = 0; i < n; i++){
			cnt += ub(all(b),mid-a[i]) - begin(b);
		}
		if(cnt >= k){
			ans = mid;
			r = mid -1;
		}
		else l = mid + 1;
	}
	cout<<ans<<endl;
	
}


  
