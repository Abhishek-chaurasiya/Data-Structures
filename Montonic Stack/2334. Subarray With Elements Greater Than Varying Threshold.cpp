// forming a subarray with cur i being the minimum elemennt in our subaray 
// can be achieved using monotonic stack 

class Solution {
public:
    #define ll long long 
    int validSubarraySize(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        vector<ll> next(n,n),prev(n,-1);
        vector<ll> stack;
        
        for(int i=0;i<n;i++){
            while(stack.size() && nums[stack.back()]>= nums[i])stack.pop_back();
            if(stack.size())prev[i] = stack.back();
            stack.push_back(i);
        }
        stack.clear();
        for(int i=n-1;i>=0;i--){
            while(stack.size() && nums[stack.back()]>=nums[i])stack.pop_back();
            if(stack.size()) next[i] = stack.back();
            stack.push_back(i);
        }

        for(int i=0;i<n;i++){
            ll sublen = (next[i]-1) - (prev[i]+1) +1;
            if(1LL*nums[i]*sublen > threshold)return sublen;
          
        }
        
        return -1;
        
    }
};
