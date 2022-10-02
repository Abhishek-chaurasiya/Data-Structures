 //Some string --->[Rolling Hash Function]--->Hash(INTEGER)
 
 int Rollinghash(string s){
  int pr=1;
  int hash=0;
  
  for(auto it: s){
    hash=(hash+(pr*(it-'a'+1))%mod)%mod;
    pr=(pr*31)%mod;
  } 
  return hash;
}
//GIVEN A STRING FIND THE NUMBER OF DIFFERENT SUBSTRING?
//Brute force approach (n*n*n*log(n*k))
//optimized O(n*n*log(n))
int countsubstrings(string s){
 
  set<int> ans;
  for(int i=0;i<(int)s.size();i++){
     
     string sub="";
     int hash=0,pr=1;
     for(int j=i;j<(int)s.size();j++){
       sub+=s[j];
       hash=(hash+ (pr*(s[j]-'a'+1))%mod)%mod;
       pr=(pr*31)%mod;
       ans.insert(hash);
     }

  }
  return ans.size();

}


//Given a string and Q queries ,every queries has 4 integers
//(i1 j1) (i2 j2)
//answer the query if substr(i1,j1) is equal to substr(i2,j2)

//brute force 

void solve(){
 
 string s; cin>>s;
 int q; cin>>q;
 std::map<pii,int> mp;
 int n=s.size();

 for(int i=0;i<n;i++){
  string str="";
  
  int pr=1,hash=0;
  for(int j=i;j<n;j++){
    str+=s[j];
    hash=(hash+ (pr*(s[j]-'a'+1))%mod)%mod;
    pr=(pr*31)%mod;
    mp[{i,j}]=hash;
  }

 }


 for(int i=0;i<q;i++){
    int i1,j1,i2,j2; cin>>i1>>j1>>i2>>j2;
    if(mp[{i1,j1}]==mp[{i2,j2}]){

      cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
 }  

}

//OPTIMIZED 



