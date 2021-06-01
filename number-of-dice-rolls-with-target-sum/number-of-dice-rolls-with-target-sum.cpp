class Solution {
    int dp[31][1001];
    const  int m=1000000007;
public:
    int numRollsToTarget(int d, int f, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(d,f,target);
    }
    
    int helper(int throws, int faces, int target)
    {
        if(target==0 && throws==0)
            return 1;
        if(target<0 || throws==0)
            return 0;
        
        
        if(dp[throws][target]!=-1)
            return dp[throws][target]%m;
        
        int ans = 0;
        for(int i=1;i<=faces;i++)
        {
            ans +=helper(throws-1,faces,target-i);
            ans=ans%m;
        }
    return dp[throws][target]=ans;
    }
};