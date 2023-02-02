class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMost(k,nums) - atMost(k-1,nums);
    }
    int atMost(int k,vector<int>&nums){
        map<int,int> mp;
        int i = 0 , ans = 0;
        for(int j=0;j<nums.size();j++){
            if(!mp[nums[j]]++)k--;
            while(k < 0){
                if(!--mp[nums[i++]])k++;
            }
            ans += j-i+1;
        }
        // cout<<ans<<" ";
        return ans;
    }
};
