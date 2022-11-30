int n;
vector<int> queen(20);

bool check(int row, int col){
	for(int i = 0 ; i< row ;i++){
		int prow = i;
		int pcol = queen[i];
		if(pcol == col || abs(pcol - col) == abs(prow - row))return 0;
	}
	return 1;
}

int helper(int level){
	if(level == n)return 1;
    
    int ans = 0;

	for(int col = 0; col < n ;col++){
         if(check(level,col)){
             queen[level] = col;
             ans += helper(level+1);
             
             queen[level] = -1;
         }
	}
	return ans;
}

void solve(){
	cin>> n;
	//memset(queen ,-1 ,sizeof queen);
	cout<<helper(0);
	
}
