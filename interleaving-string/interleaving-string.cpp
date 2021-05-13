class Solution {
    string a,b,c;
    int n1,n2,n3;
    // vector<vector<int>> dp(201,vector<int>(201,-1));
    int dp[205][205];
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        n1 = s1.length();
        n2 = s2.length();
        n3 = s3.length();
        
        if(n1+n2 != n3)
            return false;

        memset(dp,-1,sizeof(dp));
        
        a=s1,b=s2,c=s3;
        return helper(0,0,0);
            
    }
    
    bool helper(int i,int j,int k)
    {
        if(k==n3 && i==n1 && j==n2) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        bool x = false, y = false;
        
        if(i<n1 && a[i] == c[k]) x = helper(i+1,j,k+1);
        if(j<n2 && b[j] == c[k]) y = helper(i,j+1,k+1);
    
        return dp[i][j] = (int)(x || y);
    }
};