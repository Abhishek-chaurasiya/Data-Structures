// We basically forms a cluster of ones inside dsu and then we check in each grid[i][j] where it is 0 that by repacing it to one what can be 
// the maximum island we can form.



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
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        int N = grid.size(), M = grid[0].size();
        DSU d(N*M);
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 0)continue;
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 0||x >= N||y < 0||y >= M||grid[x][y] == 0)continue;
                    d.unite(i*M + j, x*M + y);
                }
                ans = max(ans,d.getSize(i*M + j));
            }
        }
     
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 1)continue;
                unordered_map<int,int> m;
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 0||x >= N||y < 0||y >= M||grid[x][y] == 0)continue;
                    m[d.find(x*M + y)] = d.getSize(x*M + y);
                }
                int size = 1;
                for(auto &x:m)size += x.second;
                ans = max(ans,size);
            }
        }
        
        return ans;
        
    }
};
