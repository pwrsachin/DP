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
	vector< vector<ll> > dp(2,vector<ll>(n2+1,0));
	ll bi = 0;
	for(ll i=1;i<=n1;i++){
		bi = (i & 1);
		for(ll j=1;j<=n2;j++){
			
			if(str1[i-1]==str2[j-1]){
				dp[bi][j] = 1+dp[1-bi][j-1];
			}
			else {
				dp[bi][j] = max(dp[1-bi][j],dp[bi][j-1]);
			}
		}
	}
	
	cout<<dp[bi][n2]<<"\n";
}
