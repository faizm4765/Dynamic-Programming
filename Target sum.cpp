class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int sum = 0,cnt = 0;
        for(auto c: nums){
            sum += c;
            if(c == 0)  cnt++;
        }
            
        if(S > sum) return 0;
        
        if((S+sum) & 1) return 0;
        
        int val = (S + sum) / 2;
        
        int n = nums.size();
        int dp[n+1][val+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=val;j++){
                if(i==0 and j>0)
                    dp[i][j] = 0;
                else if(j==0)
                    dp[i][j] = 1;
                else if(nums[i-1] == 0)
                    dp[i][j] = dp[i-1][j];
                else if(j >= nums[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            }
        }
        return pow(2,cnt)*dp[n][val];
    }
};
