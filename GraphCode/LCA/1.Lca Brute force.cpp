const int siz = 1e5;
vector<int> Par,dep;
vector<vector<int>> G;

void dfs(int node,int par){
    Par[node] = par;
    for(auto nbr:G[node]){
        if(nbr != par){
            dep[nbr] = dep[node] + 1;
            dfs(nbr,node);
        }
    }
}

int lca_brute(int u,int v){
    // Time complexcity - at worst can take O(N)
    if(u == v)return u;
    // we assume that depth of u will always be greater then v
    if(dep[u] < dep[v])swap(u,v);
    while(dep[u] != dep[v]){
        u = Par[u];
    }

    while(u != v){
        u = Par[u];
        v = Par[v];
    }
    return u;
}


void solve(){
    int n; cin>>n;
    Par.assign(n+1,-1);
    dep.assign(n+1,0);
    G.resize(n+1);
    for(int i = 0; i < n - 1; i++){
        int u,v; cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,-1);

    cout<<lca_brute(8,8)<<endl;
}
