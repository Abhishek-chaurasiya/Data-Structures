--------------------------------Approach 1 Top down -------------------------------
State - dp(idx,sumLeft)
Transition - 
              1. You can pick multiple times so for that a clean way is to stay in the
                 same index dp(idx,sumLeft-coins[idx]) if possible
			  2. move to the next index dp(idx+1,sum)
dp(idx,sumLeft) is number way to make sum = sumLeft from index [idx,n-1]

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(int idx,int sum,vector<int>&coins){
      if(idx == n) return (sum == 0);
      if(sum == 0) return 1;
	  
      if(dp[idx][sum]!=-1)return dp[idx][sum];

      int ans = 0;
      if(sum >= coins[idx])ans += rec(idx,sum-coins[idx],coins);
      ans += rec(idx+1,sum,coins);

      return dp[idx][sum] = ans;
   }
    int change(int amount, vector<int>& coins) {
       n = coins.size(); 
       dp.resize(n+1,vector<int>(amount+1,-1));
       
        return rec(0,amount,coins);
    }
};

Time complexity: O(length of coins * amount)
Space complexity: O(length of coins * amount)
If you try this approach in coin combination II in cses it will give TLE


--------------------------------Approach 2 Bottom Up ----------------------------
State - dp(idx,sum)
Transition - 
                   1. dp(idx,sum) = dp(idx-1,sum)  Number of ways to make sum = 
                       sum from index [ 0,idx-1]
				   2. dp(idx,sum) = dp(idx,sum-coins[idx]) Number of ways to make  sum = sum from index [0,idx]
				     // we will build solution from  0<=sum<=amount from [0,idx]
					 // so that we can pick multiple times idx
				    // while implementing as it is 0 based index we will do coins[idx-1] 	   
					
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        
        for(int i = 0; i <= n; i++){
            for(int sum = 0; sum <= amount; sum++){
                if(i == 0){
                    //Number of ways to make sum = sum if we 
                    // have nothing in our coins array
                    // There is one way to make sum = 0
                    dp[i][sum] = (sum == 0);
                }
                else{
                     dp[i][sum] = dp[i-1][sum];
                    if(sum >= coins[i-1])dp[i][sum] += dp[i][sum-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
        
    }
};
Time complexity: O(length of coins * amount)
Space complexity: O(length of coins * amount)

--------------------------------Approach 3 Optimized Bottom Up----------------

Since dp(idx,sum) depends on dp(idx,sum-coins[idx-1]) and dp(idx-1,sum) so 
we can reduce our dp from n*sum to 1*sum . If we observe carefully when we 
are traversing for the i th coins  we actually have i-1 th state what are all the sum that include i-1 th coin. 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int sum=0;sum<=amount;sum++){
                if(sum>=coins[i-1])dp[sum] += dp[sum-coins[i-1]];
            }
        }
        
        return dp[amount];
    }
};
