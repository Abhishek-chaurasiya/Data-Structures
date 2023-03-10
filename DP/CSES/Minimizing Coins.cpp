------------------------Approach 1 Top down-------------------------------------
State - dp(idx,sum) is the minimum nuber of coins required to make sum = sum
            index [idx,n-1]
Transition - dp(idx,sum-coins[idx-1]) and dp(idx+1,sum)

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx,int amount,vector<int>&coins){
        if(idx == coins.size()){
            if(amount == 0)return 0;
            return INT_MAX/2;
        }
        if(dp[idx][amount] != -1)return dp[idx][amount];
        
        int op1 = INT_MAX/2, op2 = INT_MAX/2;
        if(amount>=coins[idx])op1 = 1+ solve(idx,amount-coins[idx],coins);
        op2 = solve(idx+1,amount,coins);
        
        return dp[idx][amount] = min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        int ans = solve(0,amount,coins);
        return ans==INT_MAX/2?-1:ans;
    }
};

------------------------Approach 2 Optimized Top down--------------------------
State - dp(sum) is the minimum number of coins required to make the  sum =
           sum
Transition - dp(sum-x)  0 <= x < coins.size() 		   
class Solution {
public:
   
    vector<int> dp;
    int solve(int amount,vector<int>&coins){
        if(amount == 0)return 0;
        if(dp[amount] != -1)return dp[amount];
        
        int ans = INT_MAX/2;
        for(int i=0;i<coins.size();i++){
            if(amount>=coins[i])ans = min(ans,1 + solve(amount-coins[i],coins));
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-1);
        
        int ans = solve(amount,coins);
        return ans==INT_MAX/2?-1:ans;
    }
};

------------------------Approach 2 Optimized bottom up-------------------------
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<int> dp(amount+1,INT_MAX/2);
        dp[0]=0;
        // we only require the minimum number of coins needed to make the
		// amount so we done this way that what are all sum that need a ith coin
        for(int i=0;i<n;i++){
            for(int sum=0;sum<=amount;sum++){
                if(sum-coins[i]>=0)dp[sum]=min(dp[sum],1+dp[sum-coins[i]]);
            }
        }
        return dp[amount]==INT_MAX/2?-1:dp[amount];
    }
};
