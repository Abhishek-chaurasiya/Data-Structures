// good things to learn
//standard knapsack in 1-d 
EX- [1,2,3,4] k = 4;

class Solution {
public:
    int mod = 1e9+7;
    
    int countPartitions(vector<int>& nums, int k) {
       
        int total = 1;
        vector<int> dp(k,0); dp[0]=1;
        long long sum = 0;
        // for every 
        for(auto &x:nums){
            for(int i=k-1;i>=0;i--){
               if(i-x>=0){
                   dp[i]=(dp[i]+dp[i-x])%mod;
               }     
            }
            total = (total*2)%mod;
            sum += x;
        }
        if(sum<2*k)return 0;
        long long ans = 0;
        for(int i=0;i<k;i++){
            ans = (ans+2*dp[i])%mod;
        }
        return (total - ans + mod)%mod;
    }
    
};
