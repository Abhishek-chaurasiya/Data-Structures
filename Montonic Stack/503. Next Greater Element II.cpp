class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> stack,res(n,-1);
        
        for(int i=0;i<2*n;i++){
            
            while(stack.size() && nums[i%n] > nums[stack.back()]){
                res[stack.back()] = nums[i%n];
                stack.pop_back();
            }
            stack.push_back(i%n);
        }
        return res;
    }
};
