int n,m; 
void dfs(int r,int c,vector<vector<char>>& G,vector<vector<bool>> &vis){
    if(r < 0 || r >= n || c < 0 || c >= m || G[r][c] == '#' || vis[r][c])return;
    vis[r][c] = 1;
    for(int i = 0; i < 4; i++){
        int nr = r + dx[i], nc = c + dy[i];
        dfs(nr,nc,G,vis);
    }
}

void solve(){
    cin>>n>>m;
    vector<vector<char>> G(n,vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>G[i][j];
        }
    }
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    int rooms = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && G[i][j] == '.'){
                dfs(i,j,G,vis);
                rooms++;
            }
        }
    }
    cout<<rooms<<endl;
}
