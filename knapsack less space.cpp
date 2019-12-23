#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll INF = 1e18L+5;
int main(){
	ll n,w;
	cin>>n>>w;
	vector<ll> weight(n),value(n);
	for(ll i=0;i<n;i++){
		
		cin>>weight[i]>>value[i];
		
	}
	vector<ll> dp(w+1);
	for(ll i=1;i<=n;i++){
		for(ll j=w;j>=0;j--){
			if(weight[i-1]<=j){
				dp[j] = max(dp[j],dp[j-weight[i-1]]+value[i-1]);
			}
		}
	}
	ll ans = 0;
	for(ll i=0;i<=w;i++){
		ans = max(ans,dp[i]);
	}
	cout<<ans<<"\n";
}
