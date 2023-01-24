
class Solution {
public:
    #define ll long long 
    int maxSumMinProduct(vector<int>& nums) {
        vector<ll> pref;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(i==0)pref.push_back(nums[i]);
            else pref.push_back(nums[i] + pref.back());
        }
        vector<ll> next(n+1,-1),prev(n+1,-1);
        vector<ll> stack;
        
        //// prev smaller element then cur i
        for(int i=0;i<n;i++){
            while(stack.size() && nums[stack.back()] >= nums[i])stack.pop_back();
            if(stack.size())prev[i] = stack.back();
            stack.push_back(i);
        }
        stack.clear();
        //// next smaller element then cur i
        for(int i=n-1;i>=0;i--){
            while(stack.size() && nums[stack.back()] >= nums[i])stack.pop_back();
            if(stack.size())next[i] = stack.back();
            stack.push_back(i);
        }
        
        // for a given a[i] we only care about [p+1,q-1] where p is prev smaller 
        // and q is next smaller element 
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll prod = 0;
            prod = (next[i] == -1 ?pref.back():pref[next[i]-1]);
            if(prev[i] != -1)prod -= pref[prev[i]];
            ans = max(ans,nums[i]*prod);
        }
        ll mod = 1e9+7;
        
        return ans%mod;
        
    }
};
