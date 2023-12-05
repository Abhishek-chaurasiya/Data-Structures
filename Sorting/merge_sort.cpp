void merge(int l,int mid,int h,vector<int> &a){
	vi tmp;
	int i = l, j = mid + 1;
	while(i <= mid && j <= h){
		if(a[i] <= a[j]){
			tmp.pb(a[i++]);
		}
		else tmp.pb(a[j++]);
	}
	while(i <= mid)tmp.pb(a[i++]);
	while(j <= h)tmp.pb(a[j++]);

	for(int i = l; i <= h; i++)a[i] = tmp[i - l];

}

void mergesort(int l, int h,vi &a){
	if(l >= h)return ;
	int mid = (l + h)>>1;
	mergesort(l,mid,a);
	mergesort(mid + 1,h,a);

	merge(l,mid,h,a);
}

void solve(){
	int n; cin>>n;
	vector<int> a(n);
	rep(i,0,n)cin>>a[i];
	mergesort(0,n-1,a);

	for(auto x:a)cout<<x<<" ";
}
