
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k == num.size()) return "0"; 
        stack<int> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && num[i] < num[st.top()] && k>0){
                st.pop();
                k--;
            }
            st.push(i);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){ 
            ans += num[st.top()] ;
            st.pop();
        }
        if(ans == "0")return ans;
        while(ans.back() == '0')ans.pop_back();
        
        reverse(ans.begin(),ans.end());
        if(ans.size() == 0)ans="0";
        return ans;
    }
};
