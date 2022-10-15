
   int n,m;
   int dx[4]={1,-1,0,0};
   int dy[4]={0,0,1,-1};
    
    bool isvalid(int x,int y,vector<vector<int>> &grid){
        if(x<0||x>=n ||y<0||y>=m||grid[x][y]==0)return false;
        return true;
    }
   
   
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<int,int>> q;
        q.push(source);
        bool reached=false;
        int desCnt=0;
        if(source==destination)return 0;
        n=grid.size(),m=grid[0].size();
        while(!q.empty()){
            
           int siz=q.size();
          for(int k=0;k<siz;k++){ 
            auto cur=q.front(); q.pop();
            for(int i=0;i<4;i++){
                int xx=cur.first+dx[i];
                int yy=cur.second+dy[i];
                if(isvalid(xx,yy,grid) && grid[xx][yy]!=-1){
                   q.push({xx,yy});
                   grid[xx][yy]=-1;
                   if(xx==destination.first && yy==destination.second){
                       reached=true;
                       desCnt++;
                       return desCnt;
                   }
                }
            }
          }
          desCnt++;
        }
        return -1;
    }
