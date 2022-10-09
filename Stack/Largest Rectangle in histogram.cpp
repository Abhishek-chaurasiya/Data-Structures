//Concept---------------------------------------------------------------------------------------------------------------------------------------------
//If we are standing at current bar in histogram what we require is how much we can extend to left and right untill we found a bar of height less then the height of 
//current bar.

 int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nearestLeft(n),nearestRight(n);
        
        nearestLeft=findleft(heights,n);
        nearestRight=findright(heights,n);

        int ans=0;
        
        for(int i=0;i<n;i++){
            int width=nearestRight[i]-nearestLeft[i]+1;
            int height=heights[i];
            ans=max(ans,width*height);
        }
        
        return ans;
        
    }

//Finding the left bar for each indx
 vector<int> findleft(vector<int>arr, int n){
        stack<int> st;
        vector<int> idx(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                idx[i]=0;
                st.push(i);
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty())idx[i]=0;
                else idx[i]=st.top()+1;
                st.push(i);
            }
        }
        return idx;
    }

vector<int> findright(vector<int> arr, int n){
        stack<int> st;
        vector<int> idx(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                idx[i]=i;
                st.push(i);
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty())idx[i]=n-1;
                else idx[i]=st.top()-1;
                st.push(i);
            }
        }
        return idx;
    }
