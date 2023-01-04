
// here the constraint is small so we can cur out each different pieces of rectangle and then we judge that this individual piece is valid pcl or not, if
// it is valid we will count it into potential region and al last we will check accordingly that the region is not subpart of another big part.



#include<bits/stdc++.h>
#include<bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//template<typename T>
 //using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF 1e18
#define nline "\n"
#define ll long long
#define ull  unsigned long long
#define lld  long double
#define ld  long double;
#define fr first
#define sc second
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define allr1(v) (v).rbegin()+1,(v).rend()
#define sort0(v) sort(all(v))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
//debug
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


#define sz(x) (ll)x.size()
#define pb push_back
#define pf push_front
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005
const ll mod = 1e9 + 7;
const int dx[9] = {1,0,-1,0,1,-1,-1,1,0};
const int dy[9] = {0,1,0,-1,1,-1,1,-1,0};
const int N=21 ;bitset<N> b;
vector<ll> primes;
void seive()
{
  b.set(); for(ll i=2;i<=N;i++)if(b[i]){ primes.pb(i);for(ll j=i*i;j<=N;j+=i)b[j]=0;}   
}
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<char>> g(N,vector<char>(N));
vector<vector<bool>> vis(N,vector<bool>(N));
int n;

struct PCL
{
  int i1,j1;
  int i2,j2;

  bool isInside(PCL other){
     return(
        i1>=other.i1&&
        i2<=other.i2&&
        j1>=other.j1&&
        j2<=other.j2
      );
  }
  
};
int i_min,j_min,i_max,j_max;

void floodfill(int i,int j,char color){
  if(i<i_min||i>i_max||j<j_min||j>j_max
     || vis[i][j]|| g[i][j]!=color
    )return ;

    vis[i][j]=true;
    for(int d=0;d<4;d++){
      floodfill(i+dx[d],j+dy[d],color);
    }
}

bool isValid(int i1,int j1,int i2,int j2){
  
  i_min=i1,j_min=j1;
  i_max=i2,j_max=j2;
  vector<int> region_cnt(26,0);

  for(int i=i1;i<=i2;i++){
    for(int j=j1;j<=j2;j++){
      if(!vis[i][j]){
        char color = g[i][j];
        region_cnt[color-'A']++;
        floodfill(i,j,color);
      }
    }
  }
  fill(vis.begin(),vis.end(),vector<bool>(N));
  int colorcnt=0;
  bool onecolorReg=false;
  bool onecolorManyReg=false;
  for(int i=0;i<26;i++){
    if(region_cnt[i]!=0)colorcnt++;
    if(region_cnt[i]==1)onecolorReg=true;
    if(region_cnt[i]>1)onecolorManyReg=true;
  }
  // if(colorcnt==2&&onecolorReg&&onecolorManyReg){
  //   debug(region_cnt);
  // }
  return (colorcnt==2&&onecolorReg&&onecolorManyReg);

}

void solve(){
 
 cin>>n;
 for(int i=0;i<n;i++){
   for(int j=0;j<n;j++)cin>>g[i][j];
 }


  vector<PCL> region;
  for(int i1=0;i1<n;i1++){
    for(int j1=0;j1<n;j1++){
      for(int i2=0;i2<n;i2++){
        for(int j2=0;j2<n;j2++){
            if(isValid(i1,j1,i2,j2)){
              region.pb({i1,j1,i2,j2});
            }
      
        }
      }
    }
  }

  int validPcl=0;
  int len = region.size();
  for(int i=0;i<len;i++){
    // cout<<region[i].i1<<" "<<region[i].j1<<" ";
    // cout<<region[i].i2<<" "<<region[i].j2<<endl;
    bool inside = false;
    for(int j=0;j<len;j++){
      if(i==j)continue;
      if(region[i].isInside(region[j])){
         inside = true;
         break;
      }
    }
    if(!inside)validPcl++;
  }

  cout<<validPcl<<endl;



}


int main(){
 
 fast; 
#ifndef ONLINE_JUDGE
   freopen("where.in", "r", stdin);
   freopen("where.out", "w", stdout);
   freopen("Error.txt", "w", stderr);
#endif

 int tests=1;
  while(tests--)
  solve();


}
