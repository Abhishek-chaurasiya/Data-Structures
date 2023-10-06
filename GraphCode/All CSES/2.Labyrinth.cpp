int n,m; 

void solve(){
    cin>>n>>m;
    vector<vector<char>> G(n,vector<char>(m));
    pair<int,int> st;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>G[i][j];
            if(G[i][j] == 'A')st = {i,j};
        }
    }
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    vector<vector<pii>> par(n,vector<pii>(m,{-1,-1}));
    
    queue<pii> q; q.push(st);
    bool reached = false;
    pair<int,int> end;
    vis[st.fr][st.sc] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        debug(cur)
        if(G[cur.fr][cur.sc] == 'B'){
            end = {cur.fr,cur.sc};
            reached = true; 
            break;
        }
        for(int i = 0; i < 4; i++){
            int nr = cur.fr + dx[i];
            int nc = cur.sc + dy[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] || G[nr][nc] == '#')continue;
            vis[nr][nc] = 1;
            q.push({nr,nc});
            par[nr][nc] = {cur.fr,cur.sc};

        }

    }
    if(!reached){
        cout<<"NO"<<endl; return;
    }
    debug(par[1][2]);
    string steps;
    pair<int,int> bar = { -1,-1};
    while(par[end.fr][end.sc]!= bar){
        pii pc = par[end.fr][end.sc];
        if(end.sc == pc.sc){
            if(end.fr < pc.fr)steps += "U";
            else steps += "D";
        }
        else{
            if(end.sc < pc.sc)steps += "L";
            else steps += "R";
        }
        end = pc;
    }
    reverse(all(steps));
    cout<<"YES"<<endl;
    cout<<steps.size()<<endl;
    cout<<steps<<endl;
}
