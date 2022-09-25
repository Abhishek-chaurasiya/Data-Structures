//WE JUST SIMPLY FOLLOW L-R RANGE SUM PROPERTY NOTHING ELSE
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Q) {
        // Code here
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(int i=0;i<Q.size();i++){
            int a=Q[i][0];
            int b=Q[i][1];
            int c=Q[i][2];
            int d=Q[i][3];
            for(int j=a;j<=c;j++){
                ans[j][b]++;
                if(d+1<n)ans[j][d+1]--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++)ans[i][j]+=ans[i][j-1];
        }
        return ans;
    }
};
