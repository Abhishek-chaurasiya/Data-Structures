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
