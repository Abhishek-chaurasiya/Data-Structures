You are given a string S consisting of ‘(‘ and ‘)’ characters. You have to find the longest substring that is a regular bracket sequence. You also have to find the number of such substrings. A bracket sequence is called regular if by inserting ‘+’ and ‘1’ into it we can get a correct mathematical expression.

3
()((())
)()())(())
))((

4 1
4 2
0 0  
  
This is mixed dp problem -
  Make an array DP[i] which stores the left closest ‘(‘ character for every ‘)’ character. For every i, the difference between i and DP[i] tells the maximum length of the regular bracket sequence.


void solve(){
  
  string s; cin>>s;
  stack<int> ss;
  vector<int> dp(sz(s),-1);

  for(int i=0;i<sz(s);i++){
    if(s[i]=='(')ss.push(i);
    else{
      if(sz(ss)){
        int lstidx = ss.top();
        ss.pop();
        if(lstidx-1>=0 && s[lstidx-1]==')'&&dp[lstidx-1]!=-1)dp[i]=dp[lstidx-1];
        else dp[i]=lstidx;

      }
    }
  }
  int ans=0;
  for(int i=0;i<sz(s);i++){
    if(dp[i]!=-1)ans=max(ans,i-dp[i]+1);
  }
  int cnt=0;
  for(int i=0;i<sz(s);i++){
    if(dp[i]!=-1 && (i-dp[i]+1)==ans)cnt++;
  }
  cout<<ans<<" "<<cnt<<endl;

}
