/*  Count the number of subset in an array with a given difference
    The problem asks to divide the array into two subsets such that the difference between their sums is equal to the given value.  
    We need to determine in how many ways , this can be achieved.

    Ex. Input :
            Size of array: 4
            Array:         1 1 2 3
            Given diff:    1

        Output:            3 
       
*/

Approach :
        Let S1 and S2 be sum of two subsets of the given array.
        
         S1 - S2 = diff     (given)
         S1 + S2 = sumOfArray
       => S1 = (diff + sumOfArray)/2
    
  Hence, problem reduces to count no of subsets in the array with sum = S1.
-----------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;


int countSubsetsWithGivenDiff(int a[],int n,int diff,int sum){
    int subset1_sum = (sum + diff)/2;
    int** dp,i,j;
    dp = new int* [n + 1];
    for(i=0;i<=n;i++){
        dp[i] = new int[subset1_sum + 1];
    }

    for(i=0;i<=n;i++)
        dp[i][0] = 1;
    for(i=1;i<=subset1_sum;i++)
        dp[0][i] = 0;

    for(i=1;i<=n;i++){
        for(j=1;j<=subset1_sum;j++){
            if(a[i-1] <= j){
                dp[i][j] = dp[i-1][j - a[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][subset1_sum];
}


int main(){

    int n,diff = 0;
    cin>>n;
    int a[n],i,sum = 0;
    for(i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    cin>>diff;          // given difference

    cout<<countSubsetsWithGivenDiff(a,n,diff,sum);
    cout<<endl;

    return 0;
}

