vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> m;
        vector<int> ans;
        queue<pair<Node*,int>> q; q.push({root,0});
        
        while(q.size()){
            int len = q.size();
            while(len--){
                auto cur = q.front(); q.pop();
                if(!m.count(cur.second))m[cur.second] = cur.first->data;
                Node *tmp = cur.first;
                if(tmp->left)q.push({tmp->left,cur.second-1});
                if(tmp->right)q.push({tmp->right,cur.second+1});
            }
        }
        for(auto x:m)ans.push_back(x.second);
        return ans;
    }
