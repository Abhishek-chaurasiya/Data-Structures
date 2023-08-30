
void solve(){
	string pat,text; cin>>pat>>text;
	ll n = pat.size(), m = text.size();
    ll pr = 31;
	vector<ll> ppow(max(n,m));
	ppow[0] = 1;
	for(int i = 1; i < sz(ppow); i++)ppow[i] = (ppow[i-1]*pr)%mod;

	ll patHash = 0;

	for(int i = 0; i < n; i++){
		patHash = (patHash + ((pat[i] - 'a' + 1)*ppow[i])%mod )%mod;
	}

	vector<ll> prefHash(m,0);
	ll compHash = 0;
	for(int i = 0; i < m; i++){
		compHash = (compHash + ((text[i] - 'a' + 1)*ppow[i])%mod )%mod;
		prefHash[i] = compHash;
	}

    vector<int> occurences;   
    if(patHash == prefHash[n-1])occurences.pb(0);
    for(int i = 0; i < m - n; i++){
    	ll curHash = (prefHash[i+n] - prefHash[i] + mod)%mod;
      // to make the hash calculation equal we multiply the lacking factor of 31 into patHash
    	if(curHash == patHash * ppow[i+1] %mod)occurences.pb(i+1);
    }
    debug(occurences)		


}
