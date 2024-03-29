Description

Given an array of N integers and Q queries. In each query, you are given two parameters L and R; you have to find the following:

1. Smallest integer X1 such that the value of (AL XOR X1) + (AL+1 XOR X1) + ... + (AR XOR X1) is maximum possible.

2. Smallest integer X2 such that the value of (AL OR X2) + (AL+1 OR X2) + ... + (AR OR X2) is maximum possible.

3. Smallest integer X3 such that the value of (AL AND X3) + (AL+1 AND X3) + ... + (AR AND X3) is maximum possible.

Range of X1, X2, X3 allowed → 0 <= X1, X2, X3 < 2^31.

Print the sum of X1, X2, X3 for each query in a newline.

Input Format

The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^9).

The third line contains an integer Q, (1<=Q<=10^5).

The next Q lines contain two space-separated integers L, R (1<=L<=R<=N).

Sum of Q over all test cases does not exceed 10^6.

Output Format

For each query print the value of X1  + X2 + X3  in a new line.

 

Sample Input 1
 Copy

5
5
1 2 3 4 5
5
1 5
2 5
3 4
2 4
3 3
3
1 2 2
3
1 2
2 3
1 3
4
1 2 2 4
5
1 2
2 3
3 4
2 4
3 4
10
123 234565 3456765 3456 09888 433534 908767 125698 545676 23456
10
1 4
1 6
1 9
1 10
3 7
3 9
4 7
6 9
4 9
7 9
10
23456 3456 987 8765 3456 34565 9876 654555 234566 87654344
10
1 8
1 6
1 9
1 10
2 7
2 9
4 7
8 9
9 9
7 9
Sample Output 1
 Copy

4294967300
4294967294
4294967294
4294967299
4294967291
4294967294
4294967292
4294967295
4294967294
4294967292
4294967294
4294967298
4294967294
4298580736
4298580736
4299121201
4299120657
4298857985
4299120753
4295712255
4295106335
4295958639
4295222095
4295618668
4295028860
4295751805
4382781565
4295010408
4295751784
4295002150
4294863804
4294732728
4295640583

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void solve(){
	ll n; cin>>n;
	vll a(n); rep(i,0,n)cin>>a[i];
	vector<vll> bit(n,vector<ll>(32,0));

	for(ll j = 0; j < 31; j++){
		for(ll i = 0; i < n; i++){
			bit[i][j] += (a[i] >> j & 1LL);
			if(i)bit[i][j] += bit[i-1][j];
		}
	}
	
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r;

		l--; r--;
		ll x1 = 0, x2 = 0, x3 = 0;
        // double tot = (r - l + 1.0)/2;
	    for(ll i = 0; i < 31; i++){
	    	ll cnt = bit[r][i] - ((l-1 >= 0)?bit[l-1][i]:0);
	    	ll range = (r - l + 1);
      // The behaviour of xor if one bit is set in less the half the number in range we will activate that bit in x1  
	    if(2*cnt < range)x1 += (1LL<<i);
      // Or has very simple nature if all the bits are already set we dont have to do anything else we will active that bit in x2  
			if(cnt != range){
				x2 += (1LL<<i);	
			}
      // and demands a prerequiste that if any bit is set, i must also set to maximise the sum  
			if(cnt){
				x3 += (1LL<<i);
			}
	    }
	    debug(x3)
	    cout<<x1+x2+x3<<endl;

	}
}
