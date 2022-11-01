class Solution{   
public:
    int helper(vector<vector<int>> &matrix,int r,int mid){
        int lessthenmid=0,c=matrix[0].size();
        for(int i=0;i<r;i++){
            int indx=upper_bound(matrix[i].begin()
            ,matrix[i].end(),mid)-matrix[i].begin();
            lessthenmid+=indx;
        }
        return lessthenmid;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here         
        int l=1,h=2001;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            int left=helper(matrix,R,mid);
            int right=R*C-left;
            
            if(left>right)h=mid-1;
            else l=mid+1;
        }
       
        return l;
    }
};
