Basically a problem is checking if nodes are under the same component or not it just twiking with the binary search .
A unique thing was that even in a connected graph we can find a connected components .
  
int n,m;
vector<int> cows;
vector<vector<pii>> g;
vector<int> vis;

void dfs(int cow,int comp,int mid){
	vis[cow] = comp;
	for(auto nbr:g[cow]){
		if(vis[nbr.fr]==0 && (nbr.sc >= mid)){
			dfs(nbr.fr,comp,mid);
		}
	}
}

bool ispoosible(int mid){
	vis.assign(n,0);
	int comp = 1;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,comp,mid);
			comp++;
		}

	}
	bool sortable = true;
	for(int i=0;i<n;i++){
		if(vis[i] != vis[cows[i]]){
			sortable  = false;
			break;
		}
	}
	if(mid  == 10){
		debug(vis)
	}
	return sortable;
}

void solve(){
	cin>>n>>m;
	g.resize(n);
	cows.resize(n);
	rep(i,0,n){
		cin>>cows[i];
		cows[i]--;
	}
	int maxWidth = 0;
	rep(i,0,m){
		int a,b,w; cin>>a>>b>>w;
		a--;b--;
		g[a].pb({b,w});
		g[b].pb({a,w});
		maxWidth = max(maxWidth,w);
	}
	int l = 0,h = maxWidth+1;

	while(l < h){
		int mid = l + (h-l+1)/2;
		if(ispoosible(mid)){
			l = mid;
		}
		else h = mid-1;
	}
	if(l == maxWidth+1){
		cout<<-1<<endl;return;
	}
	cout<<l<<endl;



}
  
