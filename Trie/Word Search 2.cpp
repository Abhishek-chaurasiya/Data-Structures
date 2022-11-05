///////////////////////////////////////////////////////////////////////BRUTE FORCE APPROACH///////////////////////////////////////////////////////////////////////
class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int n, m;
    bool isvalid(int x,int y,vector<vector<char>>& board){
        if(x<0||x>=n||y<0||y>=m)return false;
        return true;
    }
    void dfs(int x,int y,vector<vector<char>>& board,string str,bool &flag,int idx){
        
        if(idx>=str.size()){
            flag =true; return;
        }
        
        for(int i=0;i<4;i++){
            int curx=x+dx[i];
            int cury=y+dy[i];
            if(isvalid(curx,cury,board) && board[curx][cury]!='&'){
                if(board[curx][cury]==str[idx]){
                    char oc= board[curx][cury];
                    board[curx][cury]='&';
                    dfs(curx,cury,board,str,flag,idx+1);
                    board[curx][cury]=oc;
                }
            }
        }
        
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         n = board.size() , m = board[0].size();
        vector<string> ans;
        
        for(auto str:words){
            for(int i=0;i<n;i++){
                bool flag=false;
                for(int j=0;j<m;j++){
                    if(board[i][j]==str[0]){
                        char oc=board[i][j];
                        board[i][j]='&';
                        dfs(i,j,board,str,flag,1);
                        board[i][j]=oc;
                        if(flag){
                            ans.push_back(str);
                            break;
                        }
                    }
                }
                if(flag)break;
            }
        }
        
        return ans;
    }
};
