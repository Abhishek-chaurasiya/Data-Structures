1.
N = 1e18;
FIND XOR VALUE OF  = 1^2^3^4^...^N:
There's nice observation behind it
 Number(N) : 1  2  3  4  5  6  7  8
 CumulatXor: 1  3  0  4  1  7  0  8
 Property  : 1 N+1 0  N  1 N+1 0  N
 Formula == (N-1)%4 + 1;
 Example - N = 1e15
   it comes out be 4 which is equal to N itself there ans is N;
   

2. Generating subset of subset
Tc - (3^N)
for(int mask = 0; mask < (1<<n); mask++){
  for(int sub = mask; sub; sub = (sub-1)&mask){
  
  }
}

3. Find a[i]^a[j]  for all possible pair where (i < j) O(n*n)
   Ex - [1,3,5] = 1^3 + 1^5 + 3^5 = 2 + 4 + 6 = 12;
   Xor is not distributive over addition but it is when it comes to bits
      1    3   5
 lsb  1    1   1
      0    1   0 
 msb  0    0   1
     
 (1^3) = (1^1)*2pow(0) + (0^1)*2pow(1) + (0^0)*2pow(2) = 0 + 2 + 0 = > 2
 (1^5) = (1^1)*2pow(0) + (0^0)*2pow(1) + (0^1)*2pow(2) = 0 + 0 + 4 = > 4
 (3^5) = (1^1)*2pow(0) + (1^0)*2pow(1) + (0^1)*2pow(2) = 0 + 2 + 4 = > 6
 
  we just have to move column wise and we know the nature of xor that it 1 when the bits are of opposite sign so we cnt the number of ones 
  ans zero and multiply by the two's power.
     
  void solve(){
	int n; cin>>n;
	vi a(n); rep(i,0,n)cin>>a[i];
	vi bit(32);
	rep(i,0,n){
		rep(j,0,32){
			bit[j] += (a[i]&(1<<j))?1:0;
		}
	}
	int ans = 0 , base = 1;
	rep(i,0,32){
		int ocnt = bit[i], zcnt = n - ocnt;
		ans += ocnt*zcnt*base;
		base*=2;
	}
	cout<<ans<<endl;
	// bforce
	int bans = 0;
	rep(i,0,n){
		rep(j,i+1,n){
			bans += a[i]^a[j];
		}
	}
	cout<<bans<<endl;
	debug(bit);
}
     

we can extend this to find all pairs between &
which will be nothing nc2(cnt of 1 bit) ans += ocnt*(ocnt-1)/2*base
can also extend to | or as well
which will be nothing but nc2(cnt of 1 bit) + 0 bitcnt*1 bitcnt [(ocnt*(ocnt-1)/2 + ocnt*zcnt)*base]

