
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

-----------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;


int go(int a[],int n,int range,int sum){
    int **dp,i,j; 
    dp = new int*[n+1];
    for(i=0;i<n+1;i++)
        dp[i] = new int[sum+1];
    
    for(i=0;i<n+1;i++)
        dp[i][0] = 1;
    for(i=1;i<sum+1;i++)
        dp[0][i] = 0;
    for(i=1;i<n+1;i++){
        for(j=1;j<sum+1;j++){
            if(a[i-1] <= j){
                dp[i][j] = dp[i-1][j-a[i-1]] or dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int res = INT_MAX;
    for(i=0;i<=sum;i++){
        if(dp[n][i] == 1){
            if(range - 2*i < res)
                res = range - 2*i;
        }
    }
    return res;
}



int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n],i,sum = 0;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        sum += a[i];
	    }
	    cout<<go(a,n,sum,sum/2);
	    cout<<"\n";
	    
	}
	return 0;
}
