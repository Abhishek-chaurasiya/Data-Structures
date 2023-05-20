int n,m;
vector<vector<int>> g;
vector<int> dis;
vector<int> parent;

void dfs(int node,int par,int d){
	dis[node] = d;
	parent[node] = par;
	for(auto nbr:g[node]){
		if(nbr!=par){
			dfs(nbr,node,d+1);
		}
	}
}

void solve(){
	cin>>n;
	g.resize(n);
	dis.resize(n);
	parent.resize(n);
	rep(i,0,n-1){
		int a,b; cin>>a>>b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0,-1,0);
	int max1 = 0;
	for(int i=0;i<n;i++){
		if(dis[i] > dis[max1])max1=i;
	}
    debug(max1);

	dfs(max1,-1,0);
	int max2 = 0;
	for(int i=0;i<n;i++){
		if(dis[i] > dis[max2])max2=i;
	}
	debug(parent[7]);
	debug(max2);
	cout<<dis[max2]<<endl;

	vector<int> path;
	int tmp = max2;
	while(tmp != -1){
		path.pb(tmp);
		tmp = parent[tmp];
	}
	cout<<"diameter node"<<" ";
	for(auto x:path)cout<<x<<" ";



	
}
