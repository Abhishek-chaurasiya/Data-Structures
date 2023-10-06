int n,m;
void dfs(int node,int col,vector<vi> &G,vector<int> &vis,bool &cycle){
    vis[node] = col;
    for(auto nbr:G[node]){
        if(!vis[nbr]){
            dfs(nbr,3-col,G,vis,cycle);
        }
        else if(vis[nbr] == vis[node]){
            cycle = true;
            return;
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
    vector<int> vis(n+1,0);
    bool cycle = false;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i,1,G,vis,cycle);
            if(cycle){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    for(int i = 1; i <= n; i++)cout<<vis[i]<<" ";
}
