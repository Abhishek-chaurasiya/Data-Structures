#define ll long long 
struct TrieNode{
    TrieNode *next[2]={};
};
class Solution {
    void add(TrieNode *node,ll n){
        for(ll i = 31; i>= 0; i--){
            ll b = (n>>i)&1LL;
            if(!node->next[b])node->next[b] = new TrieNode();
            node = node->next[b];
        }
    }
    ll maxXor(TrieNode *node,ll n){
        ll ans = 0;
        for(ll i = 31; i>=0; i--){
            ll b = (n>>i)&1ll;
          
             if(node->next[1-b]){
                if(ans == -1)ans = 0;
                ans |= (1<<i);
                node = node->next[1-b];
            }
            else node = node->next[b];
        }
        return ans;
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<ll>> Q;
        for(int i = 0; i < queries.size();i++){
            Q.push_back({queries[i][0],queries[i][1],i});
        }
        
        sort(begin(Q),end(Q),[](const vector<ll> &a,const vector<ll> &b){
            return a[1] < b[1];
        });
        sort(begin(nums),end(nums));
        int i = 0, n = nums.size();
        TrieNode root;
        vector<int> ans(queries.size());
        for(auto &q:Q){
            ll x = q[0], m = q[1], idx = q[2];
            ll tres = -1;
            while(i < n && nums[i] <= m){
                add(&root,nums[i]);
                i++;
            }
            
            ans[idx] = i==0 ? -1:maxXor(&root,x);
            
        }
        
        return ans;
    }
};
