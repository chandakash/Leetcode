class Solution {
public:
    // DP optimization.
    bool check(vector<int> sides, int pos)
    {
        for(int i=0;i<pos;i++)
            if(sides[i]==sides[pos])
                return true;
        return false;
    }
    bool recurse(vector<int> sides, int pos, int target, vector<int> sticks)
    {
        if(pos == sticks.size())
            return sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target;
        
        for(int i=0;i<4;i++)
        {
            if(sides[i]+sticks[pos]>target || check(sides,i))
                continue;
            
            sides[i]+=sticks[pos];
            if(recurse(sides,pos+1,target,sticks))
                return true;
            sides[i]-=sticks[pos];
        }
    return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        // long sum=0;
        if(matchsticks.size()<4)
            return false;
        // for(auto x : matchsticks)
        // {
        //     sum+=x;
        // }
        long sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<int> sides(4,0);
        sum/=4;
        if(matchsticks[0]>sum) return false;
        
    return recurse(sides,0,sum,matchsticks);
    }
};