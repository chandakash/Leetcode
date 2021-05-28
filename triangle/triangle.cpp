class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<int> dp(rows+1,0);
        
        for(int i=rows-1;i>=0;i--)
        {
            for(int j=0; j<=i; j++)
            {
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
            }
        }
    return dp[0];
    }
};