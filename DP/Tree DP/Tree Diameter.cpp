const int siz = 2e5+10;
int dp[siz][2], diameter;


void dfs(int node,int par,vector<vi> &G){
    if(node != 1 && (int)G[node].size() == 1){
        dp[node][0] = dp[node][1] = 0;
        return;
    }

    vector<int> fval;

    for(auto nbr:G[node]){
        if(nbr != par){
            dfs(nbr,node,G);
            fval.pb(dp[nbr][0]);
        }
    }
    sort(begin(fval),end(fval));

    int numchild = fval.size();
    if(numchild == 1){
        dp[node][0] = 1 + fval[sz(fval) - 1];
        dp[node][1] = 0;
    }
    else{
        dp[node][0] = 1 + fval[sz(fval) - 1];
        dp[node][1] = 2 + fval[sz(fval)-1] + fval[sz(fval)-2];
    }

    diameter = max(diameter,max(dp[node][0],dp[node][1]));

}

void solve(){
    memset(dp,0,sizeof dp);
    int n; cin>>n;
    if(n == 1){
        cout<<0<<endl;
        return;
    }
    vector<vector<int>> G(n+1);
    diameter = 0;

    for(int i = 0; i < n-1; i++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1,G);

    cout<<diameter<<endl;

}
