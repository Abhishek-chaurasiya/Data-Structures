class DSU{
    vector<int> par,rank;
    public:
    DSU(int n){
        par.assign(n+1,-1);
        rank.resize(n,1);
    }
    int find(int x){
        if(par[x] == -1)return x;
        return par[x] = find(par[x]);
    }
    void unite(int u,int v){
        int x = find(u), y = find(v);
        if(x != y){
           par[x] = y;
        }
    }
    bool connected(int u,int v){
        return (find(u) == find(v));
    }
    
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        for(int i = 0; i < q.size();i++){
            q[i].push_back(i);
        }
        sort(begin(e),end(e),[&](auto &a,auto &b){ return a[2] < b[2];});
        sort(begin(q),end(q),[&](auto &a,auto &b){ return a[2] < b[2];});
       
        DSU d(n);
        vector<bool> ans(q.size());
        int i = 0;
        for(auto que:q){
            int u = que[0],v=que[1],lim=que[2],qid=que[3];
            for(;i<e.size() && e[i][2] < lim;i++){
                d.unite(e[i][0],e[i][1]);
            }
            ans[qid] = d.connected(u,v); 
        }
        return ans;
    }
};
