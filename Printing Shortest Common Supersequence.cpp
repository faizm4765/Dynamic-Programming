#include<bits/stdc++.h>
using namespace std;

#define pb push_back

string scSubsequence(string a,string b,int m,int n){

    int**dp,i,j;
    dp = new int*[m+1];
    for(i=0;i<=m;i++)
        dp[i] = new int[n+1];
    
    for(i=0;i<m+1;i++){
        for(j=0;j<n+1;j++){
            if(i==0 or j==0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    vector<char> v;
    string s;
    i = m,j = n;
    while(i>0 and j>0){
        if(a[i-1] == b[j-1]){
            s = a[i-1] + s;
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            s = a[i-1] + s;
            i--;
        }else{
            s = b[j-1] + s;
            j--;
        }
    }
    while(i){
        s = a[i-1] + s;
        i--;
    }
    while(j){
        s = b[j-1] + s;
        j--;
    }


    return s;

}


int main(){

    string a,b;
    cin>>a>>b;

    int m = a.length(),n = b.length();

    cout<<scSubsequence(a,b,m,n)<<"\n";

    return 0;
}
