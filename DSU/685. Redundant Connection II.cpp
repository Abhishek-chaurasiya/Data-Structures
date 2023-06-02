https://leetcode.com/problems/redundant-connection-ii/discuss/3588541/Easy-Explanation-C%2B%2B
// This is an excellent problem which teaches us what scenerios are possible in a tree when an extra edge is added.There are three possibilities:
1. Only single node in a tree have two parent 
2. There is cycle present without existence of two parent node
3. There exist a cycle with existence of two parent node

//As in problem it is demanding the last possible index we will will create two possible candidates pot1 = (will be last) and pot2 = (will be first)


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

	bool unite(int u,int v){
		int x = find(u), y = find(v);
		if(x == y)return true;
       
		if(rank[x] < rank[y])swap(x,y);
		
        rank[x] += rank[y];
		par[y] = x;
        return false;
	}
    int getSize(int x){
        return rank[find(x)];
    }
    
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int pot1 = -1, pot2 = -1;
        vector<int> ind(n+1,-1);
        for(int i = 0; i < n; i++){
            if(ind[edges[i][1]] != -1){
                pot1 = i;
                pot2 = ind[edges[i][1]];
                continue;
            }
            ind[edges[i][1]] = i;
        }
        DSU d(n+1);
        
        if(pot1 == -1){
            vector<int> ans(2);
            for(auto &edge:edges){
                if(d.unite(edge[0],edge[1])){
                    ans[0] = edge[0];
                    ans[1] = edge[1];
                }
            }
            return ans;
        }
        vector<int> ans(2,-1);
        for(int i = 0; i < n; i++){
            if(i != pot1){
                 if(d.unite(edges[i][0],edges[i][1])){
                    // cout<<edges[i][0]<<edges[i][1]; 
                    ans[0] = edges[i][0];
                    ans[1] = edges[i][1];
                }
            }
        }
        if(ans[0] != -1)return edges[pot2];
        
        return edges[pot1];
        
    }
};
