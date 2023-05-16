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
vi arr(200100);
 
vector<ll> t(800100);
 
void update(ll index,ll l,ll r,ll lq,ll rq,ll val){
	if(l >  rq || lq > r)return;
	if(lq<=l && r<=rq){
		t[index] = val;
		return;
	}
	ll mid = (l+r)/2;
	update(2*index,l,mid,lq,rq,val);
	update(2*index+1,mid+1,r,lq,rq,val);
	t[index] = min(t[2*index],t[2*index+1]);
}
void build(ll index,ll l,ll r){
	if(l == r){
		t[index] = arr[l];
		return;
	}
	ll mid = (l+r)/2;
	build(2*index,l,mid);
	build(2*index+1,mid+1,r);
	t[index] = min(t[2*index],t[2*index+1]);
}
 
 
ll query(ll index,ll l,ll r,ll lq,ll rq){
	if(l >  rq || lq > r)return INT_MAX;
	if(lq<=l && r<=rq){
		return t[index];
	}
	ll mid = (l+r)/2;
	auto left = query(2*index,l,mid,lq,rq);
	auto right = query(2*index+1,mid+1,r,lq,rq);
	return min(left,right);
}
 
void solve(){
	ll n,q; cin>>n>>q;
	vll a(n); 
 
	rep(i,0,n){
		cin>>arr[i];
		// update(1,0,n-1,i,i,a[i]);
	}
	build(1,0,n-1);
	while(q--){
		ll l,r; cin>>l>>r;
		l--; r--;
		cout<<query(1,0,n-1,l,r)<<endl;
	}
	   
	
}
 
 
int main(){
 
 fast; 
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("Error.txt", "w", stderr);
#endif
 
 int tests=1;
  while(tests--)
  solve();
 
 
}
