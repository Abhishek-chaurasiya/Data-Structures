// Problem-Given a string (??()) you can replace ? with '(' or ')' find the total valid
// paranthesis possible after replacing all the ? mark

// the trick behind solving this problem is that we actually dont need stack to 
// check that a paranthesis is a valid or not , what we have to do is simple and neet
// that whenever encountered '(' increase unclosed bracket to plus one and decrease for 
// other case if unclosed is negative it is not possible to form valid paranthesis

int dp[1001][1001];

int helper(int idx,int unclosed,int n,string &s){
  if(idx == n){
    if(unclosed == 0)return 1;
    return 0;
  }
  if(unclosed<0)return 0;
  if(dp[idx][unclosed]!=-1)return dp[idx][unclosed];
  int ans = 0;
  if(s[idx]!='?')ans+=helper(idx+1,unclosed+(s[idx]=='('?1:-1),n,s);
  else {
    ans+=helper(idx+1,unclosed+1,n,s);
    ans+=helper(idx+1,unclosed-1,n,s); 
  }

  return dp[idx][unclosed]=ans;
}
