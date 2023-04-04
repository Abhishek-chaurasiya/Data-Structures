Description

You are given N balls and an integer K. The color of each ball is given in an array A. A basket is filled if it contains at least K balls of different colors. Find the maximum number of filled baskets you can get if you optimally put the balls in the baskets.

Input Format

The first line contains T, the number of test cases (1<=T<=100000).

The first line contains three space-separated integers N, K where 1<=N<=10^5, 1<=K<=N.

Next line contains N space-separated integers (0<=Ai<=1e9).

Sum of N across all test cases <=10^6.

Output Format

For each test case output the maximum number of filled baskets in a new line. 

Sample Input 1
 Copy

3
5 5
1 2 3 4 5
5 2
1 2 3 4 5
6 3
1 2 2 1 3 3
Sample Output 1
 Copy

1
2
2
Note

1st test case:
1st basket -> {1,2,3,4,5}

2nd test case:
1st basket -> {1,2,3}
2nd basket -> {4,5}

3rd test case:
1st basket -> {1,2,3}
2nd basket -> {1,2,3} 


//////////////////////////////////////////////////////////////////////CODE//////////////////////////////////////////////////////////////////////////
void solve(){
	int n,k; cin>>n>>k;
	map<int,int> mp;
	vi a(n); rep(i,0,n){ cin>>a[i];  mp[a[i]]++;} 
	int l=1,h=n;
	while(l<h){
		int mid = l + (h-l+1)/2;
		int sum = 0;
		for(auto x:mp)sum += min(x.second,mid);
		if(sum >= mid*k){
			l=mid;
		}
		else h = mid-1;	
	}
	cout<<l<<endl;

	

}
