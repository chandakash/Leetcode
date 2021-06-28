class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int dp[nums.size()][nums.size()];
        
        for(int g=0;g<nums.size();g++)
        {
            for(int i=0,j=g; j<nums.size();i++,j++)
            {
                int max = INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    int left = k==i?0:dp[i][k-1];
                    int right = k==j?0:dp[k+1][j];
                    int val = (i==0?1:nums[i-1])*nums[k]*(j==nums.size()-1?1:nums[j+1]);
                    
                    int total = left + val + right;
                    if(total>max)
                        max=total;
                }
            dp[i][j]=max;
            }
        }
    return dp[0][nums.size()-1];
    }
};