class Solution {
public:
    int numDecodings(string s) {
        
        if(s.size()==0 || s[0]=='0') 
            return 0;
        
        // int dp[s.size()+1];
        vector<int> dp(s.size()+1,0);
        
        dp[0]=(s[0]=='0')?0:1;
        dp[1]=(s[1]-'0'>0)?1:0;
        
        if((s[0]-'0')*10+(s[1]-'0') <= 26) 
            dp[1]++;
        
        for(int i=2;i<s.size();i++)
        {
            int s_digit = s[i]-'0';
            if(s_digit>0)
                dp[i]+=dp[i-1];
            
            int d_digit = (s[i-1]-'0')*10 + s_digit;
            if(d_digit >=10 && d_digit<=26)
                dp[i]+=dp[i-2];
        // cout<<dp[i]<<" ";
        }
    return dp[s.size()-1];
    }
};