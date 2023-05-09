vi arr(100100);
struct node
{
	int mini,cnt;
	node(int m=1e9,int c=0){
		mini = m;
		cnt = c;
	}
};
vector<node> t(400100);

node merge(node a,node b){
	if(a.mini == b.mini){
		return node(a.mini,a.cnt+b.cnt);
	}
	else if(a.mini < b.mini)return a;
	else return b;
}

void build(int index,int l,int r){
	if(l == r){
		t[index] = node(arr[l],1);
		return;
	}
	int mid = (l+r)/2;
	build(2*index,l,mid);
	build(2*index+1,mid+1,r);
	t[index] = merge(t[2*index] , t[2*index+1]);
	
}
void update(int index,int l,int r,int pos,int val){
	if(pos<l || pos>r)return;
	if(l == r){
		t[index] = node(val,1);
		arr[index] = val;
		return;
	}
	int mid = (l+r)/2;
	update(2*index,l,mid,pos,val);
	update(2*index+1,mid+1,r,pos,val);
	t[index] = merge(t[2*index] , t[2*index+1]);
	
}
node query(int index,int l,int r,int lq,int rq){
	if(l>rq || lq>r)return {INT_MAX,0};
	if(lq<=l && r<=rq){
		return t[index];
	}
	int mid = (l+r)/2;
	auto left = query(2*index,l,mid,lq,rq);
	auto right = query(2*index+1,mid+1,r,lq,rq);
	return merge(left,right);

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
			auto ans = query(1,0,n-1,l,r);
			cout<<ans.mini<<" "<<ans.cnt<<endl;
		}
	}
	

}
