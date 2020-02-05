#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9+7;
 
ll fastpowMOD(ll a, ll p,ll MOD);
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; a %= MOD; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
 
ll lcm(ll a,ll b){
	return (a*b)/__gcd(a,b);
}
 

vector<ll> adj[100000+5];
vector<ll> dp(100000+5,0);
vector<bool> vis(100000+5,false);
void dfs(ll v){
    vis[v] = true;
    vector<ll>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++){
        if(!vis[*it]){
          dfs(*it);
        }
        dp[v] = max(dp[v],1+dp[*it]);
      
    }

  
}


int main(){
	fastio;
  ll n,m;
  cin>>n>>m;
  
  for(ll i=0;i<m;i++){
    ll x,y;
    cin>>x>>y;
    x--;y--;
    adj[x].pb(y);
  }

  for(ll i=0;i<n;i++){
    if(!vis[i]){
      dfs(i);
    }
  }
  ll ans = 0;
  for(ll i=0;i<n;i++){
    ans = max(ans,dp[i]);
  }
  cout<<ans<<"\n";

}
