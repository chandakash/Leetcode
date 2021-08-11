class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        int i,n;
        n=startTime.size();
        for(i=0;i<n;i++)
        {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),comp);
        int l,r,mid,ans;
        int res=INT_MIN;
        int dp[n+1];
        dp[0]=0;
        for(i=0;i<n;i++)
        {
            l=0,r=i-1;
            ans=0;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(jobs[mid][1]<=jobs[i][0])
                {
                  ans=mid+1;
                  l=mid+1;
                }
                else
                r=mid-1;
            }
            dp[i+1]=jobs[i][2]+dp[ans];
            dp[i+1]=max(dp[i+1],dp[i]);
        }
        return dp[n];
    }
};