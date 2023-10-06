int n,m;



void solve(){
    cin>>n>>m;
    vector<vi> G(n+1);
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    vector<int> par(n+1,-1);
    bool reached = false;
    queue<int> q; q.push(1);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == n){
            reached = true;
            break;
        }
        for(auto nbr:G[cur]){
            if(nbr != 1 && par[nbr] == -1){
                q.push(nbr);
                par[nbr] = cur;
            }
        }
    }
    if(!reached){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> route;
    while(n != -1){
        route.pb(n);
        n = par[n];
    }
    cout<<sz(route)<<endl;
    reverse(all(route));
    for(auto x:route)cout<<x<<" ";



}
