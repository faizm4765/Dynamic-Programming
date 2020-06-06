#include <iostream>
using namespace std;



int coinChange(int a[],int m,int n){
    
    int **dp,i,j;
    dp = new int*[m+1];
    for(i=0;i<m+1;i++)
        dp[i] = new int[n+1];
    
    for(i=0;i<m+1;i++)
        dp[i][0] = 1;
    for(i=1;i<n+1;i++)
        dp[0][i] = 0;
    
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(a[i-1] <= j){
                dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];
            }else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[m][n];
    
}


int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    
	    int m,n,i;
	    cin>>m;
	    int arr[m];
	    for(i=0;i<m;i++)
	        cin>>arr[i];
	    cin>>n;
	    
	    cout<<coinChange(arr,m,n);
	    cout<<"\n";
	    
	}
	return 0;
}
