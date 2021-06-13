class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n));      //dp[i][j] contains the number of stones that Alice would have collected in the range [i,j]
        for(int g=0;g<n;g++) {                  //This represents gap i.e when g=0, there is 1 number in the array, when g=1, we have 2 numbers in the array
            for(int i=0,j=g;j<n;i++,j++) {
                if(g==0)    dp[i][j]=piles[i];             //   when g=0, there is 1 number in the array
                else if(g==1)    dp[i][j]=max(piles[i],piles[j]);
                else {
                    int val1=piles[i]+min(dp[i+2][j],dp[i+1][j-1]);
                    int val2=piles[j]+min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j]=max(val1,val2);
                }
            }
        }
        int total=0;
        for(int i: piles)    total+=i;
        int second=total-dp[0][n-1];              //dp[0][n-1] will contain the maximum number of stones at the end that Alice will have
        return total-second > second;
    }
};