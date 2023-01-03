/* We are basically finding the component and clearing out that and then gravity falling is equal to store non-zero element in vector according to column and then
place them from bottom or top , it's just a matter of implememtaion */



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
const int N=1e5 ;bitset<N> b;
vector<ll> primes;
void seive()
{
  b.set(); for(ll i=2;i<=N;i++)if(b[i]){ primes.pb(i);for(ll j=i*i;j<=N;j+=i)b[j]=0;}   
}
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int g[101][11];
bool vis[101][11];
int n,k;
bool isvalid(int x,int y){
  if(x<0||x>=n||y<0||y>=10||vis[x][y])return false;
  return true;
}
vector<pii> component;

int dfs(int x,int y,int color){
    vis[x][y]=true;
    int cnt=1;
    component.pb({x,y});
    for(int i=0;i<4;i++){
       int nx = x+dx[i];
       int ny = y+dy[i];
       if(isvalid(nx,ny) && g[nx][ny]==color){ 
         cnt+=dfs(nx,ny,color);
     
       }
      
    }
    
    return cnt;

}

bool helper(){
  bool removed=false;
  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
      if(g[i][j] !=0){
        int cnt=dfs(i,j,g[i][j]);
        if(cnt>=k){
          g[i][j]=0;
          for(auto pr:component){
            g[pr.fr][pr.sc]=0;
          }
          removed=true;
        }
        component.clear();
      }
     
    }
  }
  return removed;
}

void solve(){
   cin>>n>>k;
  for(int i=0;i<n;i++){
    string s; cin>>s;
    for(int j=0;j<10;j++){
      g[i][j]=s[j]-'0';
    }
  }
  bool someRemoved=true;

  while(someRemoved){
    if(!helper())someRemoved=false;
    // someRemoved=false;
    // gravity
    for(int i=0;i<10;i++){
      vi col;
      for(int j=0;j<n;j++){
        if(g[j][i])col.pb(g[j][i]);
        g[j][i]=0;
      }
       
      debug(col);
      int idx=col.size()-1;
      for(int j=n-1;j>=0 && idx>=0;j--){
        g[j][i]=col[idx--];
      }
    }
    memset(vis,0,sizeof vis);
  }

  for(int i=0;i<n;i++){
        for(int j=0;j<10;j++)cout<<g[i][j];
        cout<<endl;
   }

}

int main(){
 
 fast; 
#ifndef ONLINE_JUDGE
   freopen("mooyomooyo.in", "r", stdin);
   freopen("mooyomooyo.out", "w", stdout);
   freopen("Error.txt", "w", stderr);
#endif


 int tests=1;
  while(tests--)
  solve();


}
