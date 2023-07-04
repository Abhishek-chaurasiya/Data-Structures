struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int val):val(val),left(NULL),right(NULL){};
};

class BST{
	TreeNode *find(TreeNode *node,int target){
		cout<<node->val<<" ";
 		if(!node || node->val == target)return node;
 		if(target > node->val)return find(node->right,target);
 		return find(node->left,target);
 	}
 	TreeNode *insert(TreeNode *node,int data){
 		if(!node)return new TreeNode(data);
 		if(data > node->val)node->right = insert(node->right,data);
 		else if(data < node->val)node->left = insert(node->left,data);
 		return node;
 	}
 public:
 	TreeNode *root = NULL;
 	TreeNode *find(int target){
 		return find(root,target);
 	}
 	void insert(int target){
 		root = insert(root,target);
 	}

 	bool remove(int target){
 			TreeNode **parent = &root, *node = root;
 		while(node){
 			if(node->val == target)break;
 			if(target > node->val){
 				node = node->right;
 				parent = &(*parent)->right;
 			}
 			else{
 				node = node->left;
 				parent = &(*parent)->left;
 			}
 		}
 		if(!node)return false;
 		if(node->right){
 			*parent = node->right;
 			TreeNode *left = node->left;
 			delete node;
 			node = *parent;
 			while(node->left)node = node->left;
 			node->left = left;
 		}
 		else if(node->left){
 			*parent = node->left;
 			delete node;
 		}
 		else *parent = NULL;
 		return true;
 	}


};
