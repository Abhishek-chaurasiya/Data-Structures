  vector<int> rightView(Node *root)
    {
       // Your Code here
        if(!root)return{};
   
       vector<int> ans; ans.push_back(root->data);
       queue<Node*> q; q.push(root);
       while(q.size()){
           int len = q.size();
           while(len--){
               Node* cur = q.front(); q.pop();
               if(cur->left)q.push(cur->left);
               if(cur->right)q.push(cur->right);
           }
          if(q.size()){
              Node *tmp = q.back();
              ans.push_back(tmp->data);
          }
       }
       return ans;
    }
