#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second 
using namespace std;
typedef long long ll;
const ll INF = 1e18+5;
int main(){
	fastio;
	string str1,str2;
	cin>>str1>>str2;
	ll n1 = str1.size();
	ll n2 = str2.size();
	vector< vector< pair<ll,pair<ll,ll> > > > dp(n1+1,vector< pair<ll,pair<ll,ll> > > (n2+1, {0, {0,0}}));

	for(ll i=1;i<=n1;i++){
		for(ll j=1;j<=n2;j++){
			
			if(str1[i-1]==str2[j-1]){
				dp[i][j] = make_pair(1+dp[i-1][j-1].fi,make_pair(i-1,j-1));
			}
			else {
        if(dp[i-1][j]>dp[i][j-1]){
          dp[i][j] = make_pair(dp[i-1][j].fi,make_pair(i-1,j));
        }
        else{
          dp[i][j] = make_pair(dp[i][j-1].fi,make_pair(i,j-1));
        }

				
			}
		}
	}

  pair<ll,pair<ll,ll> > ans = dp[n1][n2];
  pair<ll,ll> cur = ans.se;
  string res = "";

  if(str1[n1-1]==str2[n2-1]){
    res += str1[n1-1];
  }

  while((cur.fi>0)&&(cur.se>0)){
    ll i=cur.fi;
    ll j=cur.se;
    //cout<<"("<<i<<j<<")"<<"\n";
    if(str1[i-1]==str2[j-1]){
      res += str1[i-1];
    }
    cur = make_pair(dp[i][j].se.fi,dp[i][j].se.se);


  }

  reverse(res.begin(),res.end());
  cout<<res<<"\n";

	
}
