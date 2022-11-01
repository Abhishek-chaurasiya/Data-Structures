class Solution {
public:
    int m ,n;
    vector<int> findBall(vector<vector<int>>& grid) {
     
       m=grid.size(), n=grid[0].size();
        vector<int> ans(n);
        
        for(int j=0;j<n;j++){
            int row=0,col=j;
            while(row<m && !isblocked(grid,row,col)){
                col+=grid[row][col];
                row+=1;
            }
            ans[j]=(row==m)?col:-1;
        }
        return ans;
    }
    bool isblocked(vector<vector<int>>& grid,int row, int col){
        
        return ((grid[row][col]==1 && col==n-1)
               ||(grid[row][col]==-1 && col==0)
               ||(grid[row][col]==1 && grid[row][col+1]==-1)
               ||(grid[row][col]==-1 && grid[row][col-1]==1));
    }
};
