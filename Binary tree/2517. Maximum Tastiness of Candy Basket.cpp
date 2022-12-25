// binary search on tastiness
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        
        sort(price.begin(),price.end());
        int n = price.size();
        int l = 0, h = price[n-1]-price[0];
        
        while(l<h){
            int mid = l + (h-l+1)/2;
            int reference = price[0] , sections = 0;
            for(auto &p:price){
                if(p>=reference+mid){
                    reference = p;
                    sections++;
                }
            }
            if(sections>=k-1)l=mid;
            else h = mid -1;
        }
        return l;
    }
};
