1////////////////////////////////////////////////NEVER THOUGHT THIS WAY///////////////////////////////////////////////////////////////////////
1. WHAT WE ACTUALLY HAVE TO FIND ? Initially array was sorted it is rotated then there would be a point in the array where element is smaller then the element before it,
   A[i-1] > A[i].
2. We call this point inflection point . The fact is that all the numbers to the left of the inflection point are greater then the first number and numbers right to point
   are smaller then the first number A[0].
3. We take L = 0, R = N-1  if A[mid] >= A[l] this means array is sorted from [l to mid] A[l] being the smallest element . mid +1 can be a possible answer and the we 
   continue binary search from L = mid+1 to R 
4.  if A[L] > A[mid] then definately minimum number lies between L to mid, because the array is not increasing in this range there will be inflection point where
    element is smaller then the element before it, so we continue binary search from L to R=mid;


void solve(){

	int n; cin>>n;
	vi a(n); rep(i,0,n)cin>>a[i]; 	 
    int l=0,h=n,ans=0;
    while(l<h){
    	int mid=l+(h-l)/2;
    	// inflection range 
    	if(a[0]>a[mid]){
    		ans=mid;
    		h=mid;
    	} // sorted range 
    	else l=mid+1;
    }
    cout<<ans<<endl;  
}
