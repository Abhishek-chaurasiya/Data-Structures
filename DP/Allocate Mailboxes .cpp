
class Solution {
public:
    int cost[101][101];
    int dp[101][101];
    
    int helper(int i,int k,vector<int> &houses){
        if(i==houses.size() && k==0)return 0;
        if(i==houses.size() || k==0)return INT_MAX/4;
        
        if(dp[i][k] != -1)return dp[i][k];
        int ans=INT_MAX;
        
        for(int j=i;j<houses.size();j++){
            ans = min(ans,cost[i][j]+helper(j+1,k-1,houses));
        }
        
        return dp[i][k] = ans;
    }
    
    int minDistance(vector<int>& houses, int k) {
        
        int n = houses.size();
        memset(dp,-1,sizeof dp);
        sort(houses.begin(),houses.end());
      
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int median = houses[(i+j)/2];
                for(int m=i;m<=j;m++){
                    cost[i][j]+=abs(median - houses[m]);
                }
            }
        }
        
        return helper(0,k,houses);
    }
};
