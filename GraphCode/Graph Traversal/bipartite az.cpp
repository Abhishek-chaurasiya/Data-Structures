vector<vector<int>> g;
vector<int> vis;
bool isbip;

void dfs(int node,int col){
	vis[node] = col;
	for(auto nbr:g[node]){
		if(!vis[nbr]){
			dfs(nbr,3-col);
		}
		else if(vis[nbr] == vis[node]){
			isbip = false;
		}
	}
}

void solve(){
	int n,m; cin>>n>>m;
	g.clear();
	g.resize(n);
	vis.resize(n,0);
	isbip = true;
	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,1);
		}
	}

	cout<<isbip<<endl;

}
