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
        for(int d = 2; d*d <= n; d++){
            if(n%d == 0){
                ans.push_back(d);
                while(n%d == 0)n /= d;
            }
        }
        if(n > 1)ans.push_back(n);
        return ans;
    } 
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        DSU d(n+1);
        map<int,int> m;
        for(int i = 0; i < n; i++){
            for(auto f:factors(nums[i])){
                if(m.count(f))d.unite(m[f],i);
                else m[f] = i;
            }
        }
        vector<int> sorted(n);
        map<int,vector<int>> lists;
        for(int i = 0; i < n; i++){
            lists[d.find(i)].push_back(i);
        }
        
        for(auto &[key,before] : lists){
            vector<int> after = before;
            // sorting on the basis nums value
             
        sort(begin(after),end(after),[&](const int a,const int b){return nums[a]<nums[b];});
            for(int i = 0; i < after.size() ; i++){
                sorted[before[i]] = nums[after[i]];
            }     
        }
        for(int i = 1; i < n; i++){
            if(sorted[i-1] > sorted[i])return false;
        }
        return true;
    }
};
