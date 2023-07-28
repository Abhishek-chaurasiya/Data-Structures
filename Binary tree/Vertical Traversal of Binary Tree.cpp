vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,vector<int>> m;
        vector<int> ans;
        queue<pair<Node*,int>> q; q.push({root,0});
        
        while(q.size()){
            int len = q.size();
            while(len--){
                auto cur = q.front(); q.pop();
                m[cur.second].push_back(cur.first->data);
                Node *tmp = cur.first;
                if(tmp->left)q.push({tmp->left,cur.second-1});
                if(tmp->right)q.push({tmp->right,cur.second+1});
            }
        }
        for(auto ob:m){
            for(auto &x:ob.second)ans.push_back(x);
        }
        return ans;
    }
