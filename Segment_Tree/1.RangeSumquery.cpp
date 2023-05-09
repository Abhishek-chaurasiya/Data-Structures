vi arr(100100),t(400100);

void build(int index,int l,int r){
	if(l == r){
		t[index] = arr[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*index,l,mid);
	build(2*index+1,mid+1,r);
	t[index] = t[2*index] + t[2*index+1];
}
void update(int index,int l,int r,int pos,int val){
	if(pos<l || pos>r)return;
	if(l == r){
		t[index] = val;
		arr[index] = val;
		return;
	}
	int mid = (l+r)/2;
	update(2*index,l,mid,pos,val);
	update(2*index+1,mid+1,r,pos,val);
	t[index] = t[2*index] + t[2*index+1];
}
int query(int index,int l,int r,int lq,int rq){
	if(l>rq || lq>r)return 0;
	if(lq<=l && r<=rq){
		return t[index];
	}
	int mid = (l+r)/2;
	return query(2*index,l,mid,lq,rq) + query(2*index+1,mid+1,r,lq,rq);
}

void solve(){
	int n; cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(1,0,n-1);
	int q; cin>>q;
	while(q--){
		int typ; cin>>typ;
		if(typ == 1){
			int x,v; cin>>x>>v;
			update(1,0,n-1,x,v);
		}
		else{
			int l,r; cin>>l>>r;
			cout<<query(1,0,n-1,l,r)<<endl;
		}
	}

}
