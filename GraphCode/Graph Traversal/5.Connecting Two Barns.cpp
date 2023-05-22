ll n,m;
const int maxn = 2e5;
vector<vector<ll>> g(maxn),comp(maxn);
vector<ll> com(maxn);

void dfs(ll node,ll c){
	com[node] = c;
	for(auto nbr:g[node]){
		if(!com[nbr]){
			dfs(nbr,c);
		}
	}
}

ll cost(ll a,ll b){
	ll dis = INT_MAX;
	for(auto u:comp[a]){
		ll i = lb(all(comp[b]),u)-begin(comp[b]);
		if(i)dis = min(dis,abs(comp[b][i-1] - u));
		if(i < sz(comp[b]))dis = min(dis,abs(comp[b][i] - u));
	}
	return dis*dis;
}

void solve(){
	cin>>n>>m;
	rep(i,0,n){
		g[i].clear();
		comp[i].clear();
		com[i] = 0;
	}
	
	
	rep(i,0,m){
		ll u,v; cin>>u>>v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
    ll c = 0;
	for(ll i=0;i<n;i++){
		if(!com[i]){
			dfs(i,++c);
		}
	}
	for(ll i=0;i<n;i++){
		comp[com[i]].pb(i);
	}
    // 0 is in which component and n-1 is in which component
    // debug(com)
	ll res = cost(com[0],com[n-1]);
    // debug(res)
	for(ll i=2;i<c;i++){
		res = min(res,cost(i,com[0])+cost(i,com[n-1]));
		// debug(res)
	}
  
   cout<<res<<endl;


}
