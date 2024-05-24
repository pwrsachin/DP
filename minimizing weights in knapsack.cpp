//https://leetcode.com/discuss/study-guide/1152328/01-Knapsack-Problem-and-Dynamic-Programming
//Knapsack having high range of weight //
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll INF = 1e18L+5;
int main(){
	ll n,w;
	cin>>n>>w;
	ll sum = 0;
	vector<ll> weight(n),value(n);
	for(ll i=0;i<n;i++){
		cin>>weight[i]>>value[i];
		sum += value[i];
	}
	
	vector<ll> dp(sum+1,INF);
	dp[0] = 0;
	for(ll i=1;i<=n;i++){
		for(ll j = sum-value[i-1];j>=0;j--){
				dp[j+value[i-1]] = min(dp[j+value[i-1]],dp[j]+weight[i-1]);
		}
	}
	ll ans = 0;
	for(ll i=0;i<=sum;i++){
		if(dp[i]<=w) ans = max(ans,i);
	}
	cout<<ans<<"\n";
}
