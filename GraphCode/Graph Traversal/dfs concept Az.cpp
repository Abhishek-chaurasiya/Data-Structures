// we cleverly store in visted array that a particular node belongs
// to which component - but what is the profit in doing this?
// Lets assume a case where we have Q QUERIES (a,b)and we have to answer
// does a and b belong to same component or not 
// in this case this method is quite useful

vector<vector<int>> g;
vector<int> vis;


void dfs(int node,int comp){
	vis[node] = comp;
	for(auto nbr:g[node]){
		if(!vis[nbr]){
			dfs(nbr,comp);
		}
	}
}

void solve(){
	int n,m; cin>>n>>m;
	g.clear();
	g.resize(n);
	vis.resize(n,0);
	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	int comp = 0;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			comp++;
			dfs(i,comp);
		}
	}
	debug(vis);
	vector<int> nodes_in_component(comp+1);
	for(int i=0;i<n;i++){
		nodes_in_component[vis[i]]++;
	}
	debug(nodes_in_component)

	     
}
