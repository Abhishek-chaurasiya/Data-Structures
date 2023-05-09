// There are two type of query 
   1. Update (l,r,v) range l to r with plus v
   2. Find x the position 
   
Interchange the implementation of query and update part in the segment tree. For each query of the 2nd type, the value at index i will be the sum of values from root to the leaf node representing that index. For the update query of the 1st type, add the value to each logN nodes that completely lies within that range .
     
     
vi arr(100100);

vector<int> t(400100);

void update(int index,int l,int r,int lq,int rq,int val){
	if(l>rq || lq>r)return ;
	if(lq<=l && r<=rq){
		t[index] += val;
		return;
	}
	int mid = (l+r)/2;
	update(2*index,l,mid,lq,rq,val);
	update(2*index+1,mid+1,r,lq,rq,val);
	
}
int query(int index,int l,int r,int pos){
    if(pos < l || pos > r)return 0;
	if(l == r){
		return t[index];
	}
	int mid = (l+r)/2;
	auto left = query(2*index,l,mid,pos);
	auto right = query(2*index+1,mid+1,r,pos);
	return left + right + t[index];

}

void solve(){
	int n; cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		update(1,0,n-1,i,i,arr[i]);
	}

	int q; cin>>q;
	while(q--){
		int typ; cin>>typ;
		if(typ == 1){
			int l,r,x; cin>>l>>r>>x;
			update(1,0,n-1,l,r,x);
		}
		else{
			int x; cin>>x;
			auto ans = query(1,0,n-1,x);
			cout<<ans<<endl;
		}
	}   
	
}

     
