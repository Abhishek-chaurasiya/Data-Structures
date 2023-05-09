TC-
  1
6
10
+ 5
+ 1 
+ 2
+ 4
? 2
? 3
- 1
? 3
? 2
? 1





void addToset(int index,int l,int r,int num){
	if(num < l || num > r)return;
	if(l == r && l == num){
		if(t[index] == 0)t[index]+=1;
		return;
	}
	int mid = (l+r)/2;
	addToset(2*index,l,mid,num);
	addToset(2*index+1,mid+1,r,num);
	t[index] = t[2*index] + t[2*index+1];
}

void remove(int index,int l,int r,int num){
	if(num < l || num > r)return;
	if(l == r && l == num){
		if(t[index] == 1)t[index]-=1;
		return;
	}
	int mid = (l+r)/2;
	remove(2*index,l,mid,num);
	remove(2*index+1,mid+1,r,num);
	t[index] = t[2*index] + t[2*index+1];
}

int findkth(int index,int l,int r,int k){
	if(l == r){
		if(t[index] == 0)return -1;
		return l;
	}
	int mid = (l+r)/2;
	if(t[2*index] >=k){
		return findkth(2*index,l,mid,k);
	}
	else if(k-t[2*index] <= t[2*index+1]){
		return findkth(2*index+1,mid+1,r,k-t[2*index]);
	}
	return -1;
	
}
