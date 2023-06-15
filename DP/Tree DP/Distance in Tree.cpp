vector<vi> G;
int indp[50001][501], outdp[50001][501];

void dfs1(int node,int par,int &k){
	for(auto nbr:G[node]){
		if(nbr!=par)dfs1(nbr,node,k);
	}
	// #in subtree of node what is the no of node which are at
	// distance 0 (basically it's the node itself)
	indp[node][0] = 1;
	for(int dis = 1; dis <= k; dis++){
		for(auto nbr:G[node]){
			if(nbr != par)indp[node][dis] += indp[nbr][dis-1];
		}
	}
}

void dfs2(int node,int par,int &k){
	
	for(int dis = 0; dis <= k; dis++){
		outdp[node][dis] = indp[node][dis];
	}

	if(par != -1){
		outdp[node][1] += outdp[par][0];
		for(int dis = 2; dis <= k; dis++){
			outdp[node][dis] += outdp[par][dis-1];
			outdp[node][dis] -= indp[node][dis-2];
		}
	}
	for(auto nbr:G[node]){
		if(nbr != par){
			dfs2(nbr,node,k);
		}
	}
}
void solve(){
	int n,k; cin>>n>>k;
	G.resize(n+2);
	rep(i,0,n-1){
		int x,y; cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	memset(indp,0,sizeof indp);
	memset(outdp,0,sizeof outdp);

	dfs1(1,-1,k);
	dfs2(1,-1,k);

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans +=  outdp[i][k];
		debug(ans)
	}
	cout<<ans/2<<endl;

}

