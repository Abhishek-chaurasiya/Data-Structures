Description

Given an array of N integers, find the number of subarrays with at most K distinct elements.

Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains two space-separated integers N, K where 1<=N<=10^5, 0<=K<=10^5.

Next line contains N space-separated integers (0<=Ai<=1e6).

Output Format

For each test case print the number of subarrays with at most K distinct elements in a newline.

Sample Input 1
 Copy

5
3 2
1 2 3
3 2
3 2 2
5 0
2 1 0 4 0
7 3
1 2 1 0 1 0 2
10 5
1 0 7 1 10 2 4 10 1 3
Sample Output 1
 Copy

5
6
0
28
46
 






void solve1(){
	int n,k; cin>>n>>k;
	vi a(n); rep(i,0,n)cin>>a[i];

	int ans = 0, r = -1, l = 0;
	map<int,int> m;
	while(l < n){
		while(r+1 < n && sz(m) + !m.count(a[r+1]) <= k){
			m[a[r+1]]++;
			r++;
		}
	    debug(r)
	    debug(l)
		ans += r-l+1;
		debug(ans)
		if(r >= l){
			// my window has some element
			m[a[l]]--;
			if(m[a[l]] == 0)m.erase(a[l]);
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

