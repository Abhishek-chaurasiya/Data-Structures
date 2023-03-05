


void solve(){
	int n; cin>>n;
	vi a(n),insertedAt(n);rep(i,0,n)cin>>a[i];
	vi lis,finalLis;

	for(int i=0;i<n;i++){
		if(lis.empty()||lis.back()<a[i]){
			lis.pb(a[i]);
			// at which index this i th element was inserted
			insertedAt[i]=lis.size();
			// we can do -1 its matter of preference
		}
		else{
			auto it=lb(all(lis),a[i]);
			*it=a[i];
			insertedAt[i]=it-lis.begin()+1;
		}
		cout<<i<<":"<<" ";
		for(auto x:lis)cout<<x<<",";
	    cout<<endl;
	}
	int curlen=lis.size();
	for(int i=n-1;i>=0;i--){
		if(insertedAt[i]==curlen){
			finalLis.pb(a[i]);
			curlen--;
		}
	}
	for(auto x:insertedAt)cout<<x<<" ";
    cout<<endl;
    reverse(begin(finalLis),end(finalLis));
    for(auto x:finalLis)cout<<x<<" ";
    cout<<endl;
	cout<<sz(lis);
	
}
