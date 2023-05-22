ll n,m;
const int maxn = 2e3;
vector<vector<int>> adj(maxn),adjT(maxn);
vector<bool> vis(maxn);

void dfs(ll node,stack<int> &st){
	vis[node] = 1;
	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			dfs(nbr,st);
		}
	}
	st.push(node);
}

void dfs2(ll node,vector<int> &ans){
	vis[node] = 1;
	for(auto nbr:adjT[node]){
		if(!vis[nbr]){
			dfs2(nbr,ans);
		}
	}
	ans.pb(node);
}



void solve(){
	cin>>n>>m;
	rep(i,0,n){
		adj[i].clear();
		vis[i] = 0;
	}

	rep(i,0,m){
		ll u,v; cin>>u>>v;
		adj[u].pb(v);
		adjT[v].pb(u);
	}

	stack<int> st;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,st);
		}
	}
	vis.assign(n,0);
	int scc = 0;
	vector<vi> sccComp;
	while(!st.empty()){
		int node = st.top(); st.pop(); 
		if(!vis[node]){
			vector<int> sccnodes;
			dfs2(node,sccnodes);
			scc++;
			sccComp.pb(sccnodes);
		}
	}
	cout<<scc<<endl;
	debug(sccComp)
   


}
