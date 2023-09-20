class Solution {
public:
    vector<int> indp,outdp;
    void dfs(int node,int par,vector<vector<pair<int,int>>> &G){
        
        for(auto nbr:G[node]){
            if(nbr.first == par)continue;
            dfs(nbr.first,node,G);
            indp[node] += indp[nbr.first] + nbr.second;
        }
    }
    void dfs2(int node,int par,vector<vector<pair<int,int>>> &G,int cont = 0){
        if(par == -1)outdp[node] = 0;
        else{
            outdp[node] = outdp[par];
            outdp[node] += indp[par] - indp[node] - cont + !cont;
        }
         for(auto nbr:G[node]){
            if(nbr.first == par)continue;
            dfs2(nbr.first,node,G,nbr.second);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& E) {
        vector<vector<pair<int,int>>> G(n);
        vector<int> ind(n,0);
        indp.assign(n,0), outdp.assign(n,0);
        for(auto &e:E){
            ind[e[1]]++;
            G[e[0]].push_back({e[1],0});
            G[e[1]].push_back({e[0],1});
        }
        
        dfs(0,-1,G);
        dfs2(0,-1,G);
        vector<int> ans(n);
        for(int i = 0; i < n; i++)ans[i] = indp[i] + outdp[i];
        
        return ans;
    }
};
