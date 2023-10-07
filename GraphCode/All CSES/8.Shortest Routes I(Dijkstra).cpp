ll n,m;
vector<vector<pll>> G;

void Dijkstra(){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<ll> dis(n+1,1e18);
    dis[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        ll wt = cur.fr, node = cur.sc;
        if(wt > dis[node])continue;

        for(auto child:G[node]){
            ll cost = child.sc;
            if(dis[child.fr] > dis[node] + cost){
                dis[child.fr] = dis[node] + cost;
                pq.push({dis[child.fr],child.fr});
            }
        }
    }
    for(ll i = 1; i <= n; i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}

void solve(){
     cin>>n>>m;
    G.resize(n+1);
    rep(i,1,n+1)G[i].clear();
    rep(i,0,m){
        int u,v,wt; cin>>u>>v>>wt;
        G[u].pb({v,wt});
    }
    Dijkstra();
}

