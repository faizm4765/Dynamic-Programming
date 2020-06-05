#include <bits/stdc++.h>
using namespace std;


int unboundKnapsack(int val[],int wt[],int n,int k,int dp[][1002]){
    
    if(n==0 or k==0)
        return dp[n][k] = 0;
        
    if(dp[n][k] != -1)
        return dp[n][k];
    
    if(wt[n-1] <= k){
        return dp[n][k] =max(val[n-1] + unboundKnapsack(val,wt,n,k-wt[n-1],dp),unboundKnapsack(val,wt,n-1,k,dp));
    }else
        return dp[n][k] = unboundKnapsack(val,wt,n-1,k,dp);
    
}


int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int val[n],wt[n],i;
	    for(i=0;i<n;i++)
	        cin>>val[i];
	    for(i=0;i<n;i++)
	        cin>>wt[i];
	    int dp[1002][1002];
	    memset(dp,-1,sizeof(dp));
	    cout<<unboundKnapsack(val,wt,n,k,dp);
	    cout<<"\n";
	}
	return 0;
}
