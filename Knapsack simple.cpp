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
	ll dp[n+1][w+1];
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=w;j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else if(weight[i-1]<=j){
				dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout<<dp[n][w]<<"\n";
	
}
