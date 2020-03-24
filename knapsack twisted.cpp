/*kickstart 2020 round A problem - plates*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,p;

void solve(int cn){
    cin>>n>>k>>p;
    vector< vector<int> > arr(n,vector<int>(k,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
    }
    
    vector< vector<int> > dp(n+1,vector<int>(p+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            int sum = 0;
            for(int x=0;x<j;x++){
                sum += arr[i-1][x];
            }
            for(int x=0;x<=p;x++){
                if(x>=j){
                    dp[i][x] = max(dp[i-1][x-j]+sum,dp[i][x]);
                    //cout<<dp[i][x]<<" ";
                }
                
            }
            
        }
       /* for(int x=0;x<=p;x++){
                
                    cout<<dp[i][x]<<" ";
                }
                cout<<"\n";*/
    }
    
    cout<<"Case #"<<cn<<": "<<dp[n][p]<<"\n";
}


int main()
{
    int t;
    cin>>t;
    int cn = 1;
    while(t--){
        solve(cn);cn++;
    }

    return 0;
}
