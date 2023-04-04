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


bool possible(int mid,int k,vi &a){
    
    int change=0,n=sz(a); 
	for(int i=0;i<min(mid,n);i++)change+= (a[i]==0);
	int i=0,j = mid;
    if(change <= k)return true;
	while(j<n){
       change+= (a[j]==0);
       change-= (a[i++]==0);
       if(change <= k)return true;
       j++;
	}
	return false;	
}

void solve(){
	int n,k; cin>>n>>k;

	vi a(n); rep(i,0,n){ cin>>a[i]; } 
	int l=0,h=n;
	while(l<h){
		int mid = l + (h-l+1)/2;
		if(possible(mid,k,a))l=mid;
		else h = mid-1;
			
	}
	cout<<l<<endl;

	

}


