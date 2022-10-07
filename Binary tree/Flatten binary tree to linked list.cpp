

//If we observe when we encounter a root->left we are changing it's rightmost child with root->right.
//For each node i
//1.if there is no left move to right as simple as that
//2.if there is left node
//--store the right subtree
//--now add the right subtree to the rightmost child of node in which we are currently on.
//--add left subtree to root->right and root->left=NULL
//TC-O(n==number of nodes)
//SC-O(1)

 void flatten(Node *root)
    {
        //code here
        if(!root)return ;
        
        while(root){
            
            if(root->left){
                
                Node *prev=root->left;
                while(prev->right)prev=prev->right;
                prev->right=root->right;
                root->right=root->left;
                root->left=NULL;
            }
            root=root->right;
        }
        
       
    }
