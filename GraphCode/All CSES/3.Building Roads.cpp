int n,m;

void dfs(int node,vector<vi> &G,vector<bool> &vis){
    vis[node] = 1;
    for(auto nbr:G[node]){
        if(!vis[nbr]){
            dfs(nbr,G,vis);
        }
    }
}

void solve(){
    cin>>n>>m;
    vector<vi> G(n+1);
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    vi comp;
    vector<bool> vis(n+1,0);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            comp.pb(i);
            dfs(i,G,vis);
        }
    }
    cout<<sz(comp)-1<<endl;
    for(int i = 1; i < sz(comp); i++){
        cout<<comp[i] <<" "<<comp[i-1]<<endl;
    }

}
