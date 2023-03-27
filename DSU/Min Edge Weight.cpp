Description

You are given a weighted tree of N nodes. D(u,v) is defined as the minimum weight of edge in the simple path from u to v.  Find the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v.

Input Format

The first line of input contains one integer T (1 ≤ T ≤ 105) — the number of test cases. Then T test cases follow.
The first line of each test case contains an integer N - the number of nodes in the tree (1 ≤ N ≤ 105).
The next N-1 line of each test case contains 3 space-separated integers u, v, w  denoting that there is an edge between node u and node v of weight w. (1 ≤ u,v ≤ N), (1 ≤ w ≤ 109 ).

It is guaranteed that the sum of N over all test cases does not exceed 106.

Output Format

For each test case print the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v in a new line.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class DSU{
  public:
  	  vector<int> par,rank;
  	DSU(int n){
  		par.resize(n+1);
  		rank.resize(n+1);
  		rep(i,0,n+1){
  			par[i] = i;
  			rank[i] = 1;
  		}
  		 
  	}
  
  	int find(int x){
  		if(par[x] == x)return x;
		return par[x] = find(par[x]);
  	}
  	void unite(int u,int v){
  		int x = find(u);
  		int y = find(v);
  	
  		if(x == y)return;
  		if(rank[x] >= rank[y]){
  			par[y] = x;
  			rank[x] += rank[y];
  		}
  		else {
  			par[x] = y;
  			rank[y] += rank[x];
  		}
  	

  	}

};

void solve(){
    
    int n;cin>>n;
    DSU d(n);
    vector<pair<int,pii>> edges;
    rep(i,0,n-1){
    	int u,v,w; cin>>u>>v>>w;
    	edges.pb({w,{u,v}});
    }
    // full uitilization of sorting as the picked node will always be minimum 
    sort(all(edges));
    reverse(all(edges));

    int ans = 0;
    for(int i=0;i<n-1;i++){
    	int u = edges[i].sc.fr;
    	int v = edges[i].sc.sc;
    	int w = edges[i].fr;
    	
    	int xroot = d.find(u);
    	int yroot = d.find(v);

    	if(xroot != yroot){
    		ans += 1LL*d.rank[xroot]*d.rank[yroot]*w;
    		d.unite(u,v);
    	}
    }
    cout<<ans<<endl;
	
	
}
