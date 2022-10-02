class Solution {
public:
    int mod=1e9+7;
    int solve(int n,int k,int sum,int target,vector<vector<int>> &dp){
        if(n==0){
            return sum==target;
        }
        if(sum>target)return 0;
        if(dp[n][sum]!=-1)return dp[n][sum];
        int ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+solve(n-1,k,sum+i,target,dp))%mod;
        }
        return dp[n][sum]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        int sum=0;
        vector<vector<int>> dp(n+1,vector<int>(1001,-1));
        return solve(n,k,sum,target,dp);
    }
};
