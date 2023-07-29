Brute Force O(NlogN)
void dfs(Node *root,int idx,map<int,vector<int>> &m){
    if(!root)return;
    m[idx].push_back(root->data);
    dfs(root->left,idx+1,m);
    dfs(root->right,idx,m);
}

vector<int> diagonal(Node *root)
{
   // your code here
   map<int,vector<int>> m;
   vector<int> ans;
   dfs(root,0,m);
   for(auto ob:m){
       for(auto x:ob.second)ans.push_back(x);
   }
   return ans;
}


O(N) Approach
vector<int> diagonal(Node *root)
{
   vector<int> ans;
   queue<Node*> q; q.push(root);
   
   while(q.size()){
       int len = q.size();
       while(len--){
           auto cur = q.front(); q.pop();
        
           while(cur){
               ans.push_back(cur->data);
               if(cur->left)q.push(cur->left);
               cur = cur->right;
           }
       }
   }
   return ans;
   
}
