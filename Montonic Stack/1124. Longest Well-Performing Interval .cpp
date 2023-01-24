// an important question derives from it find the longest subarray with positive sum.

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        
        unordered_map<int,int> seen;
        int score = 0 , ans = 0;
        
        for(int i=0;i<hours.size();i++){
            score += (hours[i] > 8 ?1:-1);
            if(score > 0)ans = i+1;
            else{
                if(seen.find(score) == seen.end())seen[score] = i;
                if(seen.find(score-1) != seen.end())ans=max(ans,i-seen[score-1]);
            }
        }
        return ans;
    }
};
