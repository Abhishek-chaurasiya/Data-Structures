P- You have given an undirected graph G with N nodes, indexed from 1 to N and M edges, indexed from 1 to M.

There are two types of operations:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.

Input Format

The first line of contains three space-separated numbers N, M, Q (1 ≤ N, M, Q ≤ 100000).

The next M lines contain 2 space-separated integers u and v which depicts an edge between nodes u and v (1 ≤ u, v ≤ N). ith line denotes the ith edge.

This is followed by Q lines, each describing an operation in the following format:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.

There are no self-loops or multiple edges in the graph.

Note: If there are multiple queries for removal of the same edge, then the last such query should be considered. Also, the index of the edges does not change after the removal of any of the edges between the nodes.
  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
class DSU{
  vector<int> par,rank;
  public:
  	int comp;
  	DSU(int n){
  		par.resize(n+1);
  		rank.resize(n+1);
  		rep(i,0,n+1){
  			par[i] = i;
  			rank[i] = 1;
  		}
  		
  		comp = n;
  	}
  	int find(int x){
  		if(par[x] == x)return x;
  		return par[x] = find(par[x]);

  	}
  	void unite(int u,int v){
  		int x = find(u),y=find(v);
  		if(x == y)return;
  		if(rank[x] >= rank[y]){
  			par[y] = x;
  			rank[x] += rank[y];
  		}
  		else {
  			par[x] = y;
  			rank[y] += rank[x];
  		}
  		comp--;

  	}

};

void solve(){

	int n,m,q; cin>>n>>m>>q;
	vector<pii> edges(m+1);
	vector<bool> marked(m+1,0);
	rep(i,1,m+1){
		int u,v; cin>>u>>v;
		edges[i] = {u,v};
	}
	vector<pii> query(q+1);
	for(int i=1;i<=q;i++){
		int t; cin>>t;
		if(t == 2)query[i]={2,-1};
		else{
			int idx; cin>>idx;
			query[i] = {1,idx};
			marked[idx] = 1;
		}

	}
	DSU d(n);

	for(int i=1;i<=m;i++){
		if(!marked[i]){
			d.unite(edges[i].fr,edges[i].sc);
		}
	}
	vector<int> ans;

	for(int i=q;i>=1;i--){
		if(query[i].first == 2)ans.pb(d.comp);
		else{
			int idx = query[i].sc;
			d.unite(edges[idx].fr,edges[idx].sc);
		}
	} 
	debug(ans);
	reverse(all(ans));
	for(auto x:ans)cout<<x<<endl;
	
}  
