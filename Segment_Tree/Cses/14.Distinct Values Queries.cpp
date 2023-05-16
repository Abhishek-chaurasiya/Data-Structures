		int left = query(index<<1,l,mid,lq,rq);
		int right = query(index<<1|1,mid+1,r,lq,rq);
		return (left+right);
   }
};
 
map<int,int> ccomp;
SegmentTree st;
 
 
 
void solve(){
	int n,q; cin>>n>>q;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<pair<pii,int>> Q;
	for(int i=0;i<q;i++){
		int a,b; cin>>a>>b;
		a--; b--;
		Q.pb({{a,b},i});
	}
 
	sort(all(Q));
	vector<int> ans(q);
	int cur = n-1;
	for(int i=q-1;i>=0;i--){
		int x = Q[i].fr.fr,y = Q[i].fr.sc;
		while(cur >= x){
			if(ccomp.count(a[cur]))st.update(1,0,n-1,ccomp[a[cur]],-1);
			ccomp[a[cur]] = cur; 
		    st.update(1,0,n-1,cur,1);
		    cur--;
		}
		ans[Q[i].sc] = st.query(1,0,n-1,x,y);
	}
	for(auto x:ans)cout<<x<<endl;
 
 
	
}
 
 
int main(){
 
 fast; 
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("Error.txt", "w", stderr);
#endif
 
 int tests=1;
  while(tests--)
  solve();
 
 
}
