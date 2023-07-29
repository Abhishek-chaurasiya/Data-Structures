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
