int n,m;
int cycle_s,cycle_e;
bool dfs(int node,int p,vector<vi> &G,vector<bool> &vis,vi &par){
    vis[node] = 1;
    par[node] = p;
    debug(node)
    for(auto nbr:G[node]){
        if(!vis[nbr]){
          
            if(dfs(nbr,node,G,vis,par))return true;
        }
        else if(nbr != p){
            cycle_s = nbr;
            cycle_e = node;
            return true;
        }
    }
    return false;
}
void solve(){
    cin>>n>>m;
    vector<vi> G(n+1);
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    vector<bool> vis(n+1,0);
    vector<int> par(n+1,-1);
 
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfs(i,-1,G,vis,par)){
                vi route;
                route.pb(cycle_s);
                while(cycle_e != cycle_s){
                    route.pb(cycle_e);
                    cycle_e = par[cycle_e];
                }
                route.pb(cycle_s);
                cout<<sz(route)<<endl;
                for(auto x:route)cout<<x<<" ";
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;



}
