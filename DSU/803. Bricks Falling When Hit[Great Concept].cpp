class DSU{
    vector<int> par,rank;
    public:
    DSU(int n){
        par.resize(n,-1);
        rank.resize(n,1);
    }
    int find(int x){
		if(par[x] == -1)return x;
		return par[x] = find(par[x]);
	}

	void unite(int u,int v){
		int x = find(u), y = find(v);
		if(x == y)return;
       
		if(rank[x] < rank[y])swap(x,y);
		
        rank[x] += rank[y];
		par[y] = x;
	}
    int getSize(int x){
        return rank[find(x)];
    }
    
    int getTopSize(){
        return getSize(rank.size()-1) - 1;
    }
    
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& OldGrid, vector<vector<int>>& hits) {
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        int R = OldGrid.size(), C = OldGrid[0].size();
        vector<vector<int>> NewGrid(R,vector<int>(C,0));
        for(int i = 0; i <R; i++){
            NewGrid[i] = OldGrid[i];
        }
        
        DSU d(R*C + 1);
        
        for(auto hit:hits){
            NewGrid[hit[0]][hit[1]] = 0;
        }
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(NewGrid[i][j] == 1){
                    int pos = i*C + j;
                    if(i == 0)d.unite(pos,R*C);
                    if(i >0 && NewGrid[i-1][j] == 1)d.unite(pos,(i-1)*C + j);
                    if(j > 0 && NewGrid[i][j-1] == 1)d.unite(pos,i*C + j-1);
                }
            }
        }
        int T = hits.size();
        vector<int> ans(T,0);
        for(int t = T - 1; t >= 0; t--){
       
            int r = hits[t][0], c = hits[t][1];
            if(OldGrid[r][c] == 0){
                continue;
            }
            int InitRoofAttached = d.getTopSize();
            int i = r*C + c;
            for(int k = 0; k < 4; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                if(nr < 0 || nr >= R || nc <0 || nc >= C || NewGrid[nr][nc] == 0)continue;
                d.unite(i,nr*C + nc);
            }
            if(r == 0)d.unite(i,R*C);
            ans[t] = max(0,d.getTopSize() - InitRoofAttached - 1);
            NewGrid[r][c] = 1;
            
        }
        
        return ans;
        
        
    }
};
