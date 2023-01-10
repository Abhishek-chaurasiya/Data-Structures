//Top Down Approach
class Solution {
public:
    vector<int> prefix;
    int dp[50][50][50];
    int helper(int i,int j,int piles,int k){
        if(i==j && piles ==1)return 0;
        if(i==j && piles !=1)return INT_MAX/4;
        
        if(dp[i][j][piles] != -1)return dp[i][j][piles];
        
        int ans = INT_MAX/4;
        
        if(piles == 1){
          ans = helper(i,j,k,k)+ (i-1>=0?prefix[j]-prefix[i-1]:prefix[j]);
        }
        else{
            for(int t=i;t<j;t++){
                ans = min(ans,helper(i,t,1,k)+helper(t+1,j,piles-1,k));
            }
        }
        return dp[i][j][piles] =  ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
         if((n-1)%(k-1))return -1;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<stones.size();i++){
            if(i==0)prefix.push_back(stones[i]);
            else prefix.push_back(stones[i] + prefix.back());
        }
       
        // finally we have to make one pile out of k pile already made
        return helper(0,n-1,1,k);
    }
};

//bottom up
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
     
        int n = stones.size();
        if((n-1)%(k-1))return -1;
        vector<int> pref;
        for(int i = 0; i < stones.size(); i++){
            (i==0?pref.push_back(stones[i]):pref.push_back(stones[i]+pref.back()));
        }
        
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int len=k;len<=n;len++){
            for(int i = 0; i+len<=n;i++){
                int j = i + len -1;
                dp[i][j] = INT_MAX;
                for(int mid=i;mid<j;mid+=k-1){
                    dp[i][j] = min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
                }
                if((j-i)%(k-1)==0)dp[i][j]+=pref[j]-(i-1>=0?pref[i-1]:0);
            }
        }
        return dp[0][n-1];
    }
};
