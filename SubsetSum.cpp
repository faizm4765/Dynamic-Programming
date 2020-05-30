   #include<bits/stdc++.h>
   using namespace std;

   int main(){
        bool dp[1000][1000];
        int i,j,n,sum;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>sum;
        for(i=0;i<n+1;i++)
            dp[i][0] = 1;
        for(i=1;i<=sum;i++)
            dp[0][i] = 0;

        for(i=1;i<=n;i++){
            for(j=1;j<=sum;j++){
                if(a[i-1]<=j){
                    dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        cout<<dp[n][sum];

        cout<<"\n";



       return 0;
   }