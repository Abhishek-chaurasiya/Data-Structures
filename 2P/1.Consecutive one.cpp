Description

Given a binary array of length N. The score of an array is the length of the longest continuous subsegment consisting of only one.

Find the maximum score possible if you can change at most K elements of the array.

Input Format

The first line contains an integer T, the number of test cases (1<=T<=10000).

The first line of each test case contains two space-separated integer N, K where 1<=N<=10^5, 0<=K<=N.

Next line contains N space-separated integers (Ai = {0,1}).

Sum of N across all test cases ≤ 10^6.

Output Format

For each test case print the maximum score possible if you can change at most K elements of the array in a new line.

Sample Input 1
 Copy

5
10 2
1 0 1 1 0 1 1 0 0 1
10 1
1 1 0 1 0 0 0 1 0 0
10 3
1 0 0 1 1 0 1 1 0 1
10 3
1 1 1 0 0 0 1 1 1 1
10 3
1 1 0 0 1 1 0 0 1 1
Sample Output 1
 Copy

7
4
8
10
7

void solve(){
	int n,k; cin>>n>>k;
	vi a(n); rep(i,0,n)cin>>a[i];

	int ans = 0, r = -1, l = 0;
    int cnt0 = 0;
	while(l < n){
		while(r+1 < n && cnt0 + (1 - a[r+1]) <= k){
			cnt0 += (1 - a[r+1]);
			r++;
		}
		ans = max(ans,r-l+1);
		if(r >= l){
			// my window has some element
			cnt0 -= (1- a[l]);
			l++;
		}
		else{
			// my window has empty element
			l++;
			r = l - 1;
		}
	}
	cout<<ans<<endl;
}
