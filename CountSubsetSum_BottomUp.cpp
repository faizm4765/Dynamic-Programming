#include<bits/stdc++.h>
using namespace std;

int fun(int arr[],int n,int sum){

    int** dp,i,j;
    
    dp = new int*[n+1];
    
    for(i=0;i<n+1;i++)
        dp[i] = new int[sum+1];
    
    for(i=0;i<n+1;i++)
        dp[i][0] = 1;
    for(i=1;i<sum+1;i++)
        dp[0][i] = 0;
    
    for(i=1;i<n+1;i++){
        for(j=1;j<sum+1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];    
}


int main(){
    int n,sum;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>sum;

    std::cout<<fun(a,n,sum);

    cout<<"\n";

    return 0;
}
