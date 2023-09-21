Company Queries II - CSES
struct LCA
{
    vector<int> height,euler,first,segtree;
    int n;

    LCA(vector<vi> &adj,int root = 0){
        n = adj.size();
        height.resize(n),first.resize(n);
        dfs(adj,root);
        int m = euler.size();
        segtree.resize(4*m);
        build(1,0,m-1);
    }
    void dfs(vector<vi> &adj,int node,int par = -1,int lev = 0){
        height[node] = lev;
        first[node] = euler.size();
        euler.pb(node);

        for(auto nbr:adj[node]){
            if(nbr == par)continue;
            dfs(adj,nbr,node,lev+1);
            euler.pb(node);
        }
    }
    // In segment tree based on the height we are storing node value 
    void build(int idx,int l,int r){
        if(l == r){
            segtree[idx] = euler[l];
            return;
        }
        int mid = (l + r)>>1;
        build(idx<<1,l,mid);
        build(idx<<1|1,mid+1,r);
        int lval = segtree[idx<<1],rval = segtree[idx<<1|1];
        segtree[idx] = (height[lval] < height[rval])?lval:rval;
    }
    int query(int idx,int l,int r,int lq,int rq){
        if(lq > r || l > rq)return -1;
        if(lq <= l && r <= rq)return segtree[idx];

        int mid = (l + r)>>1;
        int left = query(idx<<1,l,mid,lq,rq);
        int right = query(idx<<1|1,mid+1,r,lq,rq);

        if(left == -1)return right;
        if(right == -1)return left;
        return height[left] < height[right]?left:right;
    }

    int lca(int u,int v){
        int left = first[u], right = first[v];
        if(left > right)swap(left,right);

        return query(1,0,sz(euler) - 1,left,right);
    }
    
};


void solve(){
    int n,q; cin>>n>>q;
    vector<vi> G(n);
    for(ll i = 1; i < n; i++){
        int par; cin>>par;
        par--;
        G[i].pb(par);
        G[par].pb(i);
    }

    LCA L(G);
    while(q--){
        int u,v; cin>>u>>v;
        u--; v--;
        cout<<L.lca(u,v)+1<<endl;
    }


}
