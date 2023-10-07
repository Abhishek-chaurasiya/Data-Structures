int n,m;
vector<vi> g;
vector<pii> monsters;
map<pii,pii> par;
pii start,endd;

bool isValid(int r,int c,int timer){
    if(r < 0 || r >= n || c < 0 || c >= m)return 0;
    // this is invalid position or lava has already reached here at some previous time
    if(g[r][c] <= timer)return 0;

    return 1;
}

bool isescapePoint(int r,int c,int timer){
    if(!isValid(r,c,timer))return 0;
    if(r == 0 || r == n - 1 || c == 0 || c == m-1)return 1;
    return 0;
}

void PreMultisrcBFS(){
    queue<pair<pii,int>> q;
    for(auto m:monsters)q.push({m,0});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.fr.fr, y = cur.fr.sc;
        int timer = cur.sc;
        timer++;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(isValid(nx,ny,timer)){
                g[nx][ny] = timer;
                q.push({{nx,ny},timer});
            }
        }
    }    
}

bool isEscape(){
    queue<pair<pii,int>> q;
    q.push({start,0});
    par[start] = {-1,-1};

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.fr.fr, y = cur.fr.sc;
        int timer = cur.sc;
        timer++;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(isescapePoint(nx,ny,timer)){
                par[{nx,ny}] = {x,y};
                endd = {nx,ny};
                return true;
            }

            if(isValid(nx,ny,timer)){
                par[{nx,ny}] = {x,y};
                g[nx][ny] = timer;
                q.push({{nx,ny},timer});
            }
        }
    }
    
    return false;
}

void solve(){
    cin>>n>>m;
    g.resize(n);
    rep(i,0,n)g[i].resize(m);
    rep(i,0,n){
        rep(j,0,m){
            char c; cin>>c;
            if(c == '#')g[i][j] = 0;
            else if(c == 'M') {
                g[i][j] = 0;
                monsters.pb({i,j});
            }
            else if(c == 'A'){
                g[i][j] = 0;
                start = {i,j};
            }
            else g[i][j] = INT_MAX;
        }
    }
  
    if(start.fr == 0 || start.fr == n -1 || start.sc == 0 || start.sc == m-1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
    }
    PreMultisrcBFS();
    if(!isEscape()){
        cout<<"NO"<<endl;
        return;
    }
    string steps;

    while(endd != start){
        auto pr = par[endd];
        if(pr.fr == endd.fr){
            if(pr.sc < endd.sc)steps+= "R";
            else steps += "L";
        }
        else{
            if(pr.fr < endd.fr)steps+= "D";
            else steps+= "U";
        }
        endd = pr;
    }
    reverse(all(steps));
    cout<<"YES"<<endl;
    cout<<sz(steps)<<endl;
    cout<<steps<<endl;
}
