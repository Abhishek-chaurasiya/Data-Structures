// Here we cleverly store all indexes of a particular factor possible and then unite them.
[4,6,15,25]
// factor 2 includes indexes -- 0 , 1
// factor 3 includes indexes -- 1, 2
// factor 5 includes indexes -- 2, 3
// factor 3 includes indexes -- 3
class DSU{
    vector<int> par,rank;
    public:
    DSU(int n){
        par.resize(n,-1);
        rank.resize(n,1);
    }
    int find(int x){
		if(par[x] == -1)return x;
		return par[x] = find(par[x]);
	}

	void unite(int u,int v){
		int x = find(u), y = find(v);
		if(x == y)return;
		if(rank[x] < rank[y])swap(x,y);
		
        rank[x] += rank[y];
		par[y] = x;
	}
    int getSize(int x){
        return rank[find(x)];
    }
    
};

class Solution {
    vector<int> factors(int n){
        vector<int> ans;
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0){
                ans.push_back(i);
                while(n %i == 0)n/=i;
            }
        }
        if(n > 1)ans.push_back(n);
        return ans;
    }
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        DSU d(n);
        int ans = 0;
        unordered_map<int,vector<int>> m;
        for(int i = 0; i < n; i++){
            for(auto &fac:factors(nums[i])){
                m[fac].push_back(i);
            }
        }
        for(auto &[fact,indices]:m){
            for(int i = 1; i < indices.size(); i++){
                d.unite(indices[0],indices[i]);
            }
        }
        for(int i = 0; i < n; i++)ans = max(ans,d.getSize(i));
        return ans;
    }
};

