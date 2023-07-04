void solve(){
	// first find the next greater element of cur element and
	// make sure that upcoming element is greater then the cur element
	// bcoz when we find any greater element basically we are getting
	// its right subtree value (and it is a property of bst that all nodes
	// are greater then cur)
	vi a = {30,28,29,40,37,42,43};
	stack<int> s;
	int mn = INT_MIN;
	for(int x:a){
		if(mn > x){
			cout<<"false"<<endl;return;
		}
		while(sz(s) && s.top() < x){
			mn = s.top();
			s.pop();
		}
		s.push(x);
	}
	cout<<"true"<<endl;

	
	
}
