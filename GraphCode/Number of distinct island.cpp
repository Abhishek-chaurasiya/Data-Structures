
class Solution {
  public:
    int n,m;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    void dfs(int x,int y,int i,int j,vector<vector<int>>& grid,  vector<pair<int,int>> &v){
        if(i<0||i>=n||j<0||j>=m||grid[i][j]<=0)return ;
        grid[i][j]=-1;
        v.push_back({i-x,j-y});
        for(int k=0;k<4;k++){
            int xx=i+dx[k];
            int yy=j+dy[k];
            dfs(x,y,xx,yy,grid,v);
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        n=grid.size();
        m=grid[0].size();
        set<vector<pair<int,int>> > cor;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>> v;
                    dfs(i,j,i,j,grid,v);
                    cor.insert(v);
                }
            }
        }
        return cor.size();
        
    }
};

